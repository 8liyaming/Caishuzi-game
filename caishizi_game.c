# define  _CRT_SECURE_NO_WARNINGS 1
# include <stdio.h>
# include <stdlib.h> // srand��rand����ʹ�õ�ͷ�ļ�
# include <time.h>  // time����ʹ�õ�ͷ�ļ�

void menu()
{
	printf("@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("*****   1  play   *****\n");
	printf("*****   0  exit   *****\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@@\n");
}

void game()
{
// ����һ��1��100�������
//	srand((unsigned int)time(NULL)); // ()��Ϊһ��������ÿ�������������һ�������Ҫ�ã��������������䣬����ʱ����ĸ���  
// �������������������Բ��Ǻ�������������������Ҫ����һ�Σ��ŵ�main��������
	int ret = rand() % 100 + 1; // rand����������һ��0��32767֮�����������������������ÿ����Ϸ�����ظ���˳�������
// ����������ڵ���rand֮ǰ����srand����ȥ���������������
// Ҫ������1��100���������������������������������100ȡģ���õ�0��99���ټ�1

// ������
	int guess = 0;
	while (1) // �ظ�ִ��
	{
		printf("�������");
		scanf("%d", &guess);
		if (guess < ret)
		{
			printf("���С��\n"); // ��С�˼�����
		}
		else if (guess > ret)
		{
			printf("��´���\n"); // �´��˼�����
		}
		else
		{
			printf("��ϲ��¶���\n");
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
		menu(); // ��ӡһ���򵥵Ĳ˵���ʾ����
		printf("��ѡ��");
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
			printf("�˳���Ϸ");
			break;
		   }
		default:
		   {
			printf("�����������������\n");
			break;
		   }
		}
	}while (input); // input�պÿ������㣬����0���棬��ѭ��������������ʱִ��ѭ��
	return 0;
}