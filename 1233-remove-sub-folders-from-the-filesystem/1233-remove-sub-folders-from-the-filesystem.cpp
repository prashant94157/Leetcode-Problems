struct Node{
    Node *child[27];
    bool flag = false;
    void put(char ch, Node *node)
    {
        // cout<<"put : "<<ch<<endl;
        if(ch!='/')
        child[ch-'a'] = node;
        else child[26] = node;
    }
    Node *get(char ch)
    {
        // cout<<"get : "<<ch<<endl;
        if(ch!='/')
        return child[ch-'a'];
        return child[26];
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
        // cout<<ch<<"\n";
        if(ch!='/')
        return child[ch-'a'] != NULL;
        return child[26] != NULL;
    }
};

class Trie{
    Node *root;
    public:
    Trie()
    {
        root = new Node();
    }
    void insert(string s)
    {
        Node *node = root;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            char ch = s[i];
            if(node->isEnd() && ch=='/')
            {
                // cout<<i<<" "<<ch<<endl;
                break;
            } 
            if(!node->containKey(ch))
            {
                node->put(ch, new Node());
            }
            
            node = node->get(ch);
        }
        node->setEnd();
    }
    void explore(vector<string> &res)
    {
        stack<pair<Node*,string>> st;
        st.push({root,""});
        while(!st.empty())
        {
            Node *node = st.top().first;
            string s = st.top().second;
            st.pop();
            if(node->isEnd())
            {
                res.push_back(s);
                // continue;
            }
            for(int i=0;i<26;i++)
            {
                if(node->containKey(char(i+'a')))
                {
                    // cout<<char(i)<<" "<<s<<endl;
                    st.push({node->get(char(i+'a')), s+char(i+'a')});
                }
            }
            if(node->containKey('/'))
            {
                st.push({node->get('/'), s+'/'});
            }
            
        }
    }
};
bool cmp(string a,string b)
{
    return a.size() < b.size();
}
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end(),cmp);
        vector<string> res;
        Trie trie;
        for(auto s:folder)
        {
            trie.insert(s);
            // cout<<endl;
        }
        trie.explore(res);
        return res;
    }
};