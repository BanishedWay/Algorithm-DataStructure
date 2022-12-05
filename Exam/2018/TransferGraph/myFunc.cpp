#include "myFunc.h"
#include <stdlib.h>

void MGraph2ALGraph(MGraph M, ALGraph &G)
{
    G.vexNum = M.vexNum;
    G.edgeNum = M.edgeNum;
    //循环遍历邻接矩阵，将为1的边加入邻接表
    for (int i = 0; i < M.vexNum; i++)
    {
        G.vertics[i].first = NULL;
        for (int j = 0; j < M.vexNum; j++)
        {
            if (M.Edge[i][j] != 0)
            {
                //当存在从i到j的边时，加入邻接表
                EdgeNode *p = (EdgeNode *)malloc(sizeof(EdgeNode));
                p->adjvex = j;
                p->next = G.vertics[i].first;
                G.vertics[i].first = p; //头插法将边结点插入到顶点结点后面
            }
        }
        G.vertics[i].data = M.Vex[i]; //复制顶点信息
    }
}