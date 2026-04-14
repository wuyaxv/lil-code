/* 17. 电话号码的字母组合
 * 难度：中等
 */

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    int n; // 共按下了n个数字
    vector<char> path;
    vector<string> ans;
    vector<int> input{-1};
    vector<string> keyboard{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void backtracing(const int i) { // i = 当前的按的第i个键，其值为input[i]
        if(i > n) {
            ans.push_back(string(path.begin(), path.end()));
            return;
        }
        for (auto k: keyboard[input[i]]) {
            path.push_back(k);
            backtracing(i+1);
            path.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        n = static_cast<int>(digits.size()); // 按键的个数
        for(auto digit: digits) {
            input.push_back(static_cast<int>(digit-'1'+1));
        }
        backtracing(1);

        return ans;
    }
};

int main(void)
{
    auto s = Solution();
    auto ans = s.letterCombinations("23");
    for(auto str: ans) {
        std::cout << str << " ";
    }
    std::cout << endl;
}
