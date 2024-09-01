# define  _CRT_SECURE_NO_WARNINGS 1
# include <stdio.h>
# include <stdlib.h> // srand和rand函数使用的头文件
# include <time.h>  // time函数使用的头文件

void menu()
{
	printf("@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("*****   1  play   *****\n");
	printf("*****   0  exit   *****\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@@\n");
}

void game()
{
// 生成一个1至100的随机数
//	srand((unsigned int)time(NULL)); // ()内为一个整数，每次输入后的随机数一样，因此要让（）里面的数随机变，引入时间戳的概念  
// 当快速输入两个数据仍不是很随机，解决方法：仅需要设置一次，放到main函数里面
	int ret = rand() % 100 + 1; // rand函数返回了一个0至32767之间的数，但这个数不够随机（每次游戏都是重复的顺序随机）
// 解决方法：在调用rand之前调用srand函数去设置随机数生成器
// 要求生成1至100的随机数，解决方法：将产生的随机数对100取模，得到0至99，再加1

// 猜数字
	int guess = 0;
	while (1) // 重复执行
	{
		printf("请猜数字");
		scanf("%d", &guess);
		if (guess < ret)
		{
			printf("你猜小了\n"); // 猜小了继续猜
		}
		else if (guess > ret)
		{
			printf("你猜大了\n"); // 猜大了继续猜
		}
		else
		{
			printf("恭喜你猜对了\n");
			break;
		}
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu(); // 打印一个简单的菜单提示界面
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		   {
			game();
			break;
		   }
		case 0:
		   {
			printf("退出游戏");
			break;
		   }
		default:
		   {
			printf("输入错误，请重新输入\n");
			break;
		   }
		}
	}while (input); // input刚好可以满足，输入0不玩，不循环；输入其它数时执行循环
	return 0;
}