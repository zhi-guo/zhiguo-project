#include <stdio.h>

/**
 * @brief 代码规范练习主函数
 * @return int 程序退出码
 */
int main(void)
{
    int x = 5, y = 10;

    if (x == 5)
    {
        printf("x等于5\n");
    }
    else if (x == 10)
    {
        printf("x等于10\n");
    }
    else
    {
        printf("x既不等于5也不等于10\n");
    }

    // 循环打印0~4
    for (int i = 0; i < 5; i++)
    {
        printf("循环计数: %d\n", i);
    }

    // 计算1~10累加和
    int sum = 0;
    for (int i = 1; i <= 10; i++)
    {
        sum += i;
    }
    printf("1到10的和为: %d\n", sum);

    // 数组遍历打印
    int arr[3] = {1, 2, 3};
    for (int i = 0; i < 3; i++)
    {
        printf("数组元素: %d\n", arr[i]);
    }

    // 两数相加
    int a = 5, b = 3, c;
    c = a + b;
    printf("c的值: %d\n", c);

    return 0;
}