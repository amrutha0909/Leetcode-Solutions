class Solution {
public:
    static bool compare(const vector<int>&a,const vector<int>&b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),compare);
        int total=0;
        for(auto&it:boxTypes){
            int boxes=it[0];
            int units=it[1];
            int take=min(truckSize,boxes);
            total+=take*units;
            truckSize-=take;
        }
        return total;
    }
};