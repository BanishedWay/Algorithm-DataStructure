#include "myFunc.h"
#include <stdio.h>
#include <stdlib.h>

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
        // 前i-1个元素有序，从第i个元素开始，向前遍历，直到找到合适的插入位置
        if (A[i] < A[i - 1])
        {
            A[0] = A[i];
            int j;
            for (j = i - 1; j > 0 && A[j] > A[0]; j--)
            {
                A[j + 1] = A[j]; // 后移一位
            }
            A[j + 1] = A[0]; // 插入到合适的位置
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
            // 查找时间复杂度为O(log n)
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
            } // 最后不大于A[0]的元素位于high
            for (int j = i - 1; j >= high + 1; j--)
            {
                A[j + 1] = A[j];
            }                   // 位于high之后的元素全部后移
            A[high + 1] = A[0]; // 插入到合适的位置
        }
    }
}

void ShellSort(int A[], int n)
{
    // 增量初值为n/2，每次除2
    for (int dk = n / 2; dk >= 1; dk /= 2)
    {
        // 增量为dk的插入排序
        for (int i = dk + 1; i <= n; i++)
        {
            if (A[i] < A[i - dk])
            {
                A[0] = A[i];
                int j;
                for (j = i - dk; A[j] > A[0]; j -= dk)
                {
                    A[j + dk] = A[j];
                }                 // 同步后移
                A[j + dk] = A[0]; // 插入到合适的位置
            }
        }
    }
}

void BubbleSort(int A[], int n)
{
    int flag = 0;
    // for (int i = 1; i < n; i++)
    // {
    //     //从第一个元素到第n-1个元素
    //     flag = 0;
    //     for (int j = n; j > i; j--)
    //     {
    //         if (A[j - 1] > A[j])
    //         {
    //             //将小的元素移动到前面
    //             swap(A[j - 1], A[j]);
    //             flag = 1;
    //         }
    //     }
    //     if (flag == 0)
    //     {
    //         //表明上一次没有发生元素交换，即数组有序
    //         return;
    //     }
    // }
    for (int i = n; i > 1; i--)
    {
        flag = 0;
        for (int j = 1; j < i; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
                flag = 1;
            }
        }
        if (flag)
            return;
    }
}

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void HeapSort(int A[], int n)
{
    // 创建大顶堆
    BuildHeap(A, n);
    for (int i = n; i > 1; i--)
    {
        swap(A[1], A[i]);        // 将最大的元素放到末尾
        HeapAdjust(A, 1, i - 1); // 将剩余i-1个元素进行调整
    }
}
void BuildHeap(int A[], int n)
{
    for (int i = n / 2; i > 0; i--)
    {
        // 从最后一个分支结点开始，构建大顶堆
        HeapAdjust(A, i, n);
    }
}
void HeapAdjust(int A[], int i, int n)
{
    A[0] = A[i];
    for (int k = i * 2; k <= n; k *= 2)
    {
        if (k <= n - 1 && A[k] < A[k + 1])
        {
            // 如果不是最后一个结点，选择左右孩子中最大的一个
            k++;
        }
        if (A[0] >= A[k])
        {
            // 如果根结点大于左右孩子，返回
            return;
        }
        else
        {
            // 将孩子上移，i执向原来孩子的位置
            A[i] = A[k];
            i = k;
        }
    }
    A[i] = A[0]; // 将A[i]放入合适的位置
}

int partition(int A[], int low, int high)
{
    if (low < high)
    {
        int pivot = A[low];
        while (low < high)
        {
            // 找到第一个小于枢轴的元素，将其交换到枢轴前
            while (low < high && A[high] >= pivot)
            {
                high--;
            }
            A[low] = A[high];

            // 找到第一个小于枢轴的元素，将其交换到枢轴后
            while (low < high && A[low] <= pivot)
            {
                low++;
            }
            A[high] = A[low];
        }
        A[low] = pivot;
    }
    return low; // 返回枢轴所在的位置
}
void QuickSort(int A[], int n)
{
    QSort(A, 1, n);
}

void QSort(int A[], int low, int high)
{
    if (low < high)
    {
        // 将数组一次划分为大于A[pivot]和小于A[pivot]的两部分
        int pivot = partition(A, low, high);
        // 分别对左右两部分进行划分
        QSort(A, low, pivot - 1);
        QSort(A, pivot + 1, high);
    }
}

void SelectSort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j <= n; j++)
        {
            // 从i-1开始，寻找后面元素中最小的元素
            if (A[minIndex] > A[j])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
            swap(A[i], A[minIndex]); // 将当前元素与最小元素交换
    }
}

void mergeTwo(int A[], int p, int q, int r)
{
    // 合并两个有序数组
    int *B = (int *)malloc(sizeof(r + 1));
    for (int i = p; i <= r; i++)
    {
        B[i] = A[i];
    } // 将A中位于p、q之间的元素复制到B中
    int i = p, j = q + 1, k = p;
    while (i <= q && j <= r)
    {
        // 将两个数组中较小的一个放入A中
        if (B[i] <= B[j])
        {
            A[k++] = B[i++];
        }
        else
        {
            A[k++] = B[j++];
        }
    }
    // 将剩余元素放在数组末尾
    while (i <= q)
    {
        A[k++] = B[i++];
    }
    while (j <= r)
    {
        A[k++] = B[j++];
    }
    free(B);
}

void MSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MSort(A, low, mid);
        MSort(A, mid + 1, high);
        mergeTwo(A, low, mid, high);
    }
}

void MergeSort(int A[], int n)
{
    MSort(A, 1, n);
}