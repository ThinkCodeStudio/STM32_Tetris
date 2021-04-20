#ifndef __TETRIS_H__
#define __TETRIS_H__

#include "thint.h"

#define    NR    4  // �������ݴ�С
#define    TYPE  7  // ����������


//��Ļ 800*480
#define 	DisW		480
#define 	DisH		800
//������
#define 	BlockW	10
#define 	BlockH	10

#define   ROW    	DisH/BlockH     // ��Ϸ���������
#define   COL    	DisW/BlockW     // ��Ϸ���������

/* ����ö�� */
enum key {
   DOWN,    			// ��
   LEFT,    			// ��
   RIGHT,   			// ��
   CHANGE,  			// �仯
   STOP,    			// ֹͣ
   EXIT,    			// �˳�
   UNKNOW,  			// δ֪
};

/***** ������������ ******/
void initalGameArea(void(*)(void));                  // ��ʼ����Ϸ����
void drawBlock(char bl[NR][NR]);            // ������
void cleanBlock(char bl[NR][NR]);           // �������
void turnBlock(char bl[NR][NR]);            // ��ת����
int  gameEnd(void);                         // ������Ϸ
//void gameStop(void);                      // ��ͣ��Ϸ
void showGame(void);                        // ��ʾ��Ϸ
void gameSelf(int *signo);                   // ��Ϸ�Զ�����
void checkDeleteLine(void);                 // ����Ƿ���һ��
int  checkGameOver(char bl[NR][NR]);        // ����Ƿ���Ϸ����
int  checkMove(char bl[NR][NR], int flag);  // ��鷽���Ƿ���ƶ�
void Input(u16);                        		// ��ȡ����
#endif
