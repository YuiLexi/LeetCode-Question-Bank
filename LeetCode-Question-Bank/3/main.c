#include <stdio.h>

char s[] = "abcabcbb";
int main()
{
    int lengthOfLongestSubstring(char *s);
    printf("程序开始!!!\n");
    printf("字符串为：%s\n", s);
    printf("最长子串长度为：%d\n", lengthOfLongestSubstring(s));
    printf("程序结束!!!\n");
    return 0;
}

int lengthOfLongestSubstring(char *s)
{
    int length = 0;
    int head = 0;
    int tail = 0;
    if (s[0] == 0)
    {
        return 0;
    }
    while (s[tail] != 0)
    {
        for (int i = head; i < tail; i++)
        {
            // 如果相等，说明有重复的字符，需要重新计算长度
            if (s[i] == s[tail])
            {
                length = tail - head > length ? tail - head : length;
                head = i + 1;
                break;
            }
        }
        tail++;
    }
    length = tail - head > length ? tail - head : length;
    return length;
}