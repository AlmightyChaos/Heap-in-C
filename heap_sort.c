#include <stdio.h>
#define LEN(x) (sizeof(x)/sizeof(typeof(x[0])))

void swap(int*, int*);
void maxHeapify(int [], int, int);
void buildHeapTree(int [], int);
void heapSort(int [], int);
void printSortedArray(int [], int);
int* max(int*, int* );

int main(void){
	int a[10] = {22,43,73,17,68,43,36,6,74,31};
	heapSort(a, LEN(a));
	printSortedArray(a, LEN(a));
	return 0;
}

void swap(int* x, int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void maxHeapify(int arr[], int size, int index){
	int left_index = 2*(index+1)-1;
	int right_index = 2*(index+1);
	int *greater;

	if (left_index >= size)
		return;

	if (right_index == size){
		if (arr[left_index] > arr[index] ? 1 : 0){
			swap(&arr[index], &arr[left_index]);
		}
	}
	else{
		if (*(greater = max(&arr[left_index], &arr[right_index])) > arr[index] ? 1 : 0){
			swap(&arr[index], greater);
			maxHeapify(arr, size, greater - arr);
		}
	}
}

void heapSort(int arr[], int size){
	buildHeapTree(arr, size);

	while(size > 1){
		swap(&arr[0], &arr[--size]);
		maxHeapify(arr, size, 0);
	}
}

void buildHeapTree(int arr[], int size){
	for (int i = size/2-1;i >= 0;--i)
		maxHeapify(arr, size, i);
}

void printSortedArray(int arr[], int size){
	for(int i = 0;i < size;++i)
		printf("%d\n", arr[i]);
}

int* max(int* x, int* y){

	return *x > *y ? x : y;
}
