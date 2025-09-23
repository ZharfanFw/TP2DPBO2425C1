<?php
// Pastikan urutan ini benar: Class dulu, baru session.
require_once 'Elektronik.php';
require_once 'Komputer.php';
require_once 'Laptop.php';
session_start();

if (isset($_GET['reset'])) {
    session_destroy();
    header('Location: main.php');
    exit();
}

if (!isset($_SESSION['daftar_laptop'])) {
    $_SESSION['daftar_laptop'] = [
        new Laptop("L001", "ASUS ROG Strix G15", 23000000, 5, "uploads/rog.jpg", "ROG B550", "AMD Ryzen 7 5800H", "NVIDIA RTX 3060", "16GB DDR4", "512GB SSD", "90Wh", "15.6 inch", "1920x1080"),
        new Laptop("L002", "Lenovo Legion 5 Pro", 25000000, 3, "uploads/legion.jpg", "Legion B560", "AMD Ryzen 7 6800H", "NVIDIA RTX 3070", "32GB DDR5", "1TB SSD", "80Wh", "16 inch", "2560x1600"),
        new Laptop("L003", "MSI GF63 Thin", 15000000, 7, "uploads/msi.jpg", "MSI B460", "Intel Core i7-10750H", "NVIDIA GTX 1650", "8GB DDR4", "512GB SSD", "51Wh", "15.6 inch", "1920x1080"),
        new Laptop(
            "L004", "HP Pavilion Aero 13", 14500000, 10, "uploads/pavilion.jpg",
            "HP B550", "AMD Ryzen 5 5600U", "AMD Radeon Graphics", "16GB DDR4", "512GB SSD",
            "43Wh", "13.3 inch", "1920x1200"
        ),
        new Laptop(
            "L005", "Dell XPS 15", 35000000, 4, "uploads/xps.jpg",
            "Dell H470", "Intel Core i7-11800H", "NVIDIA RTX 3050 Ti", "16GB DDR4", "1TB SSD",
            "86Wh", "15.6 inch", "3840x2400"
        )
    ];
}

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $foto_path = '';
    $upload_dir = 'uploads/';
    if (isset($_FILES['foto_produk']) && $_FILES['foto_produk']['error'] === UPLOAD_ERR_OK) {
        $tmp_name = $_FILES['foto_produk']['tmp_name'];
        $nama_file = uniqid() . '-' . basename($_FILES['foto_produk']['name']);
        $target_file = $upload_dir . $nama_file;
        if (move_uploaded_file($tmp_name, $target_file)) {
            $foto_path = $target_file;
        }
    }
    $laptopBaru = new Laptop( $_POST['id_produk'], $_POST['nama_produk'], (int)$_POST['harga_produk'], (int)$_POST['stok_produk'], $foto_path, $_POST['motherboard'], $_POST['cpu'], $_POST['gpu'], $_POST['ram'], $_POST['storage'], $_POST['baterai'], $_POST['ukuran_layar'], $_POST['resolusi_layar'] );
    $_SESSION['daftar_laptop'][] = $laptopBaru;
    header("Location: " . $_SERVER['PHP_SELF']);
    exit();
}
?>
<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <title>Manajemen Data Laptop</title>
    <style>
        body { font-family: sans-serif; margin: 2em; background-color: #f4f4f9; color: #333; }
        h1, h2 { color: #333; }
        table { border-collapse: collapse; width: 100%; margin-bottom: 2em; box-shadow: 0 2px 3px rgba(0,0,0,0.1); }
        th, td { border: 1px solid #ddd; padding: 12px; text-align: left; vertical-align: middle; }
        th { background-color: #007BFF; color: white; }
        tr:nth-child(even) { background-color: #f2f2f2; }
        tr:hover { background-color: #e2e2e2; }
        td img { max-width: 100px; height: auto; border-radius: 4px; }
        .reset-link { font-size: 14px; position: absolute; top: 15px; right: 15px; text-decoration: none; color: #007BFF; }
        form { border: 1px solid #ccc; padding: 1.5em; margin-bottom: 2em; background-color: #fff; border-radius: 5px; }
        .form-grid { display: grid; grid-template-columns: repeat(auto-fill, minmax(220px, 1fr)); gap: 1em; }
        .form-grid div { display: flex; flex-direction: column; }
        input { padding: 8px; border: 1px solid #ccc; border-radius: 4px; }
        button { background-color: #007BFF; color: white; padding: 10px 15px; border: none; border-radius: 4px; cursor: pointer; font-size: 16px; }
        button:hover { background-color: #0056b3; }
    </style>
</head>
<body>
    <a href="main.php?reset=true" class="reset-link">Reset Data</a>
    <h1>Manajemen Data Laptop</h1>

    <h2>Tambah Laptop Baru</h2>
    <form action="main.php" method="POST" enctype="multipart/form-data">
        <div class="form-grid">
            <div><label>ID Produk:</label><input type="text" name="id_produk" required></div>
            <div><label>Nama Produk:</label><input type="text" name="nama_produk" required></div>
            <div><label>Harga:</label><input type="number" name="harga_produk" required></div>
            <div><label>Stok:</label><input type="number" name="stok_produk" required></div>
            <div><label>Foto Produk:</label><input type="file" name="foto_produk"></div>
            <div><label>Motherboard:</label><input type="text" name="motherboard"></div>
            <div><label>CPU:</label><input type="text" name="cpu"></div>
            <div><label>GPU:</label><input type="text" name="gpu"></div>
            <div><label>RAM:</label><input type="text" name="ram"></div>
            <div><label>Storage:</label><input type="text" name="storage"></div>
            <div><label>Baterai:</label><input type="text" name="baterai"></div>
            <div><label>Ukuran Layar:</label><input type="text" name="ukuran_layar"></div>
            <div><label>Resolusi Layar:</label><input type="text" name="resolusi_layar"></div>
        </div><br><button type="submit">Tambah Data</button>
    </form>

    <h2>Daftar Laptop</h2>
    <table>
        <thead>
            <tr>
                <th>Foto</th><th>ID Produk</th><th>Nama Produk</th><th>Harga</th><th>Stok</th>
                <th>Motherboard</th><th>CPU</th><th>GPU</th><th>RAM</th><th>Storage</th>
                <th>Baterai</th><th>Ukuran Layar</th><th>Resolusi Layar</th>
            </tr>
        </thead>
        <tbody>
            <?php foreach ($_SESSION['daftar_laptop'] as $laptop): ?>
                <tr>
                    <td>
                        <?php if ($laptop->getFotoProduk() && file_exists($laptop->getFotoProduk())): ?>
                            <img src="<?= htmlspecialchars($laptop->getFotoProduk()) ?>" alt="<?= htmlspecialchars($laptop->getNamaProduk()) ?>">
                        <?php else: ?>
                            No Image
                        <?php endif; ?>
                    </td>
                    <td><?= htmlspecialchars($laptop->getIdProduk()) ?></td>
                    <td><?= htmlspecialchars($laptop->getNamaProduk()) ?></td>
                    <td><?= htmlspecialchars($laptop->getHargaProduk()) ?></td>
                    <td><?= htmlspecialchars($laptop->getStokProduk()) ?></td>
                    <td><?= htmlspecialchars($laptop->getMotherboard()) ?></td>
                    <td><?= htmlspecialchars($laptop->getCpu()) ?></td>
                    <td><?= htmlspecialchars($laptop->getGpu()) ?></td>
                    <td><?= htmlspecialchars($laptop->getRam()) ?></td>
                    <td><?= htmlspecialchars($laptop->getStorage()) ?></td>
                    <td><?= htmlspecialchars($laptop->getBaterai()) ?></td>
                    <td><?= htmlspecialchars($laptop->getUkuran_layar()) ?></td>
                    <td><?= htmlspecialchars($laptop->getResolusi_layar()) ?></td>
                </tr>
            <?php endforeach; ?>
        </tbody>
    </table>
</body>
</html>
