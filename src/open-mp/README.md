
# Tugas Kecil 2 : Open MP

Paralelisasi algoritma DFT menggunakan open MPI pada bahasa pemrograman C,Open MP merupakan API (Application Programming Interface) yang memungkinkan penggunaan multithreading pada bahasa pemrograman C/C++, dengan OpenMP memungkinkan untuk mengurangi waktu yang diperlukan untuk menjalankan program dan melakukan perhitungan. 


## Penjelasan Program

Pada fungsi readMatrix, terdapat sebuah blok #pragma omp parallel yang menandakan bahwa blok kode tersebut akan dijalankan secara paralel. Selain itu, terdapat pula perintah num_threads(8) yang mengindikasikan bahwa akan digunakan 8 thread untuk menjalankan blok kode tersebut.

Pada fungsi dft, terdapat sebuah blok #pragma omp parallel for yang menandakan bahwa blok kode pada loop for di dalamnya akan dijalankan secara paralel. Selain itu, terdapat perintah reduction(+:element) yang berfungsi untuk melakukan operasi reduction pada variabel element. Reduction digunakan untuk menjumlahkan semua nilai pada variabel element yang dihasilkan oleh setiap thread sehingga menghasilkan sebuah nilai tunggal yang akan disimpan pada variabel element pada thread utama.

Pada fungsi main, terdapat dua loop for yang masing-masing diikuti oleh sebuah blok #pragma omp parallel for yang menandakan bahwa blok kode pada setiap iterasi loop akan dijalankan secara paralel. Selain itu, pada loop kedua juga terdapat perintah reduction(+:sum) yang berfungsi untuk menjumlahkan semua nilai pada variabel sum yang dihasilkan oleh setiap thread sehingga menghasilkan sebuah nilai tunggal yang akan disimpan pada variabel sum pada thread utama.

Dengan memanfaatkan OpenMP, program tersebut dapat mempercepat waktu eksekusi karena setiap thread dapat menjalankan bagian-bagian kode yang independen secara paralel. Namun, perlu diingat bahwa penggunaan OpenMP harus dilakukan dengan hati-hati karena salah penggunaan dapat menyebabkan kesalahan atau bahkan menghasilkan hasil yang tidak konsisten.



## References

 - [OpenMP Documentation](https://www.openmp.org/resources/openmp-documents/)
 - [Materi Kelas](https://cdn-edunex.itb.ac.id/38097-Parallel-and-Distributed-Systems-Parallel-Class/73156-Shared-Memory-System/1644375788982_IF3230-05-SharedMemoryOpenMP-2022.pdf)


## Authors

- 13520118 Mohamad Daffa Argakoesoemah
- 13520143 Muhammad Gerald Akbar Giffera
- 13520145 Steven Gianmarg H. Siahaan
- 13520158 Azmi Alfatih Shalahuddin


## Screenshots

**Dijalankan pada Windows11 - WSL 2 Ubuntu 20.04 - Core i5-1035GP4 CPU @1.1GHz,1498 Mhz**

 TestCase             | Hasil Serial                                                      | Hasil Paralel | 
| ----------------- | ------------------------------------------------------------------ | ------- |
| 32.txt | <img width="475" alt="32 Serial" src="https://drive.google.com/file/d/14_ofip3mHGiZPXhPhzCrQozBIkBX9N-Q/view?usp=share_link"> |<img width="702" alt="32 Open-Mp" src="https://drive.google.com/file/d/1oMxw9Z58TrAbQbG5rv-vLqLG7fRETb61/view?usp=share_link"> |
| 64.txt | <img width="475" alt="64 Serial" src="https://drive.google.com/file/d/14N_JB7N07Gk2QW1e-eZKGA7J_QkYRX4L/view?usp=share_link"> |<img width="702" alt="64 Open-Mp" src="https://drive.google.com/file/d/1P9qPqXlFSKBg3Oi-DEYw0EDa0GidJmlr/view?usp=share_link"> |
| 128.txt |  <img width="475" alt="128 Serial" src="https://drive.google.com/file/d/1w9pu3GC1nebD3VFQ3HTtHrRETbAxGlqp/view?usp=share_link"> |<img width="702" alt="128 Open-Mp" src="https://drive.google.com/file/d/1f1ab3EIYyjfPfUOq_nZ2Z_Pl_lLp-7S1/view?usp=share_link">|
| 256.txt |  <img width="475" alt="256 Serial" src="https://drive.google.com/file/d/1z3SSjlHM3lctHeLxoxax--YIU-TGZbJW/view?usp=share_link"> |<img width="702" alt="256 Open-Mp" src="https://drive.google.com/file/d/1GU48lqKz4nU7kVwFE_Ft3554KcOZ4Hj2/view?usp=share_link">|



