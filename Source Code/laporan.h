

typedef struct {
			
		int ID_transaksi;
		//waktu
		int tahun;
	    char bulan[15];
		int hari;
    	int jam;
	    int menit;
	    int detik;
			
	    //kasir
	    int ID_kasir;
		char nama_kasir[40];
//		int uang_customer;
//		int kembalian;
//		int Total_Tagihan;
		
		//kurir
		int ID;
		char nama[40];
		
	    //barang
	    int ID_barang;
		char nama_barang[30];
		int stock;
		int harga;
		int berat;
		
		} Struk;


void Cetak_Riwayat_Transaksi()
{
	int a=24;
	Struk Struk_Bayar;
	FILE *sbayar;

//	printFile("txt/PRG1.txt",4,20);
	sbayar = fopen("lib/sbarang.dat","rb");
	fread(&Struk_Bayar,sizeof(Struk_Bayar),1,sbayar);
	gotoxy(28,20);printf("ID Transaksi");
	gotoxy(44,20);printf("Tanggal");
	gotoxy(61,20); printf("Waktu"); 
	gotoxy(80,20);printf("ID Barang");
	gotoxy(95,20);printf("Nama Barang");
	gotoxy(111,20);printf("TotalHarga");
	gotoxy(130,20);printf("Nama Kasir");
	gotoxy(155,20);printf("Jumlah");	
	while(!feof(sbayar))
	{
		fflush(stdin);
		
		gotoxy(28,a);printf("TRX%d",Struk_Bayar.ID_transaksi);
		gotoxy(41,a);printf("%d %s %d",Struk_Bayar.hari,Struk_Bayar.bulan,Struk_Bayar.tahun);
		gotoxy(61,a);printf("%d:%d:%d",Struk_Bayar.jam,Struk_Bayar.menit,Struk_Bayar.detik);
		gotoxy(80,a);printf("BRG%d",Struk_Bayar.ID_barang);
		gotoxy(95,a);printf("%s",Struk_Bayar.nama_barang);
		gotoxy(113,a);printf("Rp %d",Struk_Bayar.harga);
		gotoxy(130,a);printf("%s",Struk_Bayar.nama_kasir);
		gotoxy(153,a);printf("%d",Struk_Bayar.stock);
//		printf("\nTotal Tagihan : Rp %d",Struk_Bayar.Total_Tagihan);
//		printf("\nUang Customer : Rp %d ",Struk_Bayar.uang_customer);
//		printf("\nKembalian : Rp %d \n",Struk_Bayar.kembalian);
		fread(&Struk_Bayar,sizeof(Struk_Bayar),1,sbayar);
		a++;
	}

	
	fclose(sbayar);
}


void Riwayat_Transaksi()
{
	Struk Struk_Bayar;
	
	//DEKLARASI WAKTU
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
	////////AKHIR DEKLARASI WAKTU/////////////
	
		//KASIRR
	typedef struct {
		int ID;
		char nama[40];
	}infokasir;
	infokasir ikasir;
	
	typedef struct {
			int ID;
			char nama[30];
			int stock;
			int harga;
			int berat;
			} BeliBarang;
	BeliBarang KeranjangBarang;
	int berenti;
	////// PROSES PENULISAN STRUK
	Struk_Bayar.ID_transaksi=0;
	
	FILE *fkbarang;
	FILE *info_kasir;
	FILE *sbayar;
	
	
	fkbarang = fopen("lib/kbarang.dat","rb");
	info_kasir = fopen("lib/info_kasir.dat","rb");
	sbayar = fopen("lib/sbarang.dat","a+b");
	
	fread(&ikasir,sizeof(ikasir),1,info_kasir);
	fread(&KeranjangBarang,sizeof(KeranjangBarang),1,fkbarang);
	while (!feof(fkbarang))
	{
		if(berenti==0)
		{
			fread(&Struk_Bayar.ID_transaksi,sizeof(Struk_Bayar),1,sbayar);
			while(!feof(sbayar))
			{
				
				fflush(stdin);
				fread(&Struk_Bayar.ID_transaksi,sizeof(Struk_Bayar),1,sbayar);
				
			}
				if(Struk_Bayar.ID_transaksi<1000){
					Struk_Bayar.ID_transaksi=Struk_Bayar.ID_transaksi+1000;
				}
			
		}
		Struk_Bayar.ID_transaksi++; 
		berenti=1;
		//barang
		Struk_Bayar.ID_barang= KeranjangBarang.ID;
		strcpy(Struk_Bayar.nama_barang,KeranjangBarang.nama);
		Struk_Bayar.stock=KeranjangBarang.stock;
		Struk_Bayar.harga=KeranjangBarang.harga;
		Struk_Bayar.berat=KeranjangBarang.berat;
		
		//kasir
		Struk_Bayar.ID_kasir=ikasir.ID;
		strcpy(Struk_Bayar.nama_kasir,ikasir.nama);
//		Struk_Bayar.uang_customer=uang_customer;
//		Struk_Bayar.kembalian=kembalian;
//		Struk_Bayar.Total_Tagihan=Total_Tagihan;
		
		
		//waktu
		Struk_Bayar.detik=waktu.detik;
		Struk_Bayar.menit=waktu.menit;
		Struk_Bayar.jam=waktu.jam;
		Struk_Bayar.hari=waktu.hari;
		if(waktu.bulan==1){
		strcpy(Struk_Bayar.bulan,"Januari");
		}else if(waktu.bulan==2){
			strcpy(Struk_Bayar.bulan,"Februari");
		}else if(waktu.bulan==3){
			strcpy(Struk_Bayar.bulan,"Maret");
		}else if(waktu.bulan==4){
			strcpy(Struk_Bayar.bulan,"April");
		}else if(waktu.bulan==5){
			strcpy(Struk_Bayar.bulan,"Mei");
		}else if(waktu.bulan==6){
			strcpy(Struk_Bayar.bulan,"Juni");
		}else if(waktu.bulan==7){
			strcpy(Struk_Bayar.bulan,"Juli");
		}else if(waktu.bulan==8){
			strcpy(Struk_Bayar.bulan,"Agustus");
		}else if(waktu.bulan==9){
			strcpy(Struk_Bayar.bulan,"September");
		}else if(waktu.bulan==10){
			strcpy(Struk_Bayar.bulan,"Oktober");
		}else if(waktu.bulan==11){
			strcpy(Struk_Bayar.bulan,"November");
		}else if(waktu.bulan==12){
			strcpy(Struk_Bayar.bulan,"Desember");
		}
		Struk_Bayar.tahun=waktu.tahun;
		fwrite(&Struk_Bayar,sizeof(Struk_Bayar),1,sbayar);
		fread(&KeranjangBarang,sizeof(KeranjangBarang),1,fkbarang);
	}
	

	fclose(sbayar);
	fclose(info_kasir);
	fclose(fkbarang);
}

void Laporan_Tahunan()
{
	//dek
	Struk Struk_Bayar;
	FILE *lapthn;
	FILE *sbayar;
	int caritahun,menu;
	typedef enum {false = 0, true = 1}bool;
	bool found;
	int pendapatan;
	int a=24; 
	
	
	//alg
	gotoxy(28,18);printf("Laporan Tahunan");
	gotoxy(28,20);printf("Cari Tahun : "); getnum(&caritahun,15);
	sbayar = fopen("lib/sbarang.dat","rb");
	lapthn = fopen("lib/laptahun.dat","wb");
//	Temp = fopen("lib/temp.dat","wb");
	
	
	found = false;	
	fread(&Struk_Bayar,sizeof(Struk_Bayar),1,sbayar);
	while((!feof(sbayar)))
	{
		if (Struk_Bayar.tahun == caritahun)
		{
			pendapatan = pendapatan + Struk_Bayar.harga;
			fwrite(&Struk_Bayar,sizeof(Struk_Bayar),1,lapthn);
		}	
		fread(&Struk_Bayar,sizeof(Struk_Bayar),1,sbayar);
	}
	
	fclose(sbayar);
	fclose(lapthn);
	
	lapthn = fopen("lib/laptahun.dat","rb");
	fread(&Struk_Bayar,sizeof(Struk_Bayar),1,lapthn);
	system("cls");
	kotak_tanpa_bawah();
	gotoxy(28,20);printf("ID Transaksi");
	gotoxy(44,20);printf("Tanggal");
	gotoxy(61,20);printf("Jam");
	gotoxy(80,20);printf("ID Barang");
	gotoxy(95,20);printf("Nama Barang");
	gotoxy(108,20);printf("Total Harga");
	gotoxy(121,20);printf("Nama Kasir");
	gotoxy(140,20);printf("Jumlah");
	
	
	while((!feof(lapthn)))
	{
		gotoxy(28,a);printf("TRX%d",Struk_Bayar.ID_transaksi);
		gotoxy(44,a);printf("%d %s %d",Struk_Bayar.hari,Struk_Bayar.bulan,Struk_Bayar.tahun);
		gotoxy(61,a);printf("%d:%d:%d",Struk_Bayar.jam,Struk_Bayar.menit,Struk_Bayar.detik);
		gotoxy(80,a);printf("BRG%d",Struk_Bayar.ID_barang);
		gotoxy(95,a);printf("%s",Struk_Bayar.nama_barang);
		gotoxy(108,a);printf("Rp %d",Struk_Bayar.harga);
		gotoxy(121,a);printf("%s",Struk_Bayar.nama_kasir);
		gotoxy(140,a);printf("%d",Struk_Bayar.stock);
		fread(&Struk_Bayar,sizeof(Struk_Bayar),1,lapthn);
		a++;
	}
	
	gotoxy(28,a+10);printf("Total Pendapatan Pada Tahun %d : Rp %d",caritahun,pendapatan);
	
	fclose(lapthn);
		
}

void Laporan_Bulanan()
{
	//dek
	Struk Struk_Bayar;
	FILE *lapbln;
	FILE *sbayar;
	char caribulan[20];
	int menu;
	typedef enum {false = 0, true = 1}bool;
	bool found;
	int pendapatan;
	int a=24; 
	
	
	//alg
	gotoxy(28,18);printf("Laporan Bulanan");
	gotoxy(28,20);printf("Masukkan bulan : "); getletter(caribulan,15);
	sbayar = fopen("lib/sbarang.dat","rb");
	lapbln = fopen("lib/lapbulan.dat","wb");
//	Temp = fopen("lib/temp.dat","wb");
	system("cls");
	kotak_tanpa_bawah();
	
	found = false;	
	fread(&Struk_Bayar,sizeof(Struk_Bayar),1,sbayar);
	while((!feof(sbayar)))
	{
		if (strcmp(caribulan,Struk_Bayar.bulan)==0 && Struk_Bayar.tahun==2018)
		{
			pendapatan = pendapatan + Struk_Bayar.harga;
			fwrite(&Struk_Bayar,sizeof(Struk_Bayar),1,lapbln);
		}	
		fread(&Struk_Bayar,sizeof(Struk_Bayar),1,sbayar);
	}
	
	fclose(sbayar);
	fclose(lapbln);
	
	lapbln = fopen("lib/lapbulan.dat","rb");
	fread(&Struk_Bayar,sizeof(Struk_Bayar),1,lapbln);
	
	gotoxy(28,20);printf("ID Transaksi");
	gotoxy(44,20);printf("Tanggal");
	gotoxy(61,20);printf("Jam");
	gotoxy(80,20);printf("ID Barang");
	gotoxy(95,20);printf("Nama Barang");
	gotoxy(108,20);printf("Total Harga");
	gotoxy(121,20);printf("Nama Kasir");
	gotoxy(140,20);printf("Jumlah");
	
	
	while((!feof(lapbln)))
	{
		gotoxy(28,a);printf("TRX%d",Struk_Bayar.ID_transaksi);
		gotoxy(44,a);printf("%d %s %d",Struk_Bayar.hari,Struk_Bayar.bulan,Struk_Bayar.tahun);
		gotoxy(61,a);printf("%d:%d:%d",Struk_Bayar.jam,Struk_Bayar.menit,Struk_Bayar.detik);
		gotoxy(80,a);printf("BRG%d",Struk_Bayar.ID_barang);
		gotoxy(95,a);printf("%s",Struk_Bayar.nama_barang);
		gotoxy(108,a);printf("Rp %d",Struk_Bayar.harga);
		gotoxy(121,a);printf("%s",Struk_Bayar.nama_kasir);
		gotoxy(140,a);printf("%d",Struk_Bayar.stock);
		fread(&Struk_Bayar,sizeof(Struk_Bayar),1,lapbln);
		a++;
	}
	gotoxy(28,a+10);printf("Total Pendapatan pada bulan %s : Rp %d",caribulan,pendapatan);
	
	fclose(lapbln);
}

