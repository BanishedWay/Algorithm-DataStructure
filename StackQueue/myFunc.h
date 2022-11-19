#define MAXN 105

// 十进制转换
void constrain(int num, int hex);

// 字符串回文串判定
int HuiWen(char *str);

// 行编辑程序
void edit();

// 斐波那契数列
int fib(int n);

// 汉诺塔
void hanoi(int n, char A, char B, char C);
void move(char A, char B);

// 中缀转后缀
void in2Post(char *inFix, char *postFix);
int cmpPriority(char c, char d);

// 括号匹配
int match(char *str);
