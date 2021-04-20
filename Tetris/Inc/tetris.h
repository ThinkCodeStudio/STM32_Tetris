#ifndef __TETRIS_H__
#define __TETRIS_H__

#include "thint.h"

#define    NR    4  // 方块数据大小
#define    TYPE  7  // 方块类型数


//屏幕 800*480
#define 	DisW		480
#define 	DisH		800
//方块宽高
#define 	BlockW	10
#define 	BlockH	10

#define   ROW    	DisH/BlockH     // 游戏区域的行数
#define   COL    	DisW/BlockW     // 游戏区域的列数

/* 按键枚举 */
enum key {
   DOWN,    			// 上
   LEFT,    			// 左
   RIGHT,   			// 右
   CHANGE,  			// 变化
   STOP,    			// 停止
   EXIT,    			// 退出
   UNKNOW,  			// 未知
};

/***** 函数声明区域 ******/
void initalGameArea(void(*)(void));                  // 初始化游戏区域
void drawBlock(char bl[NR][NR]);            // 画方块
void cleanBlock(char bl[NR][NR]);           // 清除方块
void turnBlock(char bl[NR][NR]);            // 旋转方块
int  gameEnd(void);                         // 结束游戏
//void gameStop(void);                      // 暂停游戏
void showGame(void);                        // 显示游戏
void gameSelf(int *signo);                   // 游戏自动运行
void checkDeleteLine(void);                 // 检查是否满一行
int  checkGameOver(char bl[NR][NR]);        // 检查是否游戏结束
int  checkMove(char bl[NR][NR], int flag);  // 检查方块是否可移动
void Input(u16);                        		// 获取输入
#endif
