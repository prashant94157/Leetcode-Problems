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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        int rem =0;
        ListNode *head = l1, *temp = l1;
        while(l1 && l2)
        {
            int sum = l1->val + l2->val + rem;
            l1->val = sum%10;
            rem  = sum/10;
            
            temp = l1;
            l1=l1->next;
            l2=l2->next;
        }        
        if(l2)
        { 
            l1 = l2;
            temp->next = l2;
        }
        while(rem)
        {
            if(l1)
            {
                int sum = l1->val + rem;
                l1->val = sum%10;
                rem  = sum/10;

                temp = l1;
                l1=l1->next;
            }
            else
            {
                temp->next = new ListNode(rem);
                rem =0;
            }
        }
        return head;
    }
};