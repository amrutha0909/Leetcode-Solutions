class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        if(n>m){
            return findMedianSortedArrays(nums2,nums1);
        }
        int l1=0;
        int r1=n;
        while(l1<=r1){
            int l2=(l1+r1)/2;
            int r2=(n+m+1)/2-l2;
            int maxLeft1=(l2==0)?INT_MIN:nums1[l2-1];
            int minRight1=(l2==n)?INT_MAX:nums1[l2];
            int maxLeft2=(r2==0)?INT_MIN:nums2[r2-1];
            int minRight2=(r2==m)?INT_MAX:nums2[r2];
            if(maxLeft1<=minRight2&&maxLeft2<=minRight1){
                if((n+m)%2==0){
                    return (max(maxLeft1,maxLeft2)+min(minRight1,minRight2))/2.0;
                }
                else{
                    return max(maxLeft1,maxLeft2);
                }
            }
            else if(maxLeft1>minRight2){
                r1=l2-1;
            }
            else{
                l1=l2+1;
            }
        }
        return 0.0;
    }
};