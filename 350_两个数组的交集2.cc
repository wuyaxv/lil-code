/* 350. 两个数组的交集2
 * 难度：简单
 *
 * 解法一：
 * 使用一个hash表存储遍历第一个元素的过程中的计数情况，然后遍历第二个数组，每次遍历，如果hash表中存在对应的键，则对应的计数减去一，并押入当前值作为结果数组。如果第一个中减到0，说明第二个的数据比第一个多，跳过；或者说根本没有交集，也跳过；最后得到的结果就是结果
 */

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return intersect(nums2, nums1);
        unordered_map<int, int> map;
        vector<int> result;

        for(const auto num: nums1) {
            if(map.find(num) != map.end()) {
                map[num] += 1;
            } else {
                map.insert({num, 1});
            }
        }   

        for(const auto num: nums2) {
            if(auto search = map.find(num); search != map.end()) {
                if(search->second) {
                    search->second-=1;
                    result.push_back(search->first);
                }
            }
        }

        return result;
    }
};

int main(void)
{
    vector<int> num1{4,9,5,4,4};
    vector<int> num2{9,4,9,8,4,6};
    auto s = Solution();
    auto result = s.intersect(num1, num2);
    for(auto i : result) {
        std::cout << i << std::endl;
    }

}
