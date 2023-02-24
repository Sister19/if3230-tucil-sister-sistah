#include <complex.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>

#define MAX_N 512

struct Matrix {
    int    size;
    double mat[MAX_N][MAX_N];
};

struct ProcMatrix {
    int    size;
    double complex mat[MAX_N][MAX_N];
};

void readMatrix(struct Matrix *m) {
    scanf("%d", &(m->size));
    for (int i = 0; i < m->size; i++)
        for (int j = 0; j < m->size; j++)
            scanf("%lf", &(m->mat[i][j]));
}

void fft(double complex *input, double complex *output, int size, int step) {
    if (size == 1) {
        output[0] = input[0];
        return;
    }

    double complex even[size / 2], odd[size / 2];
    fft(input, even, size / 2, step * 2);
    fft(input + step, odd, size / 2, step * 2);

    for (int i = 0; i < size / 2; i++) {
        double complex arg = -2.0 * M_PI * i / (double) size;
        double complex exponent = cexp(arg * I);
        output[i] = even[i] + exponent * odd[i];
        output[i + size / 2] = even[i] - exponent * odd[i];
    }
}

double complex fft2d(struct Matrix *mat, int k, int l) {
    double complex input[mat->size], output[mat->size];
    for (int i = 0; i < mat->size; i++) {
        input[i] = mat->mat[i][l];
    }
    fft(input, output, mat->size, 1);

    double complex element = 0.0;
    for (int i = 0; i < mat->size; i++) {
        double complex arg = -2.0 * M_PI * k * i / (double) mat->size;
        double complex exponent = cexp(arg * I);
        element += output[i] * exponent;
    }
    return element / (double) mat->size;
}
double complex dft(struct Matrix *mat, int k, int l) {
    double complex element = 0.0;
    for (int m = 0; m < mat->size; m++) {
        for (int n = 0; n < mat->size; n++) {
            double complex arg      = (k*m / (double) mat->size) + (l*n / (double) mat->size);
            double complex exponent = cexp(-2.0I * M_PI * arg);
            element += mat->mat[m][n] * exponent;
        }
    }
    return element / (double) (mat->size*mat->size);
}


int main(int argc, char *argv[]) {
    int num_procs, rank, source_size, i, j, k, l;
    double complex sum = 0.0;
    struct Matrix     source;
    struct ProcMatrix proc_domain;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        readMatrix(&source);
        source_size = source.size;
        proc_domain.size = source_size;
    }
    
    MPI_Bcast(&source_size, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // broadcast the matrix data separately
    if (rank != 0) {
        source.size = source_size;
    }
    MPI_Bcast(&(source.size), 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(source.mat, source_size*MAX_N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    proc_domain.size = source_size;
    
    // MPI_Bcast(&source, 64*64, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    // MPI_Bcast(&proc_domain.size, 1, MPI_INT, 0, MPI_COMM_WORLD);

    int k_start = rank * source.size / num_procs;
    int k_end   = (rank + 1) * source.size / num_procs;
    for (k = k_start; k < k_end; k++) {
        for (l = 0; l < source.size; l++) {
            proc_domain.mat[k][l] = dft(&source, k, l);
        }
    }

    for (k = k_start; k < k_end; k++) {
        for (l = 0; l < source.size; l++) {
            double complex el = proc_domain.mat[k][l];
            sum += el;
        }
    }
    sum /= source.size;
    double complex globalSum;
   
    MPI_Reduce(&sum, &globalSum, 1, MPI_C_DOUBLE_COMPLEX, MPI_SUM, 0, MPI_COMM_WORLD);

    for (k = k_start; k < k_end; k++) {
        for (l = 0; l < source.size; l++) {
            double complex el = proc_domain.mat[k][l];
            printf("(%lf, %lf) ", creal(el), cimag(el));
        }
        printf("\n");
    }    
    if (rank == 0) {
       printf("Average : (%lf, %lf)", creal(globalSum), cimag(globalSum));
    }

    MPI_Finalize();

    return 0;
}
