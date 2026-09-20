class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int num:nums){
            freq[num]++;
        }

        vector<vector<int>> buckets(nums.size()+1);
        for(auto& [num,count]:freq){
            buckets[count].push_back(num);
        }

        vector<int> res;
        for(int i=nums.size(); i>=0 && k>res.size(); i--){
            for(int num:buckets[i]){
                res.push_back(num);
                if(res.size()==k) return res;
            }
        }
        return res;
    }
};
