
void gotoxy(int x,int y);
int delay(int);    
//void loading();

void gotoxy(int x,int y)
{
     HANDLE hConsoleOutput;
     COORD dwCursorPosition;
     dwCursorPosition.X=x;
     dwCursorPosition.Y=y;
     hConsoleOutput=GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}

void setcolor(unsigned short color)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
}

int delay(int i)
{
     int j=0;
     while (j<i)
     {
           j++;
     }
     return(i);
}
 
/*void loading()
{
     int i;
     gotoxy(35,16);printf("Log off");
     gotoxy(20,18);printf("%c",218);
     for(i=21;i<57;i++)
     {
           gotoxy(i,18); printf("%c",196);
     }
     gotoxy(57,18);printf("%c",191);
     gotoxy(20,19);printf("%c",179);
     gotoxy(57,19);printf("%c",179);
     gotoxy(20,20);printf("%c",192);
     for(i=21;i<57;i++)
     {
           gotoxy(i,20); printf("%c",196);
     }
     gotoxy(57,20);printf("%c",217);
     for(i=21;i<57;i++)
     {
           gotoxy(i,19); printf("%c ",219); delay(50000000);
     }
}*/

void SetColor(unsigned short color) 
{  
     HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);  
     SetConsoleTextAttribute(hConsoleOutput,color);
}

void rupiah(int number, char output[]);
void setWindow(int Width, int Height)
{
	SMALL_RECT Rect;
	Rect.Top=0;
	Rect.Left=0;
	Rect.Bottom=Height - 1;
	Rect.Right=Width - 1;
	
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE),(COORD) {Width, Height});
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE),TRUE,&Rect);
}

void setColor(unsigned short color){
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
}

void frame(int x, int y, int n, unsigned short color){
	setColor(color);
	int i;
	gotoxy(x, y-1);
	printf("%c", 201);
	for(i=0; i<(n-2); i++) printf("%c", 205);
	printf("%c", 187);
	
	gotoxy(x, y); printf("%c", 186);
	gotoxy(x+n-1, y); printf("%c", 186);
	
	gotoxy(x, y+1);
	printf("%c", 200);
	for(i=0; i<(n-2); i++) printf("%c", 205);
	printf("%c", 188);
	
	gotoxy(x+1, y);
}

void fillScreen(int x1, int x2, int y1, int y2, unsigned short color){
	int i,j,x,y;
	x = x1;
	y = y1;
	setColor(color);
	while(y<=y2){
		x = x1;
		gotoxy(x,y);
		while(x<=x2){
			printf(" ");
			x++;
		}
		y++;
	}
}

printFile(char file[], int x, int y){
	FILE *ffile;
	int n = 200;
	char data[n];
	if((ffile=fopen(file, "r")) == NULL){
		system("CLS");
		puts("Can't open file");
		return;
	}
	while(fgets(data, n, ffile)){
		gotoxy(x, y);
		printf("%s", data);
		y++;
	}
	fclose(ffile);
}

HLine(int x, int y, int n){
	int i;
	for(i=0; i<n; i++) {
		gotoxy(x+i, y);
		printf("%c", 220);
	}
}

VLine(int x, int y, int n){
	int i;
	for(i=0; i<n; i++) {
		gotoxy(x, y+i);
		printf("%c", 219);
	}
}

void rupiah(int number, char output[])
{
	// 
	if(number < 1000) sprintf(output, "%d", number);
    else if(number < 1000000) sprintf(output, "%d.%03d", number/1000, number%1000);
    else if(number < 1000000000) sprintf(output, "%d.%03d.%03d", number/1000000, (number%1000000)/1000, number%1000);
    else sprintf(output, "%d.%03d.%03d.%03d", number/1000000000, (number%1000000000)/1000, (number%1000000)/1000, number%1000);
}
