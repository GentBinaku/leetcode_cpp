#include <dbg.h>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<std::string> res;
  void backtrack(std::string op, int open, int close, std::vector<std::string>& ans){
    /*
    
                                    op      ip
                                    ""   O-3, C-3
                            
                                    "(", O-2,C-3
                    
                "((",O-1,C-3                            "()", O-2,C-2

    "(((",0,3                   "(()",1,2                       "()(",1,2

    "((()",0,2      "(()(",0,2    "(())",1,1        "()((",0,2      "()()",1,1

    "((())",0,1     "(()()",0,1   "(())(",0,1       "()(()",0,1     "()()(",0,1

    "((()))",0,0   "(()())",0,0   "(())()",0,0      "()(())",0,0    "()()()", 0,0 
    */
    
    if(open == 0 && close == 0){
      ans.push_back(op);
      return;
    }
    if(open == close) {
      std::string op1 = op + "(";
      backtrack(op1, open-1, close, ans);
    }else if(open == 0){
      std::string op1 = op + ")";
      backtrack(op1, open, close-1, ans);
    }else if(close == 0){
      std::string op1 = op + "(";
      backtrack(op1, open-1, close, ans);
    }else{
      std::string op1 = op + "(";
      backtrack(op1, open-1, close, ans);
      std::string op2 = op + ")";
      backtrack(op2, open, close-1, ans);
    }
  }
  std::vector<std::string> generateParenthesis(int n) {
    // Generate all the parenthesis
    // How do I generate all parenthesis
    // std::vector<string> generated
    std::string parenthesis = "";
    backtrack(parenthesis, n, n, res);
    // return a vector of strings
    // and check which one are ok
    // from the previous function I know how to do this
    return res;
  }
};

int main() {

  Solution s;
  std::vector<std::string> res = s.generateParenthesis(3);
  for (auto &i : res) {
    std::cout << i << std::endl;
  }
  return 0;
};
