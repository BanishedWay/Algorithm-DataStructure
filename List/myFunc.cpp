#include "myFunc.h"
#include <stdlib.h>

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
