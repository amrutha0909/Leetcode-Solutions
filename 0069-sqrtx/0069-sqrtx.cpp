class Solution {
public:
    int binSearch(int x, int low, int high,int ans){
        if(low>high)return ans;
        int mid=low+(high-low)/2;
        if(mid<=x/mid){
            return binSearch(x,mid+1,high,mid);
        }
        else{
            return binSearch(x,low,mid-1,ans);
        }
    }
    int mySqrt(int x) {
        if(x<=1)return x;
        return binSearch(x,0,x,-1);
    }
};