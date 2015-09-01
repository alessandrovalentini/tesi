// gcc ./rnc.c; ./a.out; rm ./a.out
#include <stdio.h>

struct Couple{ int a,b; };

struct Couple setCouple(int a, int b){
	struct Couple s = {.a = a, .b = b};
	return s;
}


struct Couple r_egcd(struct Couple s){

	struct Couple old_s;	

	if (s.b == 0)
		return setCouple(1, 0);

	else{
		old_s = s;
		s = r_egcd(setCouple(s.b, (s.a % s.b)));
		return setCouple(s.b, s.a - s.b * (old_s.a/old_s.b));
	}
}

struct Couple i_egcd(struct Couple q){
	int tmp;

	int s = 0, old_s = 1;
	int t = 1, old_t = 0;
	int r = q.b, old_r = q.a;
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

	return setCouple(old_t, old_s);
}

void encode(int x, int m1, int m2, int enc[]){
	enc[0] = x%m1;
	enc[1] = x%m2;
}

int decode (int enc[], int m1, int m2){
	int v, k;
	int m = m1*m2;

	struct Couple s = i_egcd(setCouple(m1, m2));

	v = enc[0]*m2*s.a + enc[1]*m1*s.b;
	k = ((v%m)+m)%m;

	return k;
}

int main(){
	int x=37;
	int enc[2];
	int m1=31, m2=17;

	//Safety check:
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

