#include <stdio.h>

// Function to swap two elements in the array and print the array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print the elements of the array
void print_array(int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Lomuto partition scheme for Quick Sort
int partition(int *array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
            print_array(array, high + 1); // Print the array after each swap
        }
    }

    swap(&array[i + 1], &array[high]);
    print_array(array, high + 1); // Print the array after placing the pivot

    return i + 1;
}

// Quick Sort function using Lomuto partition scheme
void quick_sort(int *array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
    }
}

// Wrapper function for quick_sort
void sort_array(int *array, size_t size) {
    quick_sort(array, 0, size - 1);
}

int main() {
    int array[] = {12, 4, 5, 6, 7, 3, 1, 15};
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    print_array(array, size);

    sort_array(array, size);

    printf("\nSorted array: ");
    print_array(array, size);

    return 0;
}

