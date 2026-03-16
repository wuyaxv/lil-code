/* 376. 摆动序列
 * 难度：中等
 */

#include <cstdint>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2) return static_cast<int>(nums.size());

        int i = 1;
        int prev_diff = nums[1] - nums[0];
        int curr_diff = 0;

        while(i < static_cast<int>(nums.size())) {
        }
    }
};

int main(void)
{
    auto solu = Solution();
    //vector<int> nums{1,17,5,10,13,15,10,5,16,8};
    vector<int> nums{0, 0, 0};
    std::cout << solu.wiggleMaxLength(nums) << std::endl; 
}
