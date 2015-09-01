#include <stdio.h>

void encode(int x, int m1, int m2, int[] enc){
	enc[0] = x%m1;
	enc[1] = x%m2;
}

int decode (int[] enc){
	int dec;

	return dec;	
}


int xeuclide(int a, int b) // prototipo della funzione Euclide //
{
    while(b) //ripetere finché non riduciamo a zero
    {
         int r = a%b;
         a=b; b=r; //scambiamo il ruolo di a e b
    }
    return a; //... e quando b è (o è diventato) 0, il risultato è a
}

int main(){
	int x=10;
	int enc[2];
	int m1=4, m2=5;
	
	encode(x, m1, m2, enc);
	
	printf("Original: x=%d",x);
	printf("MCD: x1m=%d, x1m=%d",enc[0],enc[1]);
}
