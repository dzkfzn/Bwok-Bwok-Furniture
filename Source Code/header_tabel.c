#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h> 

#include "master_kasir.h"
#include "master_kurir.h"
#include "barang.h"

#include "getlib.h"
#include "menu.h"


#include "utility.h"
#include "transaksi_new.h"

#include "laporan.h"
#include "Transaksi_courir.h"

#include "desain.h"

void kotak_tanpa_bawah();
main()
{
	getch();
	
	system("color 3f");
	kotak_tanpa_bawah();
	HLine(40, 15, 80);
	printf("ID");
	printf("Nama");
	printf("Username");
	printf("Password");
	printf("ID");
	 
}



void tabel_master_kasir()
{
//	VLine(166, 0,43);
   
  //  HLine(1, 42, 24);
}

