void Tulis_Riwayat_Kurir();

	typedef struct {
			int ID;
			char nama[30];
			int jumlah;
			int harga;
			int berat;
			char alamat[50];
			char nama_kurir[30];
			} iBarang;
			
void List_Antar_Barang()
{
	FILE *akurir;
	FILE *riwkurir;
	FILE *fkbarang;
	FILE *Alkur;
	FILE *tumbalkurir;
	int berenti;
	
	berenti=0;
	char alamat_tujuan[20];
//	strcpy (alamat_tujuan,alamat);
		
	typedef struct {
			int ID;
			char nama[30];
			int stock;
			int harga;
			int berat;
			} BeliBarang;
	BeliBarang KeranjangBarang;
	iBarang kurir;
	
	///algoritma
	
	tumbalkurir = fopen("lib/tumbal_kurir.dat","a+b");
	fkbarang = fopen("lib/kbarang.dat","rb");
	akurir = fopen("lib/antar_kurir.dat","a+b");
	Alkur = fopen("lib/alkur.dat","rb");//alamat
		
	fread(&alamat_tujuan,sizeof(alamat_tujuan),1,Alkur);
	
	
	berenti=0;
	
	while (!feof(fkbarang))
	{
		if(berenti==0)
		{
			fread(&kurir.ID,sizeof(kurir),1,tumbalkurir);
			while(!feof(tumbalkurir))
			{
				
				fflush(stdin);
				fread(&kurir.ID,sizeof(kurir),1,tumbalkurir);
			}
				if(kurir.ID<1000){
					kurir.ID=kurir.ID+1000;
				}
		}
		kurir.ID++;
		berenti = 1;
		fread(&KeranjangBarang,sizeof(KeranjangBarang),1,fkbarang);
	
		strcpy(kurir.nama,KeranjangBarang.nama);
		kurir.jumlah=KeranjangBarang.stock;
		kurir.harga=KeranjangBarang.harga;
		kurir.berat=KeranjangBarang.berat;
		strcpy(kurir.alamat,alamat_tujuan);	
		
		fwrite(&kurir,sizeof(kurir),1,akurir);
		fwrite(&kurir,sizeof(kurir),1,tumbalkurir);
//		fread(&KeranjangBarang,sizeof(KeranjangBarang),1,fkbarang);
	}
		
	fclose(Alkur);
	fclose(akurir);
	fclose(tumbalkurir);
	fclose(fkbarang);

}

void Antar()
{
	typedef enum {false = 0, true = 1}bool;
	bool found;
	
	FILE *Temp;
	FILE *akurir;
	FILE *sd_antar;
	FILE *riwkurir;
	
	iBarang kurir;
	int id_antar,menu;
	
	int ID_kurir;
	typedef struct {
		int ID;
		char nama[40];
	}infokurir;
	infokurir ikurir;
	
	akurir = fopen("lib/antar_kurir.dat","rb");
	riwkurir = fopen("lib/riwayat_kurir.dat","a+b");
	Temp = fopen("lib/temp.dat","wb");
	
	gotoxy(28,18);printf("Antar Barang");
	gotoxy(28,20);printf("Masukkan ID Antar  : "); getnum(&id_antar,15);
	gotoxy(28,21);printf("Mencari Data..");
	Sleep(1500);
	found = false;
	while((!found)&&(!feof(akurir)))
	{
		fread(&kurir,sizeof(kurir),1,akurir);	
		if (id_antar == kurir.ID)
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
		gotoxy(28,24);printf("Pengantar		: %s\r",kurir.nama);
		gotoxy(28,25);printf("Nama	Barang	: %s\r\n",kurir.nama);
		gotoxy(28,26);printf("Jumlah Barang	: %d\r\n",kurir.jumlah);		
		gotoxy(28,27);printf("Berat		: %d KG\r\n",kurir.berat);
		gotoxy(28,28);printf("Alamat Tujuan	: %s",kurir.alamat);
		
		// PENULISAN KE RIWAYAT
		fwrite(&kurir,sizeof(kurir),1,riwkurir);
		//////////////////////////////////////
		
		fread(&kurir,sizeof(kurir),1,akurir);
			
			while(!feof(akurir))
			{
				fwrite(&kurir,sizeof(kurir),1,Temp);
				fread(&kurir,sizeof(kurir),1,akurir);
			}
			fclose(akurir);
			fclose(Temp);
			
			Temp = fopen("lib/temp.dat","rb");
			akurir = fopen("lib/antar_kurir.dat","wb"); 
			
			fread(&kurir,sizeof(kurir),1,Temp);
			while(!feof(Temp))
			{
				fwrite(&kurir,sizeof(kurir),1,akurir);
				fread(&kurir,sizeof(kurir),1,Temp);
			}
			fclose(akurir);
			fclose(Temp);
			fclose(riwkurir);
			gotoxy(28,35);printf("Barang Berhasil Diantar!");

	}else{
		gagal_update = 1;		
		gotoxy(28,23);printf("ID Antar Tidak Ditemukan");
		fclose(akurir);
		fclose(riwkurir);
		fclose(Temp);
	}
	
	
}



void Cetak_List_Antar_Barang()
{
	FILE *akurir;
	int a=24;
	iBarang kurir;
	
	akurir = fopen("lib/antar_kurir.dat","rb");
	
	gotoxy(28,20);printf("ID");
	gotoxy(44,20);printf("Nama Barang");
	gotoxy(61,20);printf("Total Berat");
	gotoxy(80,20);printf("Jumlah Barang");
	gotoxy(115,20);printf("Alamat Tujuan");
	 
	fread(&kurir,sizeof(kurir),1,akurir);
	while (!feof(akurir))
	{
		gotoxy(28,a);printf("ATR%d",kurir.ID);
		gotoxy(44,a);printf("%s",kurir.nama);
		gotoxy(69,a);printf("%d",kurir.berat);
		gotoxy(85,a);printf("%d",kurir.jumlah);
		gotoxy(115,a);printf("%s",kurir.alamat);
		
		fread(&kurir,sizeof(kurir),1,akurir);
		a++;
	}
	fclose(akurir);
}


void Tulis_Riwayat_Kurir()
{
	FILE *riwkurir;
//	FILE *info_kurir;
	iBarang kurir;
	int a=24;
	
	typedef struct {
		int ID;
		char nama[40];
	}infokurir;
	infokurir ikurir;
	
	riwkurir = fopen("lib/riwayat_kurir.dat","rb");
//	akurir = fopen("lib/antar_kurir.dat","rb");
//	info_kurir = fopen("lib/info_kurir.dat","rb");
	
	
	gotoxy(28,20);printf("ID");
	gotoxy(44,20);printf("Nama Barang");
	gotoxy(61,20);printf("Total Berat");
	gotoxy(80,20);printf("Jumlah Barang");
	gotoxy(115,20);printf("Alamat Tujuan");
	
	fread(&kurir,sizeof(kurir),1,riwkurir);
	while (!feof(riwkurir))
	{
		gotoxy(28,a);printf("ATR%d",kurir.ID);
		gotoxy(44,a);printf("%s",kurir.nama);
		gotoxy(61,a);printf("%d",kurir.berat);
		gotoxy(80,a);printf("%d",kurir.jumlah);
		gotoxy(115,a);printf("%s",kurir.alamat);
		fread(&kurir,sizeof(kurir),1,riwkurir);
		a++;
	}
	
//	fclose(akurir);
	fclose(riwkurir);
}
