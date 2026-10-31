class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res =0;
        int buy = prices[0];

        for(int sell:prices){
            res = max(res,sell-buy);
            buy = min(buy,sell);
        }
        return res;
    }
};
