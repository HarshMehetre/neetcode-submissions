class Solution {
public:
    bool isValid(string s) {
        //if(s.length()/2!=0) return false;
        unordered_map <char,char> mp{
            {')','('},
            {'}','{'},
            {']','['}
        };

        stack<char> open;

        for(char c:s){
            if(mp.count(c)){
                if(open.empty()) return false;

                if(open.top()==mp[c]){
                    open.pop();
                }else return false;

            }else open.push(c);
        }

        return open.empty();
    }
};
