#include "myFunc.h"

int main(int argc, char const *argv[])
{
    TSMatrix M, N;
    createTSMatrix(M);
    transpose(M, N);
    printTSMatrix(N);
    return 0;
}
