#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>
#define PHONE 20
#define SITE 20
struct preson
{
	char name[20];
	char sex[10];
	int age;
	char phone[PHONE];
	char addess[SITE];
};
void mune()
{
	printf("******************************\n");
	printf("******** 1.�����ϵ�� ********\n");
	printf("******** 2.ɾ����ϵ�� ********\n");
	printf("******** 3.�޸���ϵ�� ********\n");
	printf("******** 4.������ϵ�� ********\n");
	printf("******** 5.��ʾ��ϵ�� ********\n");
	printf("******** 0.�˳�ͨѶ¼ ********\n");
	printf("******************************\n");

}
void addlink(preson linkman[1000])
{

}

int main()
{
	preson linkman[1000] = { 0 };
	int a = 0;
	while (1)
	{
		mune();
		printf("plase chage:");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			addlink(linkman);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 0:
			break;
		default:
			system("cls");
			printf("��������ȷ�ĸ�ʽ\n");
			break;
		}
	}
	return 0;
}