#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        stack<char> stk;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] < '0' || s[i] > '9') {  
                stk.push(s[i]);
            } else {
                if (!stk.empty()) {
                    stk.pop();
                }
            }
        }

        string ans = "";
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }

        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
