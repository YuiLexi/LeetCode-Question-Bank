#include <stdio.h>
#include <malloc.h>
int reverse(int x);
int pow(int x, int y);

int main()
{
    int x = 123;
    int result = reverse(x);
    printf("%d\n", result);
    printf("程序结束!!!\n");
    return 0;
}
int reverse(int x)
{
    int coef = x >= 0 ? 1 : -1; // 符号
    x = x >= 0 ? x : -x;        // 取绝对值
    int result = 0;
    int *number = (int *)malloc(sizeof(int) * 10);
    int index = 0;
    int isEffect = 0;
    for (int i = 9; i >= 0; i--)
    {
        if (isEffect == 0 && x / pow(10, i) != 0)
        {
            isEffect = 1;
        }
        if (isEffect == 1)
        {
            number[index++] = x / pow(10, i);
            x = x % pow(10, i);
        }
    }
    for (int i = 0; i < index; i++)
    {
        result += number[i] * pow(10, i);
    }
    return result >= -2 ^ 32 && result < 2 ^ 32 - 1 ? result : 0; // 判断是否溢出
}

int pow(int x, int y)
{
    int result = 1;
    for (int i = 0; i < y; i++)
    {
        result *= x;
    }
    return result;
}