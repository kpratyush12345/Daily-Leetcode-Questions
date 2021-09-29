class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(char i: tasks) mp[i]++;
        priority_queue<int> pq;
        for(auto i : mp) pq.push(i.second);
        
        int res = 0;
        while(!pq.empty()){
            int time = 0;
            vector<int> tmp;
            for(int i = 0;i <= n;i++){
                if(!pq.empty()){
                    tmp.push_back(pq.top() - 1);
                    pq.pop();
                    time++;
                }
            }
            for(auto i: tmp){
                if(i) pq.push(i);
            }
            res += pq.empty() ? time : n+1;
        }
        return res;
    }
};