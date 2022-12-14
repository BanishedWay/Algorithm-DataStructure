/*
 * @Author: Jinqi Xu
 * @Date: 2022-12-14 15:31:44
 * @Last Modified by:   Jinqi Xu
 * @Last Modified time: 2022-12-14 15:31:44
 */
#include <stdio.h>
#include <stdlib.h>

constexpr auto MAXN = 105;

/*
 * C语言实现二路归并
 */

void MergeTwo(int A[], int low, int mid, int high);
void Merge(int A[], int low, int high);

int main(int argc, char const *argv[])
{
    int A[11] = {0, 3, 1, 6, 2, 7, 4, 5, 9, 8, 10};
    Merge(A, 1, 10);
    for (int i = 0; i < 11; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}

void MergeTwo(int A[], int low, int mid, int high)
{
    if (low < high)
    {
        int *B = (int *)malloc(sizeof(int) * MAXN);
        for (int i = low; i <= high; i++)
        {
            B[i] = A[i];
        }
        int i = low, j = mid + 1, k = low;
        while (i <= mid && j <= high)
        {
            if (B[i] > B[j])
            {
                A[k++] = B[j++];
            }
            else
            {
                A[k++] = B[i++];
            }
        }
        while (i <= mid)
        {
            A[k++] = B[i++];
        }
        while (j <= high)
        {
            A[k++] = B[j++];
        }
        free(B);
    }
}

void Merge(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        Merge(A, low, mid);
        Merge(A, mid + 1, high);
        MergeTwo(A, low, mid, high);
    }
}