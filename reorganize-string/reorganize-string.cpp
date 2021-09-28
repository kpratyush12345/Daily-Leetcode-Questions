class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char,int>m;
        int n=S.size();
        string s;
        int k=0,l=n-1;
        for(auto i:S)
            m[i]++;
        priority_queue<pair<int,char>>pq;
        for(auto i:m){
            if(i.second>ceil((double)n/2)) return "";
            pq.push({i.second,i.first});
        }
        while(!pq.empty()){
            auto top1=pq.top();pq.pop();
            s+=top1.second;
            if(!pq.empty()){
                auto top2=pq.top();
                pq.pop();
                s+=top2.second;
                if(top2.first>1)pq.push({top2.first-1,top2.second});   
            }
            if(top1.first>1)  pq.push({top1.first-1,top1.second});
        }    
        return s;    
    }
};