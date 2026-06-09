class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int profit = 0;
        int start = 0;

        for (int end = 0; end < prices.size(); end++) {
            if (prices[end] < prices[start]) {
                start = end;
            } else {
                profit = max(profit, prices[end] - prices[start]);
            }
        }
        return profit;
    }
};
