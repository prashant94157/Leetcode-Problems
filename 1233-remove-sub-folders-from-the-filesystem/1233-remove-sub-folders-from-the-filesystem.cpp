struct Node{
    Node *child[26];
    bool flag = false;
    void put(char ch, Node *node)
    {
        // cout<<"put : "<<ch<<endl;
        child[ch-'a'] = node;
    }
    Node *get(char ch)
    {
        // cout<<"get : "<<ch<<endl;
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
        // cout<<ch<<"\n";
        return child[ch-'a'] != NULL;
    }
};

class Trie{
    Node *root;
    public:
    Trie()
    {
        root = new Node();
    }
    bool insert(string word){
        Node* temp = root;
        for(int i=0;i<word.size();i++){
            if(word[i]=='/')
                continue;
            if(!temp->containKey(word[i])){
                temp->put(word[i],new Node());
            }
            temp = temp->get(word[i]);
            if(word[i+1]=='/' && temp->isEnd()){
                return false;
            }
        }
        temp->setEnd();
        return true;
    }
};
bool cmp(string a,string b)
{
    return a.size() < b.size();
}
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string> ans;
        Trie* trie = new Trie();
        for(int i=0;i<folder.size();i++){
            if(trie->insert(folder[i])){
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};