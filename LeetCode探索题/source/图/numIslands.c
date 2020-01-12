// 给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。
// 一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。
// 你可以假设网格的四个边均被水包围。
#include <stdio.h>
#include <stdlib.h>

// row和col是当前扩散的坐标，rows和cols是总的行数和列数
void infect(char **grid, int row, int col, int rows, int cols)
{
    if (row >= 0 && col >= 0 && row < rows && col < cols)
    {
        if (grid[row][col] == '1')
        {
            grid[row][col] = '2';
            // 上
            infect(grid, row - 1, col, rows, cols);
            // 下
            infect(grid, row + 1, col, rows, cols);
            // 左
            infect(grid, row, col - 1, rows, cols);
            // 右
            infect(grid, row, col + 1, rows, cols);
        }
    }
}

// 算法思想是:
// 从一个陆地开始(记为1的),将其标记为2表示已经访问,
// 递归从该陆地的上下左右四个点开始,如果是陆地则继续
// 以上操作直至所有的该区域陆地都被标记为已经访问过。
// 类似于广度优先搜索
// gridSize代表行数，gridColSize代表列数
int numIslands(char **grid, int gridSize, int *gridColSize)
{
    if (!grid)
    {
        return 0;
    }
    // 行
    int rows = gridSize;
    // 岛屿数量
    int count = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < *gridColSize; j++)
        {
            if (grid[i][j] == '1')
            {
                infect(grid, i, j, rows, *gridColSize);
                count++;
            }
        }
    }
    return count;
}