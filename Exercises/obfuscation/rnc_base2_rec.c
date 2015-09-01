// gcc ./rnc.c; ./a.out; rm ./a.out
#include <stdio.h>

struct Bezout{ int a,b; };

struct Bezout setBezout(int a, int b){
	struct Bezout s = {.a = a, .b = b};
	return s;
}


struct Bezout egcd(struct Bezout s){

	struct Bezout old_s;

	if (s.a < s.b)
		s = setBezout(s.b, s.a);		

	if (s.b == 0)
		return setBezout(1, 0);

	else{
		old_s = s;
		s = egcd(setBezout(s.b, (s.a % s.b)));
		return setBezout(s.b, s.a - s.b * (old_s.a/old_s.b));
	}
}

void encode(int x, int m1, int m2, int enc[]){
	enc[0] = x%m1;
	enc[1] = x%m2;
}

int decode (int enc[], int m1, int m2){
	int v, k;
	int m = m1*m2;

	struct Bezout s = egcd(setBezout(m1, m2));

	v = enc[0]*m2*s.a + enc[1]*m1*s.b;
	k = ((v%m)+m)%m;

	//return  v+k*m;	
	return k;
}


int main(){
	int x=37;
	int enc[2];
	int m1=31, m2=17;
	
	int tmp;
	if (m1 > m2){
		tmp = m1;
		m1 = m2;
		m2 = tmp;
	}
	
	if (x >= m1*m2)
		return -1;

	encode(x, m1, m2, enc);
	
	printf("Original: x = %d \n",x);
	printf("Encoded:  x'= [%d,%d] \n",enc[0],enc[1]);
	printf("Decoded:  %d \n", decode(enc, m1, m2));

	return 0;
}

