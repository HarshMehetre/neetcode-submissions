class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector <int> result;

        unordered_map <int,int> mp;

        for(int num : nums){
            mp[num]++;
        }

        vector<vector<int>> buckets (nums.size()+1);

        for(auto& [num,count]:mp){
            buckets[count].push_back(num);
        }

        for (int i = nums.size(); i >= 0 && result.size() < k; --i) {
            for(int num:buckets[i]){
                result.push_back(num);
                if(result.size()==k)break;
            }
        }
        return result;
    }
};
