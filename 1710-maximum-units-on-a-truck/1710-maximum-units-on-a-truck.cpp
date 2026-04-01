class Solution {
public:
    static bool compare(const vector<int>&a,const vector<int>&b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),compare);
        int total=0;
        int count=0;
        for(auto it:boxTypes){
            int currSize=it[0];
            int currCount=0;
            while(count<truckSize){
                if(currCount<currSize){
                    total+=it[1];
                    currCount++;
                    count++;
                }
                else if(currCount==currSize){
                    break;
                }
            }
        }
        return total;
    }
};