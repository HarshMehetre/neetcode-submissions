class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *std::max_element(piles.begin(), piles.end());
        int ans =r;

        while(l<=r){
            int mid = l+(r-l)/2;
            long long hoursNeeded = 0;

            for(int p: piles){
                hoursNeeded += (p + mid-1LL)/mid;
            }

            if(hoursNeeded<=h){
                ans=mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
       return ans; 
    }
};
