class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        stack<int> st;
        int n = temps.size();
        vector<int> results(n,0);

        for(int i=0; i<n; i++){
            while(!st.empty() && temps[st.top()]<temps[i]){
                int prev = st.top();
                st.pop();
                results[prev]=i-prev;
            }
            st.push(i);
        }
        return results;
    }
};
