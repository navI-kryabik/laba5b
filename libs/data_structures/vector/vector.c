#include "vector.h"
#include <malloc.h>
#include <stdlib.h>

vector createVector(size_t n) {
    int *data = (int *) malloc(sizeof(int) * n);
    if (data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    } else
        return (vector) {data, 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    v->capacity = newCapacity;
    if (v->data == NULL) {
        v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
        v->data = NULL;
    }
    if (v->data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    } else if (newCapacity == 0)
        v->data = NULL;
    else if (newCapacity < v->size)
        v->size = newCapacity;

}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->capacity = v->size;
}

void deleteVector(vector *v) {
    if (v->data == NULL) {
        free(v->data);
        v->data = NULL;
    }
}