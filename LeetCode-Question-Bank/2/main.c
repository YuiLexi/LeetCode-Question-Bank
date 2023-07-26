#include <stdio.h>
#include <malloc.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

int main()
{
    printf("程序结束!!!\n");
    return 0;
}
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->val = 0;
    head->next = NULL;

    ListNode *p = head;
    ListNode *p1 = l1;
    ListNode *p2 = l2;
    int flag = 0;
    while (p1->next != NULL && p2->next != NULL)
    {
        p->val = p1->val + p2->val + flag;
        flag = p->val / 10;
        p->val %= 10;
        p->next = (ListNode *)malloc(sizeof(ListNode));
        p = p->next;
        p1 = p1->next;
        p2 = p2->next;
    }
    if (p1->next != NULL)
    {
        p->val = p1->val;
        p->next = p1->next;
    }
    else if (p2->next != NULL)
    {
        p->val = p2->val;
        p->next = p2->next;
    }
    else
    {
        p = NULL;
    }
    return head;
}