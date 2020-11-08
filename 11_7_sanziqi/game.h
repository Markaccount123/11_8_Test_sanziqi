#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>//对于srand的头文件
#include<time.h>
#define ROW 3
#define COL 3
//初始化
void InitBoard(char board[ROW][COL], int row, int col);
//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);
//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);
//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);
//这里这个函数应该会产生4中结果
//玩家赢  '*'
//电脑赢  '#'
//平局    'Q'
//谁都没赢需要继续  'C'
char IsWin(char board[ROW][COL], int row, int col);

int IsFull(char board[ROW][COL], int row, int col);