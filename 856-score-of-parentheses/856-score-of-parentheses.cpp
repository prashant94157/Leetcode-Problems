class Solution {
public:
    int scoreOfParentheses(string str) {
        stack<string> s;
        for(auto a:str)
        {
            if(a=='(')
            {
                string temp;
                temp = a;
                s.push(temp);
            }
            else
            {
                if(s.top() == "(")
                {
                    s.pop();
                    if(s.size()==0 || s.top()=="(")
                    s.push("1");
                    else
                    {
                        int temp = stoi(s.top());
                        s.pop();
                        temp++;
                        s.push(to_string(temp));
                    }
                }
                else
                {
                    int t = stoi(s.top());
                    s.pop();
                    s.pop();
                    if(s.size()==0 || s.top()=="(")
                    s.push(to_string(2*t));
                    else
                    {
                        int temp = stoi(s.top()) + 2*t;
                        s.pop();
                        s.push(to_string(temp));
                    }
                }
            }
            cout<<s.top()<<" "<<s.size()<<endl;
        }
        return stoi(s.top());
    }
};