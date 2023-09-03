#include <iostream>
#include <vector>
#include <unordered_map>
#include <dbg.h>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k)  {
    int n = nums.size();
    unordered_map<int, int> count;
    vector<vector<int>> freq(n + 1);

    for(auto num: nums)
        count[num] = 1 + count[num];

    for(auto c: count){
        freq[c.second].emplace_back(c.first);
    }

    vector<int> res;

    for(int i = n; i >= 0; i--)
    {
        for(auto num: freq[i])
        {
            res.emplace_back(num);
            if(res.size() == k)
                return res;
        }
    }
    return res;
}

int main()
{
    vector<int> topM = {-1, -1};
    auto res = topKFrequent(topM, 1);
    dbg(res);
}

