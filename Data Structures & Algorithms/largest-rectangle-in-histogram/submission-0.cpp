class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        int maxArea = 0;
        // Stack stores pairs of {start_index, height}
        std::stack<std::pair<int, int>> st;

        for (int i = 0; i < heights.size(); i++) {
            int start = i;
            
            // Pop elements from stack while current height is smaller
            while (!st.empty() && st.top().second > heights[i]) {
                auto [index, height] = st.top();
                st.pop();
                
                // Calculate area with popped bar as the shortest height
                maxArea = std::max(maxArea, height * (i - index));
                
                // The current bar can extend back to where the popped bar started
                start = index;
            }
            
            st.push({start, heights[i]});
        }

        // Calculate area for remaining bars that extend to the end of the array
        int n = heights.size();
        while (!st.empty()) {
            auto [index, height] = st.top();
            st.pop();
            maxArea = std::max(maxArea, height * (n - index));
        }

        return maxArea;
    }
};
