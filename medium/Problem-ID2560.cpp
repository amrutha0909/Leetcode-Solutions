class Solution {
    public:
        int minCapability(vector<int>& nums, int k) {
            int n=nums.size();
            int low=*min_element(nums.begin(),nums.end());
            int high=*max_element(nums.begin(),nums.end());
            int ans=0;
            while(low<=high){
                int mid=low+(high-low)/2;
                int count=0;
                int prev_taken = -2;
                for(int i=0;i<n;i++){
                    if(nums[i]<=mid&&i>prev_taken+1){
                        count++;
                        prev_taken=i;
                    }
                }
                if(count>=k){
                    ans=mid;
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            return ans;
        }
    };