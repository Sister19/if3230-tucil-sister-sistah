
# Tugas Kecil 1 : Open MPI

Paralelisasi algoritma DFT menggunakan library open MPI pada bahasa pemrograman C, pada program paralel ini tugas untuk algoritma DFT dapat dibagi secara seimbang di masing-masing processor yang ada pada komputer, sehingga dapat mengurangi waktu yang diperlukan untuk menjalankan program dan melakukan perhitungan. 


## Penjelasan Program

Program ini memanfaatkan library open MPI untuk memparalelisasi algortima DFT yang ada, secara garis besar program akan membaca input berupa matriks yang direpresntasikan dalam TextFile. Lalu untuk proses perhitungan DFT, program akan membagi processor yang tersedia untuk menghitung sebagian dari matriks sehingga perhitungan DFT bisa dijalankan secara paralel. Setelah mendapatkan nilai untuk masing-masing bagian matriks, nantinya program juga akan menghitung total dari nilai-nilai yang diperoleh dari masing-masing processor, beberapa fungsi open MPI yang dimanfaatkan sebagai berikut:

- `MPI_Reduce` => Untuk menghitung total perhitungan dari tiap processor
- `MPI_Bcast` => Mengirim informasi dari satu processor ke processor lainnya
- `MPI_Comm_size` => Memperoleh informasi jumlah processor yang tersedia
- `MPI_Comm_rank` => Memperoleh informasi processor yang sedang berjalan
## References

 - [MPI Documentation](https://www.mpich.org/static/docs/v3.3/www3/)
 - [Materi Kelas](https://cdn-edunex.itb.ac.id/38097-Parallel-and-Distributed-Systems-Parallel-Class/73155-Distributed-Memory-System/1643769784185_IF3230-03-DistributedMemory-2022.pdf)


## Authors

- 13520118 Mohamad Daffa Argakoesoemah
- 13520143 Muhammad Gerald Akbar Giffera
- 13520145 Steven Gianmarg H. Siahaan
- 13520158 Azmi Alfatih Shalahuddin


## Screenshots

**Dijalankan pada MacOS Ventura 13.2 M1 Chip**

 TestCase             | Hasil Serial                                                      | Hasil Paralel | 
| ----------------- | ------------------------------------------------------------------ | ------- |
| 64.txt | <img width="475" alt="Screenshot 2023-02-24 at 22 30 08" src="https://user-images.githubusercontent.com/69229629/221219737-9f709f97-26c1-4174-99d2-b1a9062cff5d.png"> |<img width="702" alt="Screenshot 2023-02-24 at 22 29 51" src="https://user-images.githubusercontent.com/69229629/221220271-d7484327-f223-44a6-8947-d019e89ed678.png"> |
|  |  | |
|  |  ||
|  |  ||



