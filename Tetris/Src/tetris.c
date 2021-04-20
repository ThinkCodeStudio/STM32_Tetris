/*************************************************
 * name: main
 * 功能：实现俄罗斯方块小游戏
 * 编写人：王廷云
 * 编写日期：2018-3-21
 * 最近更新日期：2019-7-3
**************************************************/
#include "tetris.h"
#include "lcd_header.h"
#include "thint.h"
#include <stdlib.h>


/* 方块数据 */
char BLOCKS[TYPE][NR][NR][NR] = {
    /* 第一种方块 */
 {
  	{ /* 第一种方向 */
  	 {1,1,0,0},
  	 {1,1,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第二种方向 */
  	 {1,1,0,0},
  	 {1,1,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第三种方向 */
  	 {1,1,0,0},
  	 {1,1,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第四种方向 */
  	 {1,1,0,0},
  	 {1,1,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
 },

 /* 第二种方块 */
 {
  	{ /* 第一种方向 */
  	 {2,2,2,2},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第二种方向 */
  	 {0,2,0,0},
  	 {0,2,0,0},
  	 {0,2,0,0},
  	 {0,2,0,0},
  	},
  	{ /* 第三种方向 */
  	 {2,2,2,2},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第四种方向 */
  	 {0,2,0,0},
  	 {0,2,0,0},
  	 {0,2,0,0},
  	 {0,2,0,0},
  	},
 },

 /* 第三种方块 */
 {
  	{ /* 第一种方向 */
  	 {3,0,0,0},
  	 {3,3,3,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第二种方向 */
  	 {0,3,3,0},
  	 {0,3,0,0},
  	 {0,3,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第三种方向 */
  	 {3,3,3,0},
  	 {0,0,3,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第四种方向 */
  	 {0,0,3,0},
  	 {0,0,3,0},
  	 {0,3,3,0},
  	 {0,0,0,0},
  	},
 },

 /* 第四种方块 */
 {
  	{ /* 第一种方向 */
  	 {0,0,4,0},
  	 {4,4,4,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第二种方向 */
  	 {0,4,0,0},
  	 {0,4,0,0},
  	 {0,4,4,0},
  	 {0,0,0,0},
  	},
  	{ /* 第三种方向 */
  	 {0,4,4,4},
  	 {0,4,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第四种方向 */
  	 {0,4,4,0},
  	 {0,0,4,0},
  	 {0,0,4,0},
  	 {0,0,0,0},
  	},
 },

 /* 第五种方块 */
 {
  	{ /* 第一种方向 */
  	 {0,5,0,0},
  	 {5,5,5,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第二种方向 */
  	 {0,5,0,0},
  	 {0,5,5,0},
  	 {0,5,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第三种方向 */
  	 {5,5,5,0},
  	 {0,5,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第四种方向 */
  	 {0,5,0,0},
  	 {5,5,0,0},
  	 {0,5,0,0},
  	 {0,0,0,0},
  	},
 },

 /* 第六种方块 */
 {
  	{ /* 第一种方向 */
  	 {6,6,0,0},
  	 {0,6,6,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第二种方向 */
  	 {0,0,6,0},
  	 {0,6,6,0},
  	 {0,6,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第三种方向 */
  	 {6,6,0,0},
  	 {0,6,6,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第四种方向 */
  	 {0,0,6,0},
  	 {0,6,6,0},
  	 {0,6,0,0},
  	 {0,0,0,0},
  	},
 },

 /* 第七种方块 */
 {
  	{ /* 第一种方向 */
  	 {0,7,7,0},
  	 {7,7,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第二种方向 */
  	 {0,7,0,0},
  	 {0,7,7,0},
  	 {0,0,7,0},
  	 {0,0,0,0},
  	},
  	{ /* 第三种方向 */
  	 {0,0,7,7},
  	 {0,7,7,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* 第四种方向 */
  	 {0,7,0,0},
  	 {0,7,7,0},
  	 {0,0,7,0},
  	 {0,0,0,0},
  	},
  },
};

#define BEBU
#ifndef BEBUG

/* 全局变量区域 */
static char gameArea[ROW][COL] = {0};   	// 游戏区域数据
static int startX = 7, startY = 0;      	// 方块出现的起始位置
static int type = 0;                    	// 方块当前类型
static int nextType = 0;                	// 方块的下一种类型
static int diret = 0;                   	// 方块的方向
//char *state = "\033[32m游戏中...\033[0m";	// 游戏运行状态
static unsigned int level = 0;          	// 游戏等级
static unsigned int score = 0;          	// 游戏分数
//static unsigned int maxScore = 0;       	// 游戏最高记录

void(*beep_one)(void);

/*
 * 主函数：控制全局流程
*/
void Input(u16 Pin)
{
        switch (Pin)
    	{
    	    case ((uint16_t)0x0010): checkMove(BLOCKS[type][diret],RIGHT);
    	                 break;
    	    case ((uint16_t)0x0004): checkMove(BLOCKS[type][diret],LEFT);
    	                 break;
    	    case ((uint16_t)0x0008): checkMove(BLOCKS[type][diret],DOWN);
    	                 break;
    	    case ((uint16_t)0x0001): turnBlock(BLOCKS[type][(diret+1)%4]);
    	                 break;
    	}

        /* 画方块 */
        drawBlock(BLOCKS[type][diret]);

        /* 显示游戏 */
        showGame();

        /* 清除方块 */
        cleanBlock(BLOCKS[type][diret]);
}
/*
 * 函数名：initalGameArea
 * 函数功能：初始化游戏区域
 * 参数：无
 * 返回值：无
*/
void initalGameArea(void(*beep)(void))
{
		beep_one = beep;
    int i;

    /* 初始化行 */
    for (i = 0; i < COL; i++)
    {
        gameArea[0][i]     = 8;   // 第0行
        gameArea[ROW-1][i] = 8;   // 最后一行
    }

    /* 初始化列 */
    for (i = 0; i < ROW; i++)
    {
        gameArea[i][0]     = 8;  // 第0列
        gameArea[i][COL-1] = 8;  // 最后一列
    }
		
		srand(36468651);
    type     = rand()%7;
    nextType = rand()%7;
}

void DiewBlock(u16 x,u16 y){
	u16 px = x * BlockW;
	u16 py = y * BlockH;
	LCD_Fill(px,py,px+BlockW,py+BlockH,BLUE);
}

/*
 * 函数名：gameSelf
 * 函数功能：作为信号函数，闹钟时间一到就自动下落
 * 参数：信号
 * 返回值：无
*/
void gameSelf(int *signo)
{
    /* 画方块 */
    drawBlock(BLOCKS[type][diret]);

    /* 显示游戏 */
    showGame();

    /* 清除方块 */
    cleanBlock(BLOCKS[type][diret]);

    /* 如果方块已经到底 */
    if (!checkMove(BLOCKS[type][diret],DOWN))
    {
			beep_one();
    	/* 检查是否游戏结束 */
    	*signo = checkGameOver(BLOCKS[type][diret]);

    	/* 保留已经到底的方块 */
    	drawBlock(BLOCKS[type][diret]);

    	/* 显示游戏结果 */
    	showGame();

    	/* 到达边界后检查是否可消行 */
    	checkDeleteLine();

    	/* 重新开始下一个方块 */
    	startY = 0;
    	startX = 7;
    	type = nextType;
			//srand(time_clock);
    	nextType = rand()%7;
    	diret = 0;
    }
		//startY ++;
}

/*
 * 函数名：checkDeleteLine
 * 函数功能：检查是否可消行
 * 参数：无
 * 返回值：无
*/
void checkDeleteLine(void)
{
    int i, j;
    int x, y;

    /* 检查当前方块的四行区域内 */
    for (i = 3; i >= 0; i--)
    {
        for (j = 1; j < COL-1; j++)
    	{
    	    /* 检测方块是否满一行 */
    	    if (gameArea[startY+i][j] == 0)
    	        break;
    	    /* 跳过边框区域 */
    	    else if (gameArea[startY+i][j] == 8)
    	        break;
    	}
    	/* 如果满了一行则删除一行 */
    	if (j == COL-1)
    	{
    	    /* 删除满了的一行 */
    	    for (j = 1; j < COL-1; j++)
    	    {
    	        gameArea[startY+i][j] = 0;
    	    }

    	    /* 分数累加 */
    	    score += 100;

    	    /* 记录级别 */
    	    if (score%200 == 0)
    	    {
    		    /* 每200分加一级 */
    	        level++;
    	    }

    	    /* 删除后往下移动一行 */
    	    for (x = 1; x < COL-1; x++)
    	    {
    	        for (y = startY+i; y >= 7; y--)
        		{
        		    gameArea[y][x] = gameArea[y-1][x];
        		}
    	    }

    	    /* 移动的一行需要检测范围加一行 */
    	    i++;
    	}
    }
}

/*
 * 函数名：checkGameOver
 * 函数功能：检查游戏是否结束
 * 参数：待检查方块数据数据
 * 返回值：无
*/
int checkGameOver(char block[NR][NR])
{
    int i;

    for (i = 0; i < NR; i++)
    {
        /* 方块碰到上方边界则游戏结束 */
        if (block[0][i] != 0 && gameArea[startY-1][startX+i] == 8)
    	{
    	    return gameEnd();
    	}
    }
		return 0;
}

/*
 * 函数名：turnBlock
 * 函数功能：旋转方块
 * 参数：需要旋转的方块数组数据
 * 返回值：无
*/
void turnBlock(char bl[NR][NR])
{
    int x, y;

    /* 检查是否越界 */
    for (y = 0; y < NR; y++)
    {
        for (x = 0; x < NR; x++)
    	{
    	    /* 只能判断到达了边界 */
    	    if (bl[y][x] != 0 && gameArea[startY+y][startX+x] != 0)
    	    {
    	        return;
    	    }
    	}
    }

    /* 两边都没有越界则旋转方块方向 */
    diret = (diret+1)%4;
}
/*
 * 函数名：checkMove
 * 函数功能：检查方块是否可移动,能移则移
 * 参数：1.方块数组数据 2.方向标志位
 * 返回值：可移动返回1，不能移动返回0
*/
int checkMove(char bl[NR][NR], int flag)
{
    int m, n;   // 用于标明可移动方向
    int x, y;   // 用于循环

    switch (flag)
    {
      case RIGHT : n = 0; m = 1;  break;
    	case LEFT  : n = 0; m = -1; break;
    	case DOWN  : n = 1; m = 0;  break;
    }

    /* 全局检查 */
    for (y = 0; y < NR; y++)
    {
        for (x = 0; x < NR; x++)
    	{
    	    /* 只能判断到达了边界 */
    	    if (bl[y][x] != 0 && gameArea[startY+y+n][startX+x+m] != 0)
            {
                return 0;
            }
    	}
    }

    /* 出来说明没有到达边界 */
    startY += n;
    startX += m;

    return 1;
}
/*
 * 函数名：drawBlock
 * 函数功能：填充方块数据
 * 参数：方块数组数据
 * 返回值：无
*/
void drawBlock(char block[NR][NR])
{
    int x, y;

    /* 画当前方块 */
    for (y = 0; y < NR; y++)
    {
        for (x = 0; x < NR; x++)
    	{
    	    if (block[y][x] != 0)
            {
                gameArea[startY+y][startX+x] = block[y][x];
            }
    	}
    }
}

/*
 * 函数名：cleanBlock
 * 函数功能：清除方块数据
 * 参数：方块数组数据
 * 返回值：无
*/
void cleanBlock(char bl[NR][NR])
{
    int x, y;

    for (y = 0; y < NR; y++)
    {
        for (x = 0; x < NR; x++)
    	{
    	    if (bl[y][x] != 0)
            {
                gameArea[startY+y][startX+x] = 0;
            }
    	}
    }
}

/*
 * 函数名：showGame
 * 函数功能：显示游戏
 * 参数：无
 * 返回值：无
*/
void showGame(void)
{
    int i, j;
		LCD_Clear(WHITE);
    /* 打印所有数据 */
    for (i = 0; i < COL; i++)
    {
        for (j = 0; j < ROW; j++)
    	{
					if(gameArea[j][i])
            DiewBlock(i,j);
    	}
    }
}

/*
 * 函数名：gameEnd
 * 函数功能：处理游戏结束的设置
 * 参数：无
 * 返回值：无
*/
int gameEnd(void)
{
  LCD_Clear(WHITE);
	LCD_ShowString(10,300,400,100,12,"GAME OVER...");
	return 1;
}
#endif
