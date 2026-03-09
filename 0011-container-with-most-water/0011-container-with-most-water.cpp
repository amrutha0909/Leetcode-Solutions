class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int maxArea=INT_MIN;
        int hgt;
        int width;
        while(left<right){
            width=right-left;
            if(height[left]==height[right]){
                hgt=height[left];
            }
            else{
                hgt=min(height[left],height[right]);
            }
            maxArea=max(maxArea,width*hgt);
            if(height[left]<=height[right])left++;
            else right--;
        }
        return maxArea;
    }
};