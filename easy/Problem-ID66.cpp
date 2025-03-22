class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            int n=digits.size();
            long long int rem=0;
            for(int i=0;i<n;i++){
                rem=rem*10+digits[i];
            }
            rem+=1;
            vector<int>s;
            while(rem>0){
                s.push_back(rem%10);
                rem/=10;
            }
            int i=0;
            int j=s.size()-1;
            while(i<j){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            return s;
        }        
    };