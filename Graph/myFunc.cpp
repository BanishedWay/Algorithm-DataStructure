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
    visit(G.vertics[i]);

    for (EdgeNode *p = G.vertics[i].first; p; p = p->next)
    {
        if (!visited[p->adjvex])
        {
            DFS(G, p->adjvex, visited);
        } //如果邻接的顶点没有遍历，则进入该邻接顶点
    }
}

void BFS(ALGraph G, int i, int visited[])
{
    VNode queue[MAXN];
    int front = 0, rear = 0;
    //使用队列完成广度优先遍历
    //在入队的时候完成遍历
    queue[rear++] = G.vertics[i];
    visit(G.vertics[i]);
    visited[i] = 1;
    while (rear != front)
    {
        VNode u = queue[front++];
        for (EdgeNode *p = u.first; p != NULL; p = p->next)
        {
            if (!visited[p->adjvex])
            {
                visited[p->adjvex] = 1;
                visit(G.vertics[p->adjvex]);
                queue[rear++] = G.vertics[p->adjvex];
            } //依次将出队顶点的邻接顶点加入队列
        }
    }
}

void BFSTraverse(ALGraph G)
{
    int visited[MAXN];

    for (int i = 0; i < G.edgeNum; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < G.edgeNum; i++)
    {
        if (!visited[i])
        {
            BFS(G, i, visited);
        }
    }
}

int GetConnectedByBFS(ALGraph G)
{
    int visited[MAXN];
    int count = 0;
    for (int i = 0; i < G.vexNum; i++)
    {
        if (!visited[i])
        {
            visited[i] = 0;
        }
    }
    for (int i = 0; i < G.vexNum; i++)
    {
        if (!visited[i])
        {
            count++;
            BFS(G, i, visited);
        }
    }
}

int isTree(ALGraph G)
{
    int visited[MAXN];

    for (int i = 0; i < G.vexNum; i++)
    {
        visited[i] = 0;
    }

    int vexNum = 0, edgeNum = 0;
    GetVexAndEdge(G, 0, vexNum, edgeNum, visited);
    return vexNum == G.vexNum && edgeNum - 1 == G.edgeNum / 2;         //是否为生成树
    return vexNum == G.vexNum && (edgeNum - 1) * edgeNum == G.edgeNum; //是否为完全图
}

void GetVexAndEdge(ALGraph G, int i, int &vexNum, int &edgeNum, int visited[])
{
    visited[i] = 1;
    vexNum++;
    for (EdgeNode *e = G.vertics[i].first; e; e->next)
    {
        edgeNum++; //当遍历一条边时，+1
        if (!visited[e->adjvex])
        {
            GetVexAndEdge(G, e->adjvex, vexNum, edgeNum, visited);
            //深度优先遍历后续顶点
        }
    }
} //最后结果得到顶点数和边数

void DFSLoop(ALGraph G, int i, int visited[], int &flag)
{
    visited[i] = 1;
    for (EdgeNode *p = G.vertics[i].first; p; p = p->next)
    {
        //依次遍历顶点i的邻接顶点
        if (!visited[p->adjvex])
        {
            DFSLoop(G, p->adjvex, visited, flag);
        } //没有访问过则进入该顶点
        else
        {
            //否则表明该顶点已经访问过，即存在回路
            flag = 1;
        }
    }
}

int hasLoop(ALGraph G)
{
    int visited[MAXN];
    for (int i = 0; i < G.vexNum; i++)
    {
        visited[i] = 0;
    }

    int flag = 0;
    for (int i = 0; i < G.vexNum; i++)
    {
        //对未访问过的顶点采用深度优先方法遍历
        if (!visited[i])
        {
            DFSLoop(G, i, visited, flag);
        } //深度优先遍历确定是否存在环
    }
    return flag; //返回结果
}