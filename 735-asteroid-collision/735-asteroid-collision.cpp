class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        stack<int> s;
        for(auto a:asteroids)
        {
            if(s.size()==0 || a > 0 ||(a < 0 && s.top()<0))
                s.push(a);
            else
            {
                while(s.size() && s.top() > 0 && s.top() + a < 0)
                    s.pop();
                if(s.size() && a+s.top() == 0)
                {
                    s.pop();continue;
                }
                if(s.size()==0 || s.top()<0)
                    s.push(a);
            }
            cout<<s.size()<<" ";
        }
        while(s.size())
        {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};