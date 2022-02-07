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

bool isEmpty(vector *v) {
    return (v->size == 0);
}

bool isFull(vector *v) {
    return (v->size == v->capacity && v->size != 0);
}

int getVectorValue(vector *v, size_t i) {
    return (v->data[i]);
}

void pushBack(vector *v, int x) {
    if (v->capacity == 0)
        reserve(v, 1);
    if (isFull(v))
        reserve(v, 2 * v->capacity);
    v->data[v->size] = x;
    v->size += 1;
}

void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "Vector empty");
        exit(1);
    }
    v->size -= 1;
}

