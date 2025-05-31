// Kode Soal : B

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class portal{
	public:
		void login();
		void info_mhs();
		void inputKRS();
		void outputKRS();
		void beasiswa();
		void spp();
};

void portal::login(){
	
	string username = "Alfaridzi",password = "162";
	string inputUSN, inputPW;
	bool ulang = true;
	do{
		if(!ulang){
			cout << "Nama atau password salah!" << endl;
		}
	cout << "--- Login ---" << endl;
	cout << "Masukkan nama: ";
	cin >> inputUSN;
	cout << "Masukkan password: ";
	cin >> inputPW;
	ulang = false;
	}
	while(inputUSN != username || inputPW != password);
	system("cls");
	cout << "Halo, " << username << endl;
}

void portal::info_mhs(){
	ifstream info("info.txt");
	
	string baris;
	if(info.is_open()){
	
		while(getline(info, baris)){
		cout << baris << endl;
	
		}
	info.close();
	} else{
		cout << "File tidak ditemukan!" << endl;
	}
	system("pause");
	system("cls");
}

void portal::inputKRS(){
	int jumlah;
	string matkul;
	cout << "Masukkan jumlah mata kuliah yang ingin ditambahkan: "; 
	cin >> jumlah;
	cin.ignore();
	
	ofstream data("krs.txt", ios::app);
	
	if(data.is_open()){
		for(int i=1; i<=jumlah; i++){
		cout << "Masukkan mata kuliah ke-" << i << ": ";
		getline(cin, matkul);
		data << matkul << endl;
		}
		cout << "Mata kuliah berhasil ditambahkan!" << endl;
	}
	else{
		cout << "File tidak ditemukan" << endl;
	}
	data.close();
	system("pause");
	system("cls");
}

void portal::outputKRS(){
	
	cout << "-- MATA KULIAH YANG DIAMBIL --" << endl;
	ifstream data("krs.txt");
	string baris;
	if(data.is_open()){
		cout << "MATA KULIAH \t | \t NILAI " << endl;
		while(getline(data,baris)){
			cout << baris << " : 90"<< endl;
		}
	} else{
		cout << "File tidak ditemukan!" << endl;
	}
	data.close();
	system("pause");
	system("cls");
}

void portal::beasiswa(){
	int pilih;
	ulang:
	cout << "1. Beasiswa luar negeri \n2. Beasiswa Muhammadiyah \n0. Kembali" << endl;
	cout << "Pilih beasiswa yang kamu ambil: ";
	cin >> pilih;
	
	ofstream data("potongan_beasiswa.txt");
	switch (pilih){
		case 1: data << 5000000; break;
		case 2: data << 2000000; break;
		case 0: break;
		default: cout << "Pilihan tidak valid!"; goto ulang; break;
	}
	cout << "Beasiswa berhasil terdaftar!" << endl;
	system("pause");
	system("cls");
}

void portal::spp(){
	
	int banyak_matkul=0;
	string baris;
	ifstream data("krs.txt");
	while(getline(data, baris)){
		banyak_matkul++;
		}
	data.close();
	
	ifstream beasiswa("potongan_beasiswa.txt");
	string potongan_beasiswa="0";
	string diskon;
	while (getline(beasiswa,diskon)){
		potongan_beasiswa = diskon;
	}
	beasiswa.close();
	
	int biaya_matkul = banyak_matkul * 250000;
	int biaya_gedung = 7500000;
	int biaya_lab    = 2500000;
	int total_biaya = (biaya_matkul + biaya_gedung + biaya_lab);
	
	
	cout << "Biaya mata kuliah    : " << banyak_matkul << " x 250000 : " << biaya_matkul << endl;
	cout << "Biaya Gedung         : " << biaya_gedung << endl;
	cout << "Biaya Laboratorium   : " << biaya_lab << endl;
	cout << "Potongan beasiswa    : " << potongan_beasiswa << endl;
	cout << "Total biaya          : " << total_biaya << endl;
	system("pause");
	system("cls");
}

int main(){
	portal uad;
	
	uad.login();
	
	int menu;
	do{
	cout << "Pilih Menu" << endl;
	cout << "1. Lihat informasi pribadi \n2. Tambah mata kuliah \n3. Hapus mata kuliah \n4. Lihat mata kuliah \n5. Info beasiswa \n6. Bayar SPP \n0. Keluar" << endl;
	cout << "Masukkan pilihan: ";
	cin >> menu;
	system("cls");
	
	switch(menu){
		case 1: uad.info_mhs(); break;
		case 2: uad.inputKRS(); break;
		case 3: break;
		case 4: uad.outputKRS(); break;
		case 5: uad.beasiswa(); break;
		case 6: uad.spp(); break;
		case 0: return 0; break;
		default: cout << "Pilihan tidak valid!" << endl << endl; break;
	}

	}
	while(menu != 0);
}
