class Solution {
public:
    vector<vector<int>> mergeinterval( vector<vector<int>> &alongx){
        int n=alongx.size();
        sort(alongx.begin(),alongx.end());
        vector<vector<int>> temp;
        int a=-1;
        int b=-1;
        for(int i=0;i<n;i++){
            if(a==-1 && b==-1){
                a=alongx[i][0];
                b=alongx[i][1];
                continue;
            }
            if(alongx[i][0]<b){
                //overlap
                a=min(a,alongx[i][0]);
                b=max(b,alongx[i][1]);
            }else{
                temp.push_back({a,b});
                a=alongx[i][0];
                b=alongx[i][1];
            }
        }
        if(a!=-1 && b!=-1){
            temp.push_back({a,b});
        }
        return temp;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
       vector<vector<int>> alongx;
       vector<vector<int>> alongy;
       int m = rectangles.size();
       for(int i=0;i<m;i++){
        alongx.push_back({rectangles[i][0],rectangles[i][2]});
        alongy.push_back({rectangles[i][1],rectangles[i][3]});
       }
       vector<vector<int>> a=mergeinterval(alongx);
       vector<vector<int>> b=mergeinterval(alongy);
       if(a.size()>=3 || b.size()>=3){
        return true;
       }
       return false;
    }
};