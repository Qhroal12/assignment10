#include <stdio.h>
#include <stdlib.h>

typedef unsigned int elementArrayList;				//양의 정수

typedef struct arrayListType {

	elementArrayList* data;
	int size;
	int capacity;
} arrayList;

extern arrayList* createArrayList(int size);
extern void destroyArrayList(arrayList* al);

extern int isEmptyArrayList(arrayList* al);
extern int isFullArrayList(arrayList* al);
extern int sizeArrayList(arrayList* al);

extern int insertArrayList(arrayList* al, int pos, elementArrayList item);
extern elementArrayList deleteArrayList(arrayList* al, int pos);
extern int initArrayList(arrayList* al);

extern elementArrayList getItemArrayList(arrayList* al, int pos);
extern int replaceItemArrayList(arrayList* al, int pos, elementArrayList item);

extern void printArrayList(arrayList* al);
extern arrayList* NewcreateDataList(arrayList* al, int Newsize);