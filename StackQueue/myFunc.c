#include "myFunc.h"
#include <stdio.h>
#include <string.h>

void constrain(int num, int hex) {
    if (num < 0) {
        // print minus
        printf("-");
    }
    int m = 0;
    int stack[MAXN];
    int top = -1;
    while (num) {
        m = num % hex;
        num = num / hex;
        stack[++top] = m;
    }
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int HuiWen(char *str) {
    char stack[MAXN];
    int top = -1;
    // 回文串入栈和出栈顺序一样
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        stack[++top] = *(str + i);
    }
    for (int i = 0; i < len; i++) {
        if (stack[top--] != *(str + i)) {
            return 0;
        }
    }
    return 1;
}

void edit() {
    char stack[MAXN];
    int top = -1;
    char c;
    while (EOF != (c = getchar())) {
        while (c != '\n') {
            // 一次编辑一行
            switch (c) {
            case '#':
                if (top >= 0) {
                    top--;
                }
                break;
            case '@':
                // 删除整行
                top = -1;
                break;
            default:
                stack[++top] = c;
                break;
            }
            c = getchar();
        }
        stack[++top] = c;
        for (int i = 0; i <= top; i++) {
            printf("%c", stack[top]);
        }
        top = -1;
    }
}

int fib(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return fib(n - 1) + fib(n - 1);
}

void hanoi(int n, char A, char B, char C) {
    // 移动n个盘从A到C，B作为辅助
    if (n == 1) {
        move(A, C);
        // 只有一个时，从A移动到C
    } else {
        hanoi(n - 1, A, C, B);
        // 将上面n-1个盘移动到B，C做辅助盘
        move(A, C); // 将第n个从A移动到C
        hanoi(n - 1, B, A, C);
        // 将剩下的n-1个盘从B移动到C，A做辅助盘
    }
}

void move(char A, char B) {
    printf("%c-->%c\n", A, B);
}

void in2Post(char *inFix, char *postFix) {
    /**
     * 操作数直接输出
     * 操作符则判断优先级
     **/
    char stack[MAXN];
    int j = 0;
    int top = -1;
    char c;
    for (int i = 0; i < strlen(inFix); i++) {
        c = inFix[i];
        if (inFix[i] == '+' || inFix[i] == '-' || inFix[i] == '*' ||
                inFix[i] == '/') {
            while (top != -1 && cmpPriority(stack[top], c) == 1) {
                // 当栈顶操作符优先级大于c时，出栈
                postFix[j++] = stack[top--];
            }
        } else {
            // 操作数直接输出
            postFix[j++] = c;
        }
    }
    // 当栈不为空时，将剩余元素出栈
    while (top != -1) {
        postFix[j++] = stack[top--];
    }
    postFix[j++] = '\0'; // 加入字符结束标记
}

int match(char *str) {
    char stack[MAXN];
    int top = -1;
    while (*str != '\0') {
        if (*str == '(') {
            stack[++top] = ')';
        }
        if (*str == '[') {
            stack[++top] = ']';
        }
        if (*str == '{') {
            stack[++top] = '}';
        } // 输入左括号时，将对应的右括号入栈
        if (*str == ')' || *str == ']' || *str == '}') {
            if (top == -1 || stack[top--] != *str) {
                return 0;
            } // 当输出的右括号与当前右括号不等时，返回错误
        }
        str++;
    }
    return top == -1;
}

int cmpPriority(char c, char d) {
    return 1;
}
