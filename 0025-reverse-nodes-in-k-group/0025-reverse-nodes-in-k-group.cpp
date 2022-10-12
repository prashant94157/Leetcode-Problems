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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *headd = new ListNode(0);
        ListNode *temp = head;
        int len=0;
        while(temp)
        {
            temp= temp->next;
            len++;
        }
        
        temp = headd;
        for(int i=0;i<len/k;i++)
        {
            ListNode *prev = NULL, *curr = head, *next = NULL;
            for(int j=0;j<k;j++)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            temp->next = prev;
            temp = head;
            head = curr;
        }
        temp->next = head;
        return headd->next;
    
    }
};