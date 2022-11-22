#include "myFunc.h"
#include <stdio.h>

void printArray(int A[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void InsertSort(int A[], int n)
{
    for (int i = 2; i <= n; i++)
    {
        //前i-1个元素有序，从第i个元素开始，向前遍历，直到找到合适的插入位置
        if (A[i] < A[i - 1])
        {
            A[0] = A[i];
            int j;
            for (j = i - 1; j > 0 && A[j] > A[0]; j--)
            {
                A[j + 1] = A[j]; //后移一位
            }
            A[j + 1] = A[0]; //插入到合适的位置
        }
    }
}

void InsertSortBinary(int A[], int n)
{
    int low = 1, high = n;
    for (int i = 2; i <= n; i++)
    {
        if (A[i] < A[i - 1])
        {
            A[0] = A[i];
            // 折半查找合适的位置
            //查找时间复杂度为O(log n)
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (A[mid] > A[0])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            } //最后不大于A[0]的元素位于high
            for (int j = i - 1; j >= high + 1; j--)
            {
                A[j + 1] = A[j];
            }                   //位于high之后的元素全部后移
            A[high + 1] = A[0]; //插入到合适的位置
        }
    }
}

void ShellSort(int A[], int n)
{
    //增量初值为n/2，每次除2
    for (int dk = n / 2; dk >= 1; dk /= 2)
    {
        //增量为dk的插入排序
        for (int i = dk + 1; i <= n; i++)
        {
            if (A[i] < A[i - dk])
            {
                A[0] = A[i];
                int j;
                for (j = i - dk; A[j] > A[0]; j -= dk)
                {
                    A[j + dk] = A[j];
                }                 //同步后移
                A[j + dk] = A[0]; //插入到合适的位置
            }
        }
    }
}