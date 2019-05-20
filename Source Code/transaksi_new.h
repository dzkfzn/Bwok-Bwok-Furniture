void Riwayat_Transaksi();
void Beli_Barang_Kasir();
void Menu_Kasir();
void List_Antar_Barang();

int Global_Total_Tagihan;
int GlobalKonfirmasiBeli=0;
int GlobalKonfirmasiKurir=0;
int Global_uang_customer,Global_kembalian,Global_Total_Berat;

void Bayar()
{
	FILE *fkbarang;
	FILE *Alkur;
	
	char alamat_tujuan[20];
	char konfirmasi_kurir;
	Global_Total_Tagihan=0;
	Global_uang_customer=0;
	Global_kembalian=0;
	Global_Total_Berat=0;
	
	//DEKLARASI BARANG
	typedef struct {
			int ID;
			char nama[30];
			int stock;
			int harga;
			int berat;
			} BeliBarang;
	BeliBarang KeranjangBarang;
	char konfirmasi;
	
	//ALOGIRTMAAAAAAA

	fkbarang = fopen("lib/kbarang.dat","rb");
	Alkur = fopen("lib/alkur.dat","wb");

	
	fread(&KeranjangBarang,sizeof(KeranjangBarang),1,fkbarang);
	while (!feof(fkbarang))
	{	
		Global_Total_Tagihan = Global_Total_Tagihan + KeranjangBarang.harga;
		Global_Total_Berat = Global_Total_Berat + KeranjangBarang.berat;
		fflush(stdin);
		fread(&KeranjangBarang,sizeof(KeranjangBarang),1,fkbarang);
	}
	
	
	gotoxy(120,40);printf("Total : Rp %d",Global_Total_Tagihan);
	gotoxy(95,40);printf("Total : %d KG",Global_Total_Berat);
	gotoxy(25,35);printf("Apakah Anda Ingin Mengirim Barang Dengan Kurir ? Y/N");
	gotoxy(25,36);printf("Jawaban Anda : ");getletter(&konfirmasi_kurir,1);
	if(konfirmasi_kurir=='Y' || konfirmasi_kurir=='y')
	{
		gotoxy(25,37);printf("Masukkan Alamat Tujuan : ");getteks(alamat_tujuan,20);
		fwrite(&alamat_tujuan,sizeof(alamat_tujuan),1,Alkur);
		
		
		gotoxy(25,38);printf("Apakah Anda Yakin ingin tetap melanjutkan ? Y/N : ");getteks(&konfirmasi_kurir,1);
		gotoxy(25,39);if(konfirmasi_kurir=='Y' || konfirmasi_kurir=='y')
		{
			GlobalKonfirmasiKurir=1;
			if(Global_Total_Berat<100)
			{
				gotoxy(120,41);printf("<100 KG = Rp 50.000");
				Global_Total_Tagihan=Global_Total_Tagihan+50000;
			}else if(Global_Total_Berat>=100 && Global_Total_Berat<200)
			{
				
				gotoxy(120,41);printf("100-200 KG = Rp 100.000");
				Global_Total_Tagihan=Global_Total_Tagihan+100000;
			}else if(Global_Total_Berat>=200 && Global_Total_Berat<300)
			{
				gotoxy(120,41);printf("200-300 KG = Rp 150.000");
				Global_Total_Tagihan=Global_Total_Tagihan+150000;
			}else if((Global_Total_Berat>=300 && Global_Total_Berat<500))
			{
				gotoxy(120,41);printf("300-500 KG = Rp 200.000");
				Global_Total_Tagihan=Global_Total_Tagihan+200000;
			}else {
				gotoxy(120,41);printf("500++ KG = Rp 250.000");
				Global_Total_Tagihan=Global_Total_Tagihan+250000;
			}	
		fclose(Alkur);
		List_Antar_Barang();
		}
		gotoxy(120,42);printf("Total : Rp %d",Global_Total_Tagihan);
		
	}
	do{
		gotoxy(120,43);printf("Tunai : Rp "); getnum(&Global_uang_customer,15);
		if(Global_Total_Tagihan>Global_uang_customer){
			gotoxy(25,44);printf("Uang Tidak Mencukupi");
			gotoxy(25,45);printf("Silahkan Input Kembali");
		}
	}while(Global_Total_Tagihan>Global_uang_customer);

	Global_kembalian = Global_uang_customer-Global_Total_Tagihan;
	gotoxy(120,44);printf("Return : Rp %d",Global_kembalian);
	fclose(fkbarang);
	Riwayat_Transaksi();	
}




void Keranjang_Barang()
{
	int i;
	i=0;
	int a = 24;
	FILE *fkbarang;
	FILE *info_kasir;
		typedef struct {
			int ID;
			char nama[30];
			int stock;
			int harga;
			int berat;
			} BeliBarang;
	BeliBarang KeranjangBarang;
		
	typedef struct {
		int ID;
		char nama[40];
	}infokasir;
	infokasir ikasir;
	
	fkbarang = fopen("lib/kbarang.dat","rb");
	info_kasir = fopen("lib/info_kasir.dat","rb");
	kotak();
//	printFile("txt/PRG1.txt",4,20);
	if(GlobalKonfirmasiBeli==0)
	{
		gotoxy(25,18);printf("Keranjang Barang Kosong!");
		getch();
		system("cls");
		Menu_Kasir();
	}
	
	fread(&ikasir,sizeof(ikasir),1,info_kasir);
	fread(&KeranjangBarang,sizeof(KeranjangBarang),1,fkbarang);
//	printf("\nID Kasir		: KSR%d\n",ikasir.ID);
	gotoxy(28,18);printf("Keranjang Barang");
	gotoxy(120,18);printf("Nama Kasir		: %s",ikasir.nama);
	gotoxy(28,20);printf("No");
	gotoxy(41,20);printf("ID");
	gotoxy(61,20); printf("Nama"); 
	gotoxy(80,20);printf("Jumlah");
	gotoxy(95,20);printf("Total Berat(KG)");
	gotoxy(120,20);printf("Total Harga(Rp)");
	while (!feof(fkbarang))
	{
		i=i+1;
		gotoxy(28,a);printf(" [%i]",i);
		gotoxy(40,a);printf(" BRG%d",KeranjangBarang.ID);
		gotoxy(61,a);printf(" %s",KeranjangBarang.nama);
		gotoxy(80,a);printf(" %d",KeranjangBarang.stock);
		gotoxy(96,a);printf(" %d KG",KeranjangBarang.berat);
		gotoxy(120,a);printf(" Rp %d",KeranjangBarang.harga);
		fread(&KeranjangBarang,sizeof(KeranjangBarang),1,fkbarang);
		a++;
	}
	fclose(fkbarang);
	fclose(info_kasir);
}



void Beli_Barang_Kasir()
{
	//Deklarasi
		FILE *fbarang;
		FILE *fkbarang;
		FILE *Temp;
		
		int konfirmasi_beli;
		
		typedef enum {false = 0, true = 1}bool;
		bool found;


		typedef struct {
			int ID;
			char nama[30];
			char supplier[30];
			char jenis[30];
			int stock;
			int harga;
			int berat;
			} ArsipBarang;
		ArsipBarang barang;

		
		typedef struct {
			int ID;
			char nama[30];
			int stock;
			int harga;
			int berat;
			} BeliBarang;
	BeliBarang KeranjangBarang;
		
	int idBarang;
		
	//Algoritma
		fkbarang = fopen("lib/kbarang.dat","a+b");
		fbarang = fopen("lib/barang.dat","rb");
		Temp = fopen("lib/temp.dat","wb");
		
	//	printFile("txt/PRG1.txt",4,20);
		gotoxy(28,18);printf("Beli Barang");
		
		fflush(stdin);
		gotoxy(28,20);printf("ID Barang	: "); getnum(&idBarang,20);
		gotoxy(28,21);printf("Mencari Data..");
		Sleep(1500);
		found = false;
		while((!found)&&(!feof(fbarang)))
		{
			fread(&barang,sizeof(barang),1,fbarang);	
			if (idBarang==barang.ID)
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
		
			gotoxy(28,23);printf("Data Berhasil Ditemukan");
			gotoxy(28,24);printf("Nama		: %s",barang.nama);
			gotoxy(28,25);printf("Stock		: %d",barang.stock);
			gotoxy(28,26);printf("Harga		: Rp %d",barang.harga);
			gotoxy(28,27);printf("Berat		: %d KG",barang.berat);
			fflush(stdin);
			gotoxy(28,28);printf("Jumlah 	: ");getnum(&KeranjangBarang.stock,9);
			if(barang.stock<KeranjangBarang.stock)
				{
					gotoxy(28,29);printf("Stock tidak mencukupi");
					getch();
					Menu_Kasir();
				}else{
					gotoxy(28,29);printf("Loading..");
					Sleep(1500);
					/////////MINDAHIN DATA KE Keranjang BARANG///////////////////
					barang.stock = barang.stock-KeranjangBarang.stock;
					
					KeranjangBarang.berat = barang.berat*KeranjangBarang.stock;
					KeranjangBarang.harga = barang.harga*KeranjangBarang.stock;
					KeranjangBarang.ID = barang.ID;
					strcpy(KeranjangBarang.nama,barang.nama);
					fwrite(&KeranjangBarang,sizeof(KeranjangBarang),1,fkbarang);
					////////////////////////////////////////////////////////////
				}
			fwrite(&barang,sizeof(barang),1,Temp);
			fread(&barang,sizeof(barang),1,fbarang);
			while(!feof(fbarang))
			{
				fwrite(&barang,sizeof(barang),1,Temp);
				fread(&barang,sizeof(barang),1,fbarang);
			}
			///////////////////////////////////////////////
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
			fclose(fkbarang);
			
			gotoxy(28,30);printf("Data Berhasil Dimasukkan Ke keranjang belanja!");
			GlobalKonfirmasiBeli=1;
			getch();
		}else{
			gotoxy(28,22);printf("Barang dengan ID %d tidak ditemukan di dalam Data Barang", idBarang);
			fclose(fbarang);
			fclose(Temp);
			fclose(fkbarang);
		}
		
}


void Cetak_Struk()
{
	
	
	//waktu
	

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	
	time_t rawtime;
	struct tm *info;
	
	typedef struct 
	{
	       int tahun;
	       int bulan;
	       int hari;
	       int jam;
	       int menit;
	       int detik;
	}hasil;
	hasil waktu;
	
	time_t t1 = time(0);
	struct tm * now = localtime( & t1 );
	
	waktu.tahun=now->tm_year+1900;
	waktu.bulan=now->tm_mon+1;
	waktu.hari=now->tm_mday;
	waktu.jam=now->tm_hour;
	waktu.menit=now->tm_min;
	waktu.detik=now->tm_sec;
	
	///////AKHIR WAKTu
	
	int i;
	i=0;
	int a=24;
	FILE *fkbarang;
	FILE *info_kasir;
		typedef struct {
			int ID;
			char nama[30];
			int stock;
			int harga;
			int berat;
			} BeliBarang;
		BeliBarang KeranjangBarang;
		
	typedef struct {
		int ID;
		char nama[40];
	}infokasir;
	infokasir ikasir;
	
	///algoritma
	
	fkbarang = fopen("lib/kbarang.dat","rb");
	info_kasir = fopen("lib/info_kasir.dat","rb");
	
//	kotak();
//	printFile("txt/PRG1.txt",4,20);
	fread(&ikasir,sizeof(ikasir),1,info_kasir);
	fread(&KeranjangBarang,sizeof(KeranjangBarang),1,fkbarang);
	gotoxy(25,18);printf("==========================================Struk========================================");
	gotoxy(25,19);printf("Nama Kasir\t\t: %s",ikasir.nama);
	gotoxy(25,20);printf("Jam\t\t\t: %d:%d:%d ",waktu.jam,waktu.menit,waktu.detik);
	gotoxy(25,21);printf("Tanggal Pembelian\t: %d:%d:%d ",waktu.hari,waktu.bulan,waktu.tahun);
	gotoxy(28,23);printf("NO");
	gotoxy(41,23);printf("ID");
	gotoxy(61,23); printf("NAMA"); 
	gotoxy(80,23);printf("STOK");
	gotoxy(95,23);printf("BERAT");
	gotoxy(108,23);printf("HARGA");
	while (!feof(fkbarang))
	{
		i=i+1;
		gotoxy(28,a);printf("[%i]",i);
		gotoxy(41,a);printf("BRG%d",KeranjangBarang.ID);
		gotoxy(61,a);printf("%s",KeranjangBarang.nama);
		gotoxy(80,a);printf("%d",KeranjangBarang.stock);
		gotoxy(95,a);printf("%d KG",KeranjangBarang.berat);
		gotoxy(108,a);printf("Rp %d",KeranjangBarang.harga);
		fread(&KeranjangBarang,sizeof(KeranjangBarang),1,fkbarang);
		a++;
	}
		gotoxy(90,40);printf("Total : %d KG",Global_Total_Berat);
	if(GlobalKonfirmasiKurir==1)
	{
		if(Global_Total_Berat<100)
			{
				gotoxy(108,41);printf("Biaya Antar : Rp 50000");
			}else if(Global_Total_Berat>=100 && Global_Total_Berat<200)
			{
				gotoxy(108,41);printf("Biaya Antar : Rp 100000");
			}else if(Global_Total_Berat>=200 && Global_Total_Berat<300)
			{
				gotoxy(108,41);printf("Biaya Antar : Rp 150000");
			}else if((Global_Total_Berat>=300 && Global_Total_Berat<500))
			{
				gotoxy(108,41);printf("Biaya Antar : Rp 200000");
			}else {
				gotoxy(108,41);printf("Biaya Antar : Rp 250000");
			}
		
	}
	gotoxy(108,42);printf("Total : Rp %d",Global_Total_Tagihan);
	gotoxy(108,43);printf("Tunai : Rp %d",Global_uang_customer);
	gotoxy(108,44);printf("Return : Rp %d",Global_kembalian);
	fclose(fkbarang);

	fclose(info_kasir);
	
	fkbarang = fopen("lib/kbarang.dat","wb");
	fclose(fkbarang);
	GlobalKonfirmasiBeli=0;
	
}

void Hapus_Keranjang_Barang()
{
	//DEKLARASI
	
	int IDbarang,menu;
	typedef enum {false = 0, true = 1}bool;
	bool found;
	char konfirmasi;
	
	FILE *fkbarang;
	FILE *Temp;
		typedef struct {
			int ID;
			char nama[30];
			int stock;
			int harga;
			int berat;
			} BeliBarang;
		BeliBarang KeranjangBarang;
	
	//ALGORITMA
	gotoxy(25,30);printf("Masukkan ID barang yang ingin anda hapus : BRG"); getnum(&IDbarang,15);
	fkbarang = fopen("lib/kbarang.dat","rb");
	Temp = fopen("lib/temp.dat","wb");
	found = false;	
	while((!found)&&(!feof(fkbarang)))
	{
		fread(&KeranjangBarang,sizeof(KeranjangBarang),1,fkbarang);	
		if (KeranjangBarang.ID == IDbarang)
		{
			found = true;
		}
		else
		{
			fwrite(&KeranjangBarang,sizeof(KeranjangBarang),1,Temp);
		}			
	}
	
	if(found == true)
	{
		gotoxy(25,32);printf("Apakah Anda yakin ingin menghapusnya ? Y/N : ");
		getletter(&konfirmasi,1);
		if (konfirmasi=='Y' || konfirmasi == 'y')
		{
			fread(&KeranjangBarang,sizeof(KeranjangBarang),1,fkbarang);	//
			while(!feof(fkbarang))
			{
				fwrite(&KeranjangBarang,sizeof(KeranjangBarang),1,Temp);
				fread(&KeranjangBarang,sizeof(KeranjangBarang),1,fkbarang);
			}
			fclose(fkbarang);
			fclose(Temp);
		
			Temp = fopen("lib/temp.dat","rb");
			fkbarang = fopen("lib/kbarang.dat","wb"); 
			
			fread(&KeranjangBarang,sizeof(KeranjangBarang),1,Temp);
			while(!feof(Temp))
			{
				fwrite(&KeranjangBarang,sizeof(KeranjangBarang),1,fkbarang);
				fread(&KeranjangBarang,sizeof(KeranjangBarang),1,Temp);
			} 
			
			fclose(fkbarang);
			fclose(Temp);
			gotoxy(25,33);printf("Data Berhasil Di Hapus ");
		}
			
	}
	else{ 			
		gotoxy(25,33);printf("Data tidak ditemukan.");
		fclose(fkbarang);
		fclose(Temp);
		getch();
		system("cls");
	}
}
