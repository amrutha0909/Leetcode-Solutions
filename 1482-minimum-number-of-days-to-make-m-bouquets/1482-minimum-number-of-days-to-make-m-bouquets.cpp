class Solution {
public:
    bool isPossible(vector<int>& nums, int m, int k, int days){
        int bouquet=0;
        int flower=0;
        int i=0;
        while(i<nums.size()){
            if(nums[i]<=days){
                flower++;
                if(flower==k){
                    bouquet++;
                    flower=0;
                }
            }
            else{
                flower=0;
            }
            i++;
        }
        return bouquet>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        if(bloomDay.size()<(long long)m*k)return -1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(bloomDay,m,k,mid)){
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