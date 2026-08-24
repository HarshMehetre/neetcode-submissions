class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n =nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> results;

        for(int i =0; i<n-2; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l =i+1;
            int r =n-1;
            while(l<r){
            if(nums[i]+nums[l]+nums[r]==0) {
                results.push_back({nums[i],nums[l],nums[r]});
                l++;
                r--;
                while (l < r && nums[l] == nums[l - 1]) l++;
                while (l < r && nums[r] == nums[r + 1]) r--;
            }
            if(nums[i]+nums[l]+nums[r]>0) r--;
            if(nums[i]+nums[l]+nums[r]<0) l++;
            }
        }
        return results;
    }
};
