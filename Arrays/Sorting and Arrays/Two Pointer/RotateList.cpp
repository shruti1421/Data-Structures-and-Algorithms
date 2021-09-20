//https://leetcode.com/problems/rotate-list/
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *ptr=head;
        
        if(head==nullptr)
            return head;
        
        int i=1;
        while(ptr->next!=nullptr)
        {
            i++;
            ptr=ptr->next;
        }
         int n=i;    
        k=k%n;
            
        ptr->next=head;
        
        i=1;
        ptr=head;
        while(i<(n-k))
        {
            ptr=ptr->next;
            i++;
        }
        head=ptr->next;
        ptr->next=nullptr;
        
        return head;
    }
};