class Solution {
    int recur(vector<string>& words, unordered_map<char,int> &mp , vector<int>& score,int j,unordered_map<string, int> &dp)
    {
        if(j<0)
            return 0;
        string temp = to_string(j);
        for(auto a:mp)
        {
            temp+='-';
            temp+=to_string(a.second);
        }
        if(dp.find(temp) != dp.end())
            return dp[temp];
        int res=0;
        int n = words[j].size(),i;
        unordered_map<char,int> nemp;
        nemp = mp;
        bool fl = 1;
        for(i=0;i<n;i++)
        {
            char ch = words[j][i];
            if(mp[ch]>0)
            {
                mp[ch]--;
                res+=score[ch-'a'];
            }
            else
            {
                fl=0;
                break;
            }
        }
        if(fl)
            return dp[temp] = max(res + recur(words, mp, score, j-1,dp), recur(words, nemp, score, j-1,dp));
        return dp[temp] =recur(words, nemp, score, j-1,dp);
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int> mp;
        for(char ch:letters)
            mp[ch]++;
        unordered_map<string, int> dp;
        return recur(words, mp, score, words.size()-1,dp);
    }
};