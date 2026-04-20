class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxDist=INT_MIN;
        for(int i=0;i<colors.size();i++){
            for(int j=0;j<colors.size();j++){
                if(colors[i]!=colors[j]){
                    maxDist=max(maxDist,abs(i-j));
                }
            }
        }
        return maxDist==INT_MIN?-1:maxDist;
    }
};