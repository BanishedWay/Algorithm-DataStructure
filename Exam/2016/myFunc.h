#define MAXN 105

typedef struct BiNode
{
    int weight;
    struct BiNode *left, *right;
} * BiTree;

//根据输入序列创建二叉树
BiTree createBiTree(BiTree &T, int initNum[]);

//算出WPL
void getWPL(BiTree &T, int depth, int &WPL);