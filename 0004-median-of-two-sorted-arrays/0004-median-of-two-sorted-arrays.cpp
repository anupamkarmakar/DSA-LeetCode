class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> marged;
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),back_inserter(marged));
        int n=marged.size();
        if(n%2!=0) return marged[n/2];
        else return (marged[n/2]+marged[(n/2)-1])/2.0;
    }
};