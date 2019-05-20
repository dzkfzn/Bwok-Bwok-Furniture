#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

#include "Manager1.h"
#include "Admin1.h"
#include "kasir1.h"

	FILE *fkasir;
	
	typedef struct {
		char nama[40];
		char username[40];
		char pass1 [40];
		char pass2 [40];
		char alamat [40];
		char telp[40];
		char lahir[40];
		int tgl;
		int bln;
		int thn;
	
		}ArsKasir;
		


ArsKasir Log;

void login();
void signup();

void signup()
{
	fkasir=fopen("kasir.txt","w");
	printf("\nmasukan nama 		: ");getletter(&Log.nama,30);fflush(stdin);
	printf("\nmasukan username 	  : "); getteks(&Log.username,20);fflush(stdin);
	printf("\nmasukan password 	  : ");getpass(&Log.pass1,20);fflush(stdin);
	do
	{
		printf("\nmasukan konfirmasi password 	  : ");
		getpass(&Log.pass2,20);fflush(stdin);
		if(strcmp(Log.pass1,Log.pass2)!=0)
		printf("\nPassword Anda Tidak Sama");
	}while(strcmp(Log.pass1,Log.pass2)!=0);
	
	printf("\nmasukan alamat	 	  : ");getteks(&Log.alamat,50);fflush(stdin);
	printf("\nmasukan nomer telepon 	: ");getnum(&Log.telp,13);fflush(stdin);
	printf("\nmasukan TTL  	: ");getletter(&Log.lahir,20);fflush(stdin);
	printf(",");
	getnum(&Log.tgl,2);printf("-");
	getnum(&Log.bln,2);printf("-");
	getnum(&Log.thn,4);printf("-");
	fwrite(&Log,sizeof(Log),1,fkasir);
	
	fclose(fkasir);
}
void login()
{	
	typedef enum {false = 0, true = 1}boolean;
	boolean found;
	ArsKasir ArsipKasir;
	char no[40];
	FILE *fkasir;
	char user[40];
	char password[40];
	int sukses;
	int hasil;
	int kasir;
	
	sukses=0;
	fkasir = fopen("kasir.txt","r");
	printf("\nusername : ");getteks(&user,20);
	printf("\npassword : ");getpass(&password,20);

	while(!found && !feof(fkasir))
	{
		fread(&ArsipKasir, sizeof(ArsipKasir), 1, fkasir);
		hasil = strcmp(ArsipKasir.username,user);
		kasir = strcmp(ArsipKasir.pass1,password);
		
			if(strcmp(user,"ADMIN")==0 && strcmp(password,"ADMIN")==0)
			{
				sukses = 2;
				break;
			}
			else if(hasil== 0 && kasir == 0)
			{
				sukses = 1;
				break;
			}
			else if(strcmp(user,"manager")==0 && strcmp(password,"tojak")==0)
			{
				sukses = 3;
				break;
			}
	}
		if(sukses == 1)
		{
			printf ("\nlog in as kasir  ");
			getch();
			system("cls");
			Menu_Kasir();
			getch();
		}
		if(sukses == 2)
		{
			
			printf ("\nLog in as admin  ");
			getch();
			system("cls");
			Menu_Admin();
			getch();
		}
		if(sukses == 3)
		{
		    printf ("\nlog in as manager  \n");
		    getch();
		    system("cls");
		    Menu_Manager();
			getch();
		}
		else if(sukses != 3 && sukses != 2 && sukses != 1)
		{
			printf ("\nLog in gagal  ");
			getch();
			system("cls");
		}
		fclose(fkasir);
}
