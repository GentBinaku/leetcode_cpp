#include <iostream>
#include <vector>
#include <unordered_map>
#include <dbg.h>

using namespace std;
/* Time Limit Exceeded
 *     int prefixProduct(vector<int>& nums, int i){
        int sum = 1;
        for(int j = 0; j < i; j++){
            sum *= nums[j];
        }
        return sum;
    }
    int suffixProduct(vector<int>& nums, int i){
        int sum = 1;
        for(int j = i + 1; j < nums.size(); j++)
            sum *= nums[j];
        return sum;
    }

    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            auto prefix_sum = prefixProduct(nums, i);
            auto suffix_sum = suffixProduct(nums, i);
            res.emplace_back( prefix_sum * suffix_sum);
        }
        return res;
    }
 */


vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, 1);
    int left = 1, right = 1;

    for(int i = 0; i < n; i++){
        res[i] *= left;
        left *= nums[i];
        res[n - 1 - i] *= right;
        right *= nums[n - 1 - i];
    }
    return res;
}

int main() {
    vector<int> nums = {1, 2 , 3, 4};
    dbg(productExceptSelf(nums));
};