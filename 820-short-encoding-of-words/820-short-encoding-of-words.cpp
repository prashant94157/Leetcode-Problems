struct Node{
    Node *child[26];
    bool flag = false;
    void put(char ch, Node *node)
    {
        child[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return child[ch-'a'];
    }
    bool isEnd()
    {
        return flag;
    }
    void setEnd()
    {
        flag = true;
    }
    bool containKey(char ch)
    {
        return (child[ch-'a']!=NULL);
    }
};

class Trie{
    Node *root;
    public:
    Trie()
    {
        root = new Node();
    }
    void insert(string word)
    {
        Node *node = root;
        for(char ch:word)
        {
            if(!node->containKey(ch))
            {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    int explore()
    {
        stack<pair<Node*,int>> st;
        st.push({root,1});
        int res=0;
        while(!st.empty())
        {
            Node *node = st.top().first;
            int level = st.top().second;
            st.pop();
            
            bool flag = 0;
            for(auto a:node->child)
            {
                if(a)
                {
                    flag = 1;
                    st.push({a,level+1});
                }
            }
            if(flag && node->isEnd())
                res+=level;
        }
        return res;
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie trie;
        int res=0;
        sort(words.begin(), words.end());
        words.erase(unique(words.begin(), words.end()), words.end());
        for(string word:words)
        {
            reverse(word.begin(), word.end());
            trie.insert(word);
            res+=word.size()+1;
        }
        return res - trie.explore();
    }
};