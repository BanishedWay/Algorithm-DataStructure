#define MAXN 105

typedef struct
{
    int Edge[MAXN][MAXN];
    char Vex[MAXN];
    int vexNum, edgeNum;
} MGraph; //邻接矩阵

typedef struct EdgeNode
{
    int adjvex;
    struct EdgeNode *next;
} EdgeNode; //弧结点

typedef struct
{
    int data;
    EdgeNode *first;
} VNode, AdjList[MAXN]; //顶点结点

typedef struct
{
    AdjList vertics;
    int edgeNum, vexNum;
} ALGraph; //邻接表

void MGraph2ALGraph(MGraph M, ALGraph &G);