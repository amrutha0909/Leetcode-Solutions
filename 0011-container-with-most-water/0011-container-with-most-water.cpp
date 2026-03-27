class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int n=height.size();
        int right=n-1;
        int maxi=0;
        int hgt;
        while(left<right){
            if(height[left]<height[right])hgt=height[left];
            else if(height[left]>height[right])hgt=height[right];
            else hgt=height[left];
            maxi=max(maxi,hgt*(right-left));
            if(height[left]<=height[right]){
                left++;
            }
            else right--;
        }
        return maxi;
    }
};