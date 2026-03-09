class Solution {
public:
    void backtrack(string&digits,int index,unordered_map<int,string>&mpp,string&current,vector<string>&result){
        if(index==digits.size()){
            result.push_back(current);
            return;
        }
        string p=mpp[digits[index]-'0'];
        for(char c:p){
            current.push_back(c);
            backtrack(digits,index+1,mpp,current,result);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return {};
        unordered_map<int,string>mpp={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
        vector<string>result;
        string current;
        backtrack(digits,0,mpp,current,result);
        return result;
    }
};