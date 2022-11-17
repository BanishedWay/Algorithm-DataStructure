#include "myFunc.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    SeqList L;
    L.length = 5;
    int A[5] = {1, 1, 2, 2, 2};
    for (int i = 0; i < L.length; i++) {
        L.data[i] = A[i];
    }
    deleteSameSeq(L);
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
    return 0;
}
