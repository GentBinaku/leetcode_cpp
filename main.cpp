#include <dbg.h>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::vector<int> res(temperatures.size(), 0);
        std::stack<int> st;

        for(int i = temperatures.size() - 1; i >= 0; i--){
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]){
                st.pop();
            }

            if(!st.empty())
                res[i] = st.top() - i;
          
        
            st.push(i);
        }
        return res;
     }
};

int main() {

  Solution s;
  std::vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
  std::vector<int> res = s.dailyTemperatures(temperatures);
  for (auto &i : res) {
    std::cout << i << std::endl;
  }
  return 0;
};
