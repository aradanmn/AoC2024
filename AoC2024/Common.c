//
//  Common.c
//  AoC2024
//
//  Created by Scott Dean on 12/15/24.
//

#include "Common.h"

FILE* FileOpen(const char* filename, const char* mode) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        perror("Failed to open file");
        return NULL;
    }
    return file;
}

// Function to initialize the dynamic array
void initArray(DynamicArray *arr, int initialCapacity) {
    arr->data = (int *)calloc(2,initialCapacity * sizeof(int));
    arr->size = 0;
    arr->capacity = initialCapacity;
    int *tmp = realloc(arr->data, 2);
    arr->data = tmp;
}

// Function to add an element to the array
void addElement(DynamicArray *arr, int value) {
    if (arr->size == arr->capacity) {
        // Resize array if full
        arr->capacity *= 2;
        arr->data = (int *)realloc(arr->data, arr->capacity * sizeof(int));
    }
    memset(arr->data+arr->size,0,arr->size * sizeof(arr->data));
    arr->data[arr->size++] = value;
}

// Function to free the array memory
void freeArray(DynamicArray *arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = arr->capacity = 0;
}
