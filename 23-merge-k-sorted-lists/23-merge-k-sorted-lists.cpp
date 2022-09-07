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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int, ListNode*>>> pq;
        ListNode *head = new ListNode(0);
        ListNode *temp = head;
        for(auto a:lists)
        {
            if(a)
            pq.push({a->val,a});
        }
        while(pq.size())
        {
            pair<int,ListNode*> p = pq.top();
            pq.pop();
            
            temp->next = p.second;
            p.second = p.second->next;
            temp = temp->next;
            temp->next = NULL;
            if(p.second)
                pq.push({p.second->val, p.second});
        }
        return head->next;
    }
};