#include <iostream>
#include <vector>
#include <unordered_map>
#include <dbg.h>

using namespace std;


void nextPermutation(std::string str, std::string prefix){
    if(str.size() == 0)
        std::cout << prefix << std::endl;
    else{
        for(int i = 0; i < str.size(); i++){
            std::string rem = str.substr(0, i) + str.substr(i + 1);
            nextPermutation(rem, prefix + str[i]);
        }
    }
}

void permutation(std::string str){
    nextPermutation(str, "");
}


int main()
{
    vector<int> topM = {-1, -1};
    permutation("abcd");
}

