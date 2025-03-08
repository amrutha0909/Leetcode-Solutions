class Solution {
    public:
        vector<int> rearrangeArray(vector<int>& nums) {
           int n=nums.size();
           vector<int>a;
           vector<int>b;
           for(int i=0;i<n;i++){
            if(nums[i]>0){
                a.push_back(nums[i]);
            }
            else{
                b.push_back(nums[i]);
            }
           }
           int p=0,c=0;
           for(int i=0;i<n;i++){
            if(i%2==0){
                nums[i]=a[p];
                p++;
            }
            else{
                nums[i]=b[c];
                c++;
            }
        }
        return nums;
        }
    };