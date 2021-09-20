class Solution {
public:
    int parent[10000];
    int find(int a,int parent[]){
        
        if(parent[a]==-1) return a;
        return find(parent[a],parent);
    }
    int union_ds(int a,int b,int *parent){
        int para=find(a,parent);
        int parb=find(b,parent);
        if(para==parb) return true;
        
        parent[para]=parb;
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        
        // int parent[n+1];
        memset(parent,-1,sizeof(parent));
        
        for(auto i:edges){   
            if(union_ds(i[0],i[1],parent))
                return i; 
        }
        return edges[0];
    }
};