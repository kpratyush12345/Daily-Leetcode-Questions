class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b){
        return(a[1] < b[1]);
    }
	
    int check(vector<vector<int>>& r, int i){
        int lo = 0, hi = i- 1;
        while (lo <= hi){
            int mid = (lo + hi) / 2;
            if (r[mid][1] <= r[i][0]){
                if (r[mid + 1][1] <= r[i][0]) lo = mid + 1;
                else return mid;
            }
            else hi = mid - 1;
        }
        return -1;
    }
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& r) {
        sort(r.begin(),r.end(),comp);
        vector<long long> res(r.size());
        res[0] = r[0][1] - r[0][0] + r[0][2];
        for(int i = 1;i<r.size();i++){
            long long in = r[i][1] - r[i][0] + r[i][2];
            int l = check(r, i);
            if(l != -1) in += res[l];
            res[i] = max(in, res[i-1]);
        }
        return(res[r.size() - 1]);
    }
};