/* 494. 目标和
 * 难度：中等
 */

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

int findTargetSumWays(vector<int>& nums, int target) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if ((sum + target) % 2) return 0;       // 无解

    int v = static_cast<int>((sum+target)/2);       // total volume of the pack
                                                    //
    std::cout << "v: " << v << endl;

    vector<int> dp(v+1, 0); // dp array for storing total value.
    vector<int> count(v+1, 0); // tracking combination of current acculumated value. initialized with 1.
    count[0] = 1;

    int i = 0; // 遍历背包的大小

    for(auto num: nums) std::cout << num << " ";
    std::cout << endl;

    // 遍历
    for(auto j = 1; j <= nums.size(); ++j) {
        i = v;
        while(i-nums[j-1] >= 0) {
            if(dp[i] > dp[i-nums[j-1]]+nums[j-1]) continue; // Remain the same
            else if(dp[i] < dp[i-nums[j-1]]+nums[j-1]) dp[i] = dp[i-nums[j-1]] + nums[j-1]; // put in new value but the combination remains the same.
            else {  // putting new number equal not putting new number
                // The value remains the same, but combination changes.
                count[i] = count[i-nums[j-1]] + count[i];
            }
            i--;
        }

        for(int a = 0; a < dp.size(); ++a) std::cout << dp[a] << " ";
        std::cout << "|| ";
        for(int a = 0; a < count.size(); ++a) std::cout << count[a] << " ";
        std::cout << endl;
    }

    if(dp.back() == v) return count.back();
    else return 0;
}

int main(void)
{

    vector<int> input{9,7,0,3,9,8,6,5,7,6};
    int target = 2;

    int ans = findTargetSumWays(input, target);
    std::cout << ans << endl;

    return 0;
}
