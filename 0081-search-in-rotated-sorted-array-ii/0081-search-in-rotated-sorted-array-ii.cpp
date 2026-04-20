class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left=0;
        int n=nums.size();
        int right=n-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target)return true;
            if(nums[mid]==nums[left]&&nums[mid]==nums[right]){
                left++;
                right--;
                continue;
            }
            if(nums[mid]<=nums[right]){
                if(nums[mid]<=target && target<=nums[right]){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
            else{
                if(nums[left]<=target && target<=nums[mid]){
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
        }
        return false;
    }
};