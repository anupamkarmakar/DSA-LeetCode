class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buyEle=prices[0],diff=0;
        for(int i=1;i<n;i++){   
            int res=prices[i]-buyEle;

            if(res>diff) diff=res;
            if(res<0) buyEle=prices[i];
        }
        return diff;
    }
};