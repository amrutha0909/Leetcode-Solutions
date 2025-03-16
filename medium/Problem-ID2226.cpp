class Solution {
    public:
        int maximumCandies(vector<int>& candies, long long k) {
            int n=candies.size();
            int max=candies[0];
            long long int sum=0;
            for(int i=0;i<n;i++){
                sum+=candies[i];
                if(candies[i]>max){
                    max=candies[i];
                }
            }
            if(sum<k)return 0;
            int ans=0;
            int low=1,high=max;
            while(low<=high){
                long long int count=0;
                int mid=low +(high-low)/2;
                for(int i=0;i<n;i++){
                    count+=candies[i]/mid;
                }
                if(count>=k){
                    ans=mid;
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            return ans;
    
        }
    };