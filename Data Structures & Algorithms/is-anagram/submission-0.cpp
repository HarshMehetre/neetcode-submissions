class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map <char,int> freq;

        for(char s1:s){
            freq[s1]++;
        }
        for(char t1:t){
            freq[t1]--;

            if(freq[t1]<0){
                return false;
            }
        }
        return true;
    }
};
