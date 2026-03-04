class Solution {
public:
    void backtrack(unordered_map<int,string>&mpp,vector<string>&result,string&digits, int index, string &temp){
        if(index==digits.size()){
            result.push_back(temp);
            return;
        }
        string letters=mpp[digits[index]-'0'];
        for(char ch:letters){
            temp.push_back(ch);
            backtrack(mpp,result,digits,index+1,temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        unordered_map<int,string>mpp={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
        vector<string>result;
        string temp;
        backtrack(mpp,result,digits,0,temp);
        return result;
    }
};