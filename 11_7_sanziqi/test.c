#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("********************\n");
	printf("***1.play  0.exit***\n");
	printf("********************\n");
}
//��һ���Ź�������һ����*��ʾ ��������һ����#�����棬���в����л�������˵ֻҪ����3����Ӯ��
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 }; // ȫ�����ǿո�
	
	InitBoard(board, ROW,COL);//����һ����ά������˵���ڴ��ε�ʱ��һ��Ҫ�������к���Ҳ��Ϊ���е�һ����������ȥ
	//��ӡ����   ��������ֻ����Ҫ�Ȳ���һ��Ч��  
	DisplayBoard(board, ROW, COL);
	//���壨����һ����������һ��������һֱҪ��Ӯ�Ż�ͣ������
	while (1)
	{
		//�������
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//��Ϊ���ÿ��һ�������ܻ�Ӯ������ÿ��һ������Ҫ��������ж�һ��
		ret = IsWin(board,ROW,COL); // �޷Ǿ����ж�һ�º�����������б��
		if (ret != 'C')
		{
			break;
		}
		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//����Ҳ��һ���ģ�ÿ��һ�����п��ܻ�Ӯ��Ҳ��Ҫÿ�ζ��ж�һ��
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL)); // ����ʹ��ʱ�������������������������ֻ������һ��
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����,������ѡ��\n");
			break;
		}
	} while (input);
}
int main()
{
	test();  //������������Ϸ
	return 0;
}