class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>suffixProduct(n);
        suffixProduct[n-1]=1;
        for(int i=n-2;i>=0;i--){
            suffixProduct[i]=nums[i+1]*suffixProduct[i+1];
        }
        int currProduct=1;
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(currProduct*suffixProduct[i]);
            currProduct*=nums[i];
        }
        return ans;
    }
};