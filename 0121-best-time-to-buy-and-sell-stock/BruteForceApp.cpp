class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buyEle=prices[0];
        int profit=0;
        for(int i=1;i<n;i++){   
            if(prices[i]<buyEle) 
                buyEle=prices[i];

            else if(prices[i]-buyEle>profit) 
                profit=prices[i]-buyEle;
        }
        return profit;
    }
};