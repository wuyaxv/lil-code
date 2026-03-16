#include <vector>

using namespace std;

class Solution {
public:
    int fib(int n) {
        vector<int> dp;

        dp.push_back(1);
        dp.push_back(1);

        int i = 2;

        while(i <= n) {
            dp.push_back(dp[i-1] + dp[i-2]);
            ++i;
        }

        return dp.back();
    }
};
