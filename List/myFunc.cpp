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

int kth(SeqList &L, int k, int i, int j) {
    // 使用快排思想，找到第k小的元素
    int low = i, high = j;
    if (low < high) {
        int tmp = L.data[low];
        while (low < high) {
            while (low < high && L.data[high] >= tmp) {
                high--;
            }
            L.data[low] = L.data[high];
            while (low < high && L.data[low] >= tmp) {
                low++;
            }
            L.data[high] = L.data[low];
        }
        if (low == k) {
            return L.data[low];
        } else if (low < k) {
            return kth(L, k, low + 1, high);
        } else {
            return kth(L, k, i, low - 1);
        }
    }
    return -1;
}

int BiSearch(SeqList L, int e) {
    int low = 0, high = L.length - 1; // 指向当前数组的前后端
    while (low <= high) {
        int mid = (low + high) / 2; // 取中间位置
        if (L.data[mid] == e) {
            return mid; // 查找成功则返回
        } else if (L.data[mid] > e) {
            high = mid - 1; // 大于e则取左半
        } else {
            low = mid + 1; // 后半区间
        }
    }
    return -1;
}

int BiSearchFirst(SeqList L, int e) {
    // 查找第一个时，在查找过程中即使找到e，也必须判断前半没有等于e的元素
    int low = 0, high = L.length - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (L.data[mid] <= e) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return L.data[low] == e ? low : -1;
}

int midNum(SeqList L1, SeqList L2) {
    /**
     * 当两个列表的中位数相等时，则该值就是中位数
     * 当中位数不相等时，则总的中位数比如在两个中位数的区间中间
     **/
    int l1 = 0, l2 = 0, h1 = L1.length, h2 = L2.length, m1, m2;
    while (l1 != h1 || l2 != h2) {
        m1 = (l1 + h1) / 2;
        m2 = (l2 + m2) / 2;
        if (L1.data[m1] == L2.data[m2]) {
            return L1.data[m1]; // 当中位数相等时，返回
        } else if (L1.data[m1] < L2.data[m2]) {
            // 取L1后半和L2前半，且前后舍弃的元素个数相等
            l1 = m1 + (h1 - l1) % 2;
            h2 = m2;
        } else {
            l2 = m2 + (h2 - l2) % 2;
            h1 = m1;
        }
    }
    return L1.data[l1] < L2.data[l2] ? L1.data[l1] : L2.data[l2];
    // 最后一次比较是两个数之间的比较，更小的一个是中位数
}

int findHalf(SeqList L) {
    /**
     *当元素出现次数大于一半，则该元素的个数必定大于其他元素的和
     *因此使用count记录该元素出现次数，如果最后存在count>0的元素
     *则表明有可能存在次数大于一半的元素
     **/
    int count = 1, m = L.data[0];
    for (int i = 1; i < L.length; i++) {
        if (m == L.data[i]) {
            count++;
        } else {
            count--;
            if (m == 0) {
                m = L.data[i];
                count = 1;
                // 当元素出现次数等于0时，表明该元素暂时不可能是目标元素
                // 更新元素
            }
        }
    }
    // 如果最后存在count>0的元素，则判断该元素在线性表中出现次数是否真的大于一半
    count = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == m) {
            count++;
        }
    }
    return count > (L.length / 2) ? m : -1;
}

LNode *findFirstCommon(LinkList L1, LinkList L2) {
    /**
     *首先计算两条链表的长度，遍历长的一天链表直到两条链表长度相等
     *然后顺序比较，判断是否存在公共结点
     *此处假设每条链表中不存在重复的结点
     **/
    int l1 = GetLenth(L1), l2 = GetLenth(L2);
    LNode *shorter, *longer;
    int dis;
    if (l1 < l2) {
        shorter = L1->next;
        longer = L2->next;
        dis = l2 - l1;
    } else {
        shorter = L2->next;
        longer = L1->next;
        dis = l1 - l2;
    }
    while (dis--) {
        longer = longer->next;
    } // 将长的链表指针指向两个链表长度相等的结点
    while (longer && shorter) {
        if (longer->data == shorter->data) {
            return longer;
        } // 当两个结点值相等时，该结点是公共结点
        else {
            longer = longer->next;
            shorter = shorter->next;
        }
    }
    return NULL;
}

int GetLenth(LinkList L) {
    LNode *p = L;
    int length = 0;
    while (p->next) {
        length++;
        p = p->next;
    }
    return length;
}

bool hasLoop(LinkList L) {
    // 使用快慢指针判断是否存在环
    LNode *fast = L, *slow = L;
    if (!L || !L->next || !L->next->next)
        return false;
    while (slow && fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (equalLNode(slow, fast)) {
            return true;
        }
    }
    return false;
}

bool equalLNode(LNode *q, LNode *p) {
    return p->data == q->data;
}
