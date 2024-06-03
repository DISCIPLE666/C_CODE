#define _CRT_SECURE_NO_WARNINGS 1
#include"БъЭЗ.h"
int main()
{
	sl*plist=NULL;
	slpushfront(&plist, 1);
	slpushback(plist, 2);
	//sltpopback(&plist);
	//sltpopfront(&plist);
	/*sl*find=sltfind(plist, 1);
	slteraseafter(find);*/
	sltprint(plist);
	return 0;
}