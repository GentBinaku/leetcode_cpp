#include <dbg.h>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <cmath>


using namespace std;


class Solution {
public:
    long long hours_finish_eating(vector<int>& piles, int h, int k){
        long long hours_used = 0;
        for(auto const& pile: piles){
            if(pile <= k) hours_used += 1;
            else{
                hours_used += pile / k;
                if(pile % k != 0) hours_used += 1;
            }
        }
        return hours_used;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 1000000000;
        while(left <= right){
            int mid = left + (right - left) / 2;
            int k = hours_finish_eating(piles, h, mid);
            if(k <= h){
                right = mid - 1;
            }
            if(k > h) left = mid + 1;
        } 
        return left;  
    }
};


int main() {
  
    Solution s;
    vector<int> piles = { 805306368, 805306368, 805306368};
    int h = 1000000001;
    int res = s.minEatingSpeed(piles, h);
    cout << res << endl;
    return 0;
};
