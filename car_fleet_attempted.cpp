class Solution {
public:
  int carFleet(int target, vector<int> &position, vector<int> &speed) {
    if(position.size() == 1) return position[0]   == target ? position[0] : 0;
    int res = 0;
    // Is it a two pointer system
    //  One pointer for pointing at the current item
    //  One pointer to iterate through the array, except self
    for (int i = 0; i < position.size() - 1; i++) {
      int running_index = i + 1;
      while (running_index != i) {
        if (position[running_index] + speed[running_index] ==
            position[i] + speed[i])
          res += 1;
        running_index += 1;
        running_index = running_index % position.size();
      }
    }
    return res;
  }
};