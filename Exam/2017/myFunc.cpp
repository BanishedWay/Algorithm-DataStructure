#include "myFunc.h"
#include "stdio.h"
#include "stdlib.h"

int initFlag = 0;

BiNode *hasCh(BiTree &T, int ch, int &flag, BiNode *parent)
{
    if (!T)
        return NULL;
    if (T->data == ch)
    {
        flag = 1;
        return parent;
        //如果存在等于bt的结点，flag设置为1，返回parent
    }
    if (T->lchild)
    {
        //如果T不等于，则依次遍历左子树和右子树
        return hasCh(T->lchild, ch, flag, T);
    }
    if (T->rchild)
    {
        return hasCh(T->rchild, ch, flag, T);
    }
    return NULL;
}

BiTree createBiTree()
{
    char ch;
    scanf("%c", &ch);
    if (ch != '*')
    {

        BiNode *T = (BiNode *)malloc(sizeof(BiNode));
        T->data = ch;
        T->lchild = createBiTree();
        T->rchild = createBiTree();
        return T;
    }
    return NULL;
}