/* 77. 组合
 * 难度：中等
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
    void backtracking(const int n, const int k, const int start_index) {
        if(n-start_index+1+path.size() < k) { // 此时已经不可能
            return;
        }

        if(path.size() == k) {
            ans.push_back(path);
            return ;
        }

        for(int i = start_index; i <= n; ++i) {
            path.push_back(i);
            backtracking(n, k, i+1); // 如果输入的i > n，则根本不会出发循环
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return ans;
    }
};

int main(void){
    auto s = Solution();
    vector<vector<int>> ans = s.combine(3, 9);
    for(auto nums: ans) {
        for(auto num: nums) {
            std:: cout << num << " ";
        }
        std::cout << endl;
    }
}
