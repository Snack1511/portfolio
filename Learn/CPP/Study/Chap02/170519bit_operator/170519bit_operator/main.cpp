#include<stdio.h>


const int key_01 = 0x0001;
const int key_02 = 0x0002;
const int key_04 = 0x0004;
const int key_08 = 0x0008;
const int key_16 = 0x0010;
const int key_32 = 0x0020;
const int key_64 = 0x0040;

void CheckKey(int _key);

int main(){

	int i = key_32;
	i |= key_01;
	i |= key_02;
	i |= key_04;
	i |= key_08;
	i |= key_16;
	i |= key_32;
	i |= key_64;
	
	
	CheckKey(i);

	//short c = 32768;

	//printf("%d\n", c);
	

	return 0;
	
}


void CheckKey(int _key){

	if(_key & 1)
	{
		printf("1\n");
	}
	if(_key & 2)
	{
		printf("2\n");
	}
	if(_key & 4)
	{
		printf("4\n");
	}
	if(_key & 8)
	{
		printf("8\n");
	}
	if(_key & 16)
	{
		printf("16\n");
	}
	if(_key & 32)
	{
		printf("32\n");
	}
	if(_key & 64)
	{
		printf("64\n");
	}
	if(_key & 128)
	{
		printf("128\n");
	}

}






//00000001 =   1
//00000010 =   2
//00000100 =   4
//00001000 =   8
//00010000 =  16
//00100000 =  32
//01000000 =  64
//10000000 = 128



// char == -128   ~ 127
//short == -32768 ~ 32767

//비트연산자