class Solution {
    public:
        int maxArea(vector<int>& height) {
            int n=height.size();
            int left=0;
            int right=n-1;        
            int max_area=0;  
            while(left<right){
                int distance=right-left;
                int mini;
                mini=min(height[left],height[right]);
                int area=mini*distance;
                max_area=max(max_area,area);
                if(height[left]<height[right]){
                    left++;
                }
                else{
                    right--;
                }
                
            }
            return max_area;
        }
    };