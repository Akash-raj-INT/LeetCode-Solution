class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res; 
        int n=part.size();
        char last = part.back();  //c
  
        for(char i:s){    
            res.push_back(i);

            if(i==last && res.size()>=n){
                if( res.substr(res.size()-n) == part){
                res.erase(res.size()-n);
                }
            }
        }
        return res;
    }
};