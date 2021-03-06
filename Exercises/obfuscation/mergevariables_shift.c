//gcc ./mergevariables.c; ./a.out; rm ./a.out

#include <stdio.h>

long encode (char c1, char c2, char c3, char c4){
	long l, l1, l2, l3, l4;
  	l1 = c1;
  	l2 = c2<<8;
  	l3 = c3<<16;
  	l4 = c4<<24;  
  	l = l1 + l2 + l3 + l4;
	return l;
}

void decode (long l){
	char d1, d2, d3, d4;

	d1 = l;
  	d2 = l >> 8;
  	d3 = l >> 16;
  	d4 = l >> 24;
  	
  	printf("Deobfuscated: %c%c%c%c \n",d1,d2,d3,d4);
}

int main(){
  char c1 = 'c', c2 = 'i', c3 = 'a', c4 ='o';
  char d1, d2, d3, d4; 
  long l;

  printf("Original: %c%c%c%c \n",c1,c2,c3,c4);
  
  l = encode(c1, c2, c3, c4);
  printf("Obfuscated: %ld \n",l);

  decode(l);
  
  return 0;
}
