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

//直接插入排序
void InsertSort(int A[], int n);
//折半插入排序
void InsertSortBinary(int A[], int n);