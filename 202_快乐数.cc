/* 202. 快乐数
 * 难度：简单
 * 解法一：判断和是否之前存在过（用hash表存储）
 */

#include <unordered_set>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        int sum = 0;
        while(true) {
            sum = 0;
            while(n) {
                sum += static_cast<int>(pow(n%10, 2));
                n /= 10;
            }
            n = sum;
            std::cout << sum << endl;
            if(sum == 1) return true;
            if(s.find(sum) != s.end()) break;
            else s.insert(sum);
        }

        return false;
    }
};

int main(void)
{
    auto  s = Solution();
    std::cout << s.isHappy(19) << endl;;
}
