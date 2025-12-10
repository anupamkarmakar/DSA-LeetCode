class Solution {
public:
    vector<int> minOperations(string box) {
        int n=box.size();
        vector<int> ans;

        for(int i=0;i<n;i++){

            int op=0;

            for(int j=i+1;j<n;j++){
                if(box[j]=='1') op+=(j-i);
            }

            for(int k=i-1;k>=0;k--){
                if(box[k]=='1') op+=(i-k);
            }

            ans.push_back(op);
        }
        return ans;
    }
};