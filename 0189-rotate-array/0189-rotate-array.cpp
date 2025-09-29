class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {  // Changed function name to 'rotate'
        int n = nums.size();
        k = k % n; // Handle cases where k > n

        reverse(nums, 0, n - 1);  // Step 1: Reverse entire array
        reverse(nums, 0, k - 1);  // Step 2: Reverse first k elements
        reverse(nums, k, n - 1);  // Step 3: Reverse remaining n-k elements
    }
};
