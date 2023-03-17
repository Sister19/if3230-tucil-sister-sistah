// gcc mp.c --openmp -o mp
#include <complex.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define MAX_N 512

struct Matrix {
    int    size;
    double mat[MAX_N][MAX_N];
};

struct FreqMatrix {
    int    size;
    double complex mat[MAX_N][MAX_N];
};

void readMatrix(struct Matrix *m) {
    scanf("%d", &(m->size));
    int i, j, tid;
    #pragma omp parallel private(i, j, tid) num_threads(8)
    {
        tid = omp_get_thread_num();
        #pragma omp sections
        {
            #pragma omp section
            {
                for (i = 0; i < m->size/2; i++) {
                    for (j = 0; j < m->size; j++) {
                        scanf("%lf", &(m->mat[i][j]));
                    }
                }
            }
            #pragma omp section
            {
                for (i = m->size/2; i < m->size; i++) {
                    for (j = 0; j < m->size; j++) {
                        scanf("%lf", &(m->mat[i][j]));
                    }
                }
            }
        }
    }
}

double complex dft(struct Matrix *mat, int k, int l) {
    double complex element = 0.0;
    #pragma omp parallel for reduction(+:element) num_threads(8)
    for (int m = 0; m < mat->size; m++) {
        for (int n = 0; n < mat->size; n++) {
            double complex arg      = (k*m / (double) mat->size) + (l*n / (double) mat->size);
            double complex exponent = cexp(-2.0I * M_PI * arg);
            element += mat->mat[m][n] * exponent;
        }
    }
    return element / (double) (mat->size*mat->size);
}

int main(void) {
    struct Matrix     source;
    struct FreqMatrix freq_domain;
    readMatrix(&source);
    freq_domain.size = source.size;

    #pragma omp parallel for num_threads(8)
    for (int k = 0; k < source.size; k++) {
        for (int l = 0; l < source.size; l++) {
            freq_domain.mat[k][l] = dft(&source, k, l);
        }
    }

    double complex sum = 0.0;
    #pragma omp parallel for reduction(+:sum) num_threads(8)
    for (int k = 0; k < source.size; k++) {
        for (int l = 0; l < source.size; l++) {
            double complex el = freq_domain.mat[k][l];
            printf("(%lf, %lf) ", creal(el), cimag(el));
            sum += el;
        }
        printf("\n");
    }
    sum /= source.size;
    printf("Average : (%lf, %lf)", creal(sum), cimag(sum));

    return 0;
}