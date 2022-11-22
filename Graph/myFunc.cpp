#include "myFunc.h"
#include <stdlib.h>
#include <string.h>

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

void Prim(MGraph G, int u)
{
    ce closeEdge;
    for (int i = 0; i < G.vexNum; i++)
    {
        closeEdge[i] = {u, G.Edge[u][i]};
    }                         //初始化
    closeEdge[u].lowcost = 0; //表示u已经进入顶点序列
    for (int i = 0; i < G.vexNum; i++)
    {
        if (i != u)
        {
            int k, min = 9999; //最近的顶点标记为k，最近距离标记为min
            for (int j = 0; j < G.vexNum; j++)
            {
                if (closeEdge[j].lowcost > 0 && closeEdge[j].lowcost < min)
                {
                    //出现更小的顶点时，更新min和k
                    min = closeEdge[j].lowcost;
                    k = j;
                }
            }
            //加入顶点k和对应的边
            for (int j = 0; j < G.vexNum; j++)
            {
                if (G.Edge[k][j] < closeEdge[j].lowcost)
                {
                    closeEdge[j] = {k, G.Edge[k][j]};
                } //新的顶点加入顶点集后，更新lowcost和最近的顶点值
            }
        }
    }
}
void Kruskal(MGraph G)
{
    Edge edges;
    //初始化边数值
    int k = 0;
    int saved[MAXN]; //存放已经进入顶点集的顶点
    for (int i = 0; i < G.vexNum; i++)
    {
        for (int j = 0; j < G.vexNum; j++)
        {
            if (G.Edge[i][j] != -1)
            {
                edges[k].v = i;
                edges[k].w = j;
                edges[k].cost = G.Edge[i][j];
                k++;
            }
        }
    }

    /**
    //遍历边数组，找到权值最小的边
    int count = 0, savedNum = 0; //记录边数
    while (count != G.vexNum - 1 || savedNum != G.vexNum)
    {
        //当最小生成树的边数小于n-1时
        int min = 999, index;
        for (int i = 0; i < k; i++)
        {
            if (edges[i].cost != 0 && edges[i].cost < min)
            {
                min = edges[i].cost;
                index = i; //记录最小边的序号和权值
            }
        } //找到没有加入生成树的边
        int lv = includeVex(saved, savedNum, edges[index].v), lw = includeVex(saved, savedNum, edges[index].w);
        if (!lv || !lw)
        {
            //当边的两个顶点中有一个不在顶点集中，更新顶点集和边数
            count++;
            if (!lv)
                saved[savedNum++] = edges[index].v;
            if (!lw)
                saved[savedNum++] = edges[index].w;
            edges[index].cost = 0; //设置为0标记下次遍历不查询
        }
    }**/
    //此法错误，应该判断两个顶点是否在一个连通分量中
}

void Dijstra(MGraph G, int v, char *path[])
{
    // visited判断是否已经找到该顶点的最短路径
    //初始化距离
    int distance[MAXN], visited[MAXN];
    for (int i = 0; i < G.vexNum; i++)
    {
        if (G.Edge[v][i] != 0)
        {
            distance[i] = G.Edge[v][i];
            visited[i] = 0;
            strcat(path[i], "->");
            // strcat(path[i], G.Vex[i]);
        }
    }
    distance[v] = 0;
    visited[v] = 1;
    //对源点初始化

    for (int i = 0; i < G.vexNum; i++)
    {
        if (i == v)
            continue;
        int minDis = INFINITE, minIndex = 0;
        for (int j = 0; j < G.vexNum; j++)
        {
            //循环找到最近的未被访问的顶点
            if (!visited[j] && distance[j] < minDis)
            {
                minDis = distance[j];
                minIndex = j;
            }
        }
        //将最近的顶点标记为完成
        visited[minIndex] = 1;
        strcat(path[minIndex], "->");
        // strcat(path[minIndex], G.Vex[minIndex]);
        for (int j = 0; i < G.vexNum; j++)
        {
            //更新每个顶点的最短距离
            if (!visited[j] && distance[j] > distance[minIndex] + G.Edge[minIndex][j])
            {
                distance[j] = distance[minIndex] + G.Edge[minIndex][j];
                strcat(path[minIndex], "->");
                // strcat(path[minIndex], G.Vex[minIndex]);
            }
        }
    }
}

/**
 * path[u][v][w]记录w是不是uv最短路径上的顶点
 **/
void Floyd(MGraph G, int **Path[], int *dist[])
{
    //初始化
    for (int u = 0; u < G.vexNum; u++)
    {
        for (int v = 0; v < G.vexNum; v++)
        {
            dist[u][v] = G.Edge[u][v];
            for (int w = 0; w < G.vexNum; w++)
            {
                Path[u][v][w] = 0;
            }
            if (dist[u][v] < INFINITE)
            {
                // u、v之间存在直接路径
                Path[u][v][u] = 1;
                Path[u][v][v] = 1;
            }
        }
    }

    for (int w = 0; w < G.vexNum; w++)
    {
        for (int u = 0; u < G.vexNum; u++)
        {
            for (int v = 0; v < G.vexNum; v++)
            {
                //依次考虑加入w后对最短路径的影响
                if (dist[u][v] > dist[u][w] + dist[w][v])
                {
                    //更新最短路径
                    dist[u][v] = dist[u][w] + dist[w][v];
                    for (int i = 0; i < G.vexNum; i++)
                    {
                        //在uw和wv上的顶点也是最短路径uv上的顶点
                        Path[u][v][i] = Path[u][w][i] || Path[w][v][i];
                    }
                }
            }
        }
    }
}

void FindInDegree(ALGraph G, int *indegree)
{
    for (int i = 0; i < G.vexNum; i++)
    {
        indegree[i] = 0;
    } //初始化入度
    for (int i = 0; i < G.vexNum; i++)
    {
        for (EdgeNode *p = G.vertics[i].first; p; p = p->next)
        {
            indegree[p->adjvex]++;
        }
    }
}

int TopLogicalSort(ALGraph G)
{
    int indegree[MAXN];
    int stack[MAXN], top = -1;
    for (int i = -0; i < G.vexNum; i++)
    {
        //将所有入度为0的顶点入栈
        if (indegree[i] == 0)
        {
            stack[++top] = i;
        }
    }
    int count = 0; //记录已经输出的元素个数
    while (top != -1)
    {
        //当栈不空时，退栈
        int v = stack[top--];
        count++;
        //所有与顶点v邻接的顶点入度-1
        for (EdgeNode *p = G.vertics[v].first; p; p = p->next)
        {
            indegree[p->adjvex]--;
            //当入度为0则入栈
            if (indegree[p->adjvex] == 0)
            {
                stack[++top] = p->adjvex;
            }
        }
    }
    //当没有输出全部顶点，则表明有环
    if (count < G.vexNum)
    {
        return 0;
    }
    return 1;
}