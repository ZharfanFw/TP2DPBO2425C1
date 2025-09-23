<?php

require_once 'Komputer.php';

class Laptop extends Komputer {
    private string $baterai;
    private string $ukuran_layar;
    private string $resolusi_layar;

    public function __construct(
        string $id_produk = "", string $nama_produk = "", int $harga_produk = 0, int $stok_produk = 0, string $foto_produk = "",
        string $motherboard = "", string $cpu = "", string $gpu = "", string $ram = "", string $storage = "",
        string $baterai = "", string $ukuran_layar = "", string $resolusi_layar = ""
    ) {
        parent::__construct(
            $id_produk, $nama_produk, $harga_produk, $stok_produk, $foto_produk,
            $motherboard, $cpu, $gpu, $ram, $storage
        );
        $this->baterai = $baterai;
        $this->ukuran_layar = $ukuran_layar;
        $this->resolusi_layar = $resolusi_layar;
    }

    // --- Getters (Pastikan namanya seperti ini) ---
    public function getBaterai(): string {
        return $this->baterai;
    }

    public function getUkuran_layar(): string { // diganti menjadi snake_case
        return $this->ukuran_layar;
    }

    public function getResolusi_layar(): string { // diganti menjadi snake_case
        return $this->resolusi_layar;
    }

    // --- Setters ---
    public function setBaterai(string $baterai): void {
        $this->baterai = $baterai;
    }

    public function setUkuran_layar(string $ukuran_layar): void { // diganti menjadi snake_case
        $this->ukuran_layar = $ukuran_layar;
    }

    public function setResolusi_layar(string $resolusi_layar): void { // diganti menjadi snake_case
        $this->resolusi_layar = $resolusi_layar;
    }
}
