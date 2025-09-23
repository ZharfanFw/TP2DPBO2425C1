<?php

class Elektronik {
    // Properti dideklarasikan dengan visibility (private) dan tipe data (modern PHP)
    private string $id_produk;
    private string $nama_produk;
    private int $harga_produk;
    private int $stok_produk;
    private string $foto_produk;

    // Constructor di PHP menggunakan __construct
    public function __construct(
        string $id_produk = "",
        string $nama_produk = "",
        int $harga_produk = 0,
        int $stok_produk = 0,
        string $foto_produk = ""
    ) {
        // `$this` digunakan untuk merujuk ke properti milik class ini
        $this->id_produk = $id_produk;
        $this->nama_produk = $nama_produk;
        $this->harga_produk = $harga_produk;
        $this->stok_produk = $stok_produk;
        $this->foto_produk = $foto_produk;
    }

    // --- Getters ---
    public function getIdProduk(): string {
        return $this->id_produk;
    }

    public function getNamaProduk(): string {
        return $this->nama_produk;
    }

    public function getHargaProduk(): int {
        return $this->harga_produk;
    }

    public function getStokProduk(): int {
        return $this->stok_produk;
    }

    public function getFotoProduk(): string {
        return $this->foto_produk;
    }

    // --- Setters ---
    public function setIdProduk(string $id_produk): void {
        $this->id_produk = $id_produk;
    }

    public function setNamaProduk(string $nama_produk): void {
        $this->nama_produk = $nama_produk;
    }

    public function setHargaProduk(int $harga_produk): void {
        $this->harga_produk = $harga_produk;
    }

    public function setStokProduk(int $stok_produk): void {
        $this->stok_produk = $stok_produk;
    }

    public function setFotoProduk(string $foto_produk): void {
        $this->foto_produk = $foto_produk;
    }
}
