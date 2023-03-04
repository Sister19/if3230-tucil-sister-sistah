
# Tugas Kecil 2 : Open MP

Paralelisasi algoritma DFT menggunakan open MPI pada bahasa pemrograman C,Open MP merupakan API (Application Programming Interface) yang memungkinkan penggunaan multithreading pada bahasa pemrograman C/C++, dengan OpenMP memungkinkan untuk mengurangi waktu yang diperlukan untuk menjalankan program dan melakukan perhitungan. 


## Penjelasan Program

Pada fungsi readMatrix, terdapat sebuah blok #pragma omp parallel yang menandakan bahwa blok kode tersebut akan dijalankan secara paralel. Selain itu, terdapat pula perintah num_threads(8) yang mengindikasikan bahwa akan digunakan 8 thread untuk menjalankan blok kode tersebut.

Pada fungsi dft, terdapat sebuah blok #pragma omp parallel for yang menandakan bahwa blok kode pada loop for di dalamnya akan dijalankan secara paralel. Selain itu, terdapat perintah reduction(+:element) yang berfungsi untuk melakukan operasi reduction pada variabel element. Reduction digunakan untuk menjumlahkan semua nilai pada variabel element yang dihasilkan oleh setiap thread sehingga menghasilkan sebuah nilai tunggal yang akan disimpan pada variabel element pada thread utama.

Pada fungsi main, terdapat dua loop for yang masing-masing diikuti oleh sebuah blok #pragma omp parallel for yang menandakan bahwa blok kode pada setiap iterasi loop akan dijalankan secara paralel. Selain itu, pada loop kedua juga terdapat perintah reduction(+:sum) yang berfungsi untuk menjumlahkan semua nilai pada variabel sum yang dihasilkan oleh setiap thread sehingga menghasilkan sebuah nilai tunggal yang akan disimpan pada variabel sum pada thread utama.

Dengan memanfaatkan OpenMP, program tersebut dapat mempercepat waktu eksekusi karena setiap thread dapat menjalankan bagian-bagian kode yang independen secara paralel.



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
| 32.txt | <img width="475" alt="32 Serial" src="https://user-images.githubusercontent.com/88304745/222873328-b555790a-1f95-494d-826d-b329760cd3c2.png"> |<img width="702" alt="32 Open-Mp" src="https://user-images.githubusercontent.com/88304745/222873310-326999fd-537d-444d-8a39-087adabaef45.png"> |
| 64.txt | <img width="475" alt="64 Serial" src="https://user-images.githubusercontent.com/88304745/222873331-1e2243df-a8d7-453e-9df4-b56a50eb9afb.png"> |<img width="702" alt="64 Open-Mp" src="https://user-images.githubusercontent.com/88304745/222873329-ec6fc646-3e71-44f0-9687-822575877d08.png"> |
| 128.txt |  <img width="475" alt="128 Serial" src="https://user-images.githubusercontent.com/88304745/222873334-ebb6f356-cec2-436d-93b6-53b7e107f93c.png"> |<img width="702" alt="128 Open-Mp" src="https://user-images.githubusercontent.com/88304745/222873333-ea393cd4-8383-4768-af03-0137e528a89c.png">|
| 256.txt |  <img width="475" alt="256 Serial" src="https://user-images.githubusercontent.com/88304745/222873326-160ed087-2dc6-44e1-9bee-cf646d857723.png"> |<img width="702" alt="256 Open-Mp" src="https://user-images.githubusercontent.com/88304745/222873335-98936879-fac7-430a-ae90-c83f36f2b24e.png">|



