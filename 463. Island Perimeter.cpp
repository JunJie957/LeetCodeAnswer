class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size(),col = grid[0].size(), sum = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) {
                    if ((i > 0 && grid[i - 1][j] != 1) || i == 0)
                        sum += 1;   // ио
                    if ((i < row - 1 && grid[i + 1][j] != 1) || i == row - 1)
                        sum += 1;   // об
                    if ((j > 0 && grid[i][j - 1] != 1) || j == 0)
                        sum += 1;   // вС
                    if ((j < col - 1 && grid[i][j + 1] != 1) || j == col - 1)
                        sum += 1;   // ср
                }
            }
        }
        return sum;
    }
};

