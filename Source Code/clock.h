
time_t rawtime;
struct tm *info;

int i;
	
struct hasil
{
       int tahun;
       int bulan;
       int hari;
       int jam;
       int menit;
       int detik;
}waktu;

void kronos() 
{
time_t t1 = time(0);
struct tm * now = localtime( & t1 );

waktu.tahun=now->tm_year+1900;
waktu.bulan=now->tm_mon+1;
waktu.hari=now->tm_mday;
waktu.jam=now->tm_hour;
waktu.menit=now->tm_min;
waktu.detik=now->tm_sec;

gotoxy(145,6); printf("%i",waktu.hari);
gotoxy(150,6); printf("%i",waktu.bulan);
gotoxy(155,6); printf("%i",waktu.tahun);
gotoxy(148,9); printf("%i  :  %i",waktu.jam,waktu.menit);

gotoxy(143,4); printf(" Tanggal & Waktu");

for(i=144;i<160;i++)
{
        gotoxy(i,5);printf("%c",196);
        gotoxy(i,7);printf("%c",196);
}
for(i=144;i<160;i++)
{
        gotoxy(i,8);printf("%c",196);
        gotoxy(i,10);printf("%c",196);
}

gotoxy(143,6);printf("%c",179);
gotoxy(148,6);printf("%c",179);
gotoxy(153,6);printf("%c",179);
gotoxy(160,6);printf("%c",179);
gotoxy(143,9);printf("%c",179);
gotoxy(160,9);printf("%c",179);

gotoxy(143,5);printf("%c",218);
gotoxy(143,8);printf("%c",218);
gotoxy(160,5);printf("%c",191);
gotoxy(160,8);printf("%c",191);
gotoxy(143,7);printf("%c",192);
gotoxy(143,10);printf("%c",192);
gotoxy(160,7);printf("%c",217);
gotoxy(160,10);printf("%c",217);

for(i=3;i<12;i++)
{
        gotoxy(142,i);printf("%c",177);
        gotoxy(161,i);printf("%c",177);
		gotoxy(141,i);printf("%c",177);
        gotoxy(162,i);printf("%c",177);
}

}

void date()
{
	kronos();
}
