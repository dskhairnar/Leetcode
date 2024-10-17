class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char , int> m;
       for(char ch : s){
        m[ch]++;
       }
       for(char ch:t){
        if(m.find(ch)== m.end()){
            return false;
        }
        m[ch]--;
       }

       for(auto itr : m){
        if(itr.second != 0){
            return false;
        }
       }
       return true;
    }
};