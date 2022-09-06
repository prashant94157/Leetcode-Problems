class StockSpanner {
    stack<pair<int,int>> s;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int c = 1;
        while(s.size() && s.top().first <= price)
        {
            c += (s.top().second);
            s.pop();
        }
        s.push({price,c});
        return c;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */