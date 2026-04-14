/* 216. 组合总和III
 * 难度：中等
 */

#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

class Solution {
private:
    int temp;
    vector<vector<int>> ans;
    vector<int> path;

    void backtracing(const int n, const int k, const int start_index) {
        if(path.size() == k && accumulate(path.begin(), path.end(), 0) == n) {
            ans.push_back(path);
            return;
        }
        for(int i = start_index; i <= 9; ++i) {
            if(temp < i) return;        // 剪枝
            path.push_back(i);
            temp -= i;
            backtracing(n, k, i+1);
            temp += i;
            path.pop_back();
        }
    }
        
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        temp = n;
        backtracing(n, k, 1);
        return ans;
    }
};

int main(void)
{
    auto s = Solution();
    auto ans = s.combinationSum3(3, 9);
    for(auto nums: ans) {
        for(auto num: nums) {
            std::cout << num << " ";
        }
        std::cout << endl;
    }
}
