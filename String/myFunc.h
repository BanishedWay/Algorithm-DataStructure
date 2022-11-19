#define MAXN 105

// 模式串匹配（普通算法）
int Index(char *S, char *T);

// 求Next数组
void getNext(char *T, int next[]);

// 求NextVal数组
void getNextVal(char *T, int nextVal[]);

// KMP算法
int KMP(char *S, char *T);
