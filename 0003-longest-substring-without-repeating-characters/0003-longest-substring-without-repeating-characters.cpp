class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1); // Tracks last index of each character
        int maxlen = 0, start = -1;

        for (int i = 0; i < s.size(); i++) {
            if (dict[s[i]] > start) {
                start = dict[s[i]]; // Move start forward if s[i] was seen after current start
            }

            dict[s[i]] = i; // Update last seen index of s[i]
            maxlen = max(maxlen, i - start); // Update max length
        }

        return maxlen;
    }
};
