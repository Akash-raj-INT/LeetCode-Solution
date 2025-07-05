class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int>mp;
        for(int num :arr){
            mp[num]++;
        }
        int lucky = -1;

        for(auto& pair : mp){
            if(pair.first == pair.second){
                lucky =max(lucky, pair.first);
            }
           
        } return lucky;
    }
};