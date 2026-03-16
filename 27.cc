/* 27. 移除元素
 *
 */
#include <vector>
#include <iostream>


using namespace std;

void print_container(const std::vector<int>& c)
{
    for (int i : c)
        std::cout << i << ' ';
    std::cout << '\n';
}

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
/* 解法一：对撞指针解法 
 *      int temp;
 *      int match_num = 0;
 *      int i1 = 0, i2 = nums.size()-1;

 *      while(i1 <= i2) {
 *          if(nums[i1] == val) {
 *              match_num++;
 *              temp = nums[i1];
 *              nums[i1] = nums[i2];
 *              nums[i2] = temp;
 *              i2--;

 *              for(int i = i1; i < i2; ++i) {
 *                  temp = nums[i];
 *                  nums[i] = nums[i+1];
 *                  nums[i+1] =temp;
 *              } // 此时末尾的就是之前的最后一个
 *          }
 *          else i1++;
 *      }
 *      for(int i = 0; i < match_num; ++i) nums.pop_back();

 *      return nums.size();
 */
        /* 解法二：双指针
         */
        int slow_index = 0;

        for(int fast_index = 0; fast_index < nums.size(); ++fast_index) {
            if(val != nums[fast_index]) {
                nums[slow_index++] = nums[fast_index];
            }
        }
        for(int i = 0; i < nums.size() - slow_index; ++i) {
            nums.pop_back();
        }
        return nums.size() - slow_index;
    }
};


int main(void)
{
    vector<int> nums{0,1,2,2,3,0,1,4,2};
    const int val = 2;

    auto s = Solution();
    auto result = s.removeElement(nums, val);
    print_container(nums);
}
