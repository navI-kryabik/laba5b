#include "vector.h"
#include <malloc.h>
#include <stdlib.h>

// возвращает структуру-дескриптор вектор из n значений.
vector createVector(size_t n) {
    int *data = (int *) malloc(sizeof(int) * n);
    if (data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return (vector) {data, 0, n};
}

// изменяет количество памяти на newCapacity
// выделенное под хранение элементов вектора v
void reserve(vector *v, size_t newCapacity) {
    v->capacity = newCapacity;
    v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
    bool flag = newCapacity != 0;
    if (v->data == NULL && flag) {
        fprintf(stderr, "bad alloc");
        exit(1);
    } else if (newCapacity < v->size)
        v->size = newCapacity;
}

// удаляет элементы из контейнера v
void clear(vector *v) {
    v->size = 0;
}

// освобождает память, выделенную под
// неиспользуемые элементы контейнера v
void shrinkToFit(vector *v) {
    v->capacity = v->size;
}

// освобождает память, выделенную вектору v
void deleteVector(vector *v) {
    reserve(v, 0);
}

// проверяет, является ли вектор v пустым
bool isEmpty(vector *v) {
    return (v->size == 0);
}

// проверяет, является ли вектор v полным
bool isFull(vector *v) {
    return (v->size == v->capacity && v->size != 0);
}

// возвращает i-ый элемент вектора v.
int getVectorValue(vector *v, size_t i) {
    return (v->data[i]);
}

// добавляет элемент x в конец вектора.
void pushBack(vector *v, int x) {
    if (v->capacity == 0)
        reserve(v, 1);
    if (isFull(v))
        reserve(v, 2 * v->capacity);
    v->data[v->size] = x;
    v->size += 1;
}

// удаляет последний элемент из вектора v.
void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "Vector empty");
        exit(1);
    }
    v->size -= 1;
}

// возвращает указатель на
// index-ый элемент вектора.
int *atVector(vector *v, size_t index) {
    if (index >= v->size) {
        fprintf(stderr, "IndexError: a[%zu] is not exists", index);
        exit(1);
    }
    return &v->data[index];
}

// возвращает указатель на последний элемент вектора v.
int *back(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "Vector empty");
        exit(1);
    } else
        return &v->data[v->size - 1];
}

// возвращает указатель на первый элемент вектора v.
int *front(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "Vector empty");
        exit(1);
    } else
        return &v->data[0];
}