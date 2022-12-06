#include <stdio.h>

void HeapSort(int A[], int n);
void HeapAdjust(int A[], int k, int n);
void BuildHeap(int A[], int n);
void swap(int &a, int &b);

int main(int argc, char const *argv[])
{
    int A[11] = {0, 1, 3, 2, 6, 4, 8, 5, 9, 7, 10};
    HeapSort(A, 10);
    for (int i = 1; i <= 10; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}

void HeapSort(int A[], int n)
{
    BuildHeap(A, n);
    for (int i = n; i > 1; i--)
    {
        swap(A[1], A[i]);
        HeapAdjust(A, 1, i - 1);
    }
}

void BuildHeap(int A[], int n)
{
    //从最后一个非叶子结点开始，构建大顶堆
    for (int i = n / 2; i > 0; i--)
    {
        HeapAdjust(A, i, n);
    }
}

void HeapAdjust(int A[], int k, int n)
{
    A[0] = A[k];
    for (int i = k * 2; i <= n; i *= 2)
    {
        //定位到A[k]的左左孩子
        if (i < n && A[i] < A[i + 1])
        {
            i++;
        } //选择更大的孩子
        if (A[i] <= A[0])
        {
            break;
        } //如果A[0]插入到当前位置满足大顶堆条件，则退出循环
        else
        {
            A[k] = A[i];
            k = i;
        } //否则A[i]上移
    }
    A[k] = A[0];
}

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}