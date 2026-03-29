class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int buy=prices[0];
        for(int i=1;i<prices.size();i++){
            int profit=prices[i]-buy;
            ans=max(ans,profit);
            buy=min(buy,prices[i]);
        }
        return ans;
    }
};