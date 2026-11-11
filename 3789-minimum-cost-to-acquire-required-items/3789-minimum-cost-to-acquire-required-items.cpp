class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1;
        long long c2 = cost2;
        long long cb = costBoth;
        long long n1 = need1;
        long long n2 = need2;

        long long option1= (n1*c1) + (n2*c2);
        long long overlap = min(n1,n2);
        long long option2 = (overlap*cb) + ((n1-overlap) * c1) + ((n2-overlap)* c2);
        long long larger = max(n1,n2);
        long long option3 = (larger*cb);

        return min({option1,option2,option3});
    }
};