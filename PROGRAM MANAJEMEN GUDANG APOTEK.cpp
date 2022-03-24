#include<iostream>
#include<conio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include<bits/stdc++.h>
#include<fstream>
#include <stdio.h>


/// PROGRAM BY KELOMPOK PA SDAA//

// 1. FAYZA VIRDANA ADDIZA
// 2. FATHIA NUQ QAMARINA
// 3. INDAH WULAN LESTARI


using namespace std;

void awal (){
	void pengguna();
	cout<<"\t\t ------- Program Gudang Apotek Sehat --------\n\n";
	pengguna();
}

//Loginsebagai
void pengguna ()
{
	int login();
	void loginuser();
	void daftaruser();
	int JP;
	char jwb;
	system ("cls");
	cout << "=== Pilih Jenis Pengguna ==="<< endl;
	cout << "1. Admin Gudang" << endl;
	cout << "2. Pegawai Apotek" << endl;
	cout << "Anda Login Sebagai [1/2] :"; cin >> JP;
	
	if (JP == 1){
		login();
	}
	else {
		cout << "Sudah Mendaftar Akun ? [y/n]" ; cin >> jwb;
		if (jwb == 'y'){
			loginuser();
		}
		else{
			daftaruser();
		}
	}
	
}

struct loginuser {
	string username1;
	string pass1;
};

loginuser lg;

void isilogin() {
	void loginuser();
	fstream loginusr;
	loginusr.open("Akunpegawai.txt", ios::app);
	
	loginusr <<lg.username1 << endl;
	loginusr <<lg.pass1 << endl;
	
	loginusr.close();
	loginuser();
};

void readlogin(){
	ifstream bclogin;
	bclogin.open("Akunpegawai.txt");
	
	bclogin >> lg.username1 ;
	bclogin >>lg.pass1 ;
	
	cout << "Akun Pegawai Yang Terdaftar"<<endl;
	while (!bclogin.eof()) {
		cout << "Username Pegawai :" << lg.username1 << endl;
		cout << "Password Pegawai :" << lg.pass1 << endl;
		
		cout << "=====================================" << endl;
		
		bclogin >> lg.username1 ;
		bclogin >>lg.pass1 ;
		
	}
	
	bclogin.close();
}

void daftaruser()
{
	cout << "=== Daftar Akun Pegawai ===" << endl;
	cout << "Masukkan Username Anda : "; cin >> lg.username1;
	cout << "Masukkan Password Anda : "; cin >> lg.pass1 ;
	cout << "=== Pendaftaran Berhasil ==="<<endl;
	
	isilogin();
}


int loginuser (){
	string password, username;
	void menuUser();
	cout<<"\n\n\n";
	cout<<"\t\t\t ------- Silahkan Login --------\n\n";
	cout << "\t\t\t Masukkan Username Anda :";cin >> username;
	cout << "\t\t\t Masukkan Password Anda :";cin >> password;
	cout<<"\n";
	
	if (username == lg.username1 ){
		if (username == lg.username1 && password == lg.pass1 ){
			cout << "\t\t\t   === Anda Berhasil Login === \n" << endl;
			system("pause");
			system("cls");
			menuUser();
		}
		else {
			cout << "\t\t\t=== Password Salah, Coba Kembali ! === \n" << endl;
			system("pause");
			system("cls");
			loginuser();
		}
	}
	else {
	cout << "\t\t=== Username Tidak Terdaftar, Coba Kembali ! === \n" << endl;
		system("pause");
		system("cls");
		loginuser();
	}
	
	return 0;
}


//Deklarasi Struct stack
struct masukbrg
{
	string nama, jenis,kode;
	int harga,stok;
};


//Deklarasi Node stuck
struct node1 {
	masukbrg databrg;
	struct node1* next;
};

node1* TOP = NULL;


//Prosedur Input Data
void masuk_brg(node1 **top){	
    struct node1 *databaru1 = new node1();
	cout<<"======================================================"<<endl;
	cout<<"               Masukkan Data Barang                   "<<endl;
	cout<<"======================================================"<<endl;
	fflush(stdin); 
	cout<<"Kode Obat       :";
	cin>>databaru1->databrg.kode ;
	cout<<"Nama Obat       :";
	fflush(stdin); 
	cin>>databaru1->databrg.nama;
	cout<<"Harga Obat      :";
	fflush(stdin); 
	cin>>databaru1->databrg.harga;
	cout<<"Jenis Obat      :";
	fflush(stdin); 
	cin>>databaru1->databrg.jenis;
	cout<<"Stok Obat       :";
	cin>>databaru1->databrg.stok;
    if(*top == NULL){
    	*top = databaru1;
    	return;
	}
	databaru1->next = *top;
	*top = databaru1;
}

void lihat_brg (node1 *top){
	if (top == NULL){
		cout << "Stack Underflow"<< endl;
		return;
	}
	cout<<"==== Daftar Pengajuan Barang Baru ====="<<endl;
	int i = 0;
	while (top != NULL){
	        cout<<"Masukkan ke - "<<i+1<<endl;
	        cout <<"Kode Obat   :"<< top->databrg.kode<<endl;
	        cout <<"Nama Obat   :"<< top->databrg.nama<<endl;
	        cout <<"Harga Obat  :"<< top->databrg.harga<<endl;
	        cout <<"Jenis Obat  :"<< top->databrg.jenis<<endl;
	        cout <<"Stok Obat   :"<< top->databrg.stok<<endl;
			cout<<endl;
        top = top->next;
        i++;
	}
	i++;
}

void hapus_brg (node1 **top){
	if (*top == NULL){
		cout << "Stack Underflow"<< endl;
		return;
	}
	node1 *temp = *top;
	*top = (*top)->next;
	delete temp;
	cout <<"DATA BERHASIL DIHAPUS !"<<endl;
}

void shell_sort(int a[], string b[], int &n, int metodSort, int menuSort);	
int Searchingjump(string a[], string nama_obat, int n);
void cetak(struct node* data);


// Login Admin gudang
int login (){
	string password, username;
	void menu();
	cout<<"\n\n\n";
	cout<<"\t\t\t ------- Silahkan Login --------\n\n";
	cout << "\t\t\t Masukkan Username Anda :";cin >> username;
	cout << "\t\t\t Masukkan Password Anda :";cin >> password;
	cout<<"\n";
	
	if (username == "admin"){
		if (password == "admin"){
			cout << "\t\t\t   === Anda Berhasil Login === \n" << endl;
			system("pause");
			system("cls");
			menu();
		}
		else {
			cout << "\t\t\t=== Password Salah, Coba Kembali ! === \n" << endl;
			system("pause");
			system("cls");
			login();
		}
	}
	else {
	cout << "\t\t=== Username Tidak Terdaftar, Coba Kembali ! === \n" << endl;
		system("pause");
		system("cls");
		login();
	}
	
	return 0;
}


//Deklarasi Struct
struct gudang
{
	string nama, jenis,kode;
	int harga,stok,nmr;
};

//Deklarasi Node Linked List
struct node {
	//array of struct
	gudang gdg[100];
	int data;
	struct node *selanjutnya;
};struct node* dpn = NULL;

int jumlahObat = 0;
void shell_sort(int a[], string b[], int &n, int metodSort, int menuSort);	
int Searchingjump(string a[], string nama_obat, int n);


//Prosedur Input Data
void masuk_data(node **dpn, int &byk){	
    node *databaru = new node();
    databaru->data = jumlahObat;
	jumlahObat++;
	databaru->gdg->nmr = jumlahObat;
	
	cout<<"======================================================"<<endl;
	cout<<"               Masukkan Data Barang                   "<<endl;
	cout<<"======================================================"<<endl;
	cout<<"================ Data Ke-"<<byk+1<<"=================="<<endl;
	fflush(stdin); 
	cout<<"Kode Obat       :";
	cin>>databaru->gdg->kode;
	cout<<"Nama Obat       :";
	fflush(stdin); 
	cin>>databaru->gdg->nama;
	cout<<"Harga Obat      :";
	fflush(stdin); 
	cin>>databaru->gdg->harga;
	cout<<"Jenis Obat      :";
	fflush(stdin); 
	cin>>databaru->gdg->jenis;
	cout<<"Stok Obat       :";
	fflush(stdin); 
	cin>>databaru->gdg->stok;
    databaru->selanjutnya = NULL;
        if (*dpn == NULL) {
            *dpn = databaru;
			return;
        }
        node *tmp = *dpn;
        while (tmp->selanjutnya != NULL) {
            tmp = tmp->selanjutnya;
        }
        tmp->selanjutnya = databaru;
}


// Prosedur Tampilkan Data
void cetak(struct node* data){
	cout<<"No\tKode\tNama\t\tHarga\t\tJenis\tstock\n======================================================================\n";
	int j =0;
	while (data !=NULL){
        cout<< data->gdg->nmr <<"\t"<<data->gdg->kode<<"\t"<<data->gdg->nama<<"\t"<<"Rp."<<data->gdg->harga<<"/pcs"<<"\t"<<data->gdg->jenis<<"\t"<<data->gdg->stok<< " boks"<<"\n";
        j++;
        data = data->selanjutnya;
   }
}

//Prosedur Hapus Data
void hapus(struct node** data){
	struct node *dt = *data, *akhir;
	int plh, i;
    cetak(dpn);
	cout<<"======================================================"<<endl;
	cout<<"               Hapus Data Barang                      "<<endl;
	cout<<"======================================================"<<endl;
	cout<<"Masukkan Nomor Obat yang Ingin Dihapus :";
	cin>>plh;
	
	if (dt != NULL && dt->data == plh-1)
	{
		*data = dt ->selanjutnya;
		free(dt);
		cout<< "Data Telah Terhapus...."<<endl;
	    system("pause");
        jumlahObat--;
		return;
	}
	while (dt !=NULL && dt->data != plh-1)
	{
		akhir = dt;
		dt = dt->selanjutnya;
	}
	if (dt == NULL){
		cout << "Tidak Berhasil Menemukan Data....." << endl;
		system("pause");
		return;
	}
	akhir->selanjutnya = dt->selanjutnya;
	free(dt);
	cout<< "Data Telah Terhapus...."<<endl;
	system("pause");
    jumlahObat--;
	return;
}


//Prosedur Update
void update (node *data, int &pil){
	cout<<"======================================================"<<endl;
	cout<<"               Update Data Barang                     "<<endl;
	cout<<"======================================================"<<endl;
	while(data !=NULL){
		if(data->gdg->nmr == pil)
		{
			cout<<"Kode Obat Baru      :";
			fflush(stdin); 
			cin>>data->gdg->kode;
			cout<<"Nama Obat Baru      :";
			fflush(stdin); 
			cin>>data->gdg->nama;
			cout<<"Harga Obat Baru     :";
			fflush(stdin); 
			cin>>data->gdg->harga;
			cout<<"Jenis Obat Baru     :";
			fflush(stdin); 
			cin>>data->gdg->jenis;
			cout<<"Stok Obat Baru      :";
			fflush(stdin); 
			cin>>data->gdg->stok;
			cout << "Data berhasil diubah..." << endl;
			system("pause")	;
			return;
		}
		data = data->selanjutnya;
	}
	cout << "Data Tidak Ada...." << endl;
	system("pause")	;
	return;
}

//Fungsi Pencarian Menggunakan JumpSearch
int Searchingjump(string a[], string nama_obat, int n) {
	int step = sqrt(n);
	int prev = 0;
	while (a[min(step, n)-1] < nama_obat) {
		prev = step;
		step += sqrt(n);
		if (prev >= n) {
			return -1;
		}
	}
	while (a[prev] < nama_obat) {
		prev++;
		if (prev == min(step, n)) {
			return -1;
		}
	}
	if (a[prev] == nama_obat) {
		return prev;
	}
	return -1;
}


//Prosedur menu pengurutan
void Shellsort(node *data, int a[], string b[], int menuSort, int metodSort) {
	node *dpn_ = data;
	string arrO[jumlahObat][6] = {};

	int i = 0;
	if(menuSort == 1) {
		while(dpn_ != NULL) {
			a[i] = dpn_->gdg->harga;
			i++;
			dpn_ = dpn_->selanjutnya;
		}
	} else if(menuSort == 2)  {
		while(dpn_ != NULL) {
			b[i] = dpn_->gdg->nama;
			i++;
			dpn_ = dpn_->selanjutnya;
		}
	} 
	shell_sort(a, b, jumlahObat, metodSort, menuSort);

	node *_dpn = data;
	int j = 0;
	while(_dpn != NULL) {
		arrO[j][0] = _dpn->gdg->kode;
		arrO[j][1] = _dpn->gdg->nama;
		arrO[j][2] = to_string(_dpn->gdg->harga);
		arrO[j][3] = _dpn->gdg->jenis;
		arrO[j][4] = to_string(_dpn->gdg->stok);
		arrO[j][5] = to_string(_dpn->gdg->nmr);
		_dpn = _dpn->selanjutnya;
		j++;
	}

	int x = 0;
	while(x < jumlahObat) {
		int y = 0;
		while(y < jumlahObat) {
			switch(menuSort) {
				case 1:
					if(a[x] == stoi(arrO[y][2])) {
						data->gdg->kode = arrO[y][0];
						data->gdg->nama = arrO[y][1];
						data->gdg->harga = stoi(arrO[y][2]);
						data->gdg->jenis = arrO[y][3];
						data->gdg->stok = stoi(arrO[y][4]);
						data->gdg->nmr = stoi(arrO[y][5]);
						data = data->selanjutnya;
						x++;
						if(x == jumlahObat) {
							return;
							break;
						}
					}
					break;
				case 2:
					if(b[x] == arrO[y][1]) {
						data->gdg->kode = arrO[y][0];
						data->gdg->nama = arrO[y][1];
						data->gdg->harga = stoi(arrO[y][2]);
						data->gdg->jenis = arrO[y][3];
						data->gdg->stok = stoi(arrO[y][4]);
						data->gdg->nmr = stoi(arrO[y][5]);
						data = data->selanjutnya;
						x++;
						if(x == jumlahObat) {
							return;
							break;
						}
					}
					break;
			}
			y++;
		}
	}
	return;
}


//Metode Pengurutan menggunakan ShellSort
void shell_sort(int a[], string b[], int &n, int metodSort, int menuSort){
	if(menuSort == 1) {//pengurutan berdasarkan Harga
		for (int gap = n/2; gap > 0; gap /= 2) {
			if (metodSort == 1) {//Ascending
				for (int i = gap; i < n; i += 1) {
					int temp = a[i];
					int j;
					for (j = i; j >= gap &&  a[j-gap] > temp; j -= gap){
						a[j] = a[j - gap];
					}
					a[j] = temp;
				}
			}
			else if (metodSort == 2) {//Descending
				for (int i = gap; i < n; i += 1) {
					int temp = a[i];
					int j;
					for (j = i; j >= gap &&  a[j-gap] < temp; j -= gap){
						a[j] = a[j - gap];
					}
				a[j] = temp;
				}
			}
		}
	} else if(menuSort == 2) {//Pengurutan Berdasarkan Nama
		for (int gap = n/2; gap > 0; gap /= 2) {
			if (metodSort == 1) {//Ascending
				for (int i = gap; i < n; i += 1) {
					string temp = b[i];
					int j;
					for (j = i; j >= gap &&  b[j-gap] > temp; j -= gap){
						b[j] = b[j - gap];
					}
					b[j] = temp;
				}
			}
			else if (metodSort == 2) {//Descending
				for (int i = gap; i < n; i += 1) {
					string temp = b[i];
					int j;
					for (j = i; j >= gap &&  b[j-gap] < temp; j -= gap){
						b[j] = b[j - gap];
					}
				b[j] = temp;
				}
			}
		}
	}
} 




void menu()
{
	system("cls");
	char pilmn;
	int byk, pil, idn, pk;
	string x;
	int menuSort, metodSort;
	string b[jumlahObat] = {};
	int a[jumlahObat] = {};

	cout<<"\n+++========Gudang Toko Obat========+++";
   	cout<<"\n";
    cout<<"  ______  ___________________________________" << endl;
    cout<<"| Pilih |           Akses                    |" << endl;
    cout<<" ============================================" << endl;
    cout<<"|   A   | Masukkan Data Obat                 |" <<endl;
    cout<<"|   B   | Tampilkan Data Obat                |" << endl;
    cout<<"|   C   | Hapus Data Obat                    |" << endl;
    cout<<"|   D   | Update Data Obat                   |" << endl;
    cout<<"|   E   | Sorting Data Obat                  |" << endl;
    cout<<"|   F   | Searching Nama Obat                |" << endl;
    cout<<"|   G   | Lihat Akun Pegawai                 |" << endl;
	cout<<"|   H   | Lihat Daftar Pengajuan Barang Baru |"<<endl;
    cout<<"|   I   | Hapus Daftar Pengajuan Barang Baru |"<<endl;
    cout<<"|   J   | Keluar                             |" <<endl;
    cout<<"|_______|____________________________________|"<< endl;
    cout<<endl;
      cout<<"Masukkan pilihan Anda : ";
      cin>>pilmn;
      switch(toupper(pilmn))
	  {
        case 'A' :
	      	cout<< "Masukkan Banyak Data Obat Yang Ingin Diinput :";
	      	cin>>byk;
	      	for(int i = 0; i<byk; i++){
	      		masuk_data(&dpn,i);
	      		cout<<"Data Obat Berhasil diinput...."<<endl;
			}
			system("pause");
			menu();
			break;
		case 'B' :
			cetak(dpn);
			system("pause");
			menu();
			break;
		case 'C' :
			hapus(&dpn);
			menu();
			break;
		case 'D' :
			cetak(dpn);
			cout<< "Masukkan Nomor Obat Yang Ingin Di Update :"; cin>> pil;
			update(dpn, pil);
			menu();
			break;
		case 'E':
			cout << "=== Pilihan Kategori Pengurutan ==="<< endl;
			cout << "[1] Urutkan Harga" << endl;
			cout << "[2] Urutkan Nama" << endl;
			cout << "Pilih menu : "; cin >> menuSort;
			system ("pause");
			cout<< "=== Pilihan Metode Pengurutan ==="<<endl;
			cout << "[1] Ascending" << endl;
			cout << "[2] Descending" << endl;
			cout << "Pilih meotde : "; cin >> metodSort;
			Shellsort(dpn, a, b, menuSort, metodSort);
			cout << "\nData Gudang Berhasil di Urutkan" << endl;
			cetak(dpn);
			system("pause");
			menu();
			break;
		case 'F':
			Shellsort(dpn, a, b, 2, 1);
			cetak(dpn);
			Shellsort(dpn, a, b, 2, 1);
			cout<<"\nMasukkan nama obat yang ingin dicari: ";
			cin>>x;
			idn = Searchingjump(b, x, jumlahObat);
			if (idn > -1) {
				cout << "Nama obat " << x << " ada pada baris ke-" << idn+1 << endl;
			} else {
				cout << "Nama obat tidak ditemukan." << endl;
			}
			system("pause");
			menu();
			break;
		case 'G':
			readlogin();
			system("pause");
			menu();
			break;
		case 'H':
			lihat_brg(TOP);
			system("pause");
			menu();
			break;
		case 'I':
			hapus_brg(&TOP);
			cout <<"Tumpukan Atas Berhasil Dihapus ...."<<endl;
			system("pause");
			menu();
			break;
		case 'J':
			cout << "1. Kembali Ke Login" << endl;
			cout << "2. Keluar Dari Aplikasi"<< endl;
			cout << "Pilihan Anda > "; cin>> pk;
			if (pk == 1){
				pengguna();
			}
			else{
				cout<<"\n\t\t====== KELUAR DARI APLIKASI ============\t\t";
				exit(0);
			}
			break;
		default: cout<<"Inputan Salah!!";
	 		cout << "\n";
	 		system("pause");
	 		system("cls");
			menu();
	 		break;
	   }
}

void menuUser()
{
	system("cls");
	char pilmn;
	int byk1, pil, idn,pk;
	string x;
	int menuSort, metodSort;
	string b[jumlahObat] = {};
	int a[jumlahObat] = {};

	cout<<"\n+++======== Gudang Toko Obat========+++";
   	cout<<"\n";
    cout<<"  ______  ____________________________________" << endl;
    cout<<"| Pilih |           Akses                    |" << endl;
    cout<<" ============================================" << endl;
    cout<<"|   A   | Masukkan Pengajuan Barang Baru     |" <<endl;
    cout<<"|   B   | Lihat Daftar Pengajuan Barang Baru |"<<endl;
    cout<<"|   C   | Hapus Daftar Pengajuan Barang Baru |"<<endl;
    cout<<"|   D   | Tampilkan Data Obat Gudang         |" << endl;
    cout<<"|   E   | Searching Nama Obat Gudang         |" << endl;
    cout<<"|   F   | Keluar                             |" <<endl;
    cout<<"|_______|____________________________________|"<< endl;
    cout<<endl;
      cout<<"Masukkan pilihan Anda : ";
      cin>>pilmn;
      switch(toupper(pilmn))
	  {
        case 'A' :
        	system("cls");
        	masuk_brg(&TOP);
        	cout <<"Pengajuan Berhasil Di Tambah ...."<<endl;
			system("pause");
			menuUser();
			break;
		case 'B' :
			lihat_brg(TOP);
			system("pause");
			menuUser();
		case 'C':
			hapus_brg(&TOP);
			cout <<"Tumpukan Atas Berhasil Dihapus ...."<<endl;
			system("pause");
			menuUser();
		case 'D' :
			cetak(dpn);
			system("pause");
			menuUser();
			break;
		case 'E':
			Shellsort(dpn, a, b, 2, 1);
			cetak(dpn);
			Shellsort(dpn, a, b, 2, 1);
			cout<<"\nMasukkan nama obat yang ingin dicari: ";
			cin>>x;
			idn = Searchingjump(b, x, jumlahObat);
			if (idn > -1) {
				cout << "Nama obat " << x << " ada pada baris ke-" << idn+1 << endl;
			} else {
				cout << "Nama obat tidak ditemukan." << endl;
			}
			system("pause");
			menuUser();
			break;
		case 'F':
			cout << "1. Kembali Ke Login" << endl;
			cout << "2. Keluar Dari Aplikasi"<< endl;
			cout << "Pilihan Anda > "; cin>> pk;
			if (pk == 1){
				pengguna();
			}
			else{
				cout<<"\n\t\t====== KELUAR DARI APLIKASI ============\t\t";
				exit(0);
			}
			break;
		default: cout<<"Inputan Salah!!";
	 		cout << "\n";
	 		system("pause");
	 		system("cls");
			menuUser();
	 		break;
	   }
}



int main(){
	awal();
	return 0;
}
