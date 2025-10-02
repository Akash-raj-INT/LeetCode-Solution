class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;

        for (int num : nums1) {
            int next = -1; // default if no greater element found
            bool found = false;

            // find the position of num in nums2
            for (int i = 0; i < nums2.size(); i++) {
                if (nums2[i] == num) {
                    // look to the right for next greater
                    for (int j = i + 1; j < nums2.size(); j++) {
                        if (nums2[j] > num) {
                            next = nums2[j];
                            break;
                        }
                    }
                    break;
                }
            }
            result.push_back(next);
        }

        return result;
    }
};