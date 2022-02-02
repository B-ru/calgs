#include <stdio.h>
#include <stdlib.h>
#define INITSIZE 8
#define MULTIPLIER 2
#define OVERFLOW -100
#define UNDERFLOW -101
#define OUTOFMEMORY -102
////////
typedef struct{
	int length;
	int top;
	unsigned char* data;
} larray;
//proto/
larray* createLarray();
int push(larray* arr, unsigned char data);
unsigned char pop(larray* arr);
int enlargeArray(larray* arr);
void resize(larray* arr);
////////
int main(){
	larray* arr = createLarray();
	push(arr, 0);
	push(arr, 100);
	push(arr, 126);
	push(arr, 126);
	push(arr, 126);
	push(arr, 126);
	push(arr, 126);
	push(arr, 126);
	push(arr, 126);
	pop(arr);
	pop(arr);
	pop(arr);
	unsigned char temp = pop(arr);
	resize(arr);
	exit (0);
}
////////
larray* createLarray(){
	larray* arr = NULL;
	arr = malloc(sizeof(larray));
	if(arr == NULL) exit(OUTOFMEMORY);
	arr->length = INITSIZE;
	arr->data = malloc(arr->length * sizeof(void));
	if(arr->data == NULL){
		free(arr);
		exit(OUTOFMEMORY);
	}
	arr->top = 0;
	return arr;
}
////////
int push(larray* arr, unsigned char data){
	if(arr->length == arr->top) enlargeArray(arr);
	arr->data[arr->top++] = data;
	return 0;
}
////////
int enlargeArray(larray* arr){
	arr->length *= MULTIPLIER;
	arr->data = realloc(arr->data, arr->length);
	return 0;
}
////////
unsigned char pop(larray* arr){
	unsigned char buffer = arr->data[--arr->top];
	arr->data[arr->top] = 0;
	return buffer;	
}
////////
void resize(larray* arr){
	arr->length = arr->top;
	arr->data = realloc(arr->data, arr->length);
}
