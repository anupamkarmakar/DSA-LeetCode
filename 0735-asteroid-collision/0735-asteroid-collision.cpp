class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        list <int> lt;
        for(int ele : asteroids){
            if(ele>0) lt.push_back(ele);
            else{
                while(!lt.empty() && lt.back()>0 && lt.back()<abs(ele))
                    lt.pop_back();

                if(!lt.empty() && lt.back()==abs(ele)) lt.pop_back();

                else if(lt.empty() || lt.back()<0) lt.push_back(ele);
            }
        }
        vector<int>ans(lt.begin(), lt.end());
        return ans;
    }
};