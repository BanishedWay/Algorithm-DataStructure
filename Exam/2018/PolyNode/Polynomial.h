typedef struct Node
{
    float coef; //系数
    int exp;    //阶数
    struct Node *next;
} PolyNode;

//将pa和pb合并
PolyNode *polyAdd(PolyNode &pa, PolyNode &pb);