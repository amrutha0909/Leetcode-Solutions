class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        unordered_map<char,char>mpp={{')','('},{']','['},{'}','{'}};
        if(s.size()==1)return false;
        for(char c:s){
            if(c=='('||c=='['||c=='{'){
                st.push(c);
            }
            else{
                if(!st.empty() && mpp[c]==st.top()){
                    st.pop();
                }
                else return false;
            }
        }
        return st.empty();
    }
};