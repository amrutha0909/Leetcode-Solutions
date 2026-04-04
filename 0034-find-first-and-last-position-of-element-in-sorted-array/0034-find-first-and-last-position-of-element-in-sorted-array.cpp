class Solution {
public:
    int findLBorFirstOccurence(vector<int>&nums,int target){
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    int findUBorLastOccurence(vector<int>&nums,int target){
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans=mid;
                low=mid+1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int x=findLBorFirstOccurence(nums,target);
        int y=findUBorLastOccurence(nums,target);
        return {x,y};
    }
};