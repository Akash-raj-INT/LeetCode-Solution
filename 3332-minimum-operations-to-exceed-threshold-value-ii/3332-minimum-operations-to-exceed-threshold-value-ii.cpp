class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
    priority_queue <long, vector<long>, greater<long>> q;
        int count = 0;
        for(int i =0; i<nums.size(); i++){
            q.push(nums[i]);
        }
        while(q.top() < k){
            long x = q.top();
            q.pop();
            long y = q.top();
            q.pop();
            count++;
            long long z = min(x,y)*2 + max(x,y);
            q.push(z);   
        }
         return count++;
    }
    

};