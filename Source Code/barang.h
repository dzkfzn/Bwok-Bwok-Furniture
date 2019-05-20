void gotoxy(int x,int y);
void tabel();
void MenuMasterBarang();
void kotak();
typedef struct {
			int ID;
			char nama[30];
			char supplier[30];
			char jenis[30];
			int stock;
			int harga;
			int berat;
			} ArsipBarang;

int gagal_update;
	
void Buat_Barang()
{
	//Deklarasi
	char konfirmasi;
	ArsipBarang barang;
	
	//Algoritma
	FILE *fbarang;
	
	fbarang = fopen("lib/barang.dat","a+b");
	
	gotoxy(28,18);printf("Buat Data Barang");
	gotoxy(28,20);printf("ID\t\t: BRG");
	while(!feof(fbarang))
	{
		fflush(stdin);
		fread(&barang.ID,sizeof(barang),1,fbarang);
	}
	barang.ID++;
	if(barang.ID<1000)
	{
		barang.ID=barang.ID+1000-16;
	}
	
	printf("%d",barang.ID);
	kotak();
	gotoxy(28,21);printf("Nama\t: "); 
	gotoxy(28,22);printf("Jenis kayu\t: "); 
	gotoxy(28,23);printf("Supplier\t: "); 
	gotoxy(28,24);printf("Stock\t: "); 
	gotoxy(28,25);printf("Berat @1\t:"); gotoxy(46,25);printf("KG"); 
	gotoxy(28,26);printf("Harga\t: Rp "); 
	
	gotoxy(42,21);getletter(barang.nama,25);
	gotoxy(42,22);getletter(barang.jenis,25);
	gotoxy(42,23);getletter(barang.supplier,25);
	gotoxy(42,24);getnum(&barang.stock,5);
	gotoxy(42,25);getnum(&barang.berat,5);
	gotoxy(45,26);getnum(&barang.harga,15);	
	
	
	fwrite(&barang,sizeof(barang),1,fbarang);
	fclose(fbarang);
}

void Baca_Barang()
{	
	int i;
	i=0;
	int a=24; 
	FILE *fbarang;
	ArsipBarang barang;
	
	fbarang = fopen("lib/barang.dat","rb");
	tabel();
	gotoxy(28,20);printf("NO");
	gotoxy(39,20);printf("Nama");
	gotoxy(61,20); printf("Tabel"); 
	gotoxy(80,20);printf("Jenis");
	gotoxy(95,20);printf("ID");
	gotoxy(105,20);printf("Supplier");
	gotoxy(124,20);printf("Harga");
	gotoxy(141,20);printf("Stok");
	gotoxy(153,20);printf("Berat");
	fread(&barang,sizeof(barang),1,fbarang);
	while(!feof(fbarang))
	{				
		i=i+1;
			gotoxy(28,a);printf("[%i]",i);
			gotoxy(37,a);printf("%s",barang.nama);
			gotoxy(80,a);printf("%s",barang.jenis);
			gotoxy(95,a);printf(" %d",barang.ID);
			gotoxy(105,a);printf(" %s",barang.supplier);
			gotoxy(125,a);printf("Rp %d",barang.harga);
			gotoxy(141,a);printf("%d buah",barang.stock);
			gotoxy(152,a);printf("%d KG",barang.berat);
			fread(&barang,sizeof(barang),1,fbarang);	
			a++;
	}
	fclose(fbarang);
	gotoxy(2,29);printf("ketik enter...\n");getch();

}
void Update_Barang()
{
	//DEKLARASI
	ArsipBarang barang;
	FILE *fbarang;
	FILE *Temp;
	int IDbarang,menu;
	typedef enum {false = 0, true = 1}bool;
	bool found;
	char namabaru[30],jenisbaru[30],supplierbaru[30];
	int stockbaru,hargabaru,beratbaru;
	
	//ALGORITMA
	
	gotoxy(28,18);printf("Update Data Barang");
	gotoxy(28,20);printf("Masukkan ID barang yang ingin anda update : BRG"); 
	getnum(&IDbarang,15);
	gotoxy(28,21);printf("Mencari Data..");
	Sleep(1500);
	
	fbarang = fopen("lib/barang.dat","rb");
	Temp = fopen("lib/temp.dat","wb");
	found = false;
	while((!found)&&(!feof(fbarang)))
	{
		fread(&barang,sizeof(barang),1,fbarang);	
		if (barang.ID == IDbarang)
		{
			found = true;
		}
		else
		{
			fwrite(&barang,sizeof(barang),1,Temp);
		}			
	}
	
	if(found == true)
	{
		gagal_update = 0;
		gotoxy(28,23);printf("Data Berhasil Ditemukan");
		gotoxy(28,25);printf("ID			: BRG%d",barang.ID);
		gotoxy(28,26);printf("Nama		: %s",barang.nama);
		gotoxy(28,27);printf("Jenis		: %s",barang.jenis);
		gotoxy(28,28);printf("Supplier		: %s",barang.supplier);
		gotoxy(28,29);printf("Stock		: %d",barang.stock);
		gotoxy(28,30);printf("Berat		:  %d KG",barang.berat);
		gotoxy(28,31);printf("Harga		: Rp %d",barang.harga);
		gotoxy(28,32);printf("Data mana yang akan anda update ?");
		gotoxy(28,33);printf("1.Nama");
		gotoxy(28,34);printf("2.Jenis");
		gotoxy(28,35);printf("3.Supplier");
		gotoxy(28,36);printf("4.Stock");
		gotoxy(28,37);printf("5.Harga");
		gotoxy(28,38);printf("6.Berat");
		gotoxy(28,39);printf("7.Batal");
		gotoxy(28,40);printf("Menu yang diinginkan : ");
		getnum(&menu,1);
		fflush(stdin);
		switch(menu)
		{
		
		case 1 :
			gotoxy(28,41);printf("Masukkan Nama baru : "); getletter(namabaru,30);
			strcpy (barang.nama,namabaru);
			break;
		case 2 :
			gotoxy(28,41);printf("Masukkan Jenis baru : "); getletter(jenisbaru,30);
			strcpy (barang.jenis,jenisbaru);
			break;
		case 3 :
			gotoxy(28,41);printf("Masukkan Supplier baru : "); getletter(supplierbaru,30);
			strcpy (barang.supplier,supplierbaru);
			break;
		case 4 :
			gotoxy(28,41);printf("Masukkan Stock baru : "); getnum(&stockbaru,5);	
			barang.stock = stockbaru;
			break;
		case 5 :
			gotoxy(28,41);printf("Masukkan harga baru : Rp "); getnum(&hargabaru,10);	
			barang.harga = hargabaru;
			break;	
		case 6 :
			gotoxy(28,41);printf("Masukkan Berat baru :    KG"); gotoxy(50,41);getnum(&beratbaru,10);	
			barang.berat = beratbaru;
			break;	
		case 7 :
			getch();
			system("cls");
			MenuMasterBarang();
			break;		
		}
		fwrite(&barang,sizeof(barang),1,Temp);
		fread(&barang,sizeof(barang),1,fbarang);
		while(!feof(fbarang))
		{
			fwrite(&barang,sizeof(barang),1,Temp);
			fread(&barang,sizeof(barang),1,fbarang);
		}
		gotoxy(28,42);printf("Loading..");
		Sleep(1500);
		gotoxy(28,43);printf("Sukses Mengupdate Data ");getch();
		
		///////////////////////////////////////////////////
		fclose(fbarang);
		fclose(Temp);
	
		Temp = fopen("lib/temp.dat","rb");
		fbarang = fopen("lib/barang.dat","wb"); 
		
		fread(&barang,sizeof(barang),1,Temp);
		while(!feof(Temp))
		{
			fwrite(&barang,sizeof(barang),1,fbarang);
			fread(&barang,sizeof(barang),1,Temp);
		} 
		
		fclose(fbarang);
		fclose(Temp);
	}
	else
	{
		gagal_update = 1;
		gotoxy(28,23);printf("Barang dengan Id BRG%d tidak ditemukan di dalam Dat Barang", IDbarang);
		fclose(fbarang);
		fclose(Temp);	
	}
	
}

void Hapus_Barang()
{
	//DEKLARASI
	FILE *Temp;
	int IDbarang,menu;
	typedef enum {false = 0, true = 1}bool;
	bool found;
	FILE *fbarang;
	ArsipBarang barang;
	char konfirmasi;

	
	//ALGORITMA
	gotoxy(28,18);printf("Hapus Data Barang");
	gotoxy(28,20);printf("Masukkan ID barang yang ingin anda hapus : BRG"); 
	getnum(&IDbarang,15);
	gotoxy(28,21);printf("Mencari Data..");
	Sleep(1500);
	fbarang = fopen("lib/barang.dat","rb");
	Temp = fopen("lib/temp.dat","wb");
	found = false;	
	while((!found)&&(!feof(fbarang)))
	{
		fread(&barang,sizeof(barang),1,fbarang);	
		if (barang.ID == IDbarang)
		{
			found = true;
		}
		else
		{
			fwrite(&barang,sizeof(barang),1,Temp);
		}			
	}
	
	if(found == true)
	{
		gagal_update = 0;
		gotoxy(28,23);printf("Data Berhasil Ditemukan");
		gotoxy(28,25);printf("ID		: BRG%d",barang.ID);
		gotoxy(28,26);printf("Nama	: %s",barang.nama);
		gotoxy(28,27);printf("Jenis	: %s",barang.jenis);
		gotoxy(28,28);printf("Supplier : %s",barang.supplier);
		gotoxy(28,29);printf("Stock	: %d",barang.stock);
		gotoxy(28,30);printf("Berat	: %d KG",barang.berat);
		gotoxy(28,31);printf("Harga	: Rp %d",barang.harga);
		gotoxy(28,32);printf("Apakah Anda yakin ingin menghapus Data ini ? Y/N");
		gotoxy(28,33);printf("Jawaban Anda : ");
		getletter(&konfirmasi,1);
		if (konfirmasi=='Y' || konfirmasi == 'y')
		{
			gotoxy(28,34);printf("Menghapus Data..");
			Sleep(1500);
			fread(&barang,sizeof(barang),1,fbarang);	//
			while(!feof(fbarang))
			{
				fwrite(&barang,sizeof(barang),1,Temp);
				fread(&barang,sizeof(barang),1,fbarang);
			}
			fclose(fbarang);
			fclose(Temp);
		
			Temp = fopen("lib/temp.dat","rb");
			fbarang = fopen("lib/barang.dat","wb"); 
			
			fread(&barang,sizeof(barang),1,Temp);
			while(!feof(Temp))
			{
				fwrite(&barang,sizeof(barang),1,fbarang);
				fread(&barang,sizeof(barang),1,Temp);
			} 
			
			fclose(fbarang);
			fclose(Temp);
			gotoxy(28,35);printf("Data Berhasil Di Hapus! ");
		}
			
	}
	else{ 	
		gagal_update = 1;		
		gotoxy(28,23);printf("Data Tidak Ditemukan");
		fclose(fbarang);
		fclose(Temp);
		getch();
	}
}


void MenuMasterBarang()
{
	int menu;
	char jawab;
	do{
		system("cls");
		kotak();
		
		gotoxy(2,19);printf("Kelola Furniture");
		gotoxy(2,21);printf("1.Tambah Data\n");
		gotoxy(2,22);printf("2.Lihat Data\n");
		gotoxy(2,23);printf("3.Update Data\n");
		gotoxy(2,24);printf("4.Hapus Data\n");
		gotoxy(2,25);printf("5.Kembali\n");
		gotoxy(2,26);printf("6.Logout\n");
		gotoxy(2,27);printf("7.Keluar\n");
		gotoxy(2,28);printf("Pilihan Anda : ");
		getnum(&menu,1);
			switch(menu)
			{
			case 1 :
				do{
					getch();
					system("cls");
					kotak();
					gotoxy(2,19);printf("Kelola Furniture");
					gotoxy(2,21);printf("1.Tambah Data\n");
					gotoxy(2,22);printf("2.Lihat Data\n");
					gotoxy(2,23);printf("3.Update Data\n");
					gotoxy(2,24);printf("4.Hapus Data\n");
					gotoxy(2,25);printf("5.Kembali\n");
					gotoxy(2,26);printf("6.Logout\n");
					gotoxy(2,27);printf("7.Keluar\n");
					gotoxy(2,28);printf("Pilihan Anda : 1");
					
					Buat_Barang();
					gotoxy(28,27);printf("Ingin Membuat Data Lagi ? Y/N");
					gotoxy(28,28);printf("Jawaban Anda : ");
					getletter(&jawab,1);
				}while(jawab == 'Y' || jawab == 'y');
				break;			
			case 2 : 
				system("cls");
				kotak();
				gotoxy(2,19);printf("Kelola Furniture");
				gotoxy(2,21);printf("1.Tambah Data\n");
				gotoxy(2,22);printf("2.Lihat Data\n");
				gotoxy(2,23);printf("3.Update Data\n");
				gotoxy(2,24);printf("4.Hapus Data\n");
				gotoxy(2,25);printf("5.Kembali\n");
				gotoxy(2,26);printf("6.Logout\n");
				gotoxy(2,27);printf("7.Keluar\n");
				gotoxy(2,28);printf("Pilihan Anda : 2");	
				Baca_Barang();
				getch();
				system("cls");
				break;
			case 3 : 
				do{
					system("cls");
					kotak();
					gotoxy(2,19);printf("Kelola Furniture");
					gotoxy(2,21);printf("1.Tambah Data\n");
					gotoxy(2,22);printf("2.Lihat Data\n");
					gotoxy(2,23);printf("3.Update Data\n");
					gotoxy(2,24);printf("4.Hapus Data\n");
					gotoxy(2,25);printf("5.Kembali\n");
					gotoxy(2,26);printf("6.Logout\n");
					gotoxy(2,27);printf("7.Keluar\n");
					gotoxy(2,28);printf("Pilihan Anda : 3");
					Update_Barang();
					if(gagal_update==1){
						gotoxy(28,24);;printf("Ingin Update Data Lagi ? Y/N");
						gotoxy(28,25);printf("Jawaban Anda : ");
					}else{
						gotoxy(28,44);printf("Ingin Update Data Lagi ? Y/N");
						gotoxy(28,45);printf("Jawaban Anda : ");
					}
					getletter(&jawab,1);
				}while(jawab == 'Y' || jawab == 'y');
				break;
			case 4 : 
				do{
					system("cls");
					kotak();
					gotoxy(2,19);printf("Kelola Furniture");
					gotoxy(2,21);printf("1.Tambah Data\n");
					gotoxy(2,22);printf("2.Lihat Data\n");
					gotoxy(2,23);printf("3.Update Data\n");
					gotoxy(2,24);printf("4.Hapus Data\n");
					gotoxy(2,25);printf("5.Kembali\n");
					gotoxy(2,26);printf("6.Logout\n");
					gotoxy(2,27);printf("7.Keluar\n");
					gotoxy(2,28);printf("Pilihan Anda : 4");
					Hapus_Barang();
					if(gagal_update==1){
						gotoxy(28,24);;printf("Ingin Hapus Data Lagi ? Y/N");
						gotoxy(28,25);printf("Jawaban Anda : ");
					}else{
						gotoxy(28,37);printf("Ingin Hapus Data Lagi ? Y/N");
						gotoxy(28,38);printf("Jawaban Anda : ");
					}
					getletter(&jawab,1);
				}while(jawab == 'Y' || jawab == 'y');
				break;
			case 5 : 
				getch();
				system("cls");
				break;
			case 6 :
				getch();
				system("cls");
				main();
				break;	
			case 7 : 
				getch();
				system("cls");
				exit(0);
				break;	
			default :
				printf("Inputan Tidak Cocok");
				getch();
				system("cls");
			}
		}while(menu!=5);	
}	
