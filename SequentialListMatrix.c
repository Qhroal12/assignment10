#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "SequentialListMatrix.h"

#define MAX 20

arrayList* createArrayList(int size) {

	arrayList* arr = (arrayList*)malloc(sizeof(arrayList));

	arr->data = (elementArrayList**)malloc(sizeof(elementArrayList*) * size);
		for(int i = 0; i < size; i++)
			*(arr->data + i) = (elementArrayList*)malloc(sizeof(elementArrayList) * size);

	arr->size = 0;
	arr->capacity = size * size;
	arr->lineSize = size;

	for (int i = 0; i < arr->lineSize; i++) {
		for (int j = 0; j < arr->lineSize; j++)
			*(*(arr->data + i) + j) = 0;
	}

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

int insertArrayList(arrayList* al) {
	srand((unsigned int)time(NULL));

	for (int i = 0; i < al->capacity; i++) {
		if (al->size > MAX - 1)						//최대 갯수를 넘어가게 수를 넣으면
			break;				

		int randomRow, randomPos;

		randomRow = rand() % al->lineSize;			//랜덤 행
		randomPos = rand() % al->lineSize;			//랜덤 열
		
		if (*(*(al->data + randomRow) + randomPos) != 0) {						//이미 수가 들어가있으면 스킵
			continue;
		}
		else {
			*(*(al->data + randomRow) + randomPos) = (rand() % 100) + 1;
			al->size++;
		}
	}

	return 1;
}

void printArrayList(arrayList* al) {

	if (al->size < 1)
		printf("순차 리스트가 존재하지 않습니다.\n");

	else {
		printf("순차 리스트 : \n");

		for (int i = 0; i < al->lineSize; i++) {
			for (int j = 0; j < al->lineSize; j++) {

				if (*(*(al->data + i) + j) < 10) {
					printf("0%d ", *(*(al->data + i) + j));
				}																	//1자리 수 가독성 전용

				else
				printf("%d ", *(*(al->data + i) + j));
			}
			printf("\n");
		}
		printf("사이즈 : %d\n", sizeArrayList(al));
		printf("\n");
	}
}

arrayList* MakeArrayListT(arrayList* al) {

	int count = 0;
	int temp = 0;

	for (int i = 0; i < al->lineSize; i++) {
		for (int j = 0; j < al->lineSize; j++) {
			if (i == j || i > j)												//대각 위치거나 대칭 이동해야 하는 행렬의 위치시 스킵 
				continue;
			else {
				temp = *(*(al->data + i) + j);									//(0,1) -> temp
				count++;												

				*(*(al->data + i) + j) = *(*(al->data + j) + i);				//(1,0) -> (0,1)
				count++;

				*(*(al->data + j) + i) = temp;									//temp -> (1,0)
				count++;														//한 번 대칭이동 시 3번의 이동 발생
			}
		}
	}

	printf("데이터 이동 횟수: %d\n", count);
	printf("대칭 이동된 ");

	return al;
}
