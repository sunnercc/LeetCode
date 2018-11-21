//
//  main.cpp
//  岛屿的个数
//
//  Created by ifuwo on 2018/11/21.
//  Copyright © 2018 ifuwo. All rights reserved.
//


#include <stdio.h>

// 设置方向
int next[4][2] = {
    {0, 1}, // right
    {1, 0}, // bottom
    {0, -1}, // left
    {-1, 0}, // top
};

char b[100][100] = {0};


void dfs(int x, int y,char **grid, int bRow, int bCol)
{
    char *g = (char *)grid;
    // 标记路径
    b[x][y] = '1';
    
    printf("%d %d\n", x, y);
    
    // 预测下一步的路径
    for (int k = 0; k < 4; k++) {
        int nx = next[k][0] + x;
        int ny = next[k][1] + y;
        
        // 判断越界
        if (nx < 0 || nx >= bRow || ny < 0 || ny >= bCol) {
            continue;
        }
        
        char c = *(g + nx*bCol+ny);
        // 判断是否是障碍物 0 不可访问
        if (c == '0') {
            continue;
        }
        
        // 是否已经走过
        if (b[nx][ny] == '1') {
            continue;
        }
        // 走下一步
        dfs(nx, ny, grid, bRow, bCol);
    }
}

int numIslands(char** grid, int gridRowSize, int gridColSize) {
    char *g = (char *)grid;
    int num = 0;
    for (int i = 0; i < gridRowSize; i++) {
        for (int j = 0; j < gridColSize; j++) {
            // 路径没走过
            // 是岛屿
            char c = *(g + i * gridColSize + j);
            if (b[i][j] != '1' && c == '1') {
                dfs(i, j, grid, gridRowSize, gridColSize);
                num++;
            }
        }
    }
    return num;
}


// demo1
int main() {
    int num = 0;
    char grid[4][5] = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
    };
    num = numIslands(grid, 4, 5);
    printf("\n%d\n", num);
    return 0;
}

//// demo2
//int main() {
//    int num = 0;
//    char grid[4][5] = {
//        {'1', '1', '0', '0', '0'},
//        {'1', '1', '0', '0', '0'},
//        {'0', '0', '1', '0', '0'},
//        {'0', '0', '0', '1', '1'},
//    };
//    num = numIslands(grid, 4, 5);
//    printf("\n%d\n", num);
//    return 0;
//}
