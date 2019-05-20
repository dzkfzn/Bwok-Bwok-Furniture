#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "login1.h"

void signup()
{
	fkasir=fopen("kasir.txt","w");
	printf("masukan nama 		: ");scanf(" %[^\n]",&Log.nama);
	printf("masukan username 	  : ");scanf("%s",&Log.username);
	printf("masukan password 	  : ");scanf("%s",&Log.pass1);
	printf("masukan alamat	 	  : ");scanf("%s",&Log.alamat);
	printf("masukan nomer telepon 	: ");scanf("%s",&Log.telp);
	printf("masukan tempat lahir  	: ");scanf("%s",&Log.lahir);
	printf("masukan Tanggal		  : ");scanf("%d",&Log.tgl);
	printf("masukan Bulan		  : ");scanf("%d",&Log.bln);
	printf("masukan Tahun		  : ");scanf("%d",&Log.thn);	
	fwrite(&Log,sizeof(Log),1,fkasir);
	
	fclose(fkasir);
	
	
}
