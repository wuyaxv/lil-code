/* 39. 组合总和
 * 难度：中等
 */

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    int t;
    vector<int> path;
    vector<vector<int>> ans;

    void backtracking(vector<int>& candidates, int i) {
        if(t == 0) {
            ans.push_back(path);
            return;
        }
        for(int j = i; j < candidates.size(); ++j) {
            if(t < candidates[j]) continue;
            t -= candidates[j];
            path.push_back(candidates[j]);
            backtracking(candidates, j);
            path.pop_back();
            t += candidates[j];
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        t = target;
        backtracking(candidates, 0);
        return ans;
    }
};

int main(void)
{
    auto s = Solution();
    vector<int> input({8,7,4,3});
    sort(input.begin(), input.end());
//////////////////    for(auto s: input) std::cout << s << " ";
    auto ans = s.combinationSum(input, 11);

    for(auto nums: ans) {
        for(auto num: nums) {
            std::cout << num << " ";
        }
        std::cout << endl;
    }
}
