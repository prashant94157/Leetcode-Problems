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
    ListNode* partition(ListNode* head, int x) {
        ListNode* a=new ListNode(),*b=new ListNode(),*temp=head;
        ListNode *c = b;
        head = a;
        while(temp)
        {
            if(temp-> val < x)
            {
                a->next = temp;
                a=a->next;
            }
            else
            {
                // cout<<temp->val<<" ";
                b->next = temp;
                b = b->next;
            }
            temp = temp->next;
        }
        b->next = NULL;
        a->next = c -> next;
        // head = head->next;
        // return head;
        return head->next;
        // return c->next;
    }
};