class Solution {
public:
    vector<vector<int>> ans;
    void generate(int index, vector<int> &nums, vector<int> &cs){
        if(index == nums.size()){
            ans.push_back(cs);
            return;
        }
        cs.push_back(nums[index]);
        generate(index+1, nums, cs);
        cs.pop_back();
        generate(index+1, nums, cs);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cs;
        generate(0, nums,cs);
        return ans;
    }
};