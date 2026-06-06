import java.util.Scanner;

// Representasi dari 'Record' untuk Data Barang (Soal 1)
class Barang {
    String kodeBarang;a
    String namaBarang;
    int stok;

    // Constructor untuk membuat objek Barang
    public Barang(String kodeBarang, String namaBarang, int stok) {
        this.kodeBarang = kodeBarang;
        this.namaBarang = namaBarang;
        this.stok = stok;
    }

    // Fungsi untuk menampilkan data barang
    public void tampilkan() {
        System.out.printf("| %-12s | %-15s | %-6d |\n", kodeBarang, namaBarang, stok);
    }
}

// Node untuk implementasi Linked List (Soal 2)
class Node {
    Barang data;
    Node next;
    Node prev;

    public Node(Barang data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

// Class Utama Manajemen Data Barang
public class PraktikumStrukturData {
    private Node head = null;
    private Node tail = null;
    private int size = 0;

    // --- SOAL 2: FUNGSI PENAMBAHAN DATA ---
    
    // Tambah data di depan (prepend)
    public void tambahDepan(Barang barang) {
        Node newNode = new Node(barang);
        if (head == null) {
            head = tail = newNode;
        } else {
            newNode.next = head;
            head.prev = newNode;
            head = newNode;
        }
        size++;
    }

    // Tambah data di belakang (append)
    public void tambahBelakang(Barang barang) {
        Node newNode = new Node(barang);
        if (tail == null) {
            head = tail = newNode;
        } else {
            tail.next = newNode;
            newNode.prev = tail;
            tail = newNode;
        }
        size++;
    }

    // --- SOAL 1: FUNGSI PENGURUTAN (SORTING) ---
    // Mengonversi Linked List ke Array agar mudah diurutkan sesuai permintaan Soal 1
    private Barang[] toArray() {
        Barang[] arr = new Barang[size];
        Node current = head;
        int i = 0;
        while (current != null) {
            arr[i++] = current.data;
            current = current.next;
        }
        return arr;
    }

    // Insertion Sort berdasarkan STOK (Ascending)
    public void insertionSort() {
        Barang[] arr = toArray();
        int n = arr.length;
        
        for (int i = 1; i < n; ++i) {
            Barang key = arr[i];
            int j = i - 1;

            // Mengurutkan berdasarkan stok barang
            while (j >= 0 && arr[j].stok > key.stok) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
        
        System.out.println("\n=== HASIL INSERTION SORT (Berdasarkan Stok) ===");
        cetakArray(arr);
    }

    // Selection Sort berdasarkan KODE BARANG (Ascending)
    public void selectionSort() {
        Barang[] arr = toArray();
        int n = arr.length;

        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                // Membandingkan string Kode Barang secara alfabetis
                if (arr[j].kodeBarang.compareTo(arr[minIdx].kodeBarang) < 0) {
                    minIdx = j;
                }
            }
            // Swap
            Barang temp = arr[minIdx];
            arr[minIdx] = arr[i];
            arr[i] = temp;
        }

        System.out.println("\n=== HASIL SELECTION SORT (Berdasarkan Kode Barang) ===");
        cetakArray(arr);
    }

    // --- FUNGSI UTILITAS ---
    
    // Mencetak isi list saat ini
    public void tampilkanSemua() {
        if (head == null) {
            System.out.println("Data kosong!");
            return;
        }
        Node current = head;
        System.out.println("---------------------------------------------");
        System.out.printf("| %-12s | %-15s | %-6s |\n", "Kode Barang", "Nama Barang", "Stok");
        System.out.println("---------------------------------------------");
        while (current != null) {
            current.data.tampilkan();
            current = current.next;
        }
        System.out.println("---------------------------------------------");
    }

    // Mencetak array hasil sorting
    private void cetakArray(Barang[] arr) {
        System.out.println("---------------------------------------------");
        System.out.printf("| %-12s | %-15s | %-6s |\n", "Kode Barang", "Nama Barang", "Stok");
        System.out.println("---------------------------------------------");
        for (Barang b : arr) {
            b.tampilkan();
        }
        System.out.println("---------------------------------------------");
    }

    // --- MAIN METHOD ---
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        PraktikumStrukturData app = new PraktikumStrukturData();

        // 1. INPUT SOAL 1: Menginputkan 3 data awal barang (dimasukkan via tambahBelakang)
        System.out.println("=== INPUT 3 DATA BARANG AWAL (Soal 1) ===");
        for (int i = 1; i <= 3; i++) {
            System.out.println("Data ke-" + i);
            System.out.print("Kode Barang : "); String kode = input.nextLine();
            System.out.print("Nama Barang : "); String nama = input.nextLine();
            System.out.print("Stok Barang : "); int stok = input.nextInt();
            input.nextLine(); // membersihkan buffer
            app.tambahBelakang(new Barang(kode, nama, stok));
        }

        System.out.println("\n> Data Awal (3 Barang):");
        app.tampilkanSemua();

        // 2. MODIFIKASI SOAL 2: Tambah 2 data di depan
        System.out.println("\n=== TAMBAH 2 DATA DI DEPAN (Soal 2) ===");
        for (int i = 1; i <= 2; i++) {
            System.out.println("Data Depan ke-" + i);
            System.out.print("Kode Barang : "); String kode = input.nextLine();
            System.out.print("Nama Barang : "); String nama = input.nextLine();
            System.out.print("Stok Barang : "); int stok = input.nextInt();
            input.nextLine(); 
            app.tambahDepan(new Barang(kode, nama, stok));
        }

        // 3. MODIFIKASI SOAL 2: Tambah 2 data di belakang
        System.out.println("\n=== TAMBAH 2 DATA DI BELAKANG (Soal 2) ===");
        for (int i = 1; i <= 2; i++) {
            System.out.println("Data Belakang ke-" + i);
            System.out.print("Kode Barang : "); String kode = input.nextLine();
            System.out.print("Nama Barang : "); String nama = input.nextLine();
            System.out.print("Stok Barang : "); int stok = input.nextInt();
            input.nextLine(); 
            app.tambahBelakang(new Barang(kode, nama, stok));
        }

        // Menampilkan total seluruh data (3 data awal + 2 depan + 2 belakang = 7 data)
        System.out.println("\n> Data Gabungan Terkini (7 Barang):");
        app.tampilkanSemua();

        // 4. JALANKAN FUNGSI SORTING
        // Mengurutkan dengan Insertion Sort (berdasarkan jumlah Stok)
        app.insertionSort();

        // Mengurutkan dengan Selection Sort (berdasarkan Kode Barang)
        app.selectionSort();
        
        input.close();
    }
}
