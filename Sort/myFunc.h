#define MAXN 105
typedef int ElemType;

typedef struct
{
    ElemType key;
    int otherInfo;
} NodeType; //元素结构

typedef struct
{
    ElemType data[MAXN];
    int length;
} Array;

void printArray(int A[], int n);
void swap(int &a, int &b);

//直接插入排序
void InsertSort(int A[], int n);
//折半插入排序
void InsertSortBinary(int A[], int n);
//希尔排序
void ShellSort(int A[], int n);

//冒泡排序
void BubbleSort(int A[], int n);

//堆排序
void HeapSort(int A[], int n);
void BuildHeap(int A[], int n);
void HeapAdjust(int A[], int i, int n);

//快速排序
int partition(int A[], int low, int high);
void QuickSort(int A[], int n);
void QSort(int A[], int low, int high);

//简单选择排序
void SelectSort(int A[], int n);

//归并排序
void MergeSort(int A[], int n);
void mergeTwo(int A[], int n1, int l1, int n2, int l2);
void MSort(int A[], int low, int high);