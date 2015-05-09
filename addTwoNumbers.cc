#include "iostream"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    if(l1 == NULL || l2 == NULL)
        return NULL;
    int pre = 0;
    ListNode *root = (ListNode*)malloc(sizeof(ListNode));
    root->val = (l1->val + l2->val) % 10;
    root->next = NULL;
    pre = (l1->val + l2->val) / 10;

    l1 = l1->next;
    l2 = l2->next;
    ListNode *p = root, *q = NULL;

    while(l1 != NULL && l2 != NULL)
    {
        q = (ListNode*)malloc(sizeof(ListNode));
        q->val = (l1->val + l2->val + pre) % 10;
        q->next = NULL;
        pre = (l1->val + l2->val + pre) / 10;

        p->next = q;
        p = q;
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1 != NULL)
    {
        q = (ListNode*)malloc(sizeof(ListNode));
        q->val = (l1->val + pre) % 10;
        q->next = NULL;
        pre = (l1->val + pre) / 10;

        p->next = q;
        p = q;
        l1 = l1->next;
    }
    while(l2 != NULL)
    {
        q = (ListNode*)malloc(sizeof(ListNode));
        q->val = (l2->val + pre) % 10;
        q->next = NULL;
        pre = (l2->val + pre) / 10;

        p->next = q;
        p = q;
        l2 = l2->next;
    }
    if(pre > 0)
    {
        q = (ListNode*)malloc(sizeof(ListNode));
        q->val = pre % 10;
        q->next = NULL;

        p->next = q;
    }

    return root;
}

int main()
{


    return 0;
}
