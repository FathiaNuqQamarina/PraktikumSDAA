#include<iostream>
#include<conio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

void awal (){
	int login();
	cout<<"\t\t ------- Program Gudang Apotek Sehat --------\n\n";
	login();
}


// Login Admin gudang
int login (){
	string password, username;
	void menu();
	cout<<"\n\n\n";
	cout<<"\t\t\t ------- Silahkan Login --------\n\n";
	cout << "\t\t\t Masukkan Username Anda :";cin >> username;
	cout << "\t\t\t Masukkan Password Anda :";cin >> password;
	cout<<"\n";
	
	if (username == "admintoko"){
		if (password == "bukagudang"){
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

/////////////////////////

//Deklarasi STRUCT
struct gudang
{
	string nama, jenis,kode;
	int harga,stok,nmr;
};

// Deklasari Double LINKED LIST
struct node {
	int data;
	struct node *selanjutnya;
	struct node *sebelumnya;
	//array of struct
	gudang gdg[100];
};struct node* dpn = NULL, *blkg = NULL, *del;

int jumlahObat = 0;
void shell_sort(int a[], string b[], int &n, int metodSort, int menuSort);	
int jumpSearch(string a[], string nama_obat, int n);


// Prosedur Akses //

//Prosedur Input Data
void masuk_data(node **dpn, node **blkg, int &byk){	
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

	//Atur POSISI INPUT DATA
	int posisi;
	cout << "Tambahkan di posisi ke-(Masukkan Berupa Angka) :"; cin >> posisi;
    if(*dpn == NULL) {
        *dpn = databaru;
        *blkg = databaru;
        return;
    } else {
        if(posisi == 1) {
            databaru->sebelumnya = NULL;
            databaru->selanjutnya = *dpn;
            (*dpn)->sebelumnya = databaru;
            (*dpn) = databaru;
            return;
        } else if(posisi >= jumlahObat) {
            databaru->sebelumnya = *blkg;
            databaru->selanjutnya = NULL;
            (*blkg)->selanjutnya = databaru;
            (*blkg) = databaru;
            return;
        } else {
            node *cur = *dpn;
            for(int n = 1; n < posisi-1; n++) {
                cur = cur->selanjutnya;
            }
            node *afterNode = cur->selanjutnya;
            databaru->sebelumnya = cur;
            databaru->selanjutnya = afterNode;
            cur->selanjutnya = databaru;
            afterNode->sebelumnya = databaru;
            return;
        }
    }
}

// Prosedur Tampilkan Data
void cetak(struct node* data, node* data2, char pos){
	cout<<"No\tKode\tNama\t\tHarga\t\tJenis\tstock\n======================================================================\n";
	int j =0;
	//Dari Head ke Tail
	if(pos == '1') {
		while (data !=NULL){
			cout<< data->gdg->nmr <<"\t"<<data->gdg->kode<<"\t"<<data->gdg->nama<<"\t"<<"Rp."<<data->gdg->harga<<"/pcs"<<"\t"<<data->gdg->jenis<<"\t"<<data->gdg->stok<< " boks"<<"\n";
			j++;
			data = data->selanjutnya;
		}
	} 
	//Dari Tail ke Head
	else if(pos == '2') {
		while (data2 !=NULL){
			cout<< data2->gdg->nmr <<"\t"<<data2->gdg->kode<<"\t"<<data2->gdg->nama<<"\t"<<"Rp."<<data2->gdg->harga<<"/pcs"<<"\t"<<data2->gdg->jenis<<"\t"<<data2->gdg->stok<< " boks"<<"\n";
			j++;
			data2 = data2->sebelumnya;
		}
	}
}


// Prosedur Hapus Data
void hapus(struct node **data, node **data2){
	int plh, i;
    cetak(dpn, blkg, '1');
	cout<<"======================================================"<<endl;
	cout<<"               Hapus Data Barang                      "<<endl;
	cout<<"======================================================"<<endl;
	cout<<"Masukkan Nomor Obat yang Ingin Dihapus :";
	cin>>plh;

	if(*data == NULL) {
		cout << "Tidak Berhasil Menemukan Data....." << endl;
		system("pause");
		return;
	} else {
		if (*data == *data2) {
			*data = NULL;
			*data2 = NULL;
			return;
		} else {
			if(plh == 1) {
				del = *data;
				*data = (*data)->selanjutnya;
				(*data)->sebelumnya = NULL;
    			jumlahObat--;
				delete del;
				cout<< "Data Telah Terhapus...."<<endl;
				system("pause");
				return;
			} else if(plh == jumlahObat) {
				del = *data2;
				*data2 = (*data2)->sebelumnya;
				(*data2)->selanjutnya = NULL;
    			jumlahObat--;
				delete del;
				cout<< "Data Telah Terhapus...."<<endl;
				system("pause");
				return;
			} else {
				node *cur = *data;
				for(int n = 1; n > plh-1; n++) {
					cur = cur->selanjutnya;
				}
				del = cur->selanjutnya;
				node *afterNode = del->selanjutnya;
				cur->selanjutnya = afterNode;
				afterNode->sebelumnya = cur;
    			jumlahObat--;
				delete del;
				cout<< "Data Telah Terhapus...."<<endl;
				system("pause");
				return;
			}
		}
	}
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



//Pilihan Menu Akses
void menu()
{
	system("cls");
	char pilmn;
	int byk, pil, idn;
	string x;
	int menuSort, metodSort;
	string b[jumlahObat] = {};
	int a[jumlahObat] = {};

	cout<<"\n+++========Gudang Toko Obat========+++";
   	cout<<"\n";
    cout<<"  ______  ______________________________" << endl;
    cout<<"| Pilih |           Akses               |" << endl;
    cout<<" =======================================" << endl;
    cout<<"|   A   | Masukkan Data Obat            |" <<endl;
    cout<<"|   B   | Tampilkan Data Obat           |" << endl;
    cout<<"|   C   | Hapus Data Obat               |" << endl;
    cout<<"|   D   | Update Data Obat              |" << endl;
    cout<<"|   E   | Sorting Data Obat             |" << endl;
    cout<<"|   F   | Searching Nama Obat           |" << endl;
    cout<<"|   G   | Keluar                        |" <<endl;
    cout<<"|_______|_______________________________|"<< endl;
    cout<<endl;
      cout<<"Masukkan pilihan Anda : ";
      cin>>pilmn;
      switch(toupper(pilmn))
	  {
        case 'A' :
	      	cout<< "Masukkan Banyak Data Obat Yang Ingin Diinput :";
	      	cin>>byk;
	      	for(int i = 0; i<byk; i++){
	      		masuk_data(&dpn, &blkg, i);
	      		cout<<"Data Obat Berhasil diinput...."<<endl;
			}
			system("pause");
			menu();
			break;
		case 'B' :
			char pos;
			cout << "Pilihan Tampilkan Data :"<<endl;
			cout << "[1] Head ke tail" << endl;
			cout << "[2] Tail ke head" << endl;
			cout << "Menampilkan dari: "; cin >> pos;
			cetak(dpn, blkg, pos);
			system("pause");
			menu();
			break;
		case 'C' :
			hapus(&dpn, &blkg);
			menu();
			break;
		case 'D' :
			cetak(dpn, blkg, '1');
			cout<< "Masukkan Nomor Obat Yang Ingin Di Update :"; cin>> pil;
			update(dpn, pil);
			menu();
			break;
		case 'E':
			cout << "=== Pilihan Kategori Pengurutan ==="<< endl;
			cout << "[1] Urutkan Harga" << endl;
			cout << "[2] Urutkan Nama" << endl;
			cout << "Pilih menu : "; cin >> menuSort;
			system("pause");
			cout<< "=== Pilihan Metode Pengurutan ==="<<endl;
			cout << "[1] Ascending" << endl;
			cout << "[2] Descending" << endl;
			cout << "Pilih meotde : "; cin >> metodSort;
			Shellsort(dpn, a, b, menuSort, metodSort);
			cout << "\nData Gudang Berhasil di Urutkan" << endl;
			cetak(dpn, blkg, '1');
			system("pause");
			menu();
			break;
		case 'F':
			Shellsort(dpn, a, b, 2, 1);
			cetak(dpn, blkg, '1');
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
			cout<<"\n\t\t====== KELUAR DARI APLIKASI ============\t\t";
			exit(0);
			break;
		default: cout<<"Inputan Salah!!";
	 		cout << "\n";
	 		system("pause");
	 		system("cls");
			menu();
	 		break;
	   }
}

int main(){
	awal();
	return 0;
}
