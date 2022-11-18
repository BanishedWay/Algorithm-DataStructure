#define MAXN 105

typedef struct {
    int data[MAXN];
    int length;
} SeqList;

typedef struct Node {
    int data;
    struct Node *next;
} LNode, *LinkList;

void swap(int &a, int &b);
int GetLenth(LinkList L);
// 删除线性表中元素为x的值
void deleteX(SeqList &L, int x);
void deletex(LinkList &L, int x);

// 去掉有序表中相同元素
void deleteSameSeq(SeqList &L);
void deleteSameLink(LinkList &L);

// 反转线性表
void reverseSeq(SeqList &L);
void reverseLink(LinkList &L);

// 循环左移线性表n个元素、
void reLeftShift(SeqList &L, int n);
void reLeftShiftLink(LinkList &L, int n);
void reverse(int A[], int m, int n);

// 合并两个升序线性表
void mergeSeq(SeqList L1, SeqList L2, SeqList &L3);
void mergeLink(LinkList &L1, LinkList &L2, LinkList &L3);

// 将偶数元素放到奇数元素之前
void preOdd(SeqList &L);

// 查找线性表第k小元素
int kth(SeqList &L, int k, int i, int j);

// 二分查找
int BiSearch(SeqList L, int e);

// 查找有序表第一个元素为x的下标
int BiSearchFirst(SeqList L, int e);

// 查找两个有序表的中位数
int midNum(SeqList L1, SeqList L2);

// 找出线性表中出现次数大于一半的元素
int findHalf(SeqList L);

// 找出共同后缀的两条单链表的第一个公共结点
LNode *findFirstCommon(LinkList L1, LinkList L2);

// 判断链表是否有环
bool hasLoop(LinkList L);
bool equalLNode(LNode *q, LNode *p);
