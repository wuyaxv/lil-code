/* 78. 子集
 * 难度：中等
 */
#include <vector>
#include <iostream>
#include <list>

using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    list<vector<int>> q;
    q.push_back(vector<int>());
    size_t n = 0;
    vector<int> *ptr;

    for(vector<int>::const_iterator iter = nums.begin(); iter != nums.end(); ++iter) {
        n = q.size();
        while(n--) {
            ptr = &q.front();
            q.push_back(vector<int>(ptr->begin(), ptr->end()));
            ptr->push_back(*iter);
            q.push_back(vector<int>(ptr->begin(), ptr->end()));
            q.pop_front();
        }
    }

    return vector<vector<int>>(q.begin(), q.end());
}

int main(void)
{
    vector<int> input({1, 2, 3});
    vector<vector<int>> result = subsets(input);

    for(auto iter = result.begin(); iter != result.end(); ++iter) {
        for(auto iter2 = iter->begin(); iter2 != iter->end(); ++iter2) {
            std::cout << *iter2 << " ";
        }
        std::cout << endl;
    }
}

