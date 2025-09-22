# Import class Komputer dari file Komputer.py
from Komputer import Komputer


class Laptop(Komputer):
    """
    Class untuk merepresentasikan Laptop, merupakan turunan dari Komputer.
    """

    def __init__(
        self,
        # Atribut dari Elektronik
        id_produk: str = "",
        nama_produk: str = "",
        harga_produk: int = 0,
        stok_produk: int = 0,
        foto_produk: str = "",
        # Atribut dari Komputer
        motherboard: str = "",
        cpu: str = "",
        gpu: str = "",
        ram: str = "",
        storage: str = "",
        # Atribut milik Laptop sendiri
        baterai: str = "",
        ukuran_layar: str = "",
        resolusi_layar: str = "",
    ):
        # Panggil constructor dari parent class (Komputer) untuk inisialisasi semua atribut di atasnya
        super().__init__(
            id_produk,
            nama_produk,
            harga_produk,
            stok_produk,
            foto_produk,
            motherboard,
            cpu,
            gpu,
            ram,
            storage,
        )

        # Inisialisasi atribut milik Laptop
        self.baterai = baterai
        self.ukuran_layar = ukuran_layar
        self.resolusi_layar = resolusi_layar

    # --- Getters ---
    def get_baterai(self) -> str:
        return self.baterai

    def get_ukuran_layar(self) -> str:
        return self.ukuran_layar

    def get_resolusi_layar(self) -> str:
        return self.resolusi_layar

    # --- Setters ---
    def set_baterai(self, value: str):
        self.baterai = value

    def set_ukuran_layar(self, value: str):
        self.ukuran_layar = value

    def set_resolusi_layar(self, value: str):
        self.resolusi_layar = value
