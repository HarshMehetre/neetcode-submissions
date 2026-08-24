class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxA=0;
        int n=heights.size();
        int l=0;
        int r=n-1;

        while(l<r){
            int currA = min(heights[l],heights[r])*(r-l);
            maxA = max(maxA,currA);

            if(heights[l]<=heights[r])l++;
            else r--;
        }

        return maxA;
    }
};
