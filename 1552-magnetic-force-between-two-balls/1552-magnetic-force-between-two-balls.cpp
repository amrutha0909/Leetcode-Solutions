class Solution {
public:
    bool isPossible(int dist,int m, vector<int>&position){
        int lastPlaced=position[0];
        int count=1;
        for(int i=1;i<position.size();i++){
            if(position[i]-lastPlaced>=dist){
                count++;
                lastPlaced=position[i];
            }
        }
        return count>=m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low=1;
        int n=position.size();
        int high=position[n-1]-position[0];
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(mid,m,position)){
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