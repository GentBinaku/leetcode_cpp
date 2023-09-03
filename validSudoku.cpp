#include <iostream>
#include <vector>
#include <unordered_map>
#include <dbg.h>
#include <set>

using namespace std;

int coordToGrid(int i, int j){
    return (i / 3) * 3 + j / 3;
}

bool isValidSudoku(vector<vector<char>>& board) {
    vector<set<char>> rows(9), cols(9), grids(9);
    pair<set<char>::iterator , bool> ret;

    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j)
        {
            char c = board[i][j];
            if(c == '.') continue;
            int gridIdx = coordToGrid(i, j);
            ret = rows[i].insert(c);
            if(!ret.second) return false;
            ret = cols[j].insert(c);
            if(!ret.second) return false;
            ret = grids[gridIdx].insert(c);
            if(!ret.second) return false;
        }
    }
    return true;
}


int main() {
  vector<vector<char>> mat =
          {{'5','3','.','.','7','.','.','.','.'},
           {'6','.','.','1','9','5','.','.','.'},
           {'.','9','8','.','.','.','.','6','.'},
           {'8','.','.','.','6','.','.','.','3'},
           {'4','.','.','8','.','3','.','.','1'},
           {'7','.','.','.','2','.','.','.','6'},
           {'.','6','.','.','.','.','2','8','.'},
           {'.','.','.','4','1','9','.','.','5'},
           {'.','.','.','.','8','.','.','7','9'}};

    std::cout << isValidSudoku(mat) << std::endl;
};
