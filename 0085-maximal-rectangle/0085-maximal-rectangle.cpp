class Solution {
public:
    void PSE(vector<int>&hist,vector<int>&pse){
        stack<int>stk;
        stk.push(0);
        pse[0]=-1;
        for(int i=1;i<hist.size();i++){
            while(!stk.empty()&&hist[stk.top()]>=hist[i])stk.pop();
            if(stk.empty())pse[i]=-1;
            else pse[i]=stk.top();
            stk.push(i);
        }
    }
    void NSE(vector<int>&hist,vector<int>&nse){
        stack<int>stk;
        int n=nse.size();
        stk.push(n-1);
        nse[n-1]=n;
        for(int i=n-2;i>=0;i--){
            while(!stk.empty()&&hist[stk.top()]>=hist[i])stk.pop();
            if(stk.empty())nse[i]=n;
            else nse[i]=stk.top();
            stk.push(i);
        }
    }
    int lHist(vector<int>hist){
        int maxArea=0;
        int n=hist.size();
        vector<int>nse(n);
        vector<int>pse(n);
        NSE(hist,nse);
        PSE(hist,pse);
        for(int i=0;i<n;i++){
            maxArea=max(maxArea,hist[i]*(nse[i]-pse[i]-1));
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>prefixSum(n,vector<int>(m));
        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                int val=matrix[i][j]-'0';
                if(val==0)sum=0;
                else sum+=val;
                prefixSum[i][j]=sum;
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,lHist(prefixSum[i]));
        }
        return maxi;
    }
};