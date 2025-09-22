#include <bits/stdc++.h>
#include "Laptop.cpp"

using namespace std;

// =================== Fungsi Utility ===================

// Hitung lebar kolom tabel berdasarkan panjang data terpanjang tiap field
vector<size_t> hitungLebarKolom(vector<Laptop>& data) {
    // Inisialisasi lebar awal berdasarkan header
    vector<size_t> lebar = {
        string("ID Produk").size(), string("Nama Produk").size(), string("Harga").size(), string("Stok").size(),
        string("Motherboard").size(), string("CPU").size(), string("GPU").size(), string("RAM").size(),
        string("Storage").size(), string("Baterai").size(), string("Ukuran Layar").size(), string("Resolusi").size()
    };

    // Update lebar berdasarkan data setiap laptop
    for (auto& item : data) {
        lebar[0] = max(lebar[0], item.getIdProduk().size());
        lebar[1] = max(lebar[1], item.getNamaProduk().size());
        lebar[2] = max(lebar[2], to_string(item.getHargaProduk()).size());
        lebar[3] = max(lebar[3], to_string(item.getStokProduk()).size());
        lebar[4] = max(lebar[4], item.getMotherboard().size());
        lebar[5] = max(lebar[5], item.getCpu().size());
        lebar[6] = max(lebar[6], item.getGpu().size());
        lebar[7] = max(lebar[7], item.getRam().size());
        lebar[8] = max(lebar[8], item.getStorage().size());
        lebar[9] = max(lebar[9], item.getBaterai().size());
        lebar[10] = max(lebar[10], item.getUkuranLayar().size());
        lebar[11] = max(lebar[11], item.getResolusiLayar().size());
    }
    return lebar; // kembalikan vektor lebar tiap kolom
}

// Cetak garis horizontal tabel
void cetakGaris(vector<size_t>& lebar) {
    cout << "+";
    for (auto& w : lebar)
        cout << string(w + 2, '-') << "+";
    cout << "\n";
}

// Tampilkan data laptop dalam bentuk tabel rapi
void tampilkanTabel(vector<Laptop>& data) {
    if (data.empty()) { // cek jika data kosong
        cout << "Data kosong.\n";
        return;
    }

    vector<size_t> lebar = hitungLebarKolom(data); // hitung lebar tiap kolom
    vector<string> header = {"ID Produk", "Nama Produk", "Harga", "Stok", "Motherboard",
                             "CPU", "GPU", "RAM", "Storage", "Baterai", "Ukuran Layar", "Resolusi"};

    cetakGaris(lebar); // garis atas
    cout << "|";
    for (size_t i = 0; i < header.size(); i++)
        cout << " " << left << setw(lebar[i]) << header[i] << " |"; // cetak header
    cout << "\n";
    cetakGaris(lebar); // garis pemisah header

    for (auto& item : data) { // cetak setiap row laptop
        cout << "| " << setw(lebar[0]) << left << item.getIdProduk() << " |";
        cout << " " << setw(lebar[1]) << item.getNamaProduk() << " |";
        cout << " " << setw(lebar[2]) << item.getHargaProduk() << " |";
        cout << " " << setw(lebar[3]) << item.getStokProduk() << " |";
        cout << " " << setw(lebar[4]) << item.getMotherboard() << " |";
        cout << " " << setw(lebar[5]) << item.getCpu() << " |";
        cout << " " << setw(lebar[6]) << item.getGpu() << " |";
        cout << " " << setw(lebar[7]) << item.getRam() << " |";
        cout << " " << setw(lebar[8]) << item.getStorage() << " |";
        cout << " " << setw(lebar[9]) << item.getBaterai() << " |";
        cout << " " << setw(lebar[10]) << item.getUkuranLayar() << " |";
        cout << " " << setw(lebar[11]) << item.getResolusiLayar() << " |";
        cout << "\n";
    }
    cetakGaris(lebar); // garis bawah tabel
}

// =================== Fungsi Input & Validasi ===================

// Fungsi input laptop baru
Laptop inputLaptop() {
    Laptop l;
    string temp;

    cout << "\nPilih cara input data:" << endl;
    cout << "1. Input satu per satu" << endl;
    cout << "2. Input langsung semua field (dipisah ';')" << endl;
    cout << "Pilihan: ";
    int opsi; cin >> opsi; cin.ignore();

    if (opsi == 1) { // input manual per field
        cout << "Masukkan ID Produk: "; getline(cin, temp); l.setIdProduk(temp);
        cout << "Masukkan Nama Produk: "; getline(cin, temp); l.setNamaProduk(temp);
        cout << "Masukkan Harga: "; getline(cin, temp); l.setHargaProduk(stoi(temp));
        cout << "Masukkan Stok: "; getline(cin, temp); l.setStokProduk(stoi(temp));
        cout << "Masukkan Foto Produk: "; getline(cin, temp); l.setFotoProduk(temp);
        cout << "Masukkan Motherboard: "; getline(cin, temp); l.setMotherboard(temp);
        cout << "Masukkan CPU: "; getline(cin, temp); l.setCpu(temp);
        cout << "Masukkan GPU: "; getline(cin, temp); l.setGpu(temp);
        cout << "Masukkan RAM: "; getline(cin, temp); l.setRam(temp);
        cout << "Masukkan Storage: "; getline(cin, temp); l.setStorage(temp);
        cout << "Masukkan Baterai: "; getline(cin, temp); l.setBaterai(temp);
        cout << "Masukkan Ukuran Layar: "; getline(cin, temp); l.setUkuranLayar(temp);
        cout << "Masukkan Resolusi Layar: "; getline(cin, temp); l.setResolusiLayar(temp);
    } else if (opsi == 2) { // input baris langsung
        cout << "Masukkan data (dipisah ';'):\n";
        string line; getline(cin, line);
        stringstream ss(line);
        string id, nama, foto, mb, cpu, gpu, ram, storage, bat, ukuran, res, hargaStr, stokStr;

        // Pisahkan field dengan delimiter ';'
        getline(ss, id, ';'); getline(ss, nama, ';'); getline(ss, hargaStr, ';'); getline(ss, stokStr, ';');
        getline(ss, foto, ';'); getline(ss, mb, ';'); getline(ss, cpu, ';'); getline(ss, gpu, ';');
        getline(ss, ram, ';'); getline(ss, storage, ';'); getline(ss, bat, ';'); getline(ss, ukuran, ';');
        getline(ss, res, ';');

        // Set field ke object laptop
        l.setIdProduk(id); l.setNamaProduk(nama);
        l.setHargaProduk(stoi(hargaStr)); l.setStokProduk(stoi(stokStr));
        l.setFotoProduk(foto); l.setMotherboard(mb); l.setCpu(cpu); l.setGpu(gpu);
        l.setRam(ram); l.setStorage(storage); l.setBaterai(bat); l.setUkuranLayar(ukuran);
        l.setResolusiLayar(res);
    }

    return l;
}

// Cek jika ada field kosong
bool adaFieldKosong(Laptop& l) {
    return l.getIdProduk().empty() || l.getNamaProduk().empty() || l.getFotoProduk().empty() ||
           l.getMotherboard().empty() || l.getCpu().empty() || l.getGpu().empty() ||
           l.getRam().empty() || l.getStorage().empty() || l.getBaterai().empty() ||
           l.getUkuranLayar().empty() || l.getResolusiLayar().empty();
}

// Validasi harga/stok negatif
bool validasiHargaStok(Laptop& l) {
    if (l.getHargaProduk() < 0) { 
        cout << "❌ Error: Harga tidak boleh negatif!\n"; 
        return false; 
    }
    if (l.getStokProduk() < 0) { 
        cout << "❌ Error: Stok tidak boleh negatif!\n"; 
        return false; 
    }
    return true;
}

// Cek duplikat ID/Nama
bool cekDuplikat(vector<Laptop>& data, string id, string nama) {
    for (auto& item : data) {
        if (item.getIdProduk() == id) {
            cout << "❌ Error: ID Produk \"" << id << "\" sudah ada.\n";
            return true;
        }
        if (item.getNamaProduk() == nama) {
            cout << "❌ Error: Nama Produk \"" << nama << "\" sudah ada.\n";
            return true;
        }
    }
    return false;
}

// =================== Fungsi Main ===================

int main() {
    vector<Laptop> daftarLaptop; // simpan semua data laptop

    // ===== Data dummy awal =====
    Laptop l1; l1.setIdProduk("P001"); l1.setNamaProduk("ASUS ROG"); l1.setHargaProduk(20000000); l1.setStokProduk(10);
    l1.setFotoProduk("rog.jpg"); l1.setMotherboard("ROG STRIX"); l1.setCpu("Intel i7"); l1.setGpu("RTX 3060");
    l1.setRam("16GB"); l1.setStorage("1TB SSD"); l1.setBaterai("80Wh"); l1.setUkuranLayar("15.6 inci"); l1.setResolusiLayar("1920x1080");

    Laptop l2; l2.setIdProduk("P002"); l2.setNamaProduk("Acer Nitro"); l2.setHargaProduk(15000000); l2.setStokProduk(5);
    l2.setFotoProduk("nitro.jpg"); l2.setMotherboard("Nitro MB"); l2.setCpu("AMD Ryzen 5"); l2.setGpu("GTX 1650");
    l2.setRam("8GB"); l2.setStorage("512GB SSD"); l2.setBaterai("60Wh"); l2.setUkuranLayar("15.6 inci"); l2.setResolusiLayar("1920x1080");

    Laptop l3; l3.setIdProduk("P003"); l3.setNamaProduk("Lenovo ThinkPad"); l3.setHargaProduk(12000000); l3.setStokProduk(8);
    l3.setFotoProduk("thinkpad.jpg"); l3.setMotherboard("Think MB"); l3.setCpu("Intel i5"); l3.setGpu("Intel UHD");
    l3.setRam("8GB"); l3.setStorage("256GB SSD"); l3.setBaterai("50Wh"); l3.setUkuranLayar("14 inci"); l3.setResolusiLayar("1366x768");

    Laptop l4; l4.setIdProduk("P004"); l4.setNamaProduk("HP Pavilion"); l4.setHargaProduk(13000000); l4.setStokProduk(7);
    l4.setFotoProduk("pavilion.jpg"); l4.setMotherboard("HP MB"); l4.setCpu("Intel i5"); l4.setGpu("MX130");
    l4.setRam("8GB"); l4.setStorage("512GB SSD"); l4.setBaterai("55Wh"); l4.setUkuranLayar("15.6 inci"); l4.setResolusiLayar("1920x1080");

    Laptop l5; l5.setIdProduk("P005"); l5.setNamaProduk("MSI Gaming"); l5.setHargaProduk(18000000); l5.setStokProduk(6);
    l5.setFotoProduk("msi.jpg"); l5.setMotherboard("MSI MB"); l5.setCpu("Intel i7"); l5.setGpu("RTX 3050");
    l5.setRam("16GB"); l5.setStorage("1TB HDD + 256GB SSD"); l5.setBaterai("70Wh"); l5.setUkuranLayar("15.6 inci"); l5.setResolusiLayar("1920x1080");

    daftarLaptop = {l1, l2, l3, l4, l5};

    tampilkanTabel(daftarLaptop); // tampilkan tabel awal

    // Loop untuk input tambahan user
    char lanjut;
    do {
        cout << "\nApakah ingin menambah data laptop baru? (y/n): ";
        cin >> lanjut; cin.ignore();
        if (lanjut == 'y' || lanjut == 'Y') {
            Laptop baru = inputLaptop(); // input laptop baru

            // Urutan validasi: duplikat → harga/stok negatif → field kosong
            if (cekDuplikat(daftarLaptop, baru.getIdProduk(), baru.getNamaProduk())) {
                // data ditolak jika duplikat
            } else if (!validasiHargaStok(baru)) {
                // data ditolak jika harga/stok negatif
            } else if (adaFieldKosong(baru)) {
                cout << "❌ Error: Ada field yang kosong, data ditolak!\n";
            } else {
                daftarLaptop.push_back(baru); // tambahkan jika lolos semua validasi
                cout << "✅ Data berhasil ditambahkan!\n";
            }
            tampilkanTabel(daftarLaptop); // tampilkan tabel terbaru
        }
    } while (lanjut == 'y' || lanjut == 'Y');

    return 0; // program selesai
}

