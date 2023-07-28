#include <stdio.h>

char s[] = "babad";
int main()
{
    char *longestPalindrome(char *s);
    printf("程序开始!!!\n");
    printf("字符串为：%s\n", s);
    printf("最长回文子串为：%s\n", longestPalindrome(s));
    printf("程序结束!!!\n");
    return 0;
}
char *longestPalindrome(char *s)
{
    char *result = NULL;
    int length = 0;
    int head = 0;
    int tail = 0;
    // 判断字符串是否为空（空，不是空格字符）
    if (s[0] == 0)
    {
        return 0;
    }
    while (s[head] != 0)
    {
        while (s[tail] != 0)
        {
            if (s[head] == s[tail])
            {
                int flag = 1;
                for (int i = 0; i < (tail - head + 1) / 2; i++)
                {
                    if (s[head + i] != s[tail - i])
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 1)
                {
                    if (tail - head + 1 > length)
                    {
                        length = tail - head + 1;
                        result = &s[head];
                    }
                }
            }
            tail++;
        }
        head++;
        tail = head;
    }
    result[length] = 0;
    return result;
}