#define _CRT_SECURE_NO_WARNINGS 1

//x的平方根
int mySqrt(int x) {
    if (x == 0 || x == 1)
        return x;
    for (int i = 1; i < x; i++)
    {
        if (i <= x / i && (i + 1) > x / (i + 1))
            return i;
    }
    return 0;
}



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//删除排序链表中的重复元素
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL)
        return NULL;
    struct ListNode* prev = head;
    struct ListNode* cur = prev->next;
    while (cur)
    {
        if (prev->val == cur->val)
        {
            struct ListNode* next = cur->next;
            free(cur);
            prev->next = next;
            cur = next;
        }
        else
        {
            cur = cur->next;
            prev = prev->next;
        }

    }
    return head;

}