class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0, j=0;
        map<char,int> m;
        int ans=0;
        
        while(j<s.size()){
            m[s[j]]++;
        while(m[s[j]]>1){
            m[s[i]]--;
            i++;
        }
        ans = max(ans , j-i+1);        
        j++;
        }
        return ans;
    }
};