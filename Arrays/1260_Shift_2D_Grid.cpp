# LeetCode 1260 - Shift 2D Grid
🔗 Problem Link: https://leetcode.com/problems/shift-2d-grid/
Treat 2D Grid as 1D – Elegant 3-Step Reverse Solution  || (No Extra Space) || O(m×n) ||
## Concepts Used: 
- Array Rotation
- Index Mapping
- O(1) Space Optimization
- In-place Reversal
- Modulo Optimization

## Intuition
This solution uses the 3-step reverse technique commonly used for 1D array rotation.
We can treat the 2D grid like a 1D array of size m × n
Shifting the 2D grid to the right by k positions is equivalent to rotating a 1D array of size m × n by k positions.
A 1D array rotation can be achieved using three reversals:
1. Reverse whole array.
2. Reverse first k elements.
3. Reverse remaining elements.
Instead of flattening the grid, we use index mapping:-
row = index / n
col = index % n
This allows us to reverse elements directly inside the 2D grid without extra space.
This solution is optimal because it avoids extra matrix creation and works directly on the given grid.

## Approach
1. Let m = number of rows and n = number of columns.
Hence, m = grid.size() and n = grid[0].size().
2. Reduce k using:
k = k % (m * n) {we do it to keep only useful shifts and
to avoid unnecessary full rotations.}
It is a very important concept Whenever you are asked any of followings :
a.)Rotation
b.)Circular array
c.)Shifting
Always think about the concept:-> k = k % size
3. Reverse entire grid from index 0 to mn - 1(i.e. from beg to end).
4. Reverse first k elements(k will always be given in que.)
5. Reverse remaining elements from k to mn - 1(rev the all elements after K to end).
All reversals are done using index-to-row/column mapping.

## Complexity
Time complexity: O(m × n).

Space complexity: O(1).

## Code
```cpp
class Solution {
private:
  void reverse(vector<vector<int>>& grid,int start,int end){
    int m=grid.size();
    int n=grid[0].size();
    while(start<end){
        int r1=start/n;  int c1=start%n;
        int r2=end/n;    int c2=end%n;
        swap(grid[r1][c1],grid[r2][c2]);
        start++;
        end--;

    }
  }
  public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
       int m=grid.size();
      int n=grid[0].size();
      k=k%(m*n);
      reverse(grid,0,m*n-1);
      reverse(grid,0,k-1);
      reverse(grid,k,m*n-1);
      return grid;
    }
};
```
