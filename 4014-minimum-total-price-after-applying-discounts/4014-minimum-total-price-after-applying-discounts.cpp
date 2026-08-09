class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(),prices.rend());
        sort(discounts.rbegin(),discounts.rend());
        int i = 0;
        int j = 0;
        double ans = 0;
        while(i < prices.size() && j < discounts.size()){
            int p = prices[i];
            int d = discounts[j];
            double fp = (double) (p * (100-d)) / 100;
            ans += fp;
            i++;
            j++;
        }
        while(i < prices.size()){
            ans += prices[i];
            i++;
        }
        return ans;
    }
};