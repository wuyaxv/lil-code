#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);     // 初始化为1      
        for(auto i = 0; i < nums.size(); ++i) {
            for(auto j = i-1; j >= 0; --j) {
                if(nums[j] < nums[i]) dp[i] = max(dp[i], dp[j]+1);
            }
        }
        auto max_it = max_element(dp.begin(), dp.end());

        return *max_it;
    }
};

int main(void)
{
    vector<int> input{10,9,2,5,3,7,101,18};
    auto s = Solution();

    auto result = s.lengthOfLIS(input);
    std::cout << result;
}
