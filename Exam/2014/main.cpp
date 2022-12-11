#include <stdio.h>
#define MAXN 105
typedef int KeyType;
typedef struct
{
    KeyType key;
} ElemType;

typedef struct
{
    ElemType data[MAXN];
    int length;
} SqList;

int partition(SqList &L, int low, int high);
void QSort(SqList &L, int low, int high);
void QuickSort(SqList &L);

int main(int argc, char const *argv[])
{

    return 0;
}

int partition(SqList &L, int low, int high)
{
    if (low < high)
    {
        ElemType pivot = L.data[low];
        while (low < high)
        {
            while (low < high && L.data[high].key >= pivot.key)
            {
                // 从后往前遍历找到第一个大于pivot的元素
                high--;
            }
            L.data[low] = L.data[high]; // 替换low的元素
            while (low < high && L.data[low].key <= pivot.key)
            {
                low++;
            }
            L.data[high] = L.data[low];
        }
        L.data[low] = pivot; // 将pivot放在最终位置，此时pivot左边都小于pivot，右边都大于pivot
    }
    return low;
}

void QuickSort(SqList &L)
{
    QSort(L, 0, L.length - 1);
}

void QSort(SqList &L, int low, int high)
{
    if (low < high)
    {
        int mid = partition(L, low, high);
        QSort(L, low, mid - 1);
        QSort(L, mid + 1, high);
    }
}