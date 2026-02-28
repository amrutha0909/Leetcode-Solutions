class Solution {
public:
    void NSE(vector<int>histogram, vector<int>&nse){
        stack<int>st;
        int n=histogram.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && histogram[st.top()]>=histogram[i]){
                st.pop();
            }
            if(st.empty())nse[i]=n;
            else nse[i]=st.top();
            st.push(i);
        }
        
    }
    void PSE(vector<int>histogram, vector<int>&pse){
        stack<int>st;
        int n=histogram.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && histogram[st.top()]>=histogram[i]){
                st.pop();
            }
            if(st.empty())pse[i]=-1;
            else pse[i]=st.top();
            st.push(i);
        }
    }
    int lHist(vector<int>histogram){
        int n=histogram.size();
        int maxi=0;
        vector<int>nse(n);
        vector<int>pse(n);
        NSE(histogram,nse);
        PSE(histogram,pse);
        for(int i=0;i<n;i++){
            maxi=max(maxi,histogram[i]*(nse[i]-pse[i]-1));
        }
        return maxi;
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
        int maxArea=0;
        for(int i=0;i<n;i++){
            maxArea=max(maxArea,lHist(prefixSum[i]));
        }
        return maxArea;
    }
};