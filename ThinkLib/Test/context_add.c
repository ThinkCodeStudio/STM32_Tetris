#include "stdio.h"
#include "string.h"

char* context;
unsigned long len = 0;
unsigned char count = 0;

void Add(char p[]){
	long size = sizeof(p[])/sizeof(char);
	len += size;
	char temp[len];
	strcat(temp,p);
	context = temp;
	count++;
}

int main(){
	char sd[] = "Hello";
	char sdd[] = " ";
	char sad[] = "World";
	Add(sd);
	Add(sdd);
	Add(sad);

	printf("%s\n%d\n%ld",context,count,len);
}
