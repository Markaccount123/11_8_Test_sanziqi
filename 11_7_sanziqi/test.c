#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("********************\n");
	printf("***1.play  0.exit***\n");
	printf("********************\n");
}
//有一个九宫格，人下一个用*表示 ，电脑下一个用#来代替，其中不管行还是列来说只要满足3个就赢了
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 }; // 全部都是空格
	
	InitBoard(board, ROW,COL);//对于一个二维数组来说，在传参的时候一定要将它的行和列也作为其中的一个参数传过去
	//打印棋盘   这里我们只是想要先测试一下效果  
	DisplayBoard(board, ROW, COL);
	//下棋（人下一步，电脑下一步，并且一直要到赢才会停下来）
	while (1)
	{
		//玩家先下
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//因为玩家每下一步都可能会赢，所以每下一步就需要对其进行判断一下
		ret = IsWin(board,ROW,COL); // 无非就是判断一下横三，竖三，斜三
		if (ret != 'C')
		{
			break;
		}
		//电脑再下
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//电脑也是一样的，每下一步都有可能会赢，也需要每次都判断一下
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL)); // 这里使用时间戳这个概念来设置随机数，且只能设置一次
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误,请重新选择！\n");
			break;
		}
	} while (input);
}
int main()
{
	test();  //测试三子棋游戏
	return 0;
}