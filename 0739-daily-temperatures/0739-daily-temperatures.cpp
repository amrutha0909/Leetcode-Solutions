class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>stk;
        int n=temperatures.size();
        vector<int>nge(n);
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && temperatures[stk.top()]<=temperatures[i]){
                stk.pop();
            }
            if(stk.empty())nge[i]=-1;
            else nge[i]=stk.top();
            stk.push(i);
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(nge[i]==-1){
                ans[i]=0;
            }
            else{
                ans[i]=nge[i]-i;
            }
        }
        return ans;
    }
};