class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        long long c1 = cost1, c2 = cost2, cb = costBoth;
        long long n1 = need1, n2 = need2;

        long long tobuymost = min(cb, c1 + c2);

        long long numberofmost = min(n1, n2);

        long long ans = 0;

        if(tobuymost == c1 + c2){
            ans += numberofmost * (c1 + c2);
        }
        else{
            ans += numberofmost * tobuymost;
        }

        long long rem1 = abs(n1 - numberofmost);
        long long rem2 = abs(n2 - numberofmost);

        if(rem1 > 0){
            long long tobuyone = min(cb, c1);
            ans += tobuyone * rem1;
        }
        else if(rem2 > 0){
            long long tobuytwo = min(cb, c2);
            ans += tobuytwo * rem2;
        }

        return ans;
    }
};