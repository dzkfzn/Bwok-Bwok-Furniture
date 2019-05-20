void getinputmin(char input[], int min, int max, int type){
	char current;
	int i,n;
	n = 0;
	do
	{	
		current = getch();
		
		if(current == '\b' && n != 0) //backspace
		{
			printf("\b \b");
			n--;
			input[n]='\0';
		}
		//else if(current >= 32 && current <= 122){
		else if(isprint(current)){ //karakter yang bisa di print
			if(n == max) {
				continue;
			}
			else{
				if(type == 3){ //isdigit = angka doang
					if(isdigit(current)) {
						printf("%c", current);
						input[n]=current;
						n++;
					}
					else printf("\a");
				}
				else if(type == 2){ //isalpha = alpabet dan spasi co : nama
					if(isalpha(current) || current == ' ') {
						printf("%c", current);
						input[n]=current;
						n++;
					}
					else printf("\a");
				}
				else { // password //0= bebas
					if(type == 1) printf("*");
					else printf("%c", current);
					input[n]=current;
					n++;
				}
			}
		}
		else if(current == 13)
		{
			if(n < min) {
				printf("\a");
				current = 0;
			}
			else input[n]='\0';
		}
		//else if(current == 27) end();
	}
	while(current != 13);
}

void getinput(char input[], int max, int type){
	getinputmin(input, 1, max, type);
}

getteks(char input[], int max)//inputan bebas
{
	getinput(input, max, 0);
}

getletter(char input[], int max)//huruf aja
{
	getinput(input, max, 2);
}

getnummin(int *dest, int min, int max){ // NOMER SAJA MINIMUM MAKSIMUM
	char input[max];
	getinputmin(input, min, max, 3);
	*dest = atoi(input);
}

getnum(int *dest, int max)//nomer aja
{
	char input[max];
	getinput(input, max, 3);
	*dest = atoi(input);
}

getteksnummin(char input[], int min, int max){ // INPUTAN NOMER SEBAGAI KARAKTER MINIMUM MAXIMUM
	getinputmin(input, min, max, 3);
}

getteksnum(char input[], int max)//nomer sebagai karakter
{
	getinput(input, max, 3);
}

getpass(char input[], int max)//teks sebagai password jadi ada bintangnya
{
	getinput(input, max, 1);
}
