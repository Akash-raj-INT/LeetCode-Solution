class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;

        for (int i = 0; i < nums1.size(); i++) {
            int nextGreater = -1; // default if no greater element found

            // find the index of nums1[i] in nums2
            int j = 0;
            while (j < nums2.size() && nums2[j] != nums1[i])
                j++;

            // check elements after index j in nums2
            for (int k = j + 1; k < nums2.size(); k++) {
                if (nums2[k] > nums1[i]) {
                    nextGreater = nums2[k];
                    break;
                }
            }

            res.push_back(nextGreater);
        }

        return res;
    }
};
