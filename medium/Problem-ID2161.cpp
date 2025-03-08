class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            int n=nums.size();
            vector<int>lessthan;
            vector<int>greaterthan;
            vector<int>equals;
            for(int i=0;i<n;i++){
                if(nums[i]<pivot){
                    lessthan.push_back(nums[i]);
                }
                else if(nums[i]>pivot){
                    greaterthan.push_back(nums[i]);
                }
                else{
                    equals.push_back(nums[i]);
                }
            }
            int n1=lessthan.size();
            int n2=greaterthan.size();
            int n3=equals.size();
            int j=0;
            //int k=0;
            for(int i=0;i<n1;i++){
                nums[j]=lessthan[i];
                j++;
            }
            for(int i=0;i<n3;i++){
                nums[j]=equals[i];
                j++;
            }
            for(int i=0;i<n2;i++){
                nums[j]=greaterthan[i];
                j++;
            }
            return nums;
        }
    };