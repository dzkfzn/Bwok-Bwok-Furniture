
//void kotak();
void Tulis_Riwayat_Kurir();
void Antar();
void gotoxy(int x,int y);
void kotak_tanpa_bawah();
void Laporan_Bulanan();
void Laporan_Tahunan();
void MenuMasterKasir();
void MenuMasterBarang();
void MenuMasterKurir();
void Menu_Kasir();
void Menu_Admin();
void Menu_Manager();
void Baca_Barang();
void Beli_Barang_Kasir();
void Keranjang_Barang();
void Laporan_Barang();
void info_kasir(char username_kasir[20]);
void info_kurir(char username_kurir[20]);
void Cetak_Struk();
void Bayar();
void Menu_Kurir();
void Cetak_Riwayat_Transaksi();
void Riwayat_Transaksi();
void Cetak_List_Antar_Barang();
void Hapus_Keranjang_Barang();
void Sedang_Di_Antar();

void login()
{

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
		
		} Ars;
	Ars ArsipKasir;
	Ars ArsipKurir;

	FILE *fkurir;
	FILE *fkasir;
	char no[40];
	char user[40];
	char password[40];
	int sukses;
	int hasil,hasil_1;
	int kasir,kurir;
	typedef enum {false = 0, true = 1}bool;
	bool found;
	
	sukses=0;
	fkasir = fopen("lib/kasir.dat","rb");
	fkurir = fopen("lib/kurir.dat","rb");
	system("cls");
	kotak();
	gotoxy(2,19);printf("Login");
	gotoxy(2,21);printf("Username : ");
	gotoxy(2,22);printf("Password : ");

	gotoxy(15,21);getteks(user,20);	
	gotoxy(15,22);getpass(password,20);
	while(!found && !feof(fkasir) && !feof(fkurir))
	{
		fread(&ArsipKurir, sizeof(ArsipKurir), 1, fkurir);
		fread(&ArsipKasir, sizeof(ArsipKasir), 1, fkasir);
		hasil = strcmp(ArsipKasir.username,user);
		kasir = strcmp(ArsipKasir.pass1,password);
		hasil_1 = strcmp(ArsipKurir.username,user);
		kurir = strcmp(ArsipKurir.pass1,password);
		
			if(strcmp(user,"ADMIN")==0 && strcmp(password,"ADMIN")==0)
			{
				sukses = 2;
				break;
			}
			else if(hasil== 0 && kasir == 0)
			{
				sukses = 1;
				info_kasir(user);
				break;
			}
			else if(strcmp(user,"manager")==0 && strcmp(password,"tojak")==0)
			{
				sukses = 3;
				break;
			}
			else if(hasil_1== 0 && kurir == 0)
			{
				sukses = 4;
				info_kurir(user);
				break;
			}
	}
		if(sukses == 1)
		{
			gotoxy(2,24);printf ("log in as kasir  ");
			getch();
			system("cls");
			Menu_Kasir();
			getch();
		}
		if(sukses == 2)
		{
			
			gotoxy(2,24);printf ("Log in as admin  ");
			getch();
			system("cls");
			Menu_Admin();
			getch();
		}
		if(sukses == 3)
		{
		    gotoxy(2,24);printf ("log in as manager  \n");
		    getch();
		    system("cls");
		    Menu_Manager();
			getch();
		}
		if(sukses == 4)
		{
		 	gotoxy(2,24);printf ("log in as kurir  \n");
		    getch();
		    system("cls");
		    Menu_Kurir();
			getch();
		}
		else if(sukses != 3 && sukses != 2 && sukses != 1 && sukses!= 4 )
		{
			gotoxy(2,24);printf ("Log in gagal  ");
			getch();
			system("cls");
		}
		fclose(fkasir);
		fclose(fkurir);
}

void Menu_Kasir()
{	
	int NomorMenu;
	char konfirmasi;
	char jawab;
	
do{
	system("cls");	
	kotak();
	gotoxy(2,19);printf("Menu Kasir");
	gotoxy(2,21);printf("1.Beli Barang");
	gotoxy(2,22);printf("2.Bayar\n");
	gotoxy(2,23);printf("3.Riwayat Transaksi");
	gotoxy(2,24);printf("4.Logout\n");
	gotoxy(2,25);printf("5.Keluar\n");
	gotoxy(1,27);printf("Pilih Menu diatas : ");getnum(&NomorMenu,1);
	switch (NomorMenu){
		case 1 : 
		do{
		
			system("cls");	
			kotak();
			gotoxy(2,19);printf("Menu Kasir");
			gotoxy(2,21);printf("1.Beli Barang");
			gotoxy(2,22);printf("2.Bayar\n");
			gotoxy(2,23);printf("3.Riwayat Transaksi");
			gotoxy(2,24);printf("4.Logout\n");
			gotoxy(2,25);printf("5.Keluar\n");
			gotoxy(1,27);printf("Pilih Menu diatas : 1");
			Baca_Barang();
			system("cls");
			kotak();
			gotoxy(2,19);printf("Menu Kasir");
			gotoxy(2,21);printf("1.Beli Barang");
			gotoxy(2,22);printf("2.Bayar\n");
			gotoxy(2,23);printf("3.Riwayat Transaksi");
			gotoxy(2,24);printf("4.Logout\n");
			gotoxy(2,25);printf("5.Keluar\n");
			gotoxy(1,27);printf("Pilih Menu diatas : 1");
			Beli_Barang_Kasir(); 
		
				gotoxy(28,31);printf("Ingin Tambah Belanjaan ? Y/N");
				gotoxy(28,32);printf("Jawaban Anda : ");
			
			getletter(&jawab,1);
			}while(jawab == 'Y' || jawab == 'y');
			break ;
		case 2 : 
				
			do{
				system("cls");	
				kotak();
				Keranjang_Barang();
				gotoxy(2,19);printf("Bayar");
				gotoxy(2,21);printf("1.Lanjut Bayar");
				gotoxy(2,22);printf("2.Hapus Keranjang\n");
				gotoxy(2,23);printf("3.Kembali");
				gotoxy(2,24);printf("Pilihan Anda : ");getnum(&NomorMenu,1);
				switch (NomorMenu)
				{
					case 1 : 
						gotoxy(2,19);printf("Bayar");
						gotoxy(2,21);printf("1.Lanjut Bayar");
						gotoxy(2,22);printf("2.Hapus Keranjang\n");
						gotoxy(2,23);printf("3.Kembali");
						gotoxy(2,24);printf("Pilihan Anda : 1");
						Bayar();
						kotak();
						gotoxy(2,19);printf("Bayar");
						gotoxy(2,21);printf("1.Lanjut Bayar");
						gotoxy(2,22);printf("2.Hapus Keranjang\n");
						gotoxy(2,23);printf("3.Kembali");
						gotoxy(2,24);printf("Pilihan Anda : 1");
						getch();
						system("cls");
						kotak();
						gotoxy(2,19);printf("Bayar");
						gotoxy(2,21);printf("1.Lanjut Bayar");
						gotoxy(2,22);printf("2.Hapus Keranjang\n");
						gotoxy(2,23);printf("3.Kembali");
						gotoxy(2,24);printf("Pilihan Anda : 1");
						Cetak_Struk();
						getch();
						system("cls");
						Riwayat_Transaksi();								
						break ;
					case 2 :
						getch();
						system("cls");
						Keranjang_Barang();
						Hapus_Keranjang_Barang();
						break; 
				}
			}while(NomorMenu==3);
			break ;
			
		case 3 : 
			system("cls");
			gotoxy(2,19);printf("Menu Kasir");
			gotoxy(2,21);printf("1.Beli Barang");
			gotoxy(2,22);printf("2.Bayar\n");
			gotoxy(2,23);printf("3.Riwayat Transaksi");
			gotoxy(2,24);printf("4.Logout\n");
			gotoxy(2,25);printf("5.Keluar\n");
			gotoxy(1,27);printf("Pilih Menu diatas : 3");
			kotak_tanpa_bawah(); 
			Cetak_Riwayat_Transaksi();
			
			break;
		case 4 : 	getch();system("cls");main(); break;
		case 5 : 
			gotoxy(28,20);printf("terimakasi telah memakai program ini\n");getch(); exit(0);
		}
		getch();
		system("cls");
	}while(NomorMenu != 5);
	

}
void Menu_Manager()
{	
	int NomorMenu;
	
	do{
	system("cls");
	kotak();
	gotoxy(2,19);printf("Menu Manager");
	gotoxy(2,21);printf("1.Riwayat Penjualan");
	gotoxy(2,22);printf("2.Laporan Keuangan");
	gotoxy(2,23);printf("3.Kembali");
	gotoxy(2,24);printf("4.Logout");
	gotoxy(2,25);printf("5.Keluar");
	gotoxy(2,26);printf("Pilihan Anda : ");getnum(&NomorMenu,1);
	while(NomorMenu==5);
	switch (NomorMenu){
		case 1 : Cetak_Riwayat_Transaksi(); break ;
		case 2 : 
		do{
			system("cls");
			kotak();
			gotoxy(2,19);printf("Laporan Keuangan");
			gotoxy(2,21);printf("1.Laporan Tahunan");
			gotoxy(2,22);printf("2.Laporan Bulnan");
			gotoxy(2,23);printf("3.Kembali");
			gotoxy(2,24);printf("Pilih Menu diatas : ");getnum(&NomorMenu,1);
			switch (NomorMenu){
				case 1 :
					Laporan_Tahunan();
					break;
				case 2 :
					Laporan_Bulanan();
					break;
				case 3 :
					getch();
					system("cls");
					break;
				default :
					gotoxy(2,25);printf("Inputan Error");
					break;		
			}
			}while(NomorMenu != 3);
			
			break ;
		case 3 : 
			getch();
			system("cls");
			break;
		case 4 : 
			getch();system("cls");main(); break;
		case 5 :
			gotoxy(28,20);printf("terimakasi telah memakai program ini\n");getch(); exit(0); break;
			
			
		}
		getch();
		system("cls");
	}while(NomorMenu != 4);
}

void Menu_Admin()
{
	//DEC
	int menu;
	
	//ALGORITMA
	do{
		system("cls");
		kotak();
		gotoxy(2,19);printf("Menu Admin");	
		gotoxy(2,21);printf("1.Kelola Kasir");
		gotoxy(2,22);printf("2.Kelola Furniture");
		gotoxy(2,23);printf("3.Kelola Kurir");
		gotoxy(2,24);printf("4.Riwayat Transaksi");
		gotoxy(2,25);printf("5.Kembali");
		gotoxy(2,26);printf("6.Keluar");
		gotoxy(2,27);printf("Pilihan Anda : ");
		getnum(&menu,1);
		switch(menu)
		{
			case 1 :
				MenuMasterKasir();
				break;
			case 2 :
				MenuMasterBarang();
				break;
			case 3 :
				MenuMasterKurir();
				break;
			case 4 :
				Cetak_Riwayat_Transaksi();
				break;
			case 5 :
				getch();
				system("cls");
				break;
				break;
			case 6 :
				exit(0);
				break;	
		}
	}while(menu!=5);
}

void Menu_Kurir()
{	
	int NomorMenu;
	
	do{
	system("cls");
	kotak();
	gotoxy(2,19);printf("Menu Kurir");
	gotoxy(2,21);printf("1.Antar Barang");
	gotoxy(2,22);printf("2.Riwayat Antar");
	gotoxy(2,23);printf("3.Logout");
	gotoxy(2,24);printf("4.Keluar");
	gotoxy(2,25);printf("Pilihan Anda : ");getnum(&NomorMenu,1);
	switch (NomorMenu){
		case 1 :  
			system("cls");
			kotak();
			gotoxy(2,19);printf("Menu Kurir");
			gotoxy(2,21);printf("1.Antar Barang");
			gotoxy(2,23);printf("2.Riwayat Antar");
			gotoxy(2,24);printf("3.Logout");
			gotoxy(2,25);printf("4.Keluar");
			gotoxy(2,26);printf("Pilihan Anda : 1");
			Cetak_List_Antar_Barang();
			getch();
			system("cls");
			
			kotak();
			gotoxy(2,19);printf("Menu Kurir");
			gotoxy(2,21);printf("1.Antar Barang");
			gotoxy(2,23);printf("2.Riwayat Antar");
			gotoxy(2,24);printf("3.Logout");
			gotoxy(2,25);printf("4.Keluar");
			gotoxy(2,26);printf("Pilihan Anda : 1");
			Antar();
			break ;
		case 2 : 
			Tulis_Riwayat_Kurir();
			break ;
		case 3 : system("cls");
			kotak();getch(); main(); break ;
		case 4 :  printf("terimakasi telah memakai program ini\n");getch(); exit(0);
		}
		getch();
		system("cls");
	}while(NomorMenu != 4);
}

