#include "myFunc.h"
#include <stdio.h>
#include <stdlib.h>

void visit(BiNode *T)
{
    printf("%d ", T->data);
}

void preorder(BiTree T)
{
    if (T)
    {
        visit(T);
        preorder(T->lchild);
        preorder(T->rchild);
    }
}

void inorder(BiTree T)
{
    if (T)
    {
        inorder(T->lchild);
        visit(T);
        inorder(T->rchild);
    }
}

void postorder(BiTree T)
{
    if (T)
    {
        postorder(T->lchild);
        postorder(T->rchild);
        visit(T);
    }
}

void levelorder(BiTree T)
{
    if (T)
    {
        // 使用队列完成层序遍历
        BiNode *queue[105];
        int front = 0, rear = 0;
        queue[rear++] = T; // 根结点入队
        while (front != rear)
        {
            BiNode *p = queue[front++];
            visit(p);
            if (p->lchild)
            {
                queue[rear++] = p->lchild;
            }
            if (p->rchild)
            {
                queue[rear++] = p->rchild;
            } // 分别将左右子树入队
        }
    }
}

void PreOrder(BiTree T)
{
    // 借助栈实现二叉树的先序遍历
    if (!T)
        return;
    BiNode *stack[105];
    int top = -1;
    BiNode *p = T;
    while (p || top != -1)
    {
        if (p)
        {
            visit(p);
            stack[++top] = p;
            p = p->lchild;
            // 访问根结点之后，需要将根结点入栈，为了在访问左子树之后进入右子树
        }
        else
        {
            p = stack[top--];
            p = p->rchild;
            // 不需要对右孩子进行判断，如果右孩子为空则继续出栈
        }
    }
}

void InOrder(BiTree T)
{
    if (!T)
        return;
    BiNode *stack[105];
    int top = -1;
    BiNode *p = T;
    while (p || top != -1)
    {
        if (p)
        {
            stack[++top] = p;
            p = p->lchild;
        } // 将根结点入栈，访问左孩子
        else
        {
            p = stack[top--];
            visit(p);
            p = p->rchild;
        } // 访问根结点后，进入右子树
    }
}

void PostOrder(BiTree T)
{
    if (T)
    {
        BiNode *p = T, *prev = NULL;
        BiNode *stack[105];
        int top = -1;
        while (p || top != -1)
        {
            if (p)
            {
                stack[++top] = p;
                p = p->lchild;
            } // 一直向左
            else
            {
                p = stack[top];
                if (p->rchild == NULL || p->rchild == prev)
                {
                    p = stack[top--];
                    visit(p);
                    prev = p;
                    p = NULL; // 此时回溯，访问上一层
                }             // 当右子树访问或为空时，将根结点出栈
                else
                {
                    p = p->rchild;
                } // 继续遍历右子树
            }
        }
    }
}

void InThread(BiThreadTree &T, BiTNode *prev)
{
    if (T)
    {
        InThread(T->lchild, prev);
        if (!T->lchild)
        {
            T->ltag = 1;
            T->lchild = prev;
        }
        if (!prev->rchild)
        {
            prev->rtag = 1;
            prev->rchild = T;
        }
        prev = T;
        InThread(T->rchild, prev);
    }
}

BiTNode *InPreNode(BiThreadTree T)
{
    if (T->ltag == 1)
    {
        return T->lchild;
    }
    else
    {
        BiTNode *p = T->lchild;
        while (p->rtag == 0)
        {
            p = p->rchild;
        }
        return p;
    }
}

BiTNode *PostPreNode(BiThreadTree T)
{
    if (T->rtag == 1)
    {
        return T->rchild;
    }
    else
    {
        BiTNode *p = T->rchild;
        while (p->ltag == 0)
        {
            p = p->lchild;
        }
        return p;
    }
}

void PreThread(BiThreadTree &T, BiTNode *prev)
{
    if (T)
    {
        if (!T->lchild)
        {
            T->ltag = 1;
            T->lchild = prev;
        }
        if (!prev->rchild)
        {
            prev->rtag = 1;
            prev->rchild = T;
        }
        prev = T;
        if (T->ltag == 0)
        {
            InThread(T->lchild, prev);
        }
        PreThread(T->rchild, prev);
    }
}

void PostThread(BiThreadTree &T, BiTNode *prev)
{
    if (T)
    {
        PostThread(T->lchild, prev);
        PostThread(T->rchild, prev);
        if (!T->lchild)
        {
            T->ltag = 1;
            T->lchild = prev;
        }
        if (!prev->rchild)
        {
            prev->rtag = 1;
            prev->rchild = T;
        }
        prev = T;
    }
}

void preOrderLeaf(BiTree T, int &count)
{
    if (T)
    {
        if (!T->lchild && !T->rchild)
        {
            count++;
        }
        preOrderLeaf(T->lchild, count);
        preOrderLeaf(T->rchild, count);
    }
}

void MaxPreOrder(BiTree T, int &maxValue)
{
    if (T)
    {
        if (T->data > maxValue)
        {
            maxValue = T->data;
        }
        MaxPreOrder(T->lchild, maxValue);
        MaxPreOrder(T->rchild, maxValue);
    }
}

int Deep(BiTree T)
{
    if (T)
    {
        int l = Deep(T->lchild);
        int r = Deep(T->rchild);
        return maxData(l, r) + 1;
    }
    return 0;
}

int maxData(int a, int b)
{
    return a > b ? a : b;
}

int countLevelK(BiTree T, int d, int k)
{
    if (T && d <= k)
    {
        if (d == k)
        {
            return 1;
        } // 当前结点位于第k层，总数+1
        return countLevelK(T->lchild, d + 1, k) + countLevelK(T->rchild, d + 1, k);
        // 从第k-1层开始依次往上累加
    }
    return 0;
}

int GetLevel(BiTree T, BiNode *p, int d)
{
    if (T)
    {
        if (p->data == T->data)
        {
            return d;
        }
        return GetLevel(T->lchild, p, d + 1);
        return GetLevel(T->rchild, p, d + 1);
    }
    return 0;
}

int JudgeCBiTree(BiTree T)
{
    if (T)
    {
        //使用队列，如果队头元素为空且后续有空结点，则不是完全二叉树
        BiNode *queue[105];
        int front = 0, rear = 0;
        queue[rear++] = T;
        while (rear != front)
        {
            BiNode *p = queue[front++];
            if (p)
            {
                // p不为空，则将其左右孩子入队
                queue[rear++] = p->lchild;
                queue[rear++] = p->rchild;
            }
            else
            {
                //检查是否存在不为空的结点
                while (rear != front)
                {
                    p = queue[front++];
                    if (p)
                        return 0;
                }
            }
        }
    }
    return 1;
}

int JudgeMirror(BiTree T1, BiTree T2)
{
    if (!T1 && !T2)
        return 1;
    if (T1 == NULL || T2 == NULL)
    {
        return 0;
    }
    return T1->data == T2->data && JudgeMirror(T1->lchild, T2->rchild) && JudgeMirror(T1->rchild, T2->lchild);
}

void deleteNode(BiTree T)
{
    if (T)
    {
        deleteNode(T->lchild);
        deleteNode(T->rchild);
        free(T);
    }
}
void deleteNodeX(BiTree &T, int x)
{
    //使用队列实现删除结点
    if (T->data == x)
    {
        deleteNode(T);
        return;
    }
    BiNode *queue[105];
    int front = 0, rear = 0;
    queue[rear++] = T;
    while (rear != front)
    {
        BiNode *p = queue[front++];
        if (p->lchild)
        {
            if (p->lchild->data == x)
            {
                deleteNode(p->lchild);
                p->lchild = NULL;
            } //当队头结点的左孩子为目标结点时，删除以该结点为根的子树
            else
            {
                queue[rear++] = p->lchild;
            }
        }
        if (p->rchild)
        {
            if (p->rchild->data == x)
            {
                deleteNode(p->rchild);
                p->rchild = NULL;
            }
            else
            {
                queue[rear++] = p->rchild;
            }
        }
    }
}

int JudgeBalancedTree(BiTree T, int &d)
{
    if (!T)
    {
        d = 0;
        return 1;
    }
    int ld, rd;
    int l = JudgeBalancedTree(T->lchild, ld), r = JudgeBalancedTree(T->rchild, rd);
    if (!l || !r)
        return 0;                //如果左右子树不是二叉平衡树，返回0
    d = (ld > rd ? ld : rd) + 1; //计算树的高度
    return abs(ld - rd) <= 1;
}

void findFather(BiTree T, BiNode *p)
{
    //使用后续遍历查找祖先结点
    BiNode *stack[105];
    int top = -1;
    BiNode *q = T, *prev = NULL;
    while (q || top != -1)
    {
        if (q)
        {
            stack[++top] = q;
            q = q->lchild;
        } //沿着左孩子依次入栈
        else
        {
            q = stack[top];
            if (q->rchild == NULL || q->rchild == prev)
            {
                q = stack[top--]; //当右子树为空或已经访问，出栈
                if (q->data == p->data)
                    return; //此时栈内结点为目标结点所有祖先结点
                prev = q;
                q = NULL;
            }
            else
            {
                q = q->rchild;
            }
        }
    }
}