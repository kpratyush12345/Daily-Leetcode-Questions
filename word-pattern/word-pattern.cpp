class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = s.length();
        int j = 0;
        vector<string> str;
        for(int i = 0;i<n;i++){
            if(s[i] == ' ' || i == n-1){
                if(i == n-1) str.push_back(s.substr(j,i+1-j));
                else str.push_back(s.substr(j,i-j));
                j = i+1;
            }
        }
        if(pattern.length() != str.size()) return false;
        
        unordered_map<char,string> mp;
        unordered_map<string,bool> used;
        for(int i = 0;i<pattern.length();i++){
            char ch = pattern[i];
            if(mp.find(ch) == mp.end()){
                if(used[str[i]] == true) return false;
                else {
                    used[str[i]] = true;
                    mp[ch] = str[i];
                }
            }
            else{
                string word = mp[ch];
                if(word != str[i]) return false;
            }
        }
        return true;
    }
};