struct Node{
    Node *child[10];
    bool flag = false;
    void put(int ch, Node *node)
    {
        // cout<<"put : "<<ch<<endl;
        child[ch] = node;
    }
    Node *get(int ch)
    {
        // cout<<"get : "<<ch<<endl;
        return child[ch];
    }
    bool isEnd()
    {
        return flag;
    }
    void setEnd()
    {
        flag = true;
    }
    bool containKey(int ch)
    {
        return (child[ch]!=NULL);
    }
};

class Trie{
    Node *root;
    public:
    Trie()
    {
        root = new Node();
    }
    int digit(long long n) {
      return floor(log10(n) + 1);
    }
    void insert(int num)
    {
        Node *node = root;
        int di = digit(num);
        int mod = pow(10,di-1);
        
        for(int i=0;i<di;i++)
        {
            if(!node->containKey(num/mod))
            {
                node->put(num/mod, new Node());
            }
            node = node->get(num/mod);
            num%=mod;
            mod/=10;
        }
        node->setEnd();
    }
    void recur(Node *node,vector<int> &res,int num)
    {
        if(node==NULL)
            return;
        for(int i=0;i<10;i++)
        {
            if(node->containKey(i))
            {
                if(num*10 + i != 0)
                res.push_back(num*10 + i);
                recur(node->get(i),res,num*10 + i);
            }
        }
    }
    void explore(vector<int> &res)
    {
        recur(root, res,0);
    }
};
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        Trie trie;
        for(int i=1;i<=n;i++)
        {
            trie.insert(i);
            // cout<<endl;
        }
        trie.explore(res);
        return res;
    }
};