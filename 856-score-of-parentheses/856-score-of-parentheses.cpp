class Solution {
public:
    int scoreOfParentheses(string str) {
        stack<int> s;
        for(auto a:str)
        {
            if(a=='(')
            {
                s.push(-1);
            }
            else
            {
                if(s.top() == -1)
                {
                    s.pop();
                    if(s.size()==0 || s.top()==-1)
                    s.push(1);
                    else
                    {
                        int temp = s.top();
                        s.pop();
                        temp++;
                        s.push(temp);
                    }
                }
                else
                {
                    int t = s.top();
                    s.pop();
                    s.pop();
                    if(s.size()==0 || s.top()==-1)
                    s.push(2*t);
                    else
                    {
                        int temp = s.top() + 2*t;
                        s.pop();
                        s.push(temp);
                    }
                }
            }
            cout<<s.top()<<" "<<s.size()<<endl;
        }
        return s.top();
    }
};