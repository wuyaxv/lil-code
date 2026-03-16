/* 349 两个数组的交集
 * 难度：简单
 */

#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
        vector<int> inter;

        for(auto e1 = s1.begin(); e1 != s1.end(); ++e1) {
            if(auto search = s2.find(*e1); search != s2.end()) {
                inter.push_back(*search);
            }
        }

        return inter;
    }
};

int main(void)
{
    auto s = Solution();
    vector<int> nums1{4,9,5};
    vector<int> nums2{9,4,9,8,4};

    vector<int> inter = s.intersection(nums1, nums2);
    
    for(auto s = inter.begin(); s != inter.end(); ++s) {
        std::cout << *s << " ";
    }
    std::cout << endl;
}


