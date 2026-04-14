#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);

        for(auto i = 1; i < nums.size(); ++i) {
            if(nums[i-1] < nums[i]) dp[i] = max(dp[i], dp[i-1]+1);
        }
        auto max = max_element(dp.begin(), dp.end());
        return *max;
    }
};

int main(void)
{
    auto s = Solution();
    vector<int> inputs = {2,2,2,2,2,2};
    std::cout << s.findLengthOfLCIS(inputs);
}
