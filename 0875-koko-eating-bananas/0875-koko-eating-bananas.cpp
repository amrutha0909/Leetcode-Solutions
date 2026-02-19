class Solution {
public:
    bool isPossible(vector<int>& piles, int h, int speed){
        int hour=0;
        for(int i=0;i<piles.size();i++){
            hour+=ceil((double)piles[i]/speed);
        }
        return hour<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(piles,h,mid)){
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