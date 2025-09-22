# Import class yang dibutuhkan dari file lain
from Laptop import Laptop

# =================== Fungsi Utility ===================


def hitung_lebar_kolom(data: list[Laptop]) -> list[int]:
    """Hitung lebar kolom tabel berdasarkan panjang data terpanjang tiap field."""
    # Inisialisasi lebar awal berdasarkan header
    lebar = [
        len(h)
        for h in [
            "ID Produk",
            "Nama Produk",
            "Harga",
            "Stok",
            "Motherboard",
            "CPU",
            "GPU",
            "RAM",
            "Storage",
            "Baterai",
            "Ukuran Layar",
            "Resolusi",
        ]
    ]

    # Update lebar berdasarkan data setiap laptop
    for item in data:
        lebar[0] = max(lebar[0], len(item.get_id_produk()))
        lebar[1] = max(lebar[1], len(item.get_nama_produk()))
        lebar[2] = max(lebar[2], len(str(item.get_harga_produk())))
        lebar[3] = max(lebar[3], len(str(item.get_stok_produk())))
        lebar[4] = max(lebar[4], len(item.get_motherboard()))
        lebar[5] = max(lebar[5], len(item.get_cpu()))
        lebar[6] = max(lebar[6], len(item.get_gpu()))
        lebar[7] = max(lebar[7], len(item.get_ram()))
        lebar[8] = max(lebar[8], len(item.get_storage()))
        lebar[9] = max(lebar[9], len(item.get_baterai()))
        lebar[10] = max(lebar[10], len(item.get_ukuran_layar()))
        lebar[11] = max(lebar[11], len(item.get_resolusi_layar()))
    return lebar


def cetak_garis(lebar: list[int]):
    """Cetak garis horizontal tabel."""
    print("+" + "+".join("-" * (w + 2) for w in lebar) + "+")


def tampilkan_tabel(data: list[Laptop]):
    """Tampilkan data laptop dalam bentuk tabel rapi."""
    if not data:
        print("Data kosong.")
        return

    lebar = hitung_lebar_kolom(data)
    header = [
        "ID Produk",
        "Nama Produk",
        "Harga",
        "Stok",
        "Motherboard",
        "CPU",
        "GPU",
        "RAM",
        "Storage",
        "Baterai",
        "Ukuran Layar",
        "Resolusi",
    ]

    cetak_garis(lebar)
    # Cetak header
    print("|" + "|".join(f" {h:<{lebar[i]}} " for i, h in enumerate(header)) + "|")
    cetak_garis(lebar)

    # Cetak setiap baris data
    for item in data:
        print(
            f"| {item.get_id_produk():<{lebar[0]}} "
            f"| {item.get_nama_produk():<{lebar[1]}} "
            f"| {str(item.get_harga_produk()):<{lebar[2]}} "
            f"| {str(item.get_stok_produk()):<{lebar[3]}} "
            f"| {item.get_motherboard():<{lebar[4]}} "
            f"| {item.get_cpu():<{lebar[5]}} "
            f"| {item.get_gpu():<{lebar[6]}} "
            f"| {item.get_ram():<{lebar[7]}} "
            f"| {item.get_storage():<{lebar[8]}} "
            f"| {item.get_baterai():<{lebar[9]}} "
            f"| {item.get_ukuran_layar():<{lebar[10]}} "
            f"| {item.get_resolusi_layar():<{lebar[11]}} |"
        )
    cetak_garis(lebar)


# =================== Fungsi Input & Validasi ===================


def input_laptop() -> Laptop:
    """Fungsi untuk menerima input laptop baru dari user."""
    l = Laptop()
    print("\nPilih cara input data:")
    print("1. Input satu per satu")
    print("2. Input langsung semua field (dipisah ';')")
    opsi = input("Pilihan: ")

    try:
        if opsi == "1":
            l.set_id_produk(input("Masukkan ID Produk: "))
            l.set_nama_produk(input("Masukkan Nama Produk: "))
            l.set_harga_produk(int(input("Masukkan Harga: ")))
            l.set_stok_produk(int(input("Masukkan Stok: ")))
            l.set_foto_produk(input("Masukkan Foto Produk: "))
            l.set_motherboard(input("Masukkan Motherboard: "))
            l.set_cpu(input("Masukkan CPU: "))
            l.set_gpu(input("Masukkan GPU: "))
            l.set_ram(input("Masukkan RAM: "))
            l.set_storage(input("Masukkan Storage: "))
            l.set_baterai(input("Masukkan Baterai: "))
            l.set_ukuran_layar(input("Masukkan Ukuran Layar: "))
            l.set_resolusi_layar(input("Masukkan Resolusi Layar: "))
        elif opsi == "2":
            print(
                "Masukkan data (Format: ID;Nama;Harga;Stok;Foto;MB;CPU;GPU;RAM;Storage;Baterai;Ukuran;Resolusi):"
            )
            parts = input().split(";")
            l.set_id_produk(parts[0])
            l.set_nama_produk(parts[1])
            l.set_harga_produk(int(parts[2]))
            l.set_stok_produk(int(parts[3]))
            l.set_foto_produk(parts[4])
            l.set_motherboard(parts[5])
            l.set_cpu(parts[6])
            l.set_gpu(parts[7])
            l.set_ram(parts[8])
            l.set_storage(parts[9])
            l.set_baterai(parts[10])
            l.set_ukuran_layar(parts[11])
            l.set_resolusi_layar(parts[12])
        return l
    except (ValueError, IndexError):
        print(
            "❌ Error: Terjadi kesalahan saat input data. Pastikan format benar. Data dibatalkan."
        )
        return Laptop()  # Return objek kosong jika error


def ada_field_kosong(l: Laptop) -> bool:
    """Cek jika ada field string yang kosong."""
    return not all(
        [
            l.get_id_produk(),
            l.get_nama_produk(),
            l.get_foto_produk(),
            l.get_motherboard(),
            l.get_cpu(),
            l.get_gpu(),
            l.get_ram(),
            l.get_storage(),
            l.get_baterai(),
            l.get_ukuran_layar(),
            l.get_resolusi_layar(),
        ]
    )


def validasi_harga_stok(l: Laptop) -> bool:
    """Validasi harga dan stok tidak negatif."""
    if l.get_harga_produk() < 0:
        print("❌ Error: Harga tidak boleh negatif!")
        return False
    if l.get_stok_produk() < 0:
        print("❌ Error: Stok tidak boleh negatif!")
        return False
    return True


def cek_duplikat(data: list[Laptop], id_produk: str, nama_produk: str) -> bool:
    """Cek duplikat ID atau Nama Produk."""
    for item in data:
        if item.get_id_produk() == id_produk:
            print(f'❌ Error: ID Produk "{id_produk}" sudah ada.')
            return True
        if item.get_nama_produk() == nama_produk:
            print(f'❌ Error: Nama Produk "{nama_produk}" sudah ada.')
            return True
    return False


# =================== Fungsi Main ===================


def main():
    """Fungsi utama program."""
    # ===== Data dummy awal (menggunakan constructor lengkap) =====
    daftar_laptop = [
        Laptop(
            "P001",
            "ASUS ROG",
            20000000,
            10,
            "rog.jpg",
            "ROG STRIX",
            "Intel i7",
            "RTX 3060",
            "16GB",
            "1TB SSD",
            "80Wh",
            "15.6 inci",
            "1920x1080",
        ),
        Laptop(
            "P002",
            "Acer Nitro",
            15000000,
            5,
            "nitro.jpg",
            "Nitro MB",
            "AMD Ryzen 5",
            "GTX 1650",
            "8GB",
            "512GB SSD",
            "60Wh",
            "15.6 inci",
            "1920x1080",
        ),
        Laptop(
            "P003",
            "Lenovo ThinkPad",
            12000000,
            8,
            "thinkpad.jpg",
            "Think MB",
            "Intel i5",
            "Intel UHD",
            "8GB",
            "256GB SSD",
            "50Wh",
            "14 inci",
            "1366x768",
        ),
        Laptop(
            "P004",
            "HP Pavilion",
            13000000,
            7,
            "pavilion.jpg",
            "HP MB",
            "Intel i5",
            "MX130",
            "8GB",
            "512GB SSD",
            "55Wh",
            "15.6 inci",
            "1920x1080",
        ),
        Laptop(
            "P005",
            "MSI Gaming",
            18000000,
            6,
            "msi.jpg",
            "MSI MB",
            "Intel i7",
            "RTX 3050",
            "16GB",
            "1TB HDD + 256GB SSD",
            "70Wh",
            "15.6 inci",
            "1920x1080",
        ),
    ]

    tampilkan_tabel(daftar_laptop)

    # Loop untuk input tambahan user
    while True:
        lanjut = input("\nApakah ingin menambah data laptop baru? (y/n): ").lower()
        if lanjut == "y":
            baru = input_laptop()

            # Urutan validasi
            if ada_field_kosong(baru):
                print(
                    "❌ Error: Ada field yang kosong atau input tidak valid, data ditolak!"
                )
            elif cek_duplikat(
                daftar_laptop, baru.get_id_produk(), baru.get_nama_produk()
            ):
                pass  # Pesan error sudah ditampilkan di dalam fungsi
            elif not validasi_harga_stok(baru):
                pass  # Pesan error sudah ditampilkan di dalam fungsi
            else:
                daftar_laptop.append(baru)
                print("✅ Data berhasil ditambahkan!")

            tampilkan_tabel(daftar_laptop)
        else:
            break

    print("\nProgram selesai.")


if __name__ == "__main__":
    main()
