class Solution {
public:
    int arrangeCoins(int n) {
        long long coins=0;
        int count=0;
        long long i=1;
        while(coins<=n){ 
            coins+=i;
            if(coins>n)return count;
            i++;
            count++;
        }
        return count;
    }
};