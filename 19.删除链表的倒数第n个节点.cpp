/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto ptr_need_del = head;
        auto ptr_need_del_prev = head;
        auto ptr_cur = head;
        for (auto i=n; i>=1; i--)
        {
            ptr_cur = ptr_cur->next;
        }
        while(ptr_cur != NULL)
        {
            ptr_cur = ptr_cur->next;
            ptr_need_del_prev = ptr_need_del;
            ptr_need_del = ptr_need_del->next;
        }

        if(ptr_need_del == head)
        {
            head = ptr_need_del->next;
        }
        else
        {
            ptr_need_del_prev->next = ptr_need_del->next;
        }
        delete ptr_need_del;
        
        return head;
    }
};
// @lc code=end

