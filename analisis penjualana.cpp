#include<iostream>
#include<iomanip>
#include<conio.h>
#include<fstream>
using namespace std;

const int max_transaksi = 1000;

struct dataTransaksi {
	int kode;
	string nama;
	int jumlah;
	double harga;
};

dataTransaksi listTransaksi[max_transaksi] = {
	{1, "Fresh Milk", 1, 45000},
	{2, "Chococrunch", 3, 215000},
	{3, "Nescafe", 1, 12000},
	{4, "Sari Roti", 1, 8000},
	{5, "Kopi Kenangan", 1, 11000}
	};
	
int jumlahTransaksi = 5;

void simpanDataTransaksi() {
	dataTransaksi data;
	ofstream file("dataTransaksi.txt");
	for (int i=0; i<=jumlahTransaksi; i++) {
		file << setw(10) << data.kode << " |"
			<< setw(10) << data.nama << " |"
			<< setw(10) << data.jumlah << " |"
			<< setw(10) << " Rp. " << data.harga << endl; 
	}
	file.close(); 
}

void tambahTransaksi() {
	dataTransaksi listTransaksi[jumlahTransaksi];
	int kode;
	string nama;
	int jumlah;
	double harga;
	
	cout << "=== TAMBAH TRANSAKSI ===\n";
	cout << "Kode Produk\t: ";
	cin >> kode;
	cout << "Nama Produk\t: ";
	getline(cin, nama);
	cin.ignore();
	cout << "Jumlah Produk\t: ";
	cin >> jumlah;
	cin.ignore();
	cout << "Harga Produk\t: ";
	cin >> harga;
	
	listTransaksi[jumlahTransaksi].kode = kode;
	listTransaksi[jumlahTransaksi].nama = nama;
	listTransaksi[jumlahTransaksi].jumlah = jumlah;
	listTransaksi[jumlahTransaksi].harga = harga;
	jumlahTransaksi++;
	
	cout << "Data Berhasil Ditambahkan.\n";
	simpanDataTransaksi();
}

void tampilkanDataTransaksi() {
	cout << "=== DATA TRANSAKSI ===\n";
	simpanDataTransaksi();
}

void searchByCode() {
	dataTransaksi s;
	cout << "=== CARI BARANG ===\n";
	cout << "Masukkan Kode: ";
	cin >> s.kode;
	
	if (s.kode) {
		cout << setw(10) << listTransaksi[max_transaksi].kode << " |"
			<< setw(10) << listTransaksi[max_transaksi].nama << " |"
			<< setw(10) << listTransaksi[max_transaksi].jumlah << " |"
			<< setw(10) << " Rp. " << listTransaksi[max_transaksi].harga << endl;
	}
	cout << endl;
}

void searchByPrice() {
	dataTransaksi s;
	cout << "=== CARI BARANG ===\n";
	cout << "Masukkan harga: ";
	cin >> s.harga;
	
	for (int i=0; i<=s.harga; i++) {
		dataTransaksi key = listTransaksi[i];
		int j = i + 1;
		
		while (j >= 0) {
			listTransaksi[j] = listTransaksi[j+1];
			key = listTransaksi[j+1];
		}
		listTransaksi[j+1] = key;
	}
}

void sortingDown() {
	ofstream file("hasil_sort_penjualan.txt");
	dataTransaksi s;
	listTransaksi[max_transaksi];
	file << "=== URUTAN BARANG TERMAHAL ===\n";
	for (int i=0; i<s.harga; i++) {
		cout << file << listTransaksi[i].kode << " |" 
			 << listTransaksi[i].nama << " |"
			 << listTransaksi[i].jumlah << " |"
			 << "Rp. " << listTransaksi[i].harga << endl;
	}
	cout << endl;
	file.close();
}

void sortingUp() {
	ofstream file("hasil_sort.txt");
	dataTransaksi s;
	listTransaksi[max_transaksi];
	cout << "=== URUTAN BARANG TERMURAH ===\n";
	for (int i=0; i>s.harga; i--) {
		cout << file << listTransaksi[i].kode << " |" 
			 << listTransaksi[i].nama << " |"
			 << listTransaksi[i].jumlah << " |"
			 << "Rp. " << listTransaksi[i].harga << endl;
	}
	cout << endl;
	file.close();
}

double hitungTotalPerProduk(dataTransaksi listTransaksi[max_transaksi]) {
	cout << "=== TOTAL PENDAPATAN PRODUK ===\n";
	cout << "Total Pendapatan\t: ";
	dataTransaksi key = listTransaksi[max_transaksi];
	cout << key.kode;
	cout << key.nama;
	cout << key.jumlah;
	cout << key.harga;
	
	double harga = key.harga;
	int jumlah = key.jumlah;
	double hasil = harga * jumlah;

	
	cout << endl;
	getch();
}

void hitungTotalPendapatan() {
	cout << "=== HITUNG TOTAL ===\n";
}

int main() {
	int pil;
	
	cout << "=== ANALISIS PENJUALAN ===\n";
	cout << "1. Tambah Transaksi\n";
	cout << "2. Cari Barang Berdasarkan Kode\n";
	cout << "3. Cari Barang Termurah Berdasarkan Harga\n";
	cout << "4. Urutkan Produk Termahal ke Termurah\n";
	cout << "5. Urutkan produk Termurah ke Termahal\n";
	cout << "6. Hitung Total Pendapatan per Produk\n";
	cout << "7. Hitung Total Seluruh Pendapatan\n";
	cout << "8. Keluar Dari Program\n";
	cout << "Masukkan Pilihan: ";
	cin >> pil;
	system("cls");
	
	switch (pil) {
		case 1:
			tambahTransaksi();
			getch();
			system("cls");
			break;
		case 2:
			searchByCode();
			getch();
			system("cls");
			break;
		case 3: 
			searchByPrice();
			getch();
			system("clr");
			break;
		case 4:
			sortingDown();
			getch();
			system("cls");
			break;
		case 5:
			sortingUp();
			getch();
			system("cls");
			break;
		case 6:
			getch();
			system("cls");
			break;
		case 7:
			hitungTotalPendapatan();
			getch();
			system("cls");
			break;
		case 8:
			cout << "Terimakasih Telah Menggunakan Program Ini.\n";
			break;
		default: 
		cout << "Pilihan Tidak Valid.\n";
		break;
	} while (pil != 8);
	
	return 0;
}
