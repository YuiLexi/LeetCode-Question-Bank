#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main()
{
    char *convert(char *s, int numRows);
    char *s = "ABCD";
    int numRows = 3;
    char *result = convert(s, numRows);
    printf("%s\n", result);

    printf("程序结束!!!\n");
    free(result);
    return 0;
}
char *convert(char *s, int numRows)
{
    if (s[0] == 0 || numRows == 1)
    {
        return s;
    }
    int len = strlen(s);
    char *result = (char *)malloc(sizeof(char) * (len + 1));
    int cycleLen = 2 * numRows - 2;
    int index = 0;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = i; j < len; j += cycleLen)
        {
            result[index++] = s[j];
            if (i != 0 && i != numRows - 1 && j + 2 * (numRows - 1 - i) < len)
            {
                result[index++] = s[j + 2 * (numRows - 1 - i)];
            }
        }
    }
    result[index] = 0;
    return result;
}