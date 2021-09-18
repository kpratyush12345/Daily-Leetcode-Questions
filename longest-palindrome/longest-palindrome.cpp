class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> counts;
        for(auto c: s) counts[c]++;
        int res = 0;
        bool odd = false;
        for(auto c: counts){
            if(c.second%2 == 0) res += c.second;
            else {
                odd = true;
                res += c.second - 1;
            }
        }
        if(odd) res++;
        return res;
    }
};