#define _CRT_SECURE_NO_WARNINGS 1
#include<locale.h>
#include"sanke.h"
void test()
{
	int ch=0;
	do 
	{
		system("cls");
		//����̰����
		Sanke sanke = { 0 };
		//��ʼ��Ϸ
		gamestart(&sanke);
		//������Ϸ
		gamerun(&sanke);
		//��Ϸ����
		gameend(&sanke);
		setpos(20, 15);
		printf("�Ƿ�����һ��?(Y/N):");
		ch = getchar();
		while (getchar() != '\n');
	}while(ch !='Y'||'y');
	setpos(0, 27);
	
}
int main()
{
	//�������䱾�ػ���
	setlocale(LC_ALL, "");
	srand((unsigned int)time(NULL));
	test();
	return 0;
}