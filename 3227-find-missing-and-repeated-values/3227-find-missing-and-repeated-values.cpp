class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long n2 = n * n;
        
        long long S = (n2 * (n2 + 1)) / 2; 
        long long P = (n2 * (n2 + 1) * (2 * n2 + 1)) / 6;  
        
        long long S_actual = 0, P_actual = 0;
        
        for (const auto& row : grid) {
            for (int num : row) {
                S_actual += num;
                P_actual += (long long)num * num;
            }
        }
        
        long long diff1 = S_actual - S; 
        long long diff2 = P_actual - P; 
        
        long long sum_ab = diff2 / diff1; 
        
        int a = (diff1 + sum_ab) / 2;
        int b = sum_ab - a;
        
        return {a, b};
    }
};