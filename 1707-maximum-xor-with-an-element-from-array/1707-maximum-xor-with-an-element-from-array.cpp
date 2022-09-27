struct Node{
    Node *links[2];
    bool containKey(int a)
    {
        return (links[a]!=NULL);
    }
    void insert(int a,Node *node)
    {
        links[a] = node;
    }
    Node *moveNext(int a)
    {
        return links[a];
    }
};
class Trie{
    Node *root;
    public:
    Trie()
    {
        root = new Node();
    }
    void insert(int a)
    {
        Node *node = root;
        for(int i=31;i>=0;i--)
        {
            int bit = (a>>i) & 1;
            if(!node->containKey(bit))
            {
                node->insert(bit, new Node());
            }
            node = node->moveNext(bit);
        }
    }
    int maxXor(int x)
    {
        int res=0;
        Node *node = root;
        for(int i=31;i>=0;i--)
        {
            int bit = (x>>i) & 1;
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
    vector<int> maximizeXor(vector<int>& arr, vector<vector<int>>& queries) {
        vector<pair<int, pair<int,int>>> offlineQueries; 
        sort(arr.begin(), arr.end()); 
        int index = 0;
        for(auto &it: queries) {
            offlineQueries.push_back({it[1],{it[0], index++}}); 
        }
        vector<int> ans(queries.size(), 0); 
        sort(offlineQueries.begin(), offlineQueries.end()); 
        int i = 0; 
        int n = arr.size(); 
        Trie trie;

        for(auto &it : offlineQueries)
        {
             while(i < n && arr[i] <= it.first) {
                trie.insert(arr[i]); 
                i++; 
            }
            if(i!=0) ans[it.second.second] = trie.maxXor(it.second.first); 
            else ans[it.second.second] = -1; 
        }
        return ans;
    }
};