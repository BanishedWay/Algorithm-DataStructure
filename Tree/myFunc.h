typedef int ElemType;

typedef struct BiNode {
    ElemType data;
    struct BiNode *lchild, *rchild;

    BiNode(ElemType data, BiNode *lchild, BiNode *rchild) {
        this->data = data;
        this->lchild = lchild;
        this->rchild = rchild;
    }
} BiNode, *BiTree;

typedef struct BiTNode {
    ElemType data;
    int ltag, rtag;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiThreadTree;

void visit(BiNode *T);
// 遍历（递归版本）
void preorder(BiTree T);
void inorder(BiTree T);
void postorder(BiTree T);
void levelorder(BiTree T);

// 遍历（非递归）
void PreOrder(BiTree T);
void InOrder(BiTree T);
void PostOrder(BiTree T);

// 二叉树线索化
void InThread(BiThreadTree &T, BiTNode *prev);
void PreThread(BiThreadTree &T, BiTNode *prev);
void PostThread(BiThreadTree &T, BiTNode *prev);
BiTNode *InPreNode(BiThreadTree T);
BiTNode *PostPreNode(BiThreadTree T);

// 统计叶子结点个数
void preOrderLeaf(BiTree T, int &count);

// 统计结点中最大最小值
void MaxPreOrder(BiTree T, int &maxValue);

// 求树的高度
int Deep(BiTree T);
int maxData(int a, int b);

// 求第k层结点数量
int countLevelK(BiTree T, int d, int k);

//求x所在层次
int GetLevel(BiTree T, BiNode *p, int d);

//判断是否为完全二叉树
int JudgeCBiTree(BiTree T);

//检查是否为镜像
int JudgeMirror(BiTree T1, BiTree T2);

//删除值为x的结点
void deleteNode(BiTree &T);
void deleteNodeX(BiTree &T, int x);
