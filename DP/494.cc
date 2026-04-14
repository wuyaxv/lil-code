#include <vector>
#include <iostream>
#include <cmath>
#include <numeric>

using namespace std;

int findTargetSumWays(vector<int>& nums, int target) {

    target = abs(target);

    int sum = accumulate(nums.begin(), nums.end(), 0);

    if((sum+target)%2) return 0;
    if(sum < target) return 0;

    int v = static_cast<int>((sum+target)/2);

    vector<int> dp(v+1, 0);
    dp[0] = 1;

    int j = 0;

    for(auto num: nums) {
        j = v;
        while(j-num>=0) {
            dp[j] += dp[j-num];
            j--;
        }
    }

    return dp.back();
}

int main(void)
{
    vector<int> input{9,7,0,3,9,8,6,5,7,6};
    int target = 2;

    int ans = findTargetSumWays(input, target);

    std::cout << ans << endl;
}
