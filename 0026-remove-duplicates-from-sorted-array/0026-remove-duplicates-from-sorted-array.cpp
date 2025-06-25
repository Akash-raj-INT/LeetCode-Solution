class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // int n = nums.size(); 
        // if(nums.empty()) return 0;
        // int j=0;
        // for(int i=0; i<n; i++){
         
        //         if(nums[i]!=nums[j])
        //           j++;
        //            nums[j]=nums[i];
            
           
        // }
        // return j+1;
    set<int> s(nums.begin(), nums.end());
    nums.assign(s.begin(), s.end());
    return nums.size();

    }
};