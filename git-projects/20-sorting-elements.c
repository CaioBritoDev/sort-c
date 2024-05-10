#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number within a given interval [min, max]
int getRandomNumber(int min, int max) {
    // Generate a random number within the interval [min, max]
    return min + rand() % (max - min + 1);
}

int* createArray(unsigned int max_elements) {
	int* arr = (int*) malloc(sizeof(int) * max_elements);
	for (int i = 0; i < max_elements; i++) {
		arr[i] = getRandomNumber(0, 200);
	}
	return arr;
}

void printItems(int* arr, unsigned int size) {
	for (int i = 0; i < size; i++) {
		printf("%ist item: %i\n", i+1, arr[i]);
	}
}

// Bubble sort -> Sorting an array by defining the greatest value and repeating, ensuring that all positions are in the right place.

void bubbleSort(int* arr, unsigned int size) {
	for (int finishPosition = size-1; finishPosition > 1; finishPosition--) {
		for (int currentPosition = 0; currentPosition < finishPosition; currentPosition++) {
			int aux, p1, p2;
			p1 = arr[currentPosition];
			p2 = arr[currentPosition+1];
			if (p1 > p2) { // Swap positions
				aux = p2;
				p2 = p1;
				p1 = aux;
				arr[currentPosition] = p1;
				arr[currentPosition+1] = p2;
			}
		}	
	}
}

// Select sort -> Sorting an array by selecting the smallest value and put it in the begin of array. Repeating the process. The begin is relative -> the paramater is the iteration.

int* getMinimum(int* arr, int init, unsigned int size) {
	int* min = &arr[init];
	for (int i = init; i < size-1; i++) {
		if (arr[i+1] < *min) {
			*min = arr[i+1];
		}
	}
	return min;
}

// 1 - Get the minimum value of the whole arr and put in the index 0
// 2 - Get the minimum value of the subvector (arr - first position) and put in the index 1
// So...
// N - Get the minimum value of the subvector (arr - N - 1 position) and put in the index N - 1
// Do that until the size of subvector reaches 1

void selectSort(int* arr, unsigned int size) {
	for (int i = 0; i < size; i++) {
		int* min = getMinimum(arr, i, size);
		int aux = arr[i];
		arr[i] = *min;
		*min = aux;
	}	
}

int main() {
	srand(time(NULL));
	unsigned int max_elements = 20;
	int* arr1 = createArray(max_elements);
	int* arr2 = createArray(max_elements);

	//bubbleSort(arr1, max_elements);	
	//printItems(arr1, max_elements);

	selectSort(arr2, max_elements);
	printItems(arr2, max_elements);

	free(arr1);
	free(arr2);
	return 0;
}
