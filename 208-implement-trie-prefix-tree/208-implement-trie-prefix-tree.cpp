struct Node{
    Node *links[26];
    bool flag = false;
    bool containsKey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }
    void put(char ch,Node *a)
    {
        links[ch-'a'] = a;
    }
    Node *get(char ch)
    {
        return links[ch-'a'];
    }
    void setFlag()
    {
        flag = true;
    }
    bool getFlag()
    {
        return flag;
    }
};
class Trie {
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(char ch:word)
        {
            if(!node->containsKey(ch))
            {
                node->put(ch,new Node());
            }
            node = node->get(ch);
        }
        node->setFlag();
    }
    
    bool search(string word) {
        Node *node = root;
        for(char ch:word)
        {
            if(!node->containsKey(ch))
            {
                return false;
            }
            node = node->get(ch);
        }
        return node->getFlag();
    }
    
    bool startsWith(string word) {
        Node *node = root;
        for(char ch:word)
        {
            if(!node->containsKey(ch))
            {
                return false;
            }
            node = node->get(ch);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */