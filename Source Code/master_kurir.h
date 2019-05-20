
void gotoxy(int x,int y);
void kotak();
void MenuMasterKurir();

//void Baca_Barang();
	

	
	 typedef struct {
		int ID;
		char nama[40];
		char username[40];
		char pass1 [40];
		char pass2 [40];
		char alamat [40];
		char telp[20];
		char lahir[40];
		int tgl;
		int bln;
		int thn;
		char email[25];
		
		} ArsKurir;
ArsKurir kurir;
int gagal_update;

	
	
void Tambah_Kurir()
{
	FILE *fkurir;
	
	fkurir=fopen("lib/kurir.dat","a+b");
	
	gotoxy(28,18);printf("Buat Data Barang");
	gotoxy(28,20);printf("ID 	: COUR");
	while(!feof(fkurir))
	{
		fflush(stdin);
		fread(&kurir.ID,sizeof(kurir),1,fkurir);
	}
	kurir.ID++;
	if(kurir.ID<1000)
	{
		kurir.ID=kurir.ID+1000;
	}
	printf("%d",kurir.ID);
	gotoxy(28,21);printf("Nama Lengkap : ");
	gotoxy(28,22);printf("Username\t : "); 
	gotoxy(28,23);printf("Password\t : ");		
	gotoxy(28,24);printf("Alamat\t : ");
	gotoxy(28,25);printf("Nomer Telepon: ");
	gotoxy(28,26);printf("Email\t : ");	
	gotoxy(28,27);printf("TTL\t\t : ");

	gotoxy(43,21);getletter(kurir.nama,30);	
	gotoxy(43,22);getteks(kurir.username,20);
	gotoxy(43,23);getpass(kurir.pass1,20);
	gotoxy(43,24);getteks(kurir.alamat,50);
	gotoxy(43,25);getteksnum(kurir.telp,13);
	gotoxy(43,26);getteks(kurir.email,25);
	gotoxy(43,27);getletter(kurir.lahir,20);printf(",");getnum(&kurir.tgl,2);printf("-");getnum(&kurir.bln,2);printf("-");getnummin(&kurir.thn,4,4);

	fwrite(&kurir,sizeof(kurir),1,fkurir);
	fclose(fkurir);
}


void Baca_Kurir()
{	

	FILE *fkurir;
	int i;
	int a=24;
	fkurir = fopen("lib/kurir.dat","rb");
	fread(&kurir,sizeof(kurir),1,fkurir);
	gotoxy(28,21);printf("ID");
	gotoxy(41,21);printf("Nama");
	gotoxy(61,21); printf("Username"); 
	gotoxy(80,21);printf("Password");
	gotoxy(95,21);printf("TTL");
	gotoxy(115,21);printf("Telp");
	gotoxy(130,21);printf("Email");
	gotoxy(150,21);printf("Alamat");
	
	while (!feof(fkurir))
	{
	gotoxy(28,a);printf("KSR%d",kurir.ID);
	gotoxy(41,a);printf("%s",kurir.nama);
	gotoxy(61,a);printf("%s",kurir.username);
	gotoxy(80,a);printf("%s",kurir.pass1);
	gotoxy(95,a);printf("%s,%d-%d-%d",kurir.lahir,kurir.tgl,kurir.bln,kurir.thn);
	gotoxy(115,a);printf("%s",kurir.telp);
	gotoxy(130,a);printf("%s",kurir.email);
	gotoxy(149,a);printf("%s",kurir.alamat);
	fread(&kurir,sizeof(kurir),1,fkurir);
	a++;
	}
	fclose(fkurir);
}




void Update_Kurir()
{
	
	//DEKLARASI
	 struct ArsKurirBaru{
		char nama[30];
		int id;
		char password[30];
		char email[30];
		char alamat[30];
		char telp[20];
		} kurirbaru;
	FILE *fkurir; 
	FILE *Temp;
	char usernamekurir[30];
	int menu;
	typedef enum {false = 0, true = 1}bool;
	bool found;
	
	//ALGORITMA
	gotoxy(28,18);printf("Update Data Kurir");
	gotoxy(28,20);printf("Masukkan ID Kurir : COUR");
	getnum(&kurirbaru.id,20);
	gotoxy(28,21);printf("Mencari Data..");
	Sleep(1500);
	
	fkurir = fopen("lib/kurir.dat","rb");
	Temp = fopen("lib/temp.dat","wb");
	found = false;
	while((!found)&&(!feof(fkurir)))
	{
		fread(&kurir,sizeof(kurir),1,fkurir);	
		if (kurir.ID==kurirbaru.id)
		{
			found = true;
		}
		else
		{
			fwrite(&kurir,sizeof(kurir),1,Temp);
		}			
	}
	
	if(found == true)
	{
		gagal_update = 0;
		gotoxy(28,23);printf("Data Berhasil Ditemukan");
		gotoxy(28,24);printf("ID			: COUR%d",kurir.ID);
		gotoxy(28,25);printf("Nama		: %s",kurir.nama);
		gotoxy(28,26);printf("username		: %s",kurir.username);
		gotoxy(28,27);printf("Password		: %s",kurir.pass1);
		gotoxy(28,28);printf("Alamat		: %s",kurir.alamat);
		gotoxy(28,29);printf("E-Mail		: %s",kurir.email);
		gotoxy(28,30);printf("Telepon		: %s",kurir.telp);
		gotoxy(28,31);printf("Data Mana yang Akan Anda edit : ");
		gotoxy(28,32);printf("1.password");
		gotoxy(28,33);printf("2.alamat");
		gotoxy(28,34);printf("3.E-mail");
		gotoxy(28,35);printf("4.Telepon");
		gotoxy(28,36);printf("5.Batal");
		gotoxy(28,37);printf("Menu yang diinginkan : ");

		getnum(&menu,1);
		fflush(stdin);
		switch(menu)
		{
		
		case 1 :
			gotoxy(28,38);printf("Masukkan Password baru : "); getpass(kurirbaru.password,30);
			strcpy (kurir.pass1,kurirbaru.password);fflush(stdin);
			break;
		case 2 :
			gotoxy(28,38);printf("Masukkan Alamat baru : "); getteks(kurirbaru.alamat,50);	
			strcpy (kurir.alamat,kurirbaru.alamat);fflush(stdin);
			break;
		case 3 :
			gotoxy(28,38);printf("Masukkan E-Mail baru :  "); getteks(kurirbaru.email,25);	
			strcpy (kurir.email,kurirbaru.email);fflush(stdin);
			break;	
		case 4 :
			gotoxy(28,38);printf("Masukkan Telepon baru :  "); getteksnummin(kurirbaru.telp,11,13);	
			strcpy (kurir.telp,kurirbaru.telp);fflush(stdin);
			break;
		case 5 :
			getch();
			system("cls");
			MenuMasterKurir();
			break;		
		}
		fwrite(&kurir,sizeof(kurir),1,Temp);
		fread(&kurir,sizeof(kurir),1,fkurir);
		while(!feof(fkurir))
		{
			fread(&kurir,sizeof(kurir),1,fkurir);
			fwrite(&kurir,sizeof(kurir),1,Temp);
		}
		gotoxy(28,39);printf("Loading..");
		Sleep(1500);
		gotoxy(28,40);printf("Sukses Mengupdate Data ");getch();
		
		//////////
		fclose(fkurir);
		fclose(Temp);
	
		Temp = fopen("lib/temp.dat","rb");
		fkurir = fopen("lib/kurir.dat","wb"); 
		
		fread(&kurir,sizeof(kurir),1,Temp);
		while(!feof(Temp))
		{
			fwrite(&kurir,sizeof(kurir),1,fkurir);
			fread(&kurir,sizeof(kurir),1,Temp);
		} 
		
		fclose(fkurir);
		fclose(Temp);
		
		gotoxy(25,40);printf("Data Berhasil Di Update.");
		}else
	{
		gagal_update = 1;
		gotoxy(28,22);printf("Kurir dengan ID COUR%d tidak ditemukan di dalam Data Kurir", kurirbaru.id);
		fclose(fkurir);
		fclose(Temp);
	}
}
void Hapus_Kurir()
{
	//DEKLARASI
	FILE *Temp;
	char usernamekurir[30],menu;
	FILE *fkurir;
	int idkurir;
//	char namabaru[30],jenisbaru[30],supplierbaru[30];
//	int stockbaru,hargabaru;
	char konfirmasi;
	typedef enum {false = 0, true = 1}bool;
	bool found;
	
	//ALGORITMA
	gotoxy(28,18);printf("Hapus Data Barang");
	gotoxy(28,20);printf("Masukkan ID Kurir yang ingin anda hapus  : COUR"); getnum(&idkurir,15);
	fkurir = fopen("lib/kurir.dat","rb");
	Temp = fopen("lib/temp.dat","wb");
	found = false;	
	while((!found)&&(!feof(fkurir)))
	{
		fread(&kurir,sizeof(kurir),1,fkurir);	
		if (kurir.ID==idkurir)
		{
			found = true;
		}
		else
		{
			fwrite(&kurir,sizeof(kurir),1,Temp);
		}			
	}
	
	if(found == true)
	{
		gagal_update = 0;
		gotoxy(28,23);printf("Data Berhasil Ditemukan");
		gotoxy(28,25);printf("ID			: KSR%d",kurir.ID);
		gotoxy(28,26);printf("Nama		: %s",kurir.nama);
		gotoxy(28,27);printf("username		: %s",kurir.username);
		gotoxy(28,28);printf("Password		: %s",kurir.pass1);
		gotoxy(28,29);printf("Alamat		: %s",kurir.alamat);
		gotoxy(28,30);printf("E-Mail		: %s",kurir.email);
		gotoxy(28,31);printf("Telepon		: %s",kurir.telp);
		gotoxy(25,32);printf("Apakah Anda yakin ingin menghapus Data ini ? Y/N : ");
		gotoxy(28,33);printf("Jawaban Anda : ");
		getteks(&konfirmasi,1,2);
		if (konfirmasi=='Y' || konfirmasi == 'y')
		{
			gotoxy(28,34);printf("Menghapus Data..");
			Sleep(1500);
			fread(&kurir,sizeof(kurir),1,fkurir);	//
			while(!feof(fkurir))
			{
				fwrite(&kurir,sizeof(kurir),1,Temp);
				fread(&kurir,sizeof(kurir),1,fkurir);
			}
			fclose(fkurir);
			fclose(Temp);
		
			Temp = fopen("lib/temp.dat","rb");
			fkurir = fopen("lib/kurir.dat","wb"); 
			
			fread(&kurir,sizeof(kurir),1,Temp);
			while(!feof(Temp))
			{
				fwrite(&kurir,sizeof(kurir),1,fkurir);
				fread(&kurir,sizeof(kurir),1,Temp);
			} 
			
			fclose(fkurir);
			fclose(Temp);
			gotoxy(28,35);printf("	Data Berhasil Di Hapus! ");
		}
			
	}
	else{
		gagal_update = 1;		
		gotoxy(28,23);printf("Data Tidak Ditemukan");
		fclose(fkurir);
		fclose(Temp);
		getch();
	}

}

void MenuMasterKurir()
{
	int menu;
	char jawab;
	do{
				getch();
				system("cls");
				kotak();
				gotoxy(2,18);printf("Kelola Akun Kurir");
				gotoxy(2,20);printf("1.Tambah Akun Kurir");
				gotoxy(2,21);printf("2.Lihat Data Kurir");
				gotoxy(2,22);printf("3.Update Data Kurir");
				gotoxy(2,23);printf("4.Hapus Kurir");
				gotoxy(2,24);printf("5.Kembali");
				gotoxy(2,25);printf("6.Logout");
				gotoxy(2,26);printf("7.Keluar");
				gotoxy(2,27);printf("Pilihan Anda : ");
				getnum(&menu,1);
					switch(menu)
					{
					case 1 :
						do{
							getch();
							system("cls");
							kotak();
							gotoxy(2,19);printf("Kelola Kurir");
							gotoxy(2,21);printf("1.Tambah Data\n");
							gotoxy(2,22);printf("2.Lihat Data\n");
							gotoxy(2,23);printf("3.Update Data\n");
							gotoxy(2,24);printf("4.Hapus Data\n");
							gotoxy(2,25);printf("5.Kembali\n");
							gotoxy(2,26);printf("6.Logout\n");
							gotoxy(2,27);printf("7.Keluar\n");
							gotoxy(2,28);printf("Pilihan Anda : 1");
							Tambah_Kurir();
							gotoxy(28,28);printf("Ingin Membuat Data Lagi ? Y/N");
							gotoxy(28,29);printf("Jawaban Anda : ");
							getletter(&jawab,1);
							}while(jawab == 'Y' || jawab == 'y');
						break;
					case 2 : 
						system("cls");
						kotak();
						gotoxy(2,19);printf("Kelola Kurir");
						gotoxy(2,21);printf("1.Tambah Data\n");
						gotoxy(2,22);printf("2.Lihat Data\n");
						gotoxy(2,23);printf("3.Update Data\n");
						gotoxy(2,24);printf("4.Hapus Data\n");
						gotoxy(2,25);printf("5.Kembali\n");
						gotoxy(2,26);printf("6.Logout\n");
						gotoxy(2,27);printf("7.Keluar\n");
						gotoxy(2,28);printf("Pilihan Anda : 2");
						Baca_Kurir();
						getch();
						system("cls");
						break;
					case 3 : 
						do{
							getch();
							system("cls");
							kotak();
							gotoxy(2,19);printf("Kelola Kurir");
							gotoxy(2,21);printf("1.Tambah Data\n");
							gotoxy(2,22);printf("2.Lihat Data\n");
							gotoxy(2,23);printf("3.Update Data\n");
							gotoxy(2,24);printf("4.Hapus Data\n");
							gotoxy(2,25);printf("5.Kembali\n");
							gotoxy(2,26);printf("6.Logout\n");
							gotoxy(2,27);printf("7.Keluar\n");
							gotoxy(2,28);printf("Pilihan Anda : 3");
							Update_Kurir();
							if(gagal_update==1){
								gotoxy(28,24);;printf("Ingin Update Data Lagi ? Y/N");
								gotoxy(28,25);printf("Jawaban Anda : ");
							}else{
								gotoxy(28,42);printf("Ingin Update Data Lagi ? Y/N");
								gotoxy(28,43);printf("Jawaban Anda : ");
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
							Hapus_Kurir();						
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

void info_kurir(char username_kurir[20])
{
	FILE *info_kurir;
	FILE *fkurir;
	typedef struct {
		int ID;
		char nama[40];
	}infokurir;
	infokurir ikurir;
	
	info_kurir = fopen("lib/info_kurir.dat","wb");
	fkurir = fopen("lib/kurir.dat","rb");
	
	fread(&kasir,sizeof(kurir),1,fkurir);
	while (!feof(fkurir))
	{
		if ((strcmp(username_kurir,kurir.username))==0)
		{
			ikurir.ID = kurir.ID;
			strcpy (ikurir.nama,kurir.nama);
			fwrite(&ikurir,sizeof(ikurir),1,info_kurir);
			break;
		}
	fread(&kurir,sizeof(kurir),1,fkurir);
	}
	fclose(fkurir);
	fclose(info_kurir);
}

