#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int elementArrayList;

typedef struct arrayListType {

	elementArrayList** data;
	int size;
	int capacity;
	int lineSize;

} arrayList;

extern arrayList* createArrayList(int size);
extern void destroyArrayList(arrayList* al);

extern int isEmptyArrayList(arrayList* al);
extern int isFullArrayList(arrayList* al);
extern int sizeArrayList(arrayList* al);

extern int insertArrayList(arrayList* al);

extern void printArrayList(arrayList* al);
extern arrayList* MakeArrayListT(arrayList* al);
