/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*> mp;
        Node *headd= new Node(0);
        Node *temp = head, *node = headd;
        while(temp)
        {
            node->next = new Node(temp->val);
            node = node->next;
            mp[temp] = node;
            temp = temp->next;
        }
        temp = head;
        node = headd->next;
        while(temp)
        {
            if(temp->random)
            node->random = mp[temp->random];
            else node->random = NULL;
            temp = temp->next;
            node = node->next;
        }
        return headd->next;
    }
};