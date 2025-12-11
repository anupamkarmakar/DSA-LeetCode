class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> maxRow(n+1 ,0);
        vector<int> minRow(n+1 ,n+1);
        vector<int> maxCol(n+1 ,0);
        vector<int> minCol(n+1 ,n+1);

        for(auto& p : buildings){
            int x=p[0], y=p[1];

            maxRow[y] = max(maxRow[y],x); 
            minRow[y] = min(minRow[y],x); 

            maxCol[x] = max(maxCol[x],y); 
            minCol[x] = min(minCol[x],y); 
        }

        int ans=0;
        for(auto& p : buildings){
            int x=p[0], y=p[1];

            if(x<maxRow[y] && x>minRow[y] && y<maxCol[x] && y>minCol[x])
                ans+=1;
        }

        return ans;
    }
};