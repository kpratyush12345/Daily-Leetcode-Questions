class Solution {
public:
    vector<int>par;
    int find(int x){
        if(par[x]==-1) return x;
        return par[x]=find(par[x]); // path compression
    }
    bool uni(int a,int b){
        int u=find(a);
        int v=find(b);
        if(u==v) return 0;
        par[u]=v;
        return 1;
    }
    
    bool equationsPossible(vector<string>& eq) {
        int n=eq.size();
        par=vector<int>(26,-1);
        for(int i=0;i<n;i++){
           string s=eq[i];
            int a=s[0] - 'a',b=s[3] - 'a';char sign=s[1];
            if(sign == '=') uni(a,b);
        }
        for(int i=0;i<n;i++){
           string s=eq[i];
            int a=s[0] - 'a',b=s[3] - 'a';char sign=s[1];
            if(sign == '!'){
                // if(par[a] == par[b]) return 0;
                int p1 = find(a);
                int p2 = find(b);
                if(p1 == p2) return 0;
            }
        }
        return 1;
    }
};