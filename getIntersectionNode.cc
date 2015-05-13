#include "iostream"
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(NULL == headA || NULL == headB)
        return NULL;
    struct ListNode *p = headA, *q = headB;
    int i = 0, j = 0;
    while(p != NULL)
    {
        i++;
        p = p->next;
    }
    while(q != NULL)
    {
        j++;
        q = q->next;
    }
    while(i > j)
    {
        headA = headA->next;
        i--;
    }
    while(j > i)
    {
        headB = headB->next;
        j--;
    }

    while(headA != NULL)
    {
        if(headA == headB)
            return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}



int main()
{



    return 0;
}
