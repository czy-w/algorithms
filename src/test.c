#include <stdio.h>

// 函数声明
int add(int a, int b);
int subtract(int a, int b);

int main() {
    int num1, num2;
    char operation;

    // 提示用户输入
    printf("请输入第一个整数: ");
    scanf("%d", &num1);
    printf("请选择操作 (+ 或 -): ");
    scanf(" %c", &operation);  // 注意前面的空格用于忽略之前的换行符
    printf("请输入第二个整数: ");
    scanf("%d", &num2);

    // 根据用户选择的操作进行计算
    switch (operation) {
        case '+':
            printf("结果: %d + %d = %d\n", num1, num2, add(num1, num2));
            break;
        case '-':
            printf("结果: %d - %d = %d\n", num1, num2, subtract(num1, num2));
            break;
        default:
            printf("无效的操作符!\n");
            break;
    }

    return 0;
}

// 函数定义
int add(int a, int b) { return a + b; }

int subtract(int a, int b) { return a - b; }