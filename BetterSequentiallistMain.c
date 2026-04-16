#include <stdio.h>
#include <stdlib.h>

#include "BetterSequentiallist.h"

int main() {

	arrayList* NewarrayList = createArrayList(5);

	if (sizeArrayList(NewarrayList) == 0)
		printf("Creat ok\n");

	// Insert test
	insertArrayList(NewarrayList, 0, 5); // 최초 삽입
	insertArrayList(NewarrayList, 1, 10);
	insertArrayList(NewarrayList, 2, 15);
	insertArrayList(NewarrayList, 3, 20);
	insertArrayList(NewarrayList, 4, 25); //마지막 삽입

	printArrayList(NewarrayList);

	// Add test

	insertArrayList(NewarrayList, 10, 100); // 용량이 꽉 찬 상태에서 넣었기 때문에 기존 용량에서 pos까지 추가
	insertArrayList(NewarrayList, 6, 30);
	printf("용량 상태 = %d\n", isFullArrayList(NewarrayList));
	insertArrayList(NewarrayList, 100, 123456);	//아직 다 안 찼기 때문에 용량을 추가하지 않음

	printArrayList(NewarrayList);

	//Delete test
	deleteArrayList(NewarrayList, 4);
	deleteArrayList(NewarrayList, 0);

	printArrayList(NewarrayList);

	//Init test
	replaceItemArrayList(NewarrayList, 0, 300);
	replaceItemArrayList(NewarrayList, 5, 400); //없는 곳은 replace하지 않음

	printArrayList(NewarrayList);

	insertArrayList(NewarrayList, 5, 20);
	replaceItemArrayList(NewarrayList, 5, 900); //replace 확인

	printArrayList(NewarrayList);

	destroyArrayList(NewarrayList);


	return 0;
}
