// gcc ./rnc.c; ./a.out; rm ./a.out
#include <stdio.h>

void encode(int x, int m1, int m2, int m3, int enc[]){
	enc[0] = x%m1;
	enc[1] = x%m2;
	enc[2] = x%m3;
}

int decode (int enc[], int m1, int m2, int m3){
	int v, k;
	int m = m1*m2*m3;

	v = enc[0]*m2*m3*egcd(m2*m3,m1) + enc[1]*m1*m3*egcd(m1*m3,m2) + enc[2]*m1*m2*egcd(m1*m2,m3);
	k = ((v%m)+m)%m;

	//return  v+k*m;	
	return k;
}


int gcd(int a, int b){
	if (b == 0)
		return a;	
	else
		gcd(b, (a%b));
}


void extended_gcd(int, int);


int main(){
	int x=37;
	int enc[3];
	int m1=17, m2=31, m3=43;
	
	encode(x, m1, m2, m3, enc);
	
	printf("Original: x = %d \n",x);
	printf("Encoded:  x'= [%d,%d,%d] \n",enc[0],enc[1], enc[2]);
	printf("Decoded:  %d \n", decode(enc, m1, m2, m3));

	//extended_gcd(4, 15);
	//extended_gcd(15, 4);
}

//from wiki pseudocode
int egcd(a, b){
	int tmp;
	int swp = 0;
	if (a < b){
		tmp = a;
		a = b;
		b = tmp;
		swp = 1;
	}
		

	int s = 0;    
	int old_s = 1;
    	int t = 1;    
	int old_t = 0;
    	int r = b;    
	int old_r = a;
	int quotient;

    	while (r != 0){
		quotient = old_r / r;
		tmp = r;		
		r = old_r - quotient * r;
		old_r = tmp;
		tmp = s;
		s = old_s - quotient * s;
		old_s = tmp;
		tmp = t;
		t = old_t - quotient * t;
		old_t = tmp;
	}

	/*if (swp == 1)
		printf( "Bézout coefficients: %d %d \n", old_t, old_s);
	else
		printf( "Bézout coefficients: %d %d \n", old_s, old_t);

	printf( "greatest common divisor: %d \n", old_r);
	printf( "quotients by the gcd: %d %d \n\n", t, s);
	*/
	if (swp == 1)
		return old_t;
	else
		return old_s;
}


/* Iterative version
int gcd ( int a, int b ){
  int c;
  while ( a != 0 ) {
	c = a; 
	a = b%a;  
	b = c;
  }
  return b;
}*/
