class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>suffixProduct(n);
        suffixProduct[n-1]=1;
        for(int i=n-2;i>=0;i--){
            suffixProduct[i]=suffixProduct[i+1]*nums[i+1];
        }
        int prefixProduct=1;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=prefixProduct*suffixProduct[i];
            prefixProduct*=nums[i];
        }
        return ans;
    }
};