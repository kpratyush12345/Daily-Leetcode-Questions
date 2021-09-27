class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        auto cmp=[](auto a,auto b){
            return a[0]>b[0] or (a[0]==b[0] and a[1]<b[1]);
        };
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>>res;
        for(auto i:people ){
            res.insert(res.begin()+i[1],i);
        }
        return res;
    }
};