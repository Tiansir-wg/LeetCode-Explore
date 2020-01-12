// 给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
// 算法思想:
// 不能在每次遇到0时就将其所在行和所在列的所有元素置为0，这样会覆盖掉原本的值导致无法判断是原有的0还是
// 设置的0。比较好的做法是:设置两个变量分别记录第一行的元素和第一列的元素中是否出现过0，如果出现过则记为1
//  对于不在第一行和第一列的元素，如果遇到了0则将该行或者该列的第一个元素置为0;等所有的行都检查完毕后
// 1、根据第一行和第一列元素是否为0决定是否将其所在行和所在列置为0
// 2、根据这两个变量是否为0决定是否将第一行或者第一列置为0

#include <stdio.h>
// matrixSize表行数，matrixColSize表列数
void setZeroes(int **matrix, int matrixSize, int *matrixColSize)
{
    if (!matrix || matrixSize <= 0 || matrixColSize <= 0)
    {
        return;
    }
    // 第一行和第一列是否存在0元素
    int firstRowFlag = 0;
    int firstColFlag = 0;

    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < *matrixColSize; j++)
        {
            // 第一行和第一列之外的元素存在0元素
            if (i != 0 && j != 0 && matrix[i][j] == 0)
            {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
            // 第一行或第一列出现0元素
            else if (matrix[i][j] == 0)
            {
                firstRowFlag = i == 0 ? 1 : firstRowFlag;
                firstColFlag = j == 0 ? 1 : firstColFlag;
            }
        }
    }

    // 根据第一行和第一列元素是否为0将对应的整行或整列置为0
    for (int i = 1; i < matrixSize; i++)
    {
        for (int j = 1; j < *matrixColSize; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // 根据行列标记是否为1将第一行或第一列置为0
    if (firstRowFlag == 1)
    {
        for (int j = 0; j < *matrixColSize; j++)
        {
            matrix[0][j] = 0;
        }
    }

    if (firstColFlag == 1)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            matrix[j][0] = 0;
        }
    }
}
