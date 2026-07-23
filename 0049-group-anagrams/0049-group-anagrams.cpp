class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;   // final answer (groups of anagrams)
        unordered_map<string, vector<string>> map; // key = sorted string, value = group of anagrams

        for(auto x: strs){
            string temp = x;              // original string ko temp me store
            sort(x.begin(), x.end());     // string ko sort kar diya (key banane ke liye)
            map[x].push_back(temp);       // sorted string ke key ke under original string daal diya
        }

        for(auto x : map){
            ans.push_back(x.second);      // har key ke group ko ans me daal diya
        }
        return ans;                       // final groups return
    }
};
