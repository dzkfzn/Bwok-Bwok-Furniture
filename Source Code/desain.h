void kotak();
void loading();
void tabel();
void kotak_tanpa_bawah();




void hlogin()
{
	

	
	gotoxy(2,19);printf("Menu Login");
	gotoxy(2,21);printf("[1]. LOGIN");
    gotoxy(2,22);printf("[2]. KELUAR");
    gotoxy(2,23);printf("Pilihan Anda\t:");
    kotak();
   
   // printFile("txt/login.txt",42,25);
   
 //   gotoxy(42,25);printf("1.Login\n");
//	gotoxy(42,26);printf("2.Keluar\n");
//	gotoxy(42,27);printf("Pilih Menu diatas : ");
}

void tabel()
{
	HLine(26, 17, 125);// BINGKAI PINGGIR
	HLine(151, 22, 9);
	HLine(151, 17, 10);
	VLine(26, 18, 31);
	VLine(150, 18, 31);
	HLine(27, 48, 123);
	
	HLine(27, 22, 123);
	HLine(151, 48, 9);
	VLine(33, 18, 5); // BINGKAI ATAS MOBIL
	VLine(59, 18, 5);
	VLine(78, 18, 5);
	VLine(93, 18, 5);
	VLine(103, 18, 5);
	VLine(121, 18, 5);
	VLine(139, 18, 5);
	
	VLine(33, 23, 26); // BINGKAI BAWAH MOBIL
	VLine(59, 23, 26);
	VLine(78, 23, 26);
	VLine(93, 23, 26);
	VLine(103, 23, 26);
	VLine(121, 23, 26);
	VLine(139, 23, 26);
	VLine(160, 18, 31);
}
/*void loading()
{
	int i;
	i=0;
	gotoxy(1,31);printf("%c",218);
     gotoxy(168,34);printf("%c",217);
     gotoxy(168,31);printf("%c",191);
     gotoxy(1,32);printf("%c",179);
     gotoxy(1,33);printf("%c",179);
     gotoxy(168,32);printf("%c",179);
     gotoxy(168,33);printf("%c",179);
     gotoxy(1,34);printf("%c",192);

     for(i=2;i<168;i++)
     {
           gotoxy(i,31); printf("%c",196);
		   gotoxy(i,34); printf("%c",196);
	 }
     for(i=3;i<20;i++)
     {
		   gotoxy(84,36); printf(" %i%c ",i/2,37);delay(30000000);
           gotoxy(i,32); printf("%c ",219);
           gotoxy(i,33); printf("%c ",219);delay(30000000);
     }
     
     for(i=20;i<85;i++)
     {
		   gotoxy(84,36); printf(" %i%c ",i/2,37);;delay(10000000);
           gotoxy(i,32); printf("%c ",219);
           gotoxy(i,33); printf("%c ",219);delay(10000000); 
     }
	 for(i=85;i<167;i++)
     {
		   gotoxy(84,36); printf(" %i%c ",(i/2)+17,37);;delay(300000);
           gotoxy(i,32); printf("%c ",219);
           gotoxy(i,33); printf("%c ",219);delay(3000000); 
     }

	 gotoxy(67,29);printf("	   Loading Successfully\a"); delay(100000000);

	 gotoxy(1,57);system("PAUSE");
     
     system("cls");
}*/
void kotak()
{
	VLine(0, 6,44);
	VLine(166, 6,44);
    HLine(0, 5, 167);
     HLine(1, 49, 165);
    
    HLine(1, 16, 165);
    VLine(23, 17, 33);
     printFile("txt/lemari.txt",2,6);
     printFile("txt/bwok.txt",27,7);
}

void kotak_tanpa_bawah()
{
	VLine(0, 6,44);
	VLine(166, 6,44);
    HLine(0, 5, 167);
    HLine(1, 49, 23);
    
    HLine(1, 16, 165);
    VLine(23, 17, 33);
     printFile("txt/lemari.txt",2,6);
     printFile("txt/bwok.txt",27,7);
}
