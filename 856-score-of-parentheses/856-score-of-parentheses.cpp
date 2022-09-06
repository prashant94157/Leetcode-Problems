class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0, balance = 0, n = s.size() ;
        for(int i=0;i<n;i++)
        {
            char a = s[i];
            if(a=='(')
            {
                balance++;
            }
            else
            {
                balance--;
                if(s[i-1]=='(')
                score += 1<<balance;
            }
        }
        return score;
    }
};