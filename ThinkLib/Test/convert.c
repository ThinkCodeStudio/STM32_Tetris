#include "stdio.h"
#define BIT 8
#define U unsigned
void ToBit(U int da){
	while(da != 0){
		printf("%d",da%2);
		da /= 2;
	}
	printf("\n");
}
U char* ToChar(U int data){
	U char buf[4];
	U char* p = buf;
	for(int i = 3; i >= 0; i--){
		buf[i] = (char)data;
		printf("%d\n",buf[i]);
		data >>= BIT;
	}
	return p;
}

U int ToInt(U char* p){
	U int val = 0;
	printf("\n");
	for(int i = 0; i < 4; i++){
		val <<= BIT;
		val |= *p;
		printf("%d:",*p);
		ToBit(val);
		p++;
	}
	return val;
}

int main(){
	printf("char:%ld,int:%ld\n",sizeof(char),sizeof(int));
	U char* p = ToChar(40);
	char buf[4];
	for(int i = 0; i<4; i++){
		printf("%d\n",*p);
		buf[i] = *p;
		p++;
	}
	U int v = ToInt(buf);
	ToBit(v);
	printf("result:%d\n",v);
}
