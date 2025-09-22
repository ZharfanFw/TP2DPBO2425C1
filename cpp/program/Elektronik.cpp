#include <iostream>
#include <string>

using namespace std;

class Elektronik {
private:
  string id_produk, nama_produk, foto_produk; 
  int harga_produk, stok_produk;

public:
  Elektronik() {
    this->id_produk = "";
    this->nama_produk = "";
    this->harga_produk = 0;
    this->stok_produk = 0;
    this->foto_produk = "";
  }

  Elektronik(string id_produk, string nama_produk, int harga_produk, int stok_produk, string foto_produk) {
    this->id_produk = id_produk;
    this->nama_produk = nama_produk;
    this->harga_produk = harga_produk;
    this->stok_produk = stok_produk;
    this->foto_produk = foto_produk;
  }

  // --- GETTERS ---
  // Metode untuk mengambil nilai atribut

  string getIdProduk() {
      return id_produk;
  }

  string getNamaProduk() {
      return nama_produk;
  }

  int getHargaProduk() {
      return harga_produk;
  }

  int getStokProduk() {
      return stok_produk;
  }

  string getFotoProduk() {
      return foto_produk;
  }

  // --- SETTERS ---
  // Metode untuk mengubah nilai atribut

  void setIdProduk(string id_produk) {
      this->id_produk = id_produk;
  }

  void setNamaProduk(string nama_produk) {
      this->nama_produk = nama_produk;
  }

  void setHargaProduk(int harga_produk) {
      this->harga_produk = harga_produk;
  }

  void setStokProduk(int stok_produk) {
      this->stok_produk = stok_produk;
  }

  void setFotoProduk(string foto_produk) {
      this->foto_produk = foto_produk;
  }

  ~Elektronik(){}
};
