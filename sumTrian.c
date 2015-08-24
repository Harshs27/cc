#include<stdio.h>
#include<stdlib.h>

static char _rbuf[300*8]; //  the read buffer
static char *_rpos = 0; // pointer of char type
static char *_rend = 0; // end point of buffer (point towards the end of the buffer)

static int _getchar(){// read the input line to the buffer

	int n = read(0, _rbuf, sizeof(_rbuf));
//	printf("_getchar n = %d\n", n);
	if(n <= 0){printf("EOF %d\n", n); exit(1);}
	_rpos = _rbuf + 1;
	_rend = _rbuf + n;
//	printf("value of _rpos = %c and _rend = %c\n", *_rpos, *_rend);
	return *_rbuf;
}

#define mygetchar() ( (_rpos < _rend) ? *_rpos++: _getchar() ) // basically returns the character position in the buffer. 


static int get_i(){
	int c;
//	printf("entering get_i()");
	while ((c = mygetchar())< '0'){}
	int n = 0;
//	printf("n  = %d\n", n);
	while (c >= '0'){
		n = n*10 + (c - '0');
		c = mygetchar();
//		printf("inside n  = %d\n", n);
	}
	return n;
}

void put_i(int n){// put the characters on the screen 
#define BSIZE 16
	int bs;
	char _obuf[BSIZE];// output buffer: stores the output to be printed on the screen 
	bs = BSIZE - 1;
	while(n>0){
		_obuf[bs--] = '0' + n%10;
		n = n/10;
	}
	while(bs < BSIZE){
		putchar(_obuf[bs++]);
	}
	return ;
}

#define max(a, b) ((a) > (b) ? a : b)

void sumtrian(int rows){
	int a[rows];
	int b[rows];
	int *old;
	old = a;
	int *curr;
	curr = b;
	old[0] = 0;
	int i = 0;
	int n;
	while(i<rows){
		int j = 1;
		n = get_i();curr[0] = old[0] + n;
		if(i){
			while(j<i){n = get_i(); curr[j] = n + max(old[j], old[j-1]);j++;}
			n = get_i();
			curr[j] = old[j-1] + n;
		}
		if(old == a){old = b; curr = a;}
		else {old = a; curr =b;}
		i++;
	}
	int mx = 0;
	for (i=0; i<rows; i++){
//		mx = max(mx, old[i]);
		if(old[i] > mx){mx = old[i]; }
//		printf("max value changing  = %d\n", mx);
	}
//	printf("max = %d\n", mx);
	put_i(mx);
	return;
}

int main(){
	int iter = 0;
	int rows = 0; //number of rows
	iter = get_i();
//	int p = get_i();
//	printf("get_i() = %d\n", p);
//	put_i(567);
	while(iter){
		rows = get_i();
		sumtrian(rows);
		iter--;
		rows = 0;
	}
	return 0;
}


