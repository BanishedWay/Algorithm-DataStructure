#include <stdio.h>

#define MAXN 105

typedef struct EdgeNode
{
    int adjvex;
    struct EdgeNode *next;
} EdgeNode;

typedef struct
{
    int data;
    EdgeNode *first;
} VNode, AdjList[MAXN];

typedef struct
{
    AdjList vertics;
    int vexNum, edgeNum;
} ALGraph;

void dfs(ALGraph G, int start, int target, int visited[], int path[], int count);

void dfs(ALGraph G, int start, int target, int visited[], int path[], int count)
{
    visited[start] = 1;
    path[count++] = start; // 当前结点加入路径
    // 如果当前结点是最终结点，输出路径中所有结点
    if (start == target)
    {
        for (int i = 0; i < count; i++)
            printf("%d ", path[i]);
        printf("\n");
        return;
    }
    for (EdgeNode *p = G.vertics[start].first; p; p = p->next)
    {
        if (!visited[p->adjvex])
        {
            dfs(G, p->adjvex, target, visited, path, count);
        }
        visited[p->adjvex] = 0; // 回溯
    }
} // 这个算法是找到从start到target的所有简单路径，回溯的目的是为了让其他结点能够继续访问，不会漏掉任何一条路径