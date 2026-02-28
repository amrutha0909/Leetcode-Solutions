class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        unordered_map<char,char>mpp={{')','('},{']','['},{'}','{'}};
        for(char c:s){
            if(c=='('||c=='['||c=='{'){
                st.push(c);
            }
            else{
                if(!st.empty() && mpp[c]==st.top()){
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};