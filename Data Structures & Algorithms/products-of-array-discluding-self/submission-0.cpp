class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=1;
        int count=0;
        int n = nums.size();
        for(int num:nums){
            if(num!=0){
                product*=num;
            }else{
                count++;
            }
            if(count == 2){
                vector<int> zeroes(n,0);
                return zeroes;
            }
        }
        if(count==1){
            vector<int> result (n,0);
            for(int i =0; i<n; i++){
                if(nums[i]==0){
                    result[i]=product;
                }
            }
            return result;
        }

        vector<int> result;
        for(int i =0; i<n; i++){
            result.push_back(product/nums[i]);
        }
        return result;
    }
};
