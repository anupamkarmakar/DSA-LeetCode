class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque <int> dq;
        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            if(!dq.empty() && dq.front()<=i-k)  dq.pop_front(); // Remove element out of this window
            while(!dq.empty() && nums[dq.back()]<nums[i])   dq.pop_back();  // Remove smaller element from back
            dq.push_back(i); //Add current index
            if(i>=k-1) ans.push_back(nums[dq.front()]); //When we have first full window
        }
        return ans;
    }
};