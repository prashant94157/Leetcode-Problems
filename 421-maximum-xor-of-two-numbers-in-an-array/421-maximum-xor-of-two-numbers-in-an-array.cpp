struct Node{
    Node *links[2];
    bool containKey(int a)
    {
        return (links[a] != NULL);
    }
    void insert(int a, Node *node)
    {
        links[a] = node;
    }
    Node* moveNext(int a)
    {
        return links[a];
    }
};
class Trie{
    Node *root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(int a)
    {
        Node *node = root;
        for(int i=31;i>=0;i--)
        {
            int bit = (a>>i)&1;
            if(!node->containKey(bit))
            {
                node->insert(bit, new Node());
            }
            node = node->moveNext(bit);
        }
    }
    int getMax(int a)
    {
        Node *node = root;
        int res = 0;
        for(int i=31;i>=0;i--)
        {
            int bit = (a>>i)&1;
            if(node->containKey(1 - bit))
            {
                res = res|(1<<i);
                node = node->moveNext(1-bit);
            }
            else
            node = node->moveNext(bit);
        }
        return res;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto a:nums)
        {
            trie.insert(a);
        }
        int res = 0;
        for(auto a:nums)
        {
            res = max(res, trie.getMax(a));
        }
        return res;
    }
};