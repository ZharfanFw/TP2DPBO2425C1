#include <iostream>
#include "Elektronik.cpp"

using namespace std;

class Komputer : public Elektronik {
private:
  string motherboard, cpu, gpu, ram, storage;
public:
  Komputer() { 
    this->motherboard = "";
    this->cpu = "";
    this->gpu = "";
    this->ram = "";
    this->storage = "";
  }

  Komputer(string motherboard, string cpu, string gpu, string ram, string storage) { 
    // Inisialisasi atribut milik Komputer
    this->motherboard = motherboard;
    this->cpu = cpu;
    this->gpu = gpu;
    this->ram = ram;
    this->storage = storage;
  }

  // --- GETTERS ---
  string getMotherboard() { 
    return motherboard; 
  }

  string getCpu() {
    return cpu;
  }

  string getGpu() {
    return gpu;
  }
  string getRam() {
    return ram;
  }

  string getStorage() {
    return storage;
  }

  // --- SETTERS ---
  void setMotherboard(string motherboard) {
    this->motherboard = motherboard;
  }

  void setCpu(string cpu) {
    this->cpu = cpu;
  }

  void setGpu(string gpu) {
    this->gpu = gpu;
  }

  void setRam(string ram) {
    this->ram = ram;
  }

  void setStorage(string storage) {
    this->storage = storage;
  }

  ~Komputer(){}
};
