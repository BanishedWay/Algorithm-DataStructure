#include "myFunc.h"
#include <string.h>

int Index(char *S, char *T) {
    int i = 0, j = 0;
    while (i < strlen(S) && j < strlen(T)) {
        if (S[i] == T[j]) {
            i++;
            j++;
        } // 相等时同步后移
        else {
            i = i - j + 1; // 从0开始
            j = 0;
        }
    }
    if (j == strlen(T)) {
        return i - j + 1;
    } else {
        return -1;
    }
}

void getNext(char *T, int next[]) {
    int i = 1, j = 0;
    next[1] = 0;
    while (i < strlen(T)) {
        if (j == 0 || T[i - 1] == T[j - 1]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

void getNextVal(char *T, int nextVal[]) {
    int i = 1, j = 0;
    nextVal[1] = 0;
    while (i < strlen(T)) {
        if (j == 0 || T[i - 1] == T[j - 1]) {
            i++;
            j++;
            if (T[i - 1] == T[j - 1]) {
                nextVal[i] = nextVal[j];
            } else {
                nextVal[i] = j;
            }
        } else {
            j = nextVal[j];
        }
    }
}

int KMP(char *S, char *T) {
    int nextVal[MAXN];
    getNextVal(T, nextVal);
    int i = 1, j = 1;
    while (i <= strlen(S) && j <= strlen(T)) {
        if (j == 0 || S[i - 1] == T[j - 1]) {
            i++;
            j++;
        } else {
            j = nextVal[j];
        }
    }
    if (j > strlen(T)) {
        return i - j + 1;
    } else {
        return -1;
    }
}
