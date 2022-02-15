#include <stdio.h>
#include "libs/data_structures/vector/vector.h"
#include <assert.h>
#include "libs/data_structures/matrix/matrix.h"

bool isEqualVectors(vector *v1, vector *v2) {
    if (v1->size != v2->size) {
        return false;
    }
    for (size_t i = 0; i < v1->size; i++) {
        if (v1->data[i] != v2->data[i]) {
            return false;
        }
    }
    return true;
}

void test_create_newCapacity1() {
    vector v = createVector(3);
    assert(v.capacity == 3 && v.size == 0 && v.data != NULL);
    deleteVector(&v);
}

void test_create_newCapacity2() {
    vector v = createVector(0);
    assert(v.capacity == 0 && v.size == 0 && v.data != NULL);
    deleteVector(&v);
}

void test_create() {
    test_create_newCapacity1();
    test_create_newCapacity2();
}

void test_reserve_newCapacityIsNull() {
    vector v = createVector(2);
    pushBack(&v, 1);
    pushBack(&v, 2);
    reserve(&v, 0);
    assert(v.data == NULL);
    deleteVector(&v);
}

void test_reserve_newCapacityIsSmaller() {
    vector v = createVector(4);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    pushBack(&v, 4);
    reserve(&v, 2);
    assert(v.size == 2);
    deleteVector(&v);
}

void test_reserve_newCapacityIsMore() {
    vector v = createVector(3);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    reserve(&v, 6);
    assert(v.capacity == 6);
    deleteVector(&v);
}

void test_reserve() {
    test_reserve_newCapacityIsNull();
    test_reserve_newCapacityIsSmaller();
    test_reserve_newCapacityIsMore();
}

void test_clear_vector() {
    vector v = {(int[]) {1, 2}, 2, 5};
    clear(&v);
    assert(v.size == 0);
    deleteVector(&v);
}

void test_clear_full() {
    vector v = {(int[]) {7, 2, 3, 6, 9}, 5, 5};
    clear(&v);
    assert(v.size == 0);
    deleteVector(&v);
}

void test_clear_empty() {
    vector v = {(int[]) {}, 0, 0};
    clear(&v);
    assert(v.size == 0);
    deleteVector(&v);
}

void test_clear() {
    test_clear_vector();
    test_clear_full();
    test_clear_empty();
}

void test_shrinkToFit() {
    vector v = createVector(3);
    pushBack(&v, 1);
    pushBack(&v, 2);
    shrinkToFit(&v);
    assert(v.size == v.capacity);
    deleteVector(&v);
}

void test_isFull_fullVector() {
    vector v = {(int[]) {6, 2, 1, 9, 4}, 5, 5};
    assert(isFull(&v));
    deleteVector(&v);
}

void test_isFull_emptyVector() {
    vector v = {(int[]) {}, 0, 0};
    assert(!isFull(&v));
    deleteVector(&v);
}

void test_isFull() {
    test_isFull_fullVector();
    test_isFull_emptyVector();
}

void test_isEmpty_fullVector() {
    vector v = {(int[]) {4, 1, 8, 3, 2}, 5, 5};
    assert(!isEmpty(&v));
    deleteVector(&v);
}

void test_isEmpty_emptyVector() {
    vector v = {(int[]) {}, 0, 0};
    assert(isEmpty(&v));
    deleteVector(&v);
}

void test_isEmpty() {
    test_isEmpty_fullVector();
    test_isEmpty_emptyVector();
}

void test_getVectorValue_oneElement() {
    vector v = {(int[]) {5}, 1, 1};
    assert(getVectorValue(&v, 0) == v.data[0]);
    deleteVector(&v);
}

void test_getVectorValue_firstPosition() {
    vector v = {(int[]) {2, 6, 3, 8, 1}, 5, 5};
    assert(getVectorValue(&v, 0) == v.data[0]);
    deleteVector(&v);
}

void test_getVectorValue_lastPosition() {
    vector v = {(int[]) {4, 7, 1, 3, 9}, 5, 5};
    assert(getVectorValue(&v, 2) == v.data[2]);
    deleteVector(&v);
}

void test_getVectorValue() {
    test_getVectorValue_oneElement();
    test_getVectorValue_firstPosition();
    test_getVectorValue_lastPosition();
}

void test_pushBack_full() {
    vector v = createVector(1);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    vector expectedVector = {(int[]) {1, 2, 3}, 3, 4};
    assert(isEqualVectors(&v, &expectedVector));
    assert(v.capacity == expectedVector.capacity);
    deleteVector(&v);
    deleteVector(&expectedVector);
}


void test_pushBack_empty() {
    vector v = createVector(0);
    pushBack(&v, 1);
    vector expectedVector = {(int[]) {1}, 1, 1};
    assert(isEqualVectors(&v, &expectedVector));
    assert(v.capacity == expectedVector.capacity);
    deleteVector(&v);
    deleteVector(&expectedVector);
}

void test_pushBack() {
    test_pushBack_full();
    test_pushBack_empty();
}

void test_popBack() {
    vector v = createVector(0);
    pushBack(&v, 1);
    pushBack(&v, 2);
    popBack(&v);
    vector expectedVector = {(int[]) {1}, 1, 2};
    assert(isEqualVectors(&v, &expectedVector));
    assert(v.capacity == expectedVector.capacity);
    deleteVector(&v);
    deleteVector(&expectedVector);
}

void test_atVector_notEmpty() {
    vector v = createVector(1);
    pushBack(&v, 5);
    pushBack(&v, 2);
    assert(atVector(&v, 1) == &v.data[1]);
    deleteVector(&v);
}

void test_atVector_lastElement() {
    vector v = createVector(1);
    pushBack(&v, 5);
    pushBack(&v, 3);
    pushBack(&v, 7);
    pushBack(&v, 1);
    assert(atVector(&v, 2) == &v.data[2]);
    deleteVector(&v);
}

void test_atVector_firstElement() {
    vector v = createVector(1);
    pushBack(&v, 3);
    pushBack(&v, 5);
    pushBack(&v, 8);
    pushBack(&v, 7);
    pushBack(&v, 2);
    assert(atVector(&v, 0) == &v.data[0]);
    deleteVector(&v);
}

void test_atVector() {
    test_atVector_notEmpty();
    test_atVector_lastElement();
    test_atVector_firstElement();
}

void test_back_oneElement() {
    vector v = createVector(0);
    pushBack(&v, 4);
    assert(back(&v) == &v.data[0]);
    deleteVector(&v);
}

void test_back_multipleElements() {
    vector v = createVector(0);
    pushBack(&v, 3);
    pushBack(&v, 7);
    pushBack(&v, 9);
    pushBack(&v, 3);
    assert(back(&v) == &v.data[3]);
    deleteVector(&v);
}

void test_back() {
    test_back_oneElement();
    test_back_multipleElements();
}

void test_front_oneElement() {
    vector v = createVector(0);
    pushBack(&v, 3);
    assert(front(&v) == &v.data[0]);
    deleteVector(&v);
}

void test_front_multipleElements() {
    vector v = createVector(0);
    pushBack(&v, 7);
    pushBack(&v, 1);
    pushBack(&v, 8);
    pushBack(&v, 4);
    assert(front(&v) == &v.data[0]);
    deleteVector(&v);
}

void test_front() {
    test_front_oneElement();
    test_front_multipleElements();
}

void test() {
    test_create();
    test_reserve();
    test_clear();
    test_shrinkToFit();
    test_isEmpty();
    test_isFull();
    test_getVectorValue();
    test_pushBack();
    test_popBack();
    test_atVector();
    test_back();
    test_front();
}

int main() {



    return 0;
}
