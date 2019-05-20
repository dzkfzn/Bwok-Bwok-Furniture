void MenuMasterKasir();
void kotak();
void gotoxy(int x,int y);
void Baca_Barang();
	
int gagal_update;
	
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
		
		} ArsKasir;
ArsKasir kasir;

	
void Tambah_Kasir()
{
	FILE *fkasir;
	
	fkasir=fopen("lib/kasir.dat","a+b");
	gotoxy(28,18);printf("Buat Akun Kasir");
	gotoxy(28,20);printf("ID\t\t : KSR");
	while(!feof(fkasir))
	{
		fflush(stdin);
		fread(&kasir.ID,sizeof(kasir),1,fkasir);
	}
	kasir.ID++;
	if(kasir.ID<1000)
	{
		kasir.ID=kasir.ID+1000;
	}
	printf("%d",kasir.ID);
	gotoxy(28,21);printf("Nama Lengkap : ");
	gotoxy(28,22);printf("Username\t : "); 
	gotoxy(28,23);printf("Password\t : ");		
	gotoxy(28,24);printf("Alamat\t : ");
	gotoxy(28,25);printf("Nomer Telepon: ");
	gotoxy(28,26);printf("Email\t : ");	
	gotoxy(28,27);printf("TTL\t\t : ");

	gotoxy(43,21);getletter(kasir.nama,30);	
	gotoxy(43,22);getteks(kasir.username,20);
	gotoxy(43,23);getpass(kasir.pass1,20);
	gotoxy(43,24);getteks(kasir.alamat,50);
	gotoxy(43,25);getteksnum(kasir.telp,13);
	gotoxy(43,26);getteks(kasir.email,25);
	gotoxy(43,27);getletter(kasir.lahir,20);printf(",");getnum(&kasir.tgl,2);printf("-");getnum(&kasir.bln,2);printf("-");getnummin(&kasir.thn,4,4);
		
	fwrite(&kasir,sizeof(kasir),1,fkasir);
	fclose(fkasir);
}


void Baca_Kasir()
{	

	FILE *fkasir;
	int a=24;
	
	fkasir = fopen("lib/kasir.dat","rb");
	fread(&kasir,sizeof(kasir),1,fkasir);
	gotoxy(28,21);printf("ID");
	gotoxy(41,21);printf("Nama");
	gotoxy(61,21); printf("Username"); 
	gotoxy(80,21);printf("Password");
	gotoxy(95,21);printf("TTL");
	gotoxy(115,21);printf("Telp");
	gotoxy(130,21);printf("Email");
	gotoxy(150,21);printf("Alamat");
	while (!feof(fkasir))
	{
		gotoxy(28,a);printf("KSR%d",kasir.ID);
		gotoxy(41,a);printf("%s",kasir.nama);
		gotoxy(61,a);printf("%s",kasir.username);
		gotoxy(80,a);printf("%s",kasir.pass1);
		gotoxy(95,a);printf("%s,%d-%d-%d",kasir.lahir,kasir.tgl,kasir.bln,kasir.thn);
		gotoxy(115,a);printf("%s",kasir.telp);
		gotoxy(130,a);printf("%s",kasir.email);
		gotoxy(149,a);printf("%s",kasir.alamat);
		fread(&kasir,sizeof(kasir),1,fkasir);
		a++;
	}
	fclose(fkasir);
}


void Update_Kasir()
{
	
	//DEKLARASI
	 struct ArsKasirBaru{
		char nama[30];
		int id;
		char password[30];
		char email[30];
		char alamat[30];
		char telp[20];
		} kasirbaru;
	FILE *fkasir; 
	FILE *Temp;
	char usernamekasir[30],jawab;
	int menu;
	typedef enum {false = 0, true = 1}bool;
	bool found;
	
	//ALGORITMA
	gotoxy(28,18);printf("Update Data Kasir");
	gotoxy(28,20);printf("Masukkan ID Kasir : KSR");
	getnum(&kasirbaru.id,20);
	gotoxy(28,21);printf("Mencari Data..");
	Sleep(1500);
	fkasir = fopen("lib/kasir.dat","rb");
	Temp = fopen("lib/temp.dat","wb");
	found = false;
	while((!found)&&(!feof(fkasir)))
	{
		fread(&kasir,sizeof(kasir),1,fkasir);	
		if (kasir.ID==kasirbaru.id)
		{
			found = true;
		}
		else
		{
			fwrite(&kasir,sizeof(kasir),1,Temp);
		}			
	}

	if(found == true)
	{
		gagal_update = 0;
		gotoxy(28,23);printf("Data Berhasil Ditemukan");
		gotoxy(28,24);printf("ID			: KSR%d",kasir.ID);
		gotoxy(28,25);printf("Nama		: %s",kasir.nama);
		gotoxy(28,26);printf("username		: %s",kasir.username);
		gotoxy(28,27);printf("Password		: %s",kasir.pass1);
		gotoxy(28,28);printf("Alamat		: %s",kasir.alamat);
		gotoxy(28,29);printf("E-Mail		: %s",kasir.email);
		gotoxy(28,30);printf("Telepon		: %s",kasir.telp);
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
			gotoxy(28,38);printf("Masukkan Password baru : "); getpass(kasirbaru.password,30);
			strcpy (kasir.pass1,kasirbaru.password);fflush(stdin);
			break;
		case 2 :
			gotoxy(28,38);printf("Masukkan Alamat baru : "); getteks(kasirbaru.alamat,50);	
			strcpy (kasir.alamat,kasirbaru.alamat);fflush(stdin);
			break;
		case 3 :
			gotoxy(28,38);printf("Masukkan E-Mail baru :  "); getteks(kasirbaru.email,25);	
			strcpy (kasir.email,kasirbaru.email);fflush(stdin);
			break;	
		case 4 :
			gotoxy(28,38);printf("Masukkan Telepon baru :  "); getteksnummin(kasirbaru.telp,11,13);	
			strcpy (kasir.telp,kasirbaru.telp);fflush(stdin);
			break;	
		case 5 :
			getch();
			system("cls");
			MenuMasterKasir();
			break;
		}
		fwrite(&kasir,sizeof(kasir),1,Temp);
		fread(&kasir,sizeof(kasir),1,fkasir);
		while(!feof(fkasir))
		{
			fread(&kasir,sizeof(kasir),1,fkasir);
			fwrite(&kasir,sizeof(kasir),1,Temp);
		}
		gotoxy(28,39);printf("Loading..");
		Sleep(1500);
		gotoxy(28,40);printf("Sukses Mengupdate Data ");getch();
		/////////////////////
		fclose(fkasir);
		fclose(Temp);
	
		Temp = fopen("lib/temp.dat","rb");
		fkasir = fopen("lib/kasir.dat","wb"); 
		
		fread(&kasir,sizeof(kasir),1,Temp);
		while(!feof(Temp))
		{
			
			fwrite(&kasir,sizeof(kasir),1,fkasir);
			fread(&kasir,sizeof(kasir),1,Temp);
		} 
		
		fclose(fkasir);
		fclose(Temp);
		
		gotoxy(25,40);printf("	Data Berhasil Di Update.");
	}
	else
	{
		gagal_update = 1;
		gotoxy(28,22);printf("Kasir dengan id KSR%d tidak ditemukan di dalam Data Kasir", kasirbaru.id);
		fclose(fkasir);
		fclose(Temp);
	}
	
}
void Hapus_Kasir()
{
	//DEKLARASI
	FILE *Temp;
	char menu;
	int idkasir;
	FILE *fkasir;
	char konfirmasi;
	typedef enum {false = 0, true = 1}bool;
	bool found;
	
	//ALGORITMA
	gotoxy(28,18);printf("Hapus Data Barang");
	gotoxy(28,20);printf("Masukkan ID Kasir yang ingin anda hapus : KSR"); getnum(&idkasir,15);
	fkasir = fopen("lib/kasir.dat","rb");
	Temp = fopen("lib/temp.dat","wb");
	gotoxy(28,21);printf("Mencari Data..");
	Sleep(1500);
	found = false;	
	while((!found)&&(!feof(fkasir)))
	{
		fread(&kasir,sizeof(kasir),1,fkasir);	
		if (kasir.ID==idkasir)
		{
			found = true;
		}
		else
		{
			fwrite(&kasir,sizeof(kasir),1,Temp);
		}			
	}
	
	if(found == true)
	{
		gagal_update = 0;
		gotoxy(28,23);printf("Data Berhasil Ditemukan");
		gotoxy(28,25);printf("ID			: KSR%d",kasir.ID);
		gotoxy(28,26);printf("Nama		: %s",kasir.nama);
		gotoxy(28,27);printf("username		: %s",kasir.username);
		gotoxy(28,28);printf("Password		: %s",kasir.pass1);
		gotoxy(28,29);printf("Alamat		: %s",kasir.alamat);
		gotoxy(28,30);printf("E-Mail		: %s",kasir.email);
		gotoxy(28,31);printf("Telepon		: %s",kasir.telp);
		gotoxy(25,32);printf("Apakah Anda yakin ingin menghapus Data ini ? Y/N : ");
		gotoxy(28,33);printf("Jawaban Anda : ");
		getteks(&konfirmasi,1,2);
		if (konfirmasi=='Y' || konfirmasi == 'y')
		{
			gotoxy(28,34);printf("Menghapus Data..");
			Sleep(1500);
			fread(&kasir,sizeof(kasir),1,fkasir);	//
			while(!feof(fkasir))
			{
				fwrite(&kasir,sizeof(kasir),1,Temp);
				fread(&kasir,sizeof(kasir),1,fkasir);
			}
			fclose(fkasir);
			fclose(Temp);
		
			Temp = fopen("lib/temp.dat","rb");
			fkasir = fopen("lib/kasir.dat","wb"); 
			
			fread(&kasir,sizeof(kasir),1,Temp);
			while(!feof(Temp))
			{
				fwrite(&kasir,sizeof(kasir),1,fkasir);
				fread(&kasir,sizeof(kasir),1,Temp);
			} 
			
			fclose(fkasir);
			fclose(Temp);
			gotoxy(28,35);printf("Data Berhasil Di Hapus! ");
		}
			
	}
	else{ 			
		gagal_update = 1;		
		gotoxy(28,23);printf("Data Tidak Ditemukan");
		fclose(fkasir);
		fclose(Temp);
		getch();
	}

}

void MenuMasterKasir()
{
	int menu;
	char jawab;
	do{
				getch();
				system("cls");
				kotak();
				gotoxy(2,18);printf("Kelola Akun Kasir");			
				gotoxy(2,20);printf("1.Tambah Akun Kasir");
				gotoxy(2,21);printf("2.Lihat Data Kasir");
				gotoxy(2,22);printf("3.Update Data Kasir");
				gotoxy(2,23);printf("4.Hapus Kasir");
				gotoxy(2,24);printf("5.Kembali");
				gotoxy(2,25);printf("6.Logout\n");
				gotoxy(2,26);printf("7.Keluar\n");
				gotoxy(2,27);printf("Pilihan Anda : ");
				getnum(&menu,1);
					switch(menu)
					{
					case 1 :
						do{
							getch();
							system("cls");
							kotak();
							gotoxy(2,19);printf("Kelola Kasir");
							gotoxy(2,21);printf("1.Tambah Data\n");
							gotoxy(2,22);printf("2.Lihat Data\n");
							gotoxy(2,23);printf("3.Update Data\n");
							gotoxy(2,24);printf("4.Hapus Data\n");
							gotoxy(2,25);printf("5.Kembali\n");
							gotoxy(2,26);printf("6.Logout\n");
							gotoxy(2,27);printf("7.Keluar\n");
							gotoxy(2,28);printf("Pilihan Anda : 1");
							Tambah_Kasir();
							gotoxy(28,28);printf("Ingin Membuat Data Lagi ? Y/N");
							gotoxy(28,29);printf("Jawaban Anda : ");
							getletter(&jawab,1);
							}while(jawab == 'Y' || jawab == 'y');
						break;
					case 2 : 
						system("cls");
						kotak();
						gotoxy(2,19);printf("Kelola Kasir");
						gotoxy(2,21);printf("1.Tambah Data\n");
						gotoxy(2,22);printf("2.Lihat Data\n");
						gotoxy(2,23);printf("3.Update Data\n");
						gotoxy(2,24);printf("4.Hapus Data\n");
						gotoxy(2,25);printf("5.Kembali\n");
						gotoxy(2,26);printf("6.Logout\n");
						gotoxy(2,27);printf("7.Keluar\n");
						gotoxy(2,28);printf("Pilihan Anda : 2");
						Baca_Kasir();
						getch();
						break;
					case 3 : 
						do{
							getch();
							system("cls");
							kotak();
							gotoxy(2,19);printf("Kelola Kasir");
							gotoxy(2,21);printf("1.Tambah Data\n");
							gotoxy(2,22);printf("2.Lihat Data\n");
							gotoxy(2,23);printf("3.Update Data\n");
							gotoxy(2,24);printf("4.Hapus Data\n");
							gotoxy(2,25);printf("5.Kembali\n");
							gotoxy(2,26);printf("6.Logout\n");
							gotoxy(2,27);printf("7.Keluar\n");
							gotoxy(2,28);printf("Pilihan Anda : 3");
							Update_Kasir();
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
							Hapus_Kasir();						
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
						exit (0);
						break;		
					default :
						printf("Inputan Tidak Cocok");
						getch();
						system("cls");
					}
				}while(menu!=5);
}

void info_kasir(char username_kasir[20])
{
	FILE *info_kasir;
	FILE *fkasir;
	typedef struct {
		int ID;
		char nama[40];
	}infokasir;
	infokasir ikasir;
	
	info_kasir = fopen("lib/info_kasir.dat","wb");
	fkasir = fopen("lib/kasir.dat","rb");
	
	fread(&kasir,sizeof(kasir),1,fkasir);
	while (!feof(fkasir))
	{
		if ((strcmp(username_kasir,kasir.username))==0)
		{
			ikasir.ID = kasir.ID;
			strcpy(ikasir.nama,kasir.nama);
			fwrite(&ikasir,sizeof(ikasir),1,info_kasir);
			break;
		}
	fread(&kasir,sizeof(kasir),1,fkasir);
	}
	fclose(fkasir);
	fclose(info_kasir);
}
