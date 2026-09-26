class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeros= 0;
        int prod =1;
        for(int num:nums){
            if(num==0){
                zeros++;
                if(zeros ==2){
                    vector<int> res(nums.size(),0);
                    return res;
                }
            }else{
                prod *= num;
            }
        }
        if(zeros==1){
            vector<int> res;
            for(int num:nums){
                res.push_back(num==0? prod:0);
            }
            return res;
        }
        vector<int> res;
        for(int num: nums){
            res.push_back(prod/num);
        }
        return res;
    }
};
