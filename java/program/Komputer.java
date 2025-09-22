class Komputer extends Elektronik {
    private String motherboard, cpu, gpu, ram, storage;

    Komputer() {
        super();
    }

    public Komputer(String idProduk, String namaProduk, int hargaProduk, int stokProduk, String fotoProduk,
                    String motherboard, String cpu, String gpu, String ram, String storage) {
        super(idProduk, namaProduk, hargaProduk, stokProduk, fotoProduk); // Mengirim data ke Elektronik
        this.motherboard = motherboard;
        this.cpu = cpu;
        this.gpu = gpu;
        this.ram = ram;
        this.storage = storage;
    }

    // --- Getters ---
    public String getMotherboard() {
        return motherboard;
    }

    public String getCpu() {
        return cpu;
    }

    public String getGpu() {
        return gpu;
    }

    public String getRam() {
        return ram;
    }

    public String getStorage() {
        return storage;
    }

    // --- Setters ---
    public void setMotherboard(String motherboard) {
        this.motherboard = motherboard;
    }

    public void setCpu(String cpu) {
        this.cpu = cpu;
    }

    public void setGpu(String gpu) {
        this.gpu = gpu;
    }

    public void setRam(String ram) {
        this.ram = ram;
    }

    public void setStorage(String storage) {
        this.storage = storage;
    }

}
