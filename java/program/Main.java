import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    // =================== Fungsi Utility ===================

    // Hitung lebar kolom tabel berdasarkan panjang data terpanjang tiap field
    private static int[] hitungLebarKolom(List<Laptop> data) {
        int[] lebar = {
            "ID Produk".length(), "Nama Produk".length(), "Harga".length(), "Stok".length(),
            "Motherboard".length(), "CPU".length(), "GPU".length(), "RAM".length(),
            "Storage".length(), "Baterai".length(), "Ukuran Layar".length(), "Resolusi".length()
        };

        for (Laptop item : data) {
            lebar[0] = Math.max(lebar[0], item.getIdProduk().length());
            lebar[1] = Math.max(lebar[1], item.getNamaProduk().length());
            lebar[2] = Math.max(lebar[2], String.valueOf(item.getHargaProduk()).length());
            lebar[3] = Math.max(lebar[3], String.valueOf(item.getStokProduk()).length());
            lebar[4] = Math.max(lebar[4], item.getMotherboard().length());
            lebar[5] = Math.max(lebar[5], item.getCpu().length());
            lebar[6] = Math.max(lebar[6], item.getGpu().length());
            lebar[7] = Math.max(lebar[7], item.getRam().length());
            lebar[8] = Math.max(lebar[8], item.getStorage().length());
            lebar[9] = Math.max(lebar[9], item.getBaterai().length());
            lebar[10] = Math.max(lebar[10], item.getUkuran_layar().length());
            lebar[11] = Math.max(lebar[11], item.getResolusi_layar().length());
        }
        return lebar;
    }

    // Cetak garis horizontal tabel
    private static void cetakGaris(int[] lebar) {
        System.out.print("+");
        for (int w : lebar) {
            for (int i = 0; i < w + 2; i++) {
                System.out.print("-");
            }
            System.out.print("+");
        }
        System.out.println();
    }

    // Tampilkan data laptop dalam bentuk tabel rapi
    public static void tampilkanTabel(List<Laptop> data) {
        if (data.isEmpty()) {
            System.out.println("Data kosong.");
            return;
        }

        int[] lebar = hitungLebarKolom(data);
        String[] header = {"ID Produk", "Nama Produk", "Harga", "Stok", "Motherboard",
                           "CPU", "GPU", "RAM", "Storage", "Baterai", "Ukuran Layar", "Resolusi"};

        cetakGaris(lebar);
        System.out.print("|");
        for (int i = 0; i < header.length; i++) {
            System.out.printf(" %-" + lebar[i] + "s |", header[i]);
        }
        System.out.println();
        cetakGaris(lebar);

        for (Laptop item : data) {
            System.out.printf("| %-" + lebar[0] + "s |", item.getIdProduk());
            System.out.printf(" %-" + lebar[1] + "s |", item.getNamaProduk());
            System.out.printf(" %-" + lebar[2] + "d |", item.getHargaProduk());
            System.out.printf(" %-" + lebar[3] + "d |", item.getStokProduk());
            System.out.printf(" %-" + lebar[4] + "s |", item.getMotherboard());
            System.out.printf(" %-" + lebar[5] + "s |", item.getCpu());
            System.out.printf(" %-" + lebar[6] + "s |", item.getGpu());
            System.out.printf(" %-" + lebar[7] + "s |", item.getRam());
            System.out.printf(" %-" + lebar[8] + "s |", item.getStorage());
            System.out.printf(" %-" + lebar[9] + "s |", item.getBaterai());
            System.out.printf(" %-" + lebar[10] + "s |", item.getUkuran_layar());
            System.out.printf(" %-" + lebar[11] + "s |", item.getResolusi_layar());
            System.out.println();
        }
        cetakGaris(lebar);
    }

    // =================== Fungsi Input & Validasi ===================

    public static Laptop inputLaptop(Scanner scanner) {
        Laptop l = new Laptop();
        
        System.out.println("\nPilih cara input data:");
        System.out.println("1. Input satu per satu");
        System.out.println("2. Input langsung semua field (dipisah ';')");
        System.out.print("Pilihan: ");
        int opsi = scanner.nextInt(); scanner.nextLine(); // consume newline

        try {
            if (opsi == 1) {
                System.out.print("Masukkan ID Produk: "); l.setIdProduk(scanner.nextLine());
                System.out.print("Masukkan Nama Produk: "); l.setNamaProduk(scanner.nextLine());
                System.out.print("Masukkan Harga: "); l.setHargaProduk(Integer.parseInt(scanner.nextLine()));
                System.out.print("Masukkan Stok: "); l.setStokProduk(Integer.parseInt(scanner.nextLine()));
                System.out.print("Masukkan Foto Produk: "); l.setFotoProduk(scanner.nextLine());
                System.out.print("Masukkan Motherboard: "); l.setMotherboard(scanner.nextLine());
                System.out.print("Masukkan CPU: "); l.setCpu(scanner.nextLine());
                System.out.print("Masukkan GPU: "); l.setGpu(scanner.nextLine());
                System.out.print("Masukkan RAM: "); l.setRam(scanner.nextLine());
                System.out.print("Masukkan Storage: "); l.setStorage(scanner.nextLine());
                System.out.print("Masukkan Baterai: "); l.setBaterai(scanner.nextLine());
                System.out.print("Masukkan Ukuran Layar: "); l.setUkuran_layar(scanner.nextLine());
                System.out.print("Masukkan Resolusi Layar: "); l.setResolusi_layar(scanner.nextLine());
            } else if (opsi == 2) {
                System.out.println("Masukkan data (Format: ID;Nama;Harga;Stok;Foto;MB;CPU;GPU;RAM;Storage;Baterai;Ukuran;Resolusi):");
                String line = scanner.nextLine();
                String[] parts = line.split(";");

                l.setIdProduk(parts[0]); l.setNamaProduk(parts[1]);
                l.setHargaProduk(Integer.parseInt(parts[2])); l.setStokProduk(Integer.parseInt(parts[3]));
                l.setFotoProduk(parts[4]); l.setMotherboard(parts[5]); l.setCpu(parts[6]); l.setGpu(parts[7]);
                l.setRam(parts[8]); l.setStorage(parts[9]); l.setBaterai(parts[10]); l.setUkuran_layar(parts[11]);
                l.setResolusi_layar(parts[12]);
            }
        } catch (Exception e) {
            System.out.println("❌ Error: Terjadi kesalahan saat input data. Pastikan format benar. Data dibatalkan.");
            return new Laptop(); // Mengembalikan objek kosong jika ada error
        }
        return l;
    }

    public static boolean adaFieldKosong(Laptop l) {
        return l.getIdProduk() == null || l.getIdProduk().isEmpty() ||
               l.getNamaProduk() == null || l.getNamaProduk().isEmpty() ||
               l.getFotoProduk() == null || l.getFotoProduk().isEmpty() ||
               l.getMotherboard() == null || l.getMotherboard().isEmpty() ||
               l.getCpu() == null || l.getCpu().isEmpty() ||
               l.getGpu() == null || l.getGpu().isEmpty() ||
               l.getRam() == null || l.getRam().isEmpty() ||
               l.getStorage() == null || l.getStorage().isEmpty() ||
               l.getBaterai() == null || l.getBaterai().isEmpty() ||
               l.getUkuran_layar() == null || l.getUkuran_layar().isEmpty() ||
               l.getResolusi_layar() == null || l.getResolusi_layar().isEmpty();
    }

    public static boolean validasiHargaStok(Laptop l) {
        if (l.getHargaProduk() < 0) {
            System.out.println("❌ Error: Harga tidak boleh negatif!");
            return false;
        }
        if (l.getStokProduk() < 0) {
            System.out.println("❌ Error: Stok tidak boleh negatif!");
            return false;
        }
        return true;
    }

    public static boolean cekDuplikat(List<Laptop> data, String id, String nama) {
        for (Laptop item : data) {
            if (item.getIdProduk().equals(id)) {
                System.out.println("❌ Error: ID Produk \"" + id + "\" sudah ada.");
                return true;
            }
            if (item.getNamaProduk().equals(nama)) {
                System.out.println("❌ Error: Nama Produk \"" + nama + "\" sudah ada.");
                return true;
            }
        }
        return false;
    }

    // =================== Fungsi Main ===================

    public static void main(String[] args) {
        List<Laptop> daftarLaptop = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);

        // ===== Data dummy awal (menggunakan constructor lengkap) =====
        daftarLaptop.add(new Laptop("P001", "ASUS ROG", 20000000, 10, "rog.jpg", "ROG STRIX", "Intel i7", "RTX 3060", "16GB", "1TB SSD", "80Wh", "15.6 inci", "1920x1080"));
        daftarLaptop.add(new Laptop("P002", "Acer Nitro", 15000000, 5, "nitro.jpg", "Nitro MB", "AMD Ryzen 5", "GTX 1650", "8GB", "512GB SSD", "60Wh", "15.6 inci", "1920x1080"));
        daftarLaptop.add(new Laptop("P003", "Lenovo ThinkPad", 12000000, 8, "thinkpad.jpg", "Think MB", "Intel i5", "Intel UHD", "8GB", "256GB SSD", "50Wh", "14 inci", "1366x768"));
        daftarLaptop.add(new Laptop("P004", "HP Pavilion", 13000000, 7, "pavilion.jpg", "HP MB", "Intel i5", "MX130", "8GB", "512GB SSD", "55Wh", "15.6 inci", "1920x1080"));
        daftarLaptop.add(new Laptop("P005", "MSI Gaming", 18000000, 6, "msi.jpg", "MSI MB", "Intel i7", "RTX 3050", "16GB", "1TB HDD + 256GB SSD", "70Wh", "15.6 inci", "1920x1080"));

        tampilkanTabel(daftarLaptop);

        char lanjut;
        do {
            System.out.print("\nApakah ingin menambah data laptop baru? (y/n): ");
            lanjut = scanner.next().charAt(0);
            scanner.nextLine(); // consume newline

            if (lanjut == 'y' || lanjut == 'Y') {
                Laptop baru = inputLaptop(scanner);

                if (adaFieldKosong(baru)) {
                     System.out.println("❌ Error: Ada field yang kosong atau input tidak valid, data ditolak!");
                } else if (cekDuplikat(daftarLaptop, baru.getIdProduk(), baru.getNamaProduk())) {
                    // Pesan error sudah ditampilkan di dalam fungsi
                } else if (!validasiHargaStok(baru)) {
                    // Pesan error sudah ditampilkan di dalam fungsi
                } else {
                    daftarLaptop.add(baru);
                    System.out.println("✅ Data berhasil ditambahkan!");
                }
                tampilkanTabel(daftarLaptop);
            }
        } while (lanjut == 'y' || lanjut == 'Y');

        scanner.close();
        System.out.println("\nProgram selesai.");
    }
}
