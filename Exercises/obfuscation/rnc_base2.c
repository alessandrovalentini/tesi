// gcc ./rnc.c; ./a.out; rm ./a.out
#include <stdio.h>

void encode(int x, int m1, int m2, int enc[]){
	enc[0] = x%m1;
	enc[1] = x%m2;
}

int decode (int enc[], int m1, int m2){
	int v, k;
	int m = m1*m2;

	v = enc[0]*m2*egcd(m2,m1) + enc[1]*m1*egcd(m1,m2);
	k = ((v%m)+m)%m;

	return k;
}

int main(){
	int x=37;
	int enc[2];
	int m1=17, m2=31;
	
	encode(x, m1, m2, enc);
	
	printf("Original: x = %d \n",x);
	printf("Encoded:  x'= [%d,%d] \n",enc[0],enc[1]);
	printf("Decoded:  %d \n", decode(enc, m1, m2));

}

//from wiki pseudocode
int egcd(a, b){
	int tmp;

	int s = 0, old_s = 1;
	int t = 1, old_t = 0;
	int r = b, old_r = a;
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

	return old_s;
}


/* Greatest Common Divisor

//Iterative version
int gcd ( int a, int b ){
  int c;
  while ( a != 0 ) {
	c = a; 
	a = b%a;  
	b = c;
  }
  return b;

}

//recursive version
int gcd(int a, int b){
	if (b == 0)
		return a;	
	else
		gcd(b, (a%b));
}
*/
