#include <stdio.h>

#define MAXN 105
#define INFINITE 9999

typedef int ElemType;

typedef struct
{
    int Vex[MAXN][MAXN];
    ElemType vextics[MAXN];
    int vexNum, edgeNum;
} MGraph;

typedef struct
{
    int lowcost; // 权值
    int adjvex;  // 在顶点集合中距离当前结点最近的结点
} ce[MAXN];

void Prim(MGraph G, int v);

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

void Prim(MGraph G, int v)
{
    // 定义结构体ce，存储结点的最小权值，从第一个顶点开始，循环遍历找到权值最小的邻接边
    ce closestEdge;
    for (int i = 0; i < G.vexNum; i++)
    {
        closestEdge[i] = {G.Vex[v][i], v}; // 初始图中所有顶点
    }
    closestEdge[v].lowcost = 0; // 0表示当前结点已经加入顶点集
    for (int i = 0; i < G.vexNum; i++)
    {
        int minIndex = -1, minValue = INFINITE;
        for (int j = 0; j < G.vexNum; j++)
        {
            if (minValue > closestEdge[j].lowcost)
            {
                minValue = closestEdge[i].lowcost;
                minIndex = j;
            }
        } // 遍历找到邻接边中最小的一条边，将该边加入顶点集
        closestEdge[minIndex].lowcost = 0;
        // 更新剩余顶点的最短路径
        for (int k = 0; k < G.vexNum; k++)
        {
            if (G.Vex[minIndex][k] < closestEdge[k].lowcost)
            {
                closestEdge[k] = {G.Vex[minIndex][k], minIndex};
            }
        }
    }
}
