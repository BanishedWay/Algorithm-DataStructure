#include "myFunc.h"
#include <cstddef>
#include <stdlib.h>

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}
void deleteX(SeqList &L, int x) {
    // 从第一个元素开始遍历找到x
    int j = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] != x) {
            L.data[j++] = L.data[i];
        } // 将不等于x的元素插入到[0,j)的区间内
    }
    L.length = j;
}

void deletex(LinkList &L, int x) {
    LNode *p = L, *q;
    while (p->next) {
        if (p->next->data == x) {
            q = p->next;
            p->next = q->next;
            free(q);
        } // 遍历链表，当p->next->data等于x时，删除p->next
        else {
            p = p->next;
        } // 否则检查下一个
    }
}

void deleteSameSeq(SeqList &L) {
    int i, j = 0;
    // 使用j记录下一个不重复的元素存放的位置
    for (i = 1; i < L.length; i++) {
        if (L.data[i] != L.data[j]) {
            L.data[++j] = L.data[i];
            // 当前元素不等于已经遍历的最后一个不重复元素时，插入到不重复元素的末尾
        }
    }
    L.length = j + 1;
}

void deleteSameLink(LinkList &L) {
    LNode *p = L->next;
    while (p && p->next) {
        if (p->data == p->next->data) {
            // 当相邻两个元素相等时，删去后面一个元素
            LNode *q = p->next;
            p->next = q->next;
            free(q);
        } else {
            p = p->next;
        }
    }
}

void reverseSeq(SeqList &L) {
    for (int i = 0; i < L.length / 2; i++) {
        swap(L.data[i], L.data[L.length - i - 1]);
    } // 将第i个元素与第n-i-1的元素互换
}

void reverseLink(LinkList &L) {
    LNode *p = L->next, *q = NULL, *r;
    while (p) {
        r = p->next; // 保存后继，防止断链
        p->next = q; // 反转链表
        q = p;       // 向后移动
        p = r;
    }
    L->next = q;
}

void reLeftShift(SeqList &L, int n) {
    n = n % L.length;
    // 左移的实质是将前半和后半元素逆置，然后对整个线性表逆置
    reverse(L.data, 0, n);
    reverse(L.data, n, L.length);
    reverse(L.data, 0, L.length);
}

void reverse(int A[], int m, int n) {
    for (int i = m; i < (m + n) / 2; i++) {
        swap(A[i], A[m - i - 1]);
    }
}

void mergeSeq(SeqList L1, SeqList L2, SeqList &L3) {
    int i = 0, j = 0, k = 0;
    while (i < L1.length && j < L2.length) {
        if (L1.data[i] > L2.data[j]) {
            L3.data[k++] = L2.data[j++];
        } else {
            L3.data[k++] = L1.data[i++];
        }
    } // 比较两个链表的元素，比较小的一个插入L3的后面
    while (i < L1.length) {
        L3.data[k++] = L1.data[i++];
    }
    while (j < L2.length) {
        L3.data[k++] = L2.data[j++];
    }
    // 将两个链表中剩余元素插入到L3末尾
}

void mergeLink(LinkList L1, LinkList L2, LinkList &L3) {
    LNode *p = L1->next, *q = L2->next, *r = L3;
    while (p && q) {
        if (p->data < q->data) {
            r->next = p;
            p = p->next;
        } else {
            r->next = q;
            q = q->next;
        }
        r = r->next;
    }
    if (p) {
        r->next = p;
    } else {
        r->next = q;
    }
}

void preOdd(SeqList &L) {
    int low = 0, high = L.length - 1;
    int tmp = L.data[low];
    // 使用快排的思想，将偶数元素放到前面，奇数元素放到后面
    while (low < high) {
        while (low < high && L.data[high] % 2 == 1) {
            high--;
        }
        L.data[low] = L.data[high];
        while (low < high && L.data[low] % 2 == 0) {
            low++;
        }
        L.data[high] = L.data[low];
    }
    L.data[low] = tmp;
}
