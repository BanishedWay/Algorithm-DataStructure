#include "myFunc.h"
#include <stdlib.h>

int initFlag = 0;
BiTree createBiTree(BiTree &T, int initNum[])
{
    //先序遍历创建二叉树
    if (initNum[initFlag] == 0 || initFlag >= 17)
    {
        T = NULL;
        initFlag++;
    }
    else
    {
        T = (BiNode *)malloc(sizeof(BiNode));
        if (T == NULL)
        {
            return NULL;
        }
        else
        {
            T->weight = initNum[initFlag];
            initFlag++;
            T->left = createBiTree(T->left, initNum);
            T->right = createBiTree(T->right, initNum);
        }
    }
    return T;
}

void getWPL(BiTree &T, int depth, int &WPL)
{
    if (T->left == NULL && T->right == NULL)
    {
        WPL += T->weight * depth;
    } //是叶子结点则加上WPL
    if (T->left)
    {
        getWPL(T->left, depth + 1, WPL);
    }
    if (T->right)
    {
        getWPL(T->right, depth + 1, WPL);
    }
}