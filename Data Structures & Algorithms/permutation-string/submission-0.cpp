class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        if(n1>n2) return false;

        vector<int> s1_freq(26,0);
        vector<int> s2_freq(26,0);

        for(int i =0; i<n1; i++){
            s1_freq[s1[i] - 'a']++;
            s2_freq[s2[i] - 'a']++;
        }

        if(s1_freq == s2_freq) return true;

        for(int i =1; i+n1-1<n2; i++){
            s2_freq[s2[i-1]-'a']--;
            s2_freq[s2[i+n1-1]-'a']++;
            if(s1_freq == s2_freq) return true;
        }
        return false;
    }
};
