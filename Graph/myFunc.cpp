#include "myFunc.h"
#include <stdlib.h>

void ALGraph2MGraph(ALGraph AG, MGraph &MG)
{
    MG.edgeNum = AG.edgeNum;
    MG.vexNum = AG.vexNum;
    for (int i = 0; i < AG.vexNum; i++)
    {
        EdgeNode *p = AG.vertics[i].first;
        while (p)
        {
            MG.Edge[i][p->adjvex] = 1; //复制边信息
            p = p->next;
        }                               //遍历边结点
        MG.Vex[i] = AG.vertics[i].data; //复制顶点信息
    }
}

void MGraph2ALGraph(MGraph MG, ALGraph &AG)
{
    AG.edgeNum = MG.edgeNum;
    AG.vexNum = MG.vexNum;
    for (int i = 0; i < MG.vexNum; i++)
    {
        for (int j = 0; j < MG.vexNum; j++)
        {
            if (MG.Edge[i][j] != 0)
            {
                //建立一个新的弧结点
                EdgeNode *p = (EdgeNode *)malloc(sizeof(EdgeNode));
                p->adjvex = j;
                p->next = AG.vertics[i].first;
                AG.vertics[i].first = p; //头插法插入结点
            }                            //复制边信息
        }
        AG.vertics[i].data = MG.Vex[i]; //复制顶点信息
    }
}

void DFSTraverse(ALGraph G)
{
    int visited[MAXN];
    for (int i = 0; i < G.vexNum; i++)
    {
        visited[i] = 0;
    } //初始化

    for (int i = 0; i < G.vexNum; i++)
    {
        if (visited[i] == 0)
        {
            DFS(G, i, visited);
        }
    } //从第0个结点开始遍历
}
void DFS(ALGraph G, int i, int visited[])
{
    visited[i] = 1;
    visit(i);

    for (EdgeNode *p = G.vertics[i].first; p; p = p->next)
    {
        if (!visited[p->adjvex])
        {
            DFS(G, p->adjvex, visited);
        } //如果邻接的顶点没有遍历，则进入该邻接顶点
    }
}