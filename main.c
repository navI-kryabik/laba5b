#include "libs/data_structures/matrix/matrix.h"

void exercise1(matrix m) {
    position p1 = getMinValuePos(m);
    position p2 = getMaxValuePos(m);
    swapRows(m, p1.rowIndex, p2.rowIndex);
}

int main() {


    return 0;
}
