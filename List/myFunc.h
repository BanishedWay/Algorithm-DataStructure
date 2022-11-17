#define MAXN 105

typedef struct {
    int data[MAXN];
    int length;
} SeqList;

typedef struct Node {
    int data;
    struct Node *next;
} LNode, *LinkList;
// 删除线性表中元素为x的值
void deleteX(SeqList &L, int x);
void deletex(LinkList &L, int x);

// 去掉有序表中相同元素
void deleteSameSeq(SeqList &L);
void deleteSameLink(LinkList &L);
