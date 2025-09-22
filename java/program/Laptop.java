class Laptop extends Komputer {
    private String baterai, ukuran_layar, resolusi_layar;

    public Laptop() {
        super();
    }

    public Laptop(String idProduk, String namaProduk, int hargaProduk, int stokProduk, String fotoProduk,
                  String motherboard, String cpu, String gpu, String ram, String storage,
                  String baterai, String ukuran_layar, String resolusi_layar) {
        // Mengirim semua data ke constructor Komputer (yang kemudian akan mengirim sebagian ke Elektronik)
        super(idProduk, namaProduk, hargaProduk, stokProduk, fotoProduk, motherboard, cpu, gpu, ram, storage);
        this.baterai = baterai;
        this.ukuran_layar = ukuran_layar;
        this.resolusi_layar = resolusi_layar;
    }
    // --- Getters ---
    public String getBaterai() {
        return baterai;
    }

    public String getUkuran_layar() {
        return ukuran_layar;
    }

    public String getResolusi_layar() {
        return resolusi_layar;
    }

    // --- Setters ---
    public void setBaterai(String baterai) {
        this.baterai = baterai;
    }

    public void setUkuran_layar(String ukuran_layar) {
        this.ukuran_layar = ukuran_layar;
    }

    public void setResolusi_layar(String resolusi_layar) {
        this.resolusi_layar = resolusi_layar;
    }
}
