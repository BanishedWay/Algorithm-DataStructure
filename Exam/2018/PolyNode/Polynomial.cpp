#include "Polynomial.h"
#include <stdlib.h>

void polyAdd(PolyNode *pa, PolyNode *pb)
{
    PolyNode *p = pa->next;
    PolyNode *q = pb->next;
    PolyNode *pre = pa; // pre执行被比较结点的前一个
    PolyNode *r;
    //将两个链表合成一个
    while (p && q)
    {
        if (p->exp < q->exp)
        {
            // p更小时，p、pre同步后移
            pre = p;
            p = p->next;
        }
        else if (p->exp > q->exp)
        {
            // q更小时，q插入到q的前面
            r = q->next;
            q->next = p;
            pre->next = q;
            pre = q;
            q = r;
        }
        else
        {
            //相等时，如果二者系数相加为0，则删去两个结点
            if (p->coef + q->coef == 0)
            {
                //删去p
                pre->next = p->next;
                r = p;
                free(r);
            }
            else
            {
                p->coef += q->coef;
                pre = p;
            }
            p = pre->next;
            r = q;
            q = q->next;
            free(r);
        }
    }
}