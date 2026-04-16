#include <stdio.h>
#include <stdlib.h>

#include "BetterSequentiallist.h"

arrayList* createArrayList(int size) {

	arrayList* arr = (arrayList*)malloc(sizeof(arrayList));

	arr->data = (elementArrayList*)malloc(sizeof(elementArrayList*) * size);
	arr->size = 0;
	arr->capacity = size;

	for (int i = 0; i <= size; i++)
		arr->data[i] = NULL;

	return arr;
}

void destroyArrayList(arrayList* al) {
	free(al->data);
	free(al);

	printf("메모리를 해제합니다.");
}

int isEmptyArrayList(arrayList* al) {
	if (al->size == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int isFullArrayList(arrayList* al) {
	if (al->size == al->capacity) {
		return 1;
	}
	else {
		return 0;
	}
}

int sizeArrayList(arrayList* al) {
	return al->size;
}

int insertArrayList(arrayList* al,
	int pos, elementArrayList item) {
	if (pos < 0) {
		return 0;
	}

	if (isFullArrayList(al) == 1) {
		printf("메모리 용량을 재조정합니다.\n");
		NewcreateDataList(al, pos - (al->capacity - 1));
		insertArrayList(al, pos, item);
	}

	if (al->data[pos] != NULL) {
		replaceItemArrayList(al, pos, item);
	}
	else {
		for (int i = al->size; i >= pos; i--) {
			al->data[i + 1] = al->data[i];
		}

		al->data[pos] = item;
		al->size++;
	}

	return 1;
}

elementArrayList deleteArrayList(
	arrayList* al, int pos) {
	if (pos < 0 || pos > al->size - 1) {
		return 0;
	}

	elementArrayList item = al->data[pos];


	for (int i = pos; i < al->capacity - 1; i++) {
		al->data[i] = al->data[i + 1];
	}
	al->data[al->capacity - 1] = NULL;

	al->size--;
	al->data[al->size] = NULL;

	return item;
}

int initArrayList(arrayList* al) {
	for (int i = al->size - 1; i >= 0; i--) {
		deleteArrayList(al, i);
	}
}

elementArrayList getItemArrayList(
	arrayList* al, int pos) {
	return al->data[pos];
}

int replaceItemArrayList(arrayList* al,
	int pos, elementArrayList item) {
	if (pos < 0 || pos > al->size - 1) {
		return 0;
	}

	al->data[pos] = item;

	return 1;
}

void printArrayList(arrayList* al) {
	/*
	int Voidlist = 0;

	for (int i = 0; i < al->capacity; i++) {
		if (al->data[i] != NULL) {
			if (i > Voidlist) {
				al->data[Voidlist] = al->data[i];
				al->data[i] = NULL;
			}
			Voidlist++;
		}
	}
	*/

	if (al->size < 1)
		printf("순차 리스트가 존재하지 않습니다\n");
	else {
		printf("순차 리스트: ");

		for (int i = 0; i < al->capacity; i++)
			printf("%d ", al->data[i]);

		printf("\n");
	}
}

arrayList* NewcreateDataList(arrayList* al, int Newsize) {

	elementArrayList* Newarr = (elementArrayList*)realloc(al->data, sizeof(elementArrayList*) * (al->capacity + Newsize));
	al->data = Newarr;

	for (int i = al->capacity; i < al->capacity + Newsize; i++)
		al->data[i] = NULL;

	al->capacity = al->capacity + Newsize;

	printf("재조정된 용량: %d\n", al->capacity);

	return al;

}


