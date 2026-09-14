class Solution {
public:
    bool isRectangleOverlap(vector<int>& a, vector<int>& b) {
        // rename the rec1 with a and rec2 with b
     int width = min(a[2] , b[2]) - max(a[0], b[0]);
      int height  = min(a[3] , b[3]) - max(a[1], b[1]);   

      return width > 0 &&  height > 0;
    }
};