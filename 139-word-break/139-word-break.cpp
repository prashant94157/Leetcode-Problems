struct Node{
    Node *links[26];
    bool flag = false;
    bool containKey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }
    void insert(char ch ,Node *node)
    {
        links[ch -'a'] = node;
    }
    Node *moveNext(char ch)
    {
        return links[ch -'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    bool getEnd()
    {
        return flag;
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
        for(auto ch:s)
        {
            if(!node->containKey(ch))
            {
                node->insert(ch, new Node());
            }
            node = node->moveNext(ch);
        }
        node->setEnd();
    }
    bool check(string s)
    {
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i=0;i<n;i++)
        {
            if (dp[i]) {
                Node *p = root;
                for (int j = i; j < n; j++) {
                    if (!p->containKey(s[j]))
                        break;
                    p = p->moveNext(s[j]);
                    if (p->getEnd())
                        dp[j+1] = true;
                }
            }
        }
        return dp[n];
    }
};
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for(auto word:wordDict)
        {
            trie.insert(word);
        }
        return trie.check(s);
    }
};