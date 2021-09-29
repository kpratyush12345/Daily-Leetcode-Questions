class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<pair<int, int>>v;
        unordered_map <int, int>m;
        for(auto i: arr) m[i]++;
        for(auto i:m) v.push_back ({i.second,i.first});
        sort(v.rbegin(), v.rend());
        int n = arr.size(), target = n/2, c = 0, sum = 0;
        for(auto i: v){
            if(sum >= target) return c;
            sum += i.first;
            c++;
        }
        return c;  
    }
};