#include "myFunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void transpose(TSMatrix M, TSMatrix &N)
{
    //稀疏矩阵转置不是简单地转换行列，必须得修正转置后的元素次序
    int count_col[MAXN], index_col[MAXN]; //记录每列元素个数以及第i列元素的起始位置
    memset(count_col, 0, MAXN);
    N.mu = M.nu;
    N.nu = M.mu;
    N.tu = M.tu;

    for (int i = 1; i <= M.tu; i++)
    {
        count_col[M.data[i].j]++; //第j列元素+1
    }
    //转置后变为第j行第i列元素，所以列数更小的元素在前
    index_col[1] = 1; //从1开始
    for (int i = 2; i <= M.nu; i++)
    {
        index_col[i] = index_col[i - 1] + count_col[i - 1];
        //第i列元素的起始位置为第i-1列起始位置+i-1列元素个数
    }

    for (int i = 1; i <= M.tu; i++)
    {
        int k = index_col[M.data[i].j]; //取出第j列元素当前的起始地址
        N.data[k].i = M.data[i].j;
        N.data[k].j = M.data[i].i;
        N.data[k].e = M.data[i].e;
        index_col[M.data[i].j]++; // j列的起始位置后移一位
    }
} //另一种思路是对三元组data进行稳定的排序，那么在对j排序后，j相等的情况下，i小的在前，i大的在后（因为原来i大的在后，稳定排序保持j相等的元素相对次序不变，时间复杂度为O(n^2)）

void createTSMatrix(TSMatrix &M)
{
    printf("输出三元组的三维：\n");
    scanf("%d %d %d", &M.mu, &M.nu, &M.tu);

    printf("输入三元组的元素：\n");
    for (int i = 1; i <= M.tu; i++)
    {
        scanf("%d %d %d", &M.data[i].i, &M.data[i].j, &M.data[i].e);
        getchar();
    }
}

void printTSMatrix(TSMatrix M)
{
    printf("输出的三元组：\n");
    for (int i = 1; i <= M.tu; i++)
    {
        printf("%d %d %d\n", M.data[i].i, M.data[i].j, M.data[i].e);
    }
}