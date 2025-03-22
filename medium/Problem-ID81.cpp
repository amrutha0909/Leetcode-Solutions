class Solution {
    public:
        bool search(vector<int>& nums, int target) {
            int n=nums.size();
            int left=0;
            int right=n-1;
            sort(nums.begin(),nums.end());
            while(left<=right){
                int mid=left+(right-left)/2;
                if(nums[mid]==target){
                    return true;
                }
                else if(nums[mid]<target){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
            return false;
        }
    };