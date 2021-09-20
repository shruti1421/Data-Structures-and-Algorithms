//https://leetcode.com/problems/remove-nth-node-from-end-of-list/
//fast and slow pointer
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode *slow=head,*fast=head;
        
        if(n==1&&head->next==nullptr)
            return nullptr;
        
        int i=0;
        while(i<n)
        {
            i++;
            fast=fast->next;
        }
        
        if(fast==nullptr)
            return slow->next;
        
        while(fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next;
        }
        
        slow->next=slow->next->next;
        
        return head;
        
    }
};