#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row ; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}


//     |   |   
//  ---|---|---
//     |   |            我可以说这个就是我理想中想要打印出来的棋盘模样
//  ---|---|---
//     |   |
//好好思考这里是怎么来分析的
//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		//打印一行的数据
//		printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
//		//打印分隔行
//		if (i < row - 1)
//		{
//			printf("---|---|---\n");
//		}
//	}     对于一个这样的打印棋盘方法，很low，因为如果我突然想要打印一个10*10的棋盘，你会发现其实打印的是一个10*3的棋盘
//}

//这次我们通过控制行列的方法来实现打印棋盘，一次只打印其中的一个小方格
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;  //这里输入的坐标要存起来
	printf("玩家走：>\n");
	while (1)
	{
		printf("请输入要下的坐标：>");
		scanf("%d %d", &x, &y);
		//判断x，y的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')        //这个地方是用来判断你说准备下的地方是否已经有被占住（已经有别的棋下落在这里）
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标被占用\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入！");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走：> \n");
	while (1)
	{
		x = rand() % row;  //这个可以确保我的我的随机数在0-2中间
		y = rand() % row;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}


char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)      //横3行
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];//这样写很好的就把行的三种情况都考虑进去了
		}
	}
	for (i = 0; i < col; i++)    //竖3列
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//2个对角线的判断
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[1][1];
	//判断是否平局（棋盘满了，但是还没有得到结果）
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';
}


int  IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

