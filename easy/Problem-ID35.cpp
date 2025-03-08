class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int count=0;
            int n=nums.size();
            for(int i=0;i<n;i++){
                if(nums[i]>=target){
                    return i;
                }
            }
            return n;
        }
    };