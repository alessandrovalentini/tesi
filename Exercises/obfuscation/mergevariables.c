//gcc ./mergevariables.c; ./a.out; rm ./a.out

#include <stdio.h>

long encode (char c1, char c2, char c3, char c4){
	long l;
  	l = c1 + 256*c2 + 256*256*c3 + 256*256*256*c4;  
	return l;
}

void decode (long l){
	char d1, d2, d3, d4;

	d1 = l%256;
  	d2 = (l/256)%(256*256);
  	d3 = (l/(256*256))%(256*256*256);
  	d4 = (l/(256*256*256));
  	
  	printf("Deobfuscated: %c%c%c%c \n",d1,d2,d3,d4);
}

void dirtyDecode (long l){
	char d1, d2, d3, d4;

	d1 = l;
  	d2 = l/256;
  	d3 = l/(256*256);
  	d4 = (l/(256*256*256));
  	
  	printf("Deobfuscated dirty: %c%c%c%c \n",d1,d2,d3,d4);
}

int main(){
  char c1 = 'c', c2 = 'i', c3 = 'a', c4 ='o';
  char d1, d2, d3, d4; 
  long l;

  printf("Original: %c%c%c%c \n",c1,c2,c3,c4);
  
  l = encode(c1, c2, c3, c4);
  printf("Obfuscated: %ld \n",l);

  decode(l);
  dirtyDecode(l);
  
  return 0;
}


/*
//2-to-one  version

int main(){
  char c1 = 'a', c2 = 'b';
  char d1, d2;
  
  long l;

  l = c1 + 255*c2;
  //l = c1;
  printf("Original: %c%c \n",c1,c2);
  printf("Obfuscated: %ld \n",l);
  d1 = l%255;
  d2 = l/255;
  printf("Deobfuscated: %c%c \n",d1,d2);
  return 0;
}
*/
