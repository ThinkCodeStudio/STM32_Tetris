#include "stdio.h"
char* Slice(char* dat, int dt, int size){
	char temp[size];
	char* p = temp;
	dat += dt;
	for(int i = 0; i < size; i++){
		temp[i] = *dat;
		dat++;
	}
	return p;
}
int main(){
	char temp[] = {
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9
	};
	char* t = Slice(temp,2,3);
	for(int i=0;i<3;i++){
		printf("%d\n",*t);
		t++;
	}
}
