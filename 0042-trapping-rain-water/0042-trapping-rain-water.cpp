class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>prefixMax(n);
        vector<int>suffixMax(n);
        prefixMax[0]=height[0];
        suffixMax[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            prefixMax[i]=max(height[i],prefixMax[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            suffixMax[i]=max(height[i],suffixMax[i+1]);
        }
        int total=0;
        for(int i=0;i<n;i++){
            int left=prefixMax[i];
            int right=suffixMax[i];
            total+=min(left,right)-height[i];
        }
        return total;
    }
};