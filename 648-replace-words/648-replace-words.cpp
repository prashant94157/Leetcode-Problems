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
    string replaceWord(string sentence)
    {
        string replacingWord = "";
        Node *node = root;
        int state = 0;
        /*
            state = 0 means we have to insert while checking in trie
            state = 1 means we have don't have insert
            state = 2 maens we have to insert without checking
        */
        for(char ch:sentence)
        {
            if(ch==' ')
            {
                replacingWord += ch;
                state = 0;
                node = root;
            }
            else if(state == 0)
            {
                if(node->isEnd()) 
                {
                    
                    state = 1;
                }
                else if(node->containKey(ch))
                {
                    replacingWord += ch;
                    node = node->get(ch);
                }
                else
                {
                    replacingWord += ch;
                    state = 2;
                }
            }
            else if(state == 1)
            {
                continue;
            }
            else
            {
                replacingWord += ch;
            }
        }
        return replacingWord;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for(string word:dictionary)
        {
            trie.insert(word);
        }
        return trie.replaceWord(sentence);
    }
};