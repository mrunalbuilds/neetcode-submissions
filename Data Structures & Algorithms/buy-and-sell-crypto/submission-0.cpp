class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //we buy at minimum and sell at max
        int profit = 0, buy = prices[0];
        for(int i=1;i<prices.size();i++){
            if(buy > prices[i])
                buy = prices[i];
            else 
                profit = max(profit, prices[i]-buy);
        }

        return profit;
    }
};
