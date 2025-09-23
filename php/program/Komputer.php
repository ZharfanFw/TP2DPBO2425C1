<?php

// Sertakan file class parent agar bisa di-extend
require_once 'Elektronik.php';

class Komputer extends Elektronik {
    private string $motherboard;
    private string $cpu;
    private string $gpu;
    private string $ram;
    private string $storage;

    public function __construct(
        // Parameter untuk parent (Elektronik)
        string $id_produk = "",
        string $nama_produk = "",
        int $harga_produk = 0,
        int $stok_produk = 0,
        string $foto_produk = "",
        // Parameter untuk Komputer sendiri
        string $motherboard = "",
        string $cpu = "",
        string $gpu = "",
        string $ram = "",
        string $storage = ""
    ) {
        // Panggil constructor parent untuk inisialisasi properti Elektronik
        parent::__construct($id_produk, $nama_produk, $harga_produk, $stok_produk, $foto_produk);

        // Inisialisasi properti milik Komputer
        $this->motherboard = $motherboard;
        $this->cpu = $cpu;
        $this->gpu = $gpu;
        $this->ram = $ram;
        $this->storage = $storage;
    }

    // --- Getters ---
    public function getMotherboard(): string {
        return $this->motherboard;
    }

    public function getCpu(): string {
        return $this->cpu;
    }

    public function getGpu(): string {
        return $this->gpu;
    }

    public function getRam(): string {
        return $this->ram;
    }

    public function getStorage(): string {
        return $this->storage;
    }

    // --- Setters ---
    public function setMotherboard(string $motherboard): void {
        $this->motherboard = $motherboard;
    }

    public function setCpu(string $cpu): void {
        $this->cpu = $cpu;
    }

    public function setGpu(string $gpu): void {
        $this->gpu = $gpu;
    }

    public function setRam(string $ram): void {
        $this->ram = $ram;
    }

    public function setStorage(string $storage): void {
        $this->storage = $storage;
    }
}
