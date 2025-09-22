#include <iostream>
#include "Komputer.cpp"

using namespace std;

class Laptop : public Komputer {
private:
  string baterai, ukuran_layar, resolusi_layar;

public:
  Laptop () { 
    this->baterai = "";
    this->ukuran_layar = "";
    this->resolusi_layar = "";
  }

  Laptop (string baterai, string ukuran_layar, string resolusi_layar) { 
    this->baterai = baterai;
    this->ukuran_layar = ukuran_layar;
    this->resolusi_layar = resolusi_layar;
  }

  // --- GETTERS ---
  string getBaterai() {
      return baterai;
  }

  string getUkuranLayar() {
      return ukuran_layar;
  }

  string getResolusiLayar() {
      return resolusi_layar;
  }

  // --- SETTERS ---
  void setBaterai(string baterai) {
      this->baterai = baterai;
  }

  void setUkuranLayar(string ukuran_layar) {
      this->ukuran_layar = ukuran_layar;
  }

  void setResolusiLayar(string resolusi_layar) {
      this->resolusi_layar = resolusi_layar;
  }

  ~Laptop(){}
};
