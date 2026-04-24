class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int origin=0;
        int ans=INT_MIN;
        for(char c:moves){
            if(c=='L')origin--;
            else if(c=='R')origin++;
            else{
                origin++;
            }
        }
        ans=max(ans,abs(origin));
        origin=0;
        for(char c:moves){
            if(c=='L')origin--;
            else if(c=='R')origin++;
            else{
                origin--;
            }
        }
        ans=max(ans,abs(origin));
        return ans;
    }
};