#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

struct vector init(int size) {
    vector v;
    v.size = size;
    v.current_element = 0;
    v.values = malloc(sizeof(int) * size);
    return v;
}

void push_back(struct vector* self, int value) {
    if (self->current_element == self->size) {
        int copy[self->size];
        for (int i = 0; i < self->size; ++i) {
            copy[i] = self->values[i];
        }
        free(self->values);
        self->size *= 2;
        self->values = malloc(sizeof(int) * self->size);
        for (int i = 0; i < self->current_element; ++i) {
            self->values[i] = copy[i];
        }
        self->values[self->current_element] = value;
        self->current_element++;
    }
    else {
        self->values[self->current_element] = value;
        self->current_element++;
    }
}

void delete_vector(struct vector* self) {
    free(self->values);
    self->values = NULL;
    self->size = 0;
    self->current_element = 0;
}

void print_vector(struct vector self) {
    for (int i = 0; i < self.current_element; ++i) {
        printf("%d ", self.values[i]);
    }
    printf("\n");
}

int pop_back(struct vector* self) {
    int last_element = self->current_element - 1;
    self->current_element--;
    return self->values[last_element];
}

struct vector* reverse(struct vector* self) {
    int temp;
    int start = 0;
    int end = self->current_element - 1;
    while (start < end) {
        temp = self->values[start];
        self->values[start] = self->values[end];
        self->values[end] = temp;
        start++;
        end--;
    }
    return self;
}

void erase(struct vector* self, int pos) {
    if (pos >= self->current_element || pos < 0) {
        printf("Index out of range");
    }
    else {
        for (int i = pos + 1; i < self->current_element; ++i) {
            self->values[i - 1] = self->values[i];
        }
        self->current_element--;
    }
}