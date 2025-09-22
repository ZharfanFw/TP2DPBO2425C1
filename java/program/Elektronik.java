class Elektronik {
    private String idProduk, namaProduk, fotoProduk;
    private int hargaProduk, stokProduk;

    Elektronik(){}

    public Elektronik(String idProduk, String namaProduk, int hargaProduk, int stokProduk, String fotoProduk) {
        this.idProduk = idProduk;
        this.namaProduk = namaProduk;
        this.hargaProduk = hargaProduk;
        this.stokProduk = stokProduk;
        this.fotoProduk = fotoProduk;
    }

    // Getters
    public String getIdProduk() {
        return idProduk;
    }

    public String getNamaProduk() {
        return namaProduk;
    }

    public int getHargaProduk() {
        return hargaProduk;
    }

    public int getStokProduk() {
        return stokProduk;
    }

    public String getFotoProduk() {
        return fotoProduk;
    }

    // Setters

    public void setIdProduk(String idProduk) {
        this.idProduk = idProduk;
    }

    public void setNamaProduk(String namaProduk) {
        this.namaProduk = namaProduk;
    }

    public void setHargaProduk(int hargaProduk) {
        this.hargaProduk = hargaProduk;
    }

    public void setStokProduk(int stokProduk) {
        this.stokProduk = stokProduk;
    }
    
    public void setFotoProduk(String fotoProduk) {
        this.fotoProduk = fotoProduk;
    }
}
