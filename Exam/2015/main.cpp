#include <stdio.h>
#include <string.h>
#define MAXN 105

typedef int ElemType;
typedef struct
{
    int i, j;
    ElemType e;
} Triple;

typedef struct
{
    Triple data[MAXN];
    int mu, nu, tu; // 表示行、列、元素个数
} Matrix;

void reverseMatrix(Matrix &M, Matrix &T);
void printMatrix(Matrix M);

int main(int argc, char const *argv[])
{
    Matrix M, T;
    reverseMatrix(M, T);
    printMatrix(T);
    return 0;
}

void reverseMatrix(Matrix &M, Matrix &T)
{
    // 使用数组记录每一列元素个数，转置后按列优先存储
    int count[MAXN], T_index[MAXN];
    memset(count, 0, MAXN);

    // 给T初始化
    T.mu = M.nu;
    T.nu = M.mu;
    T.tu = M.tu;

    // 记录每一列元素的个数和这一列元素开始的位置
    for (int i = 1; i <= M.tu; i++)
    {
        // 输入初始化原矩阵
        scanf("%d %d %d", &M.data[i].i, &M.data[i].j, &M.data[i].e);
        count[M.data[i].j]++; // 统计每一列元素个数
    }

    T_index[1] = 1;
    for (int i = 2; i <= M.nu; i++)
    {
        // 第i列元素的起始位置是第i-1列元素起始位置+第i-1列元素个数
        T_index[i] = T_index[i - 1] + count[i - 1];
    }

    // 转置
    for (int i = 1; i <= M.tu; i++)
    {
        // 记录当前元素的列数，找到转置后该元素列的起始位置
        int k = T_index[M.data[i].j];
        T.data[k].i = M.data[i].j;
        T.data[k].j = M.data[i].i;
        T.data[i].e = M.data[i].e;
        T_index[M.data[i].j]++; // 表明这一列起始元素向后移动一位
    }
}

void printMatrix(Matrix M)
{
    for (int i = 1; i <= M.tu; i++)
    {
        printf("%d %d %d\n", M.data[i].i, M.data[i].j, M.data[i].e);
    }
}