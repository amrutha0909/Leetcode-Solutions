class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            unordered_map<int,int>mpp;
            int n=nums.size();
            int max=-1;
            int max_freq=0;
            for (int num : nums) {
                mpp[num]++;
                if (mpp[num] > max_freq) {  // Update max frequency and element
                    max_freq = mpp[num];
                    max = num;
                }
            }
            int f=max_freq;
            int f1=0;
            for(int i=0;i<n-1;i++){
                if(nums[i]==max){
                    f1++;
                }
                int f2=f-f1;
                int left=i+1;
                int right=n-i-1;
                if(f1>left/2&&f2>right/2){
                    return i;
                }
            }
            return -1;
        }
    };