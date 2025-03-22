class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            vector<int>sol;
            int n=nums.size();
            int index;
            for(int i=0;i<n;i++){
                if(nums[i]==target){
                    sol.push_back(i);
                    index=i;
                    break;
                }
            }
            for(int j=n-1;j>=index;j--){
                if(nums[j]==target){
                    sol.push_back(j);
                    break;
                }
            }
            if(sol.size()==0){
                sol.push_back(-1);
                sol.push_back(-1);
            }
            return sol;
        }
    };
    