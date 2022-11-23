#include "myFunc.h"

int main(int argc, char const *argv[])
{
    int A[6] = {0, 1, 3, 2, 5, 4};
    printArray(A, 5);
    MergeSort(A, 5);
    printArray(A, 5);
    return 0;
}
