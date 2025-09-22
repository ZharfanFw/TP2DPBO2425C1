class Elektronik:
    """
    Sebuah class untuk merepresentasikan produk elektronik
    menggunakan metode getter dan setter konvensional.
    """

    def __init__(
        self,
        id_produk: str = "",
        nama_produk: str = "",
        harga_produk: int = 0,
        stok_produk: int = 0,
        foto_produk: str = "",
    ):
        """Constructor untuk class Elektronik."""
        self.id_produk = id_produk
        self.nama_produk = nama_produk
        self.harga_produk = harga_produk
        self.stok_produk = stok_produk
        self.foto_produk = foto_produk

    # --- Getters ---
    def get_id_produk(self) -> str:
        return self.id_produk

    def get_nama_produk(self) -> str:
        return self.nama_produk

    def get_harga_produk(self) -> int:
        return self.harga_produk

    def get_stok_produk(self) -> int:
        return self.stok_produk

    def get_foto_produk(self) -> str:
        return self.foto_produk

    # --- Setters ---
    def set_id_produk(self, value: str):
        self.id_produk = value

    def set_nama_produk(self, value: str):
        self.nama_produk = value

    def set_harga_produk(self, value: int):
        if value < 0:
            print("Warning: Harga produk tidak boleh negatif.")
        self.harga_produk = value

    def set_stok_produk(self, value: int):
        if value < 0:
            print("Warning: Stok produk tidak boleh negatif.")
        self.stok_produk = value

    def set_foto_produk(self, value: str):
        self.foto_produk = value
