#include <stdio.h>
#include "libs/data_structures/vector/vector.h"

int main() {
    vector v = createVector(0);

    popBack(&v);

    printf("%zu", v.size);

    return 0;
}
