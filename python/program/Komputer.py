# Import class Elektronik dari file Elektronik.py
from Elektronik import Elektronik


class Komputer(Elektronik):
    """
    Class untuk merepresentasikan Komputer, merupakan turunan dari Elektronik.
    """

    def __init__(
        self,
        # Atribut dari parent (Elektronik)
        id_produk: str = "",
        nama_produk: str = "",
        harga_produk: int = 0,
        stok_produk: int = 0,
        foto_produk: str = "",
        # Atribut milik Komputer sendiri
        motherboard: str = "",
        cpu: str = "",
        gpu: str = "",
        ram: str = "",
        storage: str = "",
    ):
        # Panggil constructor dari parent class (Elektronik) untuk inisialisasi atributnya
        super().__init__(id_produk, nama_produk, harga_produk, stok_produk, foto_produk)

        # Inisialisasi atribut milik Komputer
        self.motherboard = motherboard
        self.cpu = cpu
        self.gpu = gpu
        self.ram = ram
        self.storage = storage

    # --- Getters ---
    def get_motherboard(self) -> str:
        return self.motherboard

    def get_cpu(self) -> str:
        return self.cpu

    def get_gpu(self) -> str:
        return self.gpu

    def get_ram(self) -> str:
        return self.ram

    def get_storage(self) -> str:
        return self.storage

    # --- Setters ---
    def set_motherboard(self, value: str):
        self.motherboard = value

    def set_cpu(self, value: str):
        self.cpu = value

    def set_gpu(self, value: str):
        self.gpu = value

    def set_ram(self, value: str):
        self.ram = value

    def set_storage(self, value: str):
        self.storage = value
