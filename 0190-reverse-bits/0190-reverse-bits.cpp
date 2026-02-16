class Solution {
public:
    int reverseBits(uint32_t n) {
        string bit = "";
        
        // Step 1: Build full 32-bit binary string
        for(int i = 0; i < 32; i++) {
            bit += (n % 2) + '0';
            n /= 2;
        }
        
        // Step 2: Reverse it
        //reverse(bit.begin(), bit.end());
        
        // Step 3: Convert binary string back to number
        int ans = 0;
        
        for(int i = 0; i < 32; i++) {
            ans = ans * 2 + (bit[i] - '0');
        }
        
        return ans;
    }
};
