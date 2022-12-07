#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 105

typedef struct node
{
    char data[MAXN];
    int count;
    struct node *next;
} LNode, *LinkList;

LNode *checkNode(LinkList &L, char *data); // 检查单词是否出现过
LNode *createNode(char *word);             // 创建结点
void InsertWord(LinkList &L, char *word);  // 插入结点
LNode *getMax(LinkList L);                 // 找到计数最大的结点并放在第一个位置
void printN(LNode *p, int K);              // 打印前K个字符

int main(int argc, char const *argv[])
{
    LinkList L = (LinkList)malloc(sizeof(LNode)); // 创建头结点
    int n;
    scanf("%d", &n); // 输入单词个数
    char *word = "";
    while (n--)
    {
        scanf("%s", word); // 输入单词
        LNode *p = checkNode(L, word);
        if (p)
        {
            p->count++;
        }
        else
        {
            InsertWord(L, word);
        } // 如果输入的单词存在，则计数+1，否则插入新的单词
    }
    LNode *maxNode = getMax(L);
    int K = 5;
    printN(maxNode, K);
    return 0;
}

LNode *checkNode(LinkList &L, char *word)
{
    if (!L->next)
        return NULL;
    LNode *p = L->next;
    while (p)
    {
        if (strcmp(word, p->data) == 0)
        {
            // 表明单词已经出现过，返回该结点
            return p;
        }
        p = p->next;
    }
    return NULL;
}

LNode *createNode(char *word)
{
    LNode *p = (LNode *)malloc(sizeof(LNode));
    // 给p赋值
    strcpy(p->data, word);
    p->count = 1;
    p->next = NULL;
    return p;
}

void InsertWord(LinkList &L, char *word)
{
    // 创建结点
    LNode *t = createNode(word);
    // 采用头插法插入结点
    LNode *p = L->next;
    t->next = p;
    L->next = t;
}

LNode *getMax(LinkList L)
{
    if (!L->next)
    {
        return NULL;
    }
    int maxCount = 0;
    LNode *maxNode = NULL, *p = L->next;
    while (p)
    {
        if (maxCount < p->count)
        {
            maxCount = p->count;
            maxNode = p;
        }
        p = p->next;
    } // 找到计数最大的结点
    return maxNode;
}

void printN(LNode *p, int K)
{
    for (int i = 0; i < K; i++)
    {
        if (p->data[i] == '\0')
        {
            printf("K大于单词长度\n");
            exit(0); // 退出
        }
        printf("%c", p->data[i]);
    }
    printf("\n");
}