#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>//����srand��ͷ�ļ�
#include<time.h>
#define ROW 3
#define COL 3
//��ʼ��
void InitBoard(char board[ROW][COL], int row, int col);
//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col);
//�������
void PlayerMove(char board[ROW][COL], int row, int col);
//��������
void ComputerMove(char board[ROW][COL], int row, int col);
//�����������Ӧ�û����4�н��
//���Ӯ  '*'
//����Ӯ  '#'
//ƽ��    'Q'
//˭��ûӮ��Ҫ����  'C'
char IsWin(char board[ROW][COL], int row, int col);

int IsFull(char board[ROW][COL], int row, int col);