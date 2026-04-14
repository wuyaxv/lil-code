/* 40. 组合总和II
 * 难度：中等
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> ans;
    void backtracking(const vector<int> &candidates, int target, const int n, const int start_index) {
        if(!target) {
            ans.push_back(path);
            return;
        }
        
        for(auto i = start_index; i < n; ++i) {
            if(target < candidates[i]) return;
            if(i > start_index) {
                if(candidates[i]==candidates[i-1]) continue;
            }
            target -= candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, n, i+1);
            path.pop_back();
            target += candidates[i];
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, candidates.size(), 0);
        return ans;
    }
};

int main(void)
{
    auto s = Solution();
    vector<int> candidates{10,1,2,7,6,1,5};
    auto ans = s.combinationSum2(candidates, 8);
    for(auto nums: ans) {
        for(auto num: nums) {
            std::cout << num << " ";
        }
        std::cout << endl;
    }

}
