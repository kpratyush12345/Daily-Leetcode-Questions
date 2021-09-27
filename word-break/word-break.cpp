class Solution {
public:
    unordered_map<string,int>dp;
    int solve(string a,vector<string>&d ){
        int n=a.length();
        if(n==0) return 1;
        if(dp[a]!=0) return dp[a];
   
        for(int i=1;i<=n;i++){
            int f=0;
            string y=a.substr(0,i);
            for(int j=0;j<d.size();j++){
                if(y.compare(d[j])==0) {
                    f=1;break;
            }
        }   
        if(f==1 and solve(a.substr(i,n-i),d)==1) return dp[a]=1;
        }
        
        return dp[a]=-1;
    }
    
    bool wordBreak(string A, vector<string>& B) {
        int x=solve(A,B);
        if(x==1) return true;
        return false;
    }
};