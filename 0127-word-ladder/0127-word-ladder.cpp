static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        bool p=0;
        for(auto w:wordList)
        {
            if(endWord.compare(w)==0 )
                p=1;
            s.insert(w);
        }
        if(p==0)
            return 0;
        queue<string> q;
        q.push(beginWord);
        int res=0;
        while(q.size())
        {
            res++;
            int n = q.size();
            while(n--)
            {
                string temp = q.front();
                q.pop();
                
                for(int i=0;i<temp.size();i++)
                {
                    string t = temp;
                    for(char c = 'a';c<='z';c++)
                    {
                        t[i] = c;
                        if(t == temp)
                            continue;
                        if(t==endWord)
                            return res+1;
                        if(s.find(t)!=s.end())
                        {
                            s.erase(t);
                            q.push(t);
                        }
                    }
                }
                
            }
        }
        return 0;
    }
};