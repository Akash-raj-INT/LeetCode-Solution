class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int usedBits = 0, maxLength = 0, i = 0;

        for (int j = 0; j < nums.size(); j++) {
            while ((usedBits & nums[j]) != 0) {
                usedBits ^= nums[i]; 
                i++; 
            }
            usedBits |= nums[j]; 
            maxLength = max(maxLength, j - i + 1);
        }

        return maxLength;
    }
};
