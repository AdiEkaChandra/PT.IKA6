// Program aplikasi CRUD dengan menggunakan C++
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Struktur data untuk menyimpan data motor
struct Mahasiswa {
  string nama;
  int nim;
  double ipk;
};

// Fungsi untuk menampilkan menu pilihan
void tampilkanMenu() {
  cout << "Pilih operasi yang ingin Anda lakukan:\n";
  cout << "1. Create (Menambahkan data mahasiswa)\n";
  cout << "2. Read (Menampilkan data mahasiswa)\n";
  cout << "3. Update (Mengubah data mahasiswa)\n";
  cout << "4. Delete (Menghapus data mahasiswa)\n";
  cout << "5. Exit (Keluar dari program)\n";
}

// Fungsi untuk menambahkan data mahasiswa ke dalam vektor
void tambahData(vector<Mahasiswa>& data) {
  Mahasiswa m;
  cout << "Masukkan nama mahasiswa: ";
  cin >> m.nama;
  cout << "Masukkan NIM mahasiswa: ";
  cin >> m.nim;
  cout << "Masukkan IPK mahasiswa: ";
  cin >> m.ipk;
  data.push_back(m); // Menyimpan data mahasiswa ke dalam vektor
  cout << "Data mahasiswa berhasil ditambahkan.\n";
}

// Fungsi untuk menampilkan data mahasiswa dari vektor
void tampilkanData(const vector<Mahasiswa>& data) {
  if (data.empty()) { // Jika vektor kosong, tidak ada data yang ditampilkan
    cout << "Tidak ada data mahasiswa.\n";
    return;
  }
  cout << "Data mahasiswa yang tersimpan:\n";
  cout << "No.\tNama\tNIM\tIPK\n";
  for (int i = 0; i < data.size(); i++) { // Looping untuk menampilkan setiap data mahasiswa
    cout << i + 1 << "\t" << data[i].nama << "\t" << data[i].nim << "\t" << data[i].ipk << "\n";
  }
}

// Fungsi untuk mengubah data mahasiswa dari vektor berdasarkan indeks
void ubahData(vector<Mahasiswa>& data) {
  if (data.empty()) { // Jika vektor kosong, tidak ada data yang dapat diubah
    cout << "Tidak ada data mahasiswa yang dapat diubah.\n";
    return;
  }
  int indeks;
  cout << "Masukkan nomor data mahasiswa yang ingin diubah: ";
  cin >> indeks;
  if (indeks < 1 || indeks > data.size()) { // Jika indeks tidak valid, operasi dibatalkan
    cout << "Nomor data mahasiswa tidak valid.\n";
    return;
  }
  indeks--; // Mengurangi indeks dengan 1 karena vektor dimulai dari 0
  Mahasiswa m;
  cout << "Masukkan nama mahasiswa baru: ";
  cin >> m.nama;
  cout << "Masukkan NIM mahasiswa baru: ";
  cin >> m.nim;
  cout << "Masukkan IPK mahasiswa baru: ";
  cin >> m.ipk;
  data[indeks] = m; // Mengganti data mahasiswa lama dengan data mahasiswa baru
  cout << "Data mahasiswa berhasil diubah.\n";
}

// Fungsi untuk menghapus data mahasiswa dari vektor berdasarkan indeks
void hapusData(vector<Mahasiswa>& data) {
  if (data.empty()) { // Jika vektor kosong, tidak ada data yang dapat dihapus
    cout << "Tidak ada data mahasiswa yang dapat dihapus.\n";
    return;
  }
  int indeks;
  cout << "Masukkan nomor data mahasiswa yang ingin dihapus: ";
  cin >> indeks;
  if (indeks < 1 || indeks > data.size()) { // Jika indeks tidak valid, operasi dibatalkan
    cout << "Nomor data mahasiswa tidak valid.\n";
    return;
  }
  indeks--; // Mengurangi indeks dengan 1 karena vektor dimulai dari 0
  data.erase(data.begin() + indeks); // Menghapus data mahasiswa dari vektor
  cout << "Data mahasiswa berhasil dihapus.\n";
}

// Fungsi utama untuk menjalankan program aplikasi CRUD
int main() {
  vector<Mahasiswa> data; // Vektor untuk menyimpan data mahasiswa
  int pilihan; // Variabel untuk menyimpan pilihan operasi
  bool selesai = false; // Variabel untuk menentukan apakah program selesai atau tidak
  while (!selesai) { // Looping selama program belum selesai
    tampilkanMenu(); // Menampilkan menu pilihan
    cout << "Masukkan pilihan Anda: ";
    cin >> pilihan;
    switch (pilihan) { // Menentukan operasi yang akan dilakukan berdasarkan pilihan
      case 1: // Create
        tambahData(data); // Menambahkan data mahasiswa
        break;
      case 2: // Read
        tampilkanData(data); // Menampilkan data mahasiswa
        break;
      case 3: // Update
        ubahData(data); // Mengubah data mahasiswa
        break;
      case 4: // Delete
        hapusData(data); // Menghapus data mahasiswa
        break;
      case 5: // Exit
        selesai = true; // Mengakhiri program
        cout << "Terima kasih telah menggunakan program aplikasi CRUD ini.\n";
        break;
      default: // Pilihan tidak valid
        cout << "Pilihan Anda tidak valid. Silakan coba lagi.\n";
        break;
    }
  }
  return 0;
}