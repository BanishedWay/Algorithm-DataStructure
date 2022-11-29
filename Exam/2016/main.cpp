#include "myFunc.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int initNum[] = {10, 2, 7, 0, 0, 18, 30, 0, 0, 0, 46, 0, 8, 60, 0, 0, 0};
    BiTree T;
    T = createBiTree(T, initNum);
    int WPL = 0;
    getWPL(T, 1, WPL);
    printf("%d\n", WPL);
    BiTree stack[MAXN];
    int top = -1;
    BiNode *p = T;
    while (p || top != -1)
    {
        if (p)
        {
            printf("%d ", p->weight);
            stack[++top] = p;
            p = p->left;
        }
        else
        {
            p = stack[top--];
            p = p->right;
        }
    }
    return 0;
}
