#define MAXN 105

typedef char ElemType;

typedef struct BiNode
{
    ElemType data;
    struct BiNode *lchild, *rchild;
} BiNide, *BiTree;

//找到关键字等于ch的结点的父结点
BiNode *hasCh(BiTree &T, int ch, int &flag, BiNode *parent);

//先序遍历创建二叉树
BiTree createBiTree();