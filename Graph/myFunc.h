#define MAXN 105
typedef int ElemType;

typedef struct
{
    ElemType Vex[MAXN];
    int Edge[MAXN][MAXN];
    int vexNum, edgeNum;
} MGraph; //临界矩阵

typedef struct EdgeNode
{
    ElemType adjvex;       //弧头顶点
    struct EdgeNode *next; //下一天邻接的弧
} EdgeNode;

typedef struct
{
    ElemType data;   //弧尾顶点
    EdgeNode *first; //第一条邻接弧
} VNode, AdjList[MAXN];

typedef struct
{
    AdjList vertics;
    int vexNum, edgeNum;
} ALGraph; //邻接表存储

//邻接表转邻接矩阵
void ALGraph2MGraph(ALGraph AG, MGraph &MG);

//邻接矩阵转邻接表
void MGraph2ALGraph(MGraph MG, ALGraph &AG);

//深度优先遍历
void DFSTraverse(ALGraph G);
void DFS(ALGraph G, int i, int visited[]);
void visit(int i);