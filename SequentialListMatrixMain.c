#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "SequentialListMatrix.h"

int main() {

	arrayList* NewarrayList = createArrayList(10);

	if (sizeArrayList(NewarrayList) == 0)
		printf("Creat ok\n\n");

	// Insert test

	insertArrayList(NewarrayList);

	printArrayList(NewarrayList);

	printArrayList(MakeArrayListT(NewarrayList)); //전치행렬

	printArrayList(MakeArrayListT(NewarrayList)); //전치행렬의 전치행렬은 원본

	destroyArrayList(NewarrayList);

	return 0;
}
