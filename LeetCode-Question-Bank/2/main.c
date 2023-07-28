#include <stdio.h>
#include <malloc.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

int main()
{
    printf("程序结束!!!\n");
    return 0;
}
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = 0;
    head->next = NULL;
    struct ListNode *p = head;
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;
    int flag = 0;
    while (p1 != NULL && p2 != NULL)
    {
        int number = p1->val + p2->val + flag;
        flag = number / 10;
        number %= 10;

        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p = p->next;
        p->val = number;
        p->next = NULL;
        p1 = p1->next;
        p2 = p2->next;
    }
    if (p1 == NULL)
    {
        while (p2 != NULL)
        {
            int number = p2->val + flag;
            flag = number / 10;
            number %= 10;

            p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            p = p->next;
            p->val = number;
            p->next = NULL;
            p2 = p2->next;
        }
    }
    else
    {
        while (p1 != NULL)
        {
            int number = p1->val + flag;
            flag = number / 10;
            number %= 10;

            p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            p = p->next;
            p->val = number;
            p->next = NULL;
            p1 = p1->next;
        }
    }
    if (flag == 1)
    {
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p = p->next;
        p->val = 1;
        p->next = NULL;
    }
    return head->next;
}