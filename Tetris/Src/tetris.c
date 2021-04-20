/*************************************************
 * name: main
 * ���ܣ�ʵ�ֶ���˹����С��Ϸ
 * ��д�ˣ���͢��
 * ��д���ڣ�2018-3-21
 * ����������ڣ�2019-7-3
**************************************************/
#include "tetris.h"
#include "lcd_header.h"
#include "thint.h"
#include <stdlib.h>


/* �������� */
char BLOCKS[TYPE][NR][NR][NR] = {
    /* ��һ�ַ��� */
 {
  	{ /* ��һ�ַ��� */
  	 {1,1,0,0},
  	 {1,1,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �ڶ��ַ��� */
  	 {1,1,0,0},
  	 {1,1,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �����ַ��� */
  	 {1,1,0,0},
  	 {1,1,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �����ַ��� */
  	 {1,1,0,0},
  	 {1,1,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
 },

 /* �ڶ��ַ��� */
 {
  	{ /* ��һ�ַ��� */
  	 {2,2,2,2},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �ڶ��ַ��� */
  	 {0,2,0,0},
  	 {0,2,0,0},
  	 {0,2,0,0},
  	 {0,2,0,0},
  	},
  	{ /* �����ַ��� */
  	 {2,2,2,2},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �����ַ��� */
  	 {0,2,0,0},
  	 {0,2,0,0},
  	 {0,2,0,0},
  	 {0,2,0,0},
  	},
 },

 /* �����ַ��� */
 {
  	{ /* ��һ�ַ��� */
  	 {3,0,0,0},
  	 {3,3,3,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �ڶ��ַ��� */
  	 {0,3,3,0},
  	 {0,3,0,0},
  	 {0,3,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �����ַ��� */
  	 {3,3,3,0},
  	 {0,0,3,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �����ַ��� */
  	 {0,0,3,0},
  	 {0,0,3,0},
  	 {0,3,3,0},
  	 {0,0,0,0},
  	},
 },

 /* �����ַ��� */
 {
  	{ /* ��һ�ַ��� */
  	 {0,0,4,0},
  	 {4,4,4,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �ڶ��ַ��� */
  	 {0,4,0,0},
  	 {0,4,0,0},
  	 {0,4,4,0},
  	 {0,0,0,0},
  	},
  	{ /* �����ַ��� */
  	 {0,4,4,4},
  	 {0,4,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �����ַ��� */
  	 {0,4,4,0},
  	 {0,0,4,0},
  	 {0,0,4,0},
  	 {0,0,0,0},
  	},
 },

 /* �����ַ��� */
 {
  	{ /* ��һ�ַ��� */
  	 {0,5,0,0},
  	 {5,5,5,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �ڶ��ַ��� */
  	 {0,5,0,0},
  	 {0,5,5,0},
  	 {0,5,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �����ַ��� */
  	 {5,5,5,0},
  	 {0,5,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �����ַ��� */
  	 {0,5,0,0},
  	 {5,5,0,0},
  	 {0,5,0,0},
  	 {0,0,0,0},
  	},
 },

 /* �����ַ��� */
 {
  	{ /* ��һ�ַ��� */
  	 {6,6,0,0},
  	 {0,6,6,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �ڶ��ַ��� */
  	 {0,0,6,0},
  	 {0,6,6,0},
  	 {0,6,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �����ַ��� */
  	 {6,6,0,0},
  	 {0,6,6,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �����ַ��� */
  	 {0,0,6,0},
  	 {0,6,6,0},
  	 {0,6,0,0},
  	 {0,0,0,0},
  	},
 },

 /* �����ַ��� */
 {
  	{ /* ��һ�ַ��� */
  	 {0,7,7,0},
  	 {7,7,0,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �ڶ��ַ��� */
  	 {0,7,0,0},
  	 {0,7,7,0},
  	 {0,0,7,0},
  	 {0,0,0,0},
  	},
  	{ /* �����ַ��� */
  	 {0,0,7,7},
  	 {0,7,7,0},
  	 {0,0,0,0},
  	 {0,0,0,0},
  	},
  	{ /* �����ַ��� */
  	 {0,7,0,0},
  	 {0,7,7,0},
  	 {0,0,7,0},
  	 {0,0,0,0},
  	},
  },
};

#define BEBU
#ifndef BEBUG

/* ȫ�ֱ������� */
static char gameArea[ROW][COL] = {0};   	// ��Ϸ��������
static int startX = 7, startY = 0;      	// ������ֵ���ʼλ��
static int type = 0;                    	// ���鵱ǰ����
static int nextType = 0;                	// �������һ������
static int diret = 0;                   	// ����ķ���
//char *state = "\033[32m��Ϸ��...\033[0m";	// ��Ϸ����״̬
static unsigned int level = 0;          	// ��Ϸ�ȼ�
static unsigned int score = 0;          	// ��Ϸ����
//static unsigned int maxScore = 0;       	// ��Ϸ��߼�¼

void(*beep_one)(void);

/*
 * ������������ȫ������
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

        /* ������ */
        drawBlock(BLOCKS[type][diret]);

        /* ��ʾ��Ϸ */
        showGame();

        /* ������� */
        cleanBlock(BLOCKS[type][diret]);
}
/*
 * ��������initalGameArea
 * �������ܣ���ʼ����Ϸ����
 * ��������
 * ����ֵ����
*/
void initalGameArea(void(*beep)(void))
{
		beep_one = beep;
    int i;

    /* ��ʼ���� */
    for (i = 0; i < COL; i++)
    {
        gameArea[0][i]     = 8;   // ��0��
        gameArea[ROW-1][i] = 8;   // ���һ��
    }

    /* ��ʼ���� */
    for (i = 0; i < ROW; i++)
    {
        gameArea[i][0]     = 8;  // ��0��
        gameArea[i][COL-1] = 8;  // ���һ��
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
 * ��������gameSelf
 * �������ܣ���Ϊ�źź���������ʱ��һ�����Զ�����
 * �������ź�
 * ����ֵ����
*/
void gameSelf(int *signo)
{
    /* ������ */
    drawBlock(BLOCKS[type][diret]);

    /* ��ʾ��Ϸ */
    showGame();

    /* ������� */
    cleanBlock(BLOCKS[type][diret]);

    /* ��������Ѿ����� */
    if (!checkMove(BLOCKS[type][diret],DOWN))
    {
			beep_one();
    	/* ����Ƿ���Ϸ���� */
    	*signo = checkGameOver(BLOCKS[type][diret]);

    	/* �����Ѿ����׵ķ��� */
    	drawBlock(BLOCKS[type][diret]);

    	/* ��ʾ��Ϸ��� */
    	showGame();

    	/* ����߽�����Ƿ������ */
    	checkDeleteLine();

    	/* ���¿�ʼ��һ������ */
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
 * ��������checkDeleteLine
 * �������ܣ�����Ƿ������
 * ��������
 * ����ֵ����
*/
void checkDeleteLine(void)
{
    int i, j;
    int x, y;

    /* ��鵱ǰ��������������� */
    for (i = 3; i >= 0; i--)
    {
        for (j = 1; j < COL-1; j++)
    	{
    	    /* ��ⷽ���Ƿ���һ�� */
    	    if (gameArea[startY+i][j] == 0)
    	        break;
    	    /* �����߿����� */
    	    else if (gameArea[startY+i][j] == 8)
    	        break;
    	}
    	/* �������һ����ɾ��һ�� */
    	if (j == COL-1)
    	{
    	    /* ɾ�����˵�һ�� */
    	    for (j = 1; j < COL-1; j++)
    	    {
    	        gameArea[startY+i][j] = 0;
    	    }

    	    /* �����ۼ� */
    	    score += 100;

    	    /* ��¼���� */
    	    if (score%200 == 0)
    	    {
    		    /* ÿ200�ּ�һ�� */
    	        level++;
    	    }

    	    /* ɾ���������ƶ�һ�� */
    	    for (x = 1; x < COL-1; x++)
    	    {
    	        for (y = startY+i; y >= 7; y--)
        		{
        		    gameArea[y][x] = gameArea[y-1][x];
        		}
    	    }

    	    /* �ƶ���һ����Ҫ��ⷶΧ��һ�� */
    	    i++;
    	}
    }
}

/*
 * ��������checkGameOver
 * �������ܣ������Ϸ�Ƿ����
 * ����������鷽����������
 * ����ֵ����
*/
int checkGameOver(char block[NR][NR])
{
    int i;

    for (i = 0; i < NR; i++)
    {
        /* ���������Ϸ��߽�����Ϸ���� */
        if (block[0][i] != 0 && gameArea[startY-1][startX+i] == 8)
    	{
    	    return gameEnd();
    	}
    }
		return 0;
}

/*
 * ��������turnBlock
 * �������ܣ���ת����
 * ��������Ҫ��ת�ķ�����������
 * ����ֵ����
*/
void turnBlock(char bl[NR][NR])
{
    int x, y;

    /* ����Ƿ�Խ�� */
    for (y = 0; y < NR; y++)
    {
        for (x = 0; x < NR; x++)
    	{
    	    /* ֻ���жϵ����˱߽� */
    	    if (bl[y][x] != 0 && gameArea[startY+y][startX+x] != 0)
    	    {
    	        return;
    	    }
    	}
    }

    /* ���߶�û��Խ������ת���鷽�� */
    diret = (diret+1)%4;
}
/*
 * ��������checkMove
 * �������ܣ���鷽���Ƿ���ƶ�,��������
 * ������1.������������ 2.�����־λ
 * ����ֵ�����ƶ�����1�������ƶ�����0
*/
int checkMove(char bl[NR][NR], int flag)
{
    int m, n;   // ���ڱ������ƶ�����
    int x, y;   // ����ѭ��

    switch (flag)
    {
      case RIGHT : n = 0; m = 1;  break;
    	case LEFT  : n = 0; m = -1; break;
    	case DOWN  : n = 1; m = 0;  break;
    }

    /* ȫ�ּ�� */
    for (y = 0; y < NR; y++)
    {
        for (x = 0; x < NR; x++)
    	{
    	    /* ֻ���жϵ����˱߽� */
    	    if (bl[y][x] != 0 && gameArea[startY+y+n][startX+x+m] != 0)
            {
                return 0;
            }
    	}
    }

    /* ����˵��û�е���߽� */
    startY += n;
    startX += m;

    return 1;
}
/*
 * ��������drawBlock
 * �������ܣ���䷽������
 * ������������������
 * ����ֵ����
*/
void drawBlock(char block[NR][NR])
{
    int x, y;

    /* ����ǰ���� */
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
 * ��������cleanBlock
 * �������ܣ������������
 * ������������������
 * ����ֵ����
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
 * ��������showGame
 * �������ܣ���ʾ��Ϸ
 * ��������
 * ����ֵ����
*/
void showGame(void)
{
    int i, j;
		LCD_Clear(WHITE);
    /* ��ӡ�������� */
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
 * ��������gameEnd
 * �������ܣ�������Ϸ����������
 * ��������
 * ����ֵ����
*/
int gameEnd(void)
{
  LCD_Clear(WHITE);
	LCD_ShowString(10,300,400,100,12,"GAME OVER...");
	return 1;
}
#endif
