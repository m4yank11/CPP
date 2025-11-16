#include<iostream>
#include <vector>
#include<unordered_map>
#include<set>
using namespace std;

class Solution {
    vector<pair<int, int>> internal;

    void dfs(vector<vector<int>>& grid, int r, int c, int originalColor,
             int newColor) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() ||
            grid[r][c] != originalColor)
            return;
        grid[r][c] = -newColor;
        dfs(grid, r + 1, c, originalColor, newColor);
        dfs(grid, r - 1, c, originalColor, newColor);
        dfs(grid, r, c + 1, originalColor, newColor);
        dfs(grid, r, c - 1, originalColor, newColor);

        // below code will be executed while coming back from the recursion
        if (not(r == 0 || c == 0 || r == grid.size() - 1 || c == grid[0].size() - 1)) {
            if (not(grid[r + 1][c] != -newColor ||
                    grid[r - 1][c] != -newColor ||
                    grid[r][c + 1] != -newColor || grid[r][c - 1] != -newColor))
                internal.push_back({r, c}); // curr cell is internal
        }
    }

public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col,
                                    int color) {
        int originalColor = grid[row][col];
        if (originalColor == color)
            return grid;
        dfs(grid, row, col, originalColor, color);
        for (auto p : internal) {
            int i = p.first;
            int j = p.second;
            grid[i][j] = originalColor;
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] < 0)
                    grid[i][j] *= -1;
            }
        }
        return grid;
    }
};
int main(){}