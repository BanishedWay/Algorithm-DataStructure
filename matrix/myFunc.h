#define MAXN 105
typedef struct
{
    int i, j; //行、列
    int e;    //数据元素
} Triple;

typedef union {
    Triple data[MAXN]; //三元组数据
    int mu, nu, tu;    //行数、列数、元素个数
} TSMatrix;

//转置三元组
void transpose(TSMatrix M, TSMatrix &N);

//创建三元组
void createTSMatrix(TSMatrix &M);

//输出三元组
void printTSMatrix(TSMatrix M);