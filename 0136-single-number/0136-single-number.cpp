class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> m;
        for (int num : nums) {
            m[num]++;
        }
        for (auto& pair : m) {
            if (pair.second == 1) {
                return pair.first;
            }
        }
        return -1;
    }
};

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int result = 0;
//         for (int num : nums) {
//             result ^= num; // XOR cancels out duplicates
//         }
//         return result;
//     }
// };
// }