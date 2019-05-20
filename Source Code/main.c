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

main()
{
	
	
		
	int NomorMenu;
	do{
		

	getch();
	
	system("color 1f");
	hlogin();
	
	gotoxy(18,23);getnum(&NomorMenu,1);
	while(NomorMenu==4);
	switch (NomorMenu){
		case 1 : 
			login();
			break ;
		case 2 : 
			printf("\nterimakasih\n"); break ;
		
		}
		getch();
		system("cls");
	}while(NomorMenu != 3);
}

