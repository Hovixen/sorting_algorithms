#include <stdio.h>

// Function to swap two elements in the array and print the array after swap
void swap(int *array, int index1, int index2) {
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;

    // Print the array after each swap
    printf("After swapping indices %d and %d: ", index1, index2);
    for (int k = 0; k < 8; k++) {
        printf("%d ", array[k]);
    }
    printf("\n");
}

// Lomuto partition scheme for Quick Sort
int partition(int *array, int low, int high) {
    // Choose the last element as the pivot
    int pivot = array[high];
    
    // Index of smaller element
    int i = low - 1;
    
    // Traverse through the array
    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (array[j] <= pivot) {
            // Swap array[i] and array[j]
            i++;
            swap(array, i, j);
        }
    }
    
    // Swap array[i+1] and array[high] to place the pivot in the correct position
    swap(array, i + 1, high);
    
    // Return the partition index
    return i + 1;
}

// Quick Sort function using Lomuto partition scheme
void quick_sort(int *array, int low, int high) {
    if (low < high) {
        // Find the partition index
        int pi = partition(array, low, high);
        
        // Recursively sort the sub-arrays
        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
    }
}

// Wrapper function for quick_sort
void sort_array(int *array, size_t size) {
    quick_sort(array, 0, size - 1);
}

int main() {
    // Example usage
    int array[] = {12, 4, 5, 6, 7, 3, 1, 15};
    size_t size = sizeof(array) / sizeof(array[0]);
    
    printf("Original array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    // Call the sorting function
    sort_array(array, size);
    
    printf("\nSorted array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    
    return 0;
}

