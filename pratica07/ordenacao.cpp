/*
 * ordenacao.cpp
 *
 *  Created on: 20 de out de 2017
 *      Author: ramide
 */

#include <iostream>
#include <stdlib.h>
#include <chrono>

using namespace std;

// Swap two values
// Can be used in sorting functions
void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

// Make a copy of an array into a new one
int* clone(int *array, int size) {
	int *copy = new int[size];
	for (int i = 0; i < size; i++) {
		copy[i] = array[i];
	}
	return copy;
}

// NO-OP Sort: don't mess with it
void noopsort(int *array, int size) {
	// no-op
}

void bubblesort(int *array, int size) {
	int tam = size - 1;
	int conferir = 0;
	while (conferir == 0) {
		conferir = 1;
		for (int i = 0; i < tam; i++) {
			if (array[i] > array[i + 1]) {
				swap(array[i], array[i + 1]);
				conferir = 0;
			}
		}
		tam--;
	}
}

void selectionsort(int *array, int size) {

	for (int index = 0; index < size - 1; index++) {
		int minimo_index = index;

		for (int index2 = index + 1; index2 < size; index2++) {
			if (array[minimo_index] > array[index2]) {
				minimo_index = index2;
			}
		}
		;

		swap(array[minimo_index], array[index]);
	};

}

void insertionsort(int *array, int size) {
	//TO DO
}

// Merges the subarrays in aux to array, i.e. array[...] = aux[...]
void merge(int *array, int *aux, int start, int mid, int finish) {
	int i = start;
	int j = mid;
	int k = start;

	while (i < mid && j <= finish) {

		if (aux[i] <= aux[j]) {
			array[k] = aux[i];
			i++;
		} else {
			array[k] = aux[j];
			j++;
		}
		k++;

	}
	while (i < mid) {
		array[k] = aux[i];
		i++;
		k++;
	}
	while (j <= finish) {
		array[k] = aux[j];
		j++;
		k++;
	}
}

// Array: array that will contain the sorted result
// Aux: auxiliary array used to sort the two halves, left and right
// Notice that in the recursive call to mergesorte, array and aux alternate
// That is, one time one is the main and the other is the auxiliary, then they reverse
void mergesort(int *array, int *aux, int start, int finish) {
	if (start >= finish)
		return;

	int mid = (start + finish) / 2;

	mergesort(aux, array, start, mid);
	mergesort(aux, array, mid + 1, finish);

	merge(array, aux, start, mid + 1, finish);
}

// Function called initially;
// Call the mergesorte() function above with start and finish bounds, and array clone (aux).
void mergesort(int *array, int size) {
	int *aux = clone(array, size);
	mergesort(array, aux, 0, size - 1);
	delete[] aux;
}

// QuickSort partition
int partition(int *array, int start, int finish) {
	int pivo = array[finish];
	int p = start - 1;
	for (int i = start; i < finish; i++) {
		if (array[i] <= pivo) {
			p++;
			swap(array[i], array[p]);
		}
		//swap(array[i], array[p]);
	}

	swap(array[p + 1], array[finish]);

	return p + 1;
}

void quicksort(int *array, int start, int finish) {
	if (finish <= start)
		return;
	int pivot = partition(array, start, finish);
	quicksort(array, start, pivot - 1);
	quicksort(array, pivot + 1, finish);
}

// Similar to MergeSort.
void quicksort(int *array, int size) {
	quicksort(array, 0, size - 1);
}

// Utility Functions

// Validates an array (i.e. whether it's sorted or not)
int validate(int *data, int size) {
	for (int i = 0; i < size - 1; i++) {
		if (data[i] > data[i + 1])
			return 0;
	}
	return 1;
}

// Display an array on the screen
void print(int *data, int size) {
	for (int i = 0; i < size; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}

// Tests an algorithm passed as a parameter.
void test(int *array, int size, const char *name, void function(int*, int),
		int printFlag) {
	int *copy = clone(array, size);
	auto start = std::chrono::high_resolution_clock::now();

	function(copy, size);

	auto finish = std::chrono::high_resolution_clock::now();
	long elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(
			finish - start).count() / 1000;

	int valid = validate(copy, size);
	cout << name << ": " << (valid ? "ok" : "erro") << " (tempo[us] = "
			<< elapsed << ") ";

	if (printFlag)
		print(copy, size);
	else
		cout << endl;

	delete[] copy;
}

int main() {
	int size = 10;
	int print = 1;

	int *array = new int[size];

	for (int i = 0; i < size; i++) {
		array[i] = rand() % (size * 2);
	}

	test(array, size, "NoOpSort     ", noopsort, print);
	test(array, size, "BubbleSort   ", bubblesort, print);
	test(array, size, "SelectionSort", selectionsort, print);
	test(array, size, "InsertionSort", insertionsort, print);
	test(array, size, "MergeSort    ", mergesort, print);
	test(array, size, "QuickSort    ", quicksort, print);

	delete[] array;
}

