class StockSpanner {
public:
    stack <pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span=1;
        while(!st.empty() && st.top().first<=price){
            span+=st.top().second; //We store span to compress many days into one stack entry, so we can count multiple days at once instead of one-by-one.
            st.pop();
        }

        st.push({price,span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */