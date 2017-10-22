#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#include "TESTMessageHandle.h"

int main()
{
	CManager* manger = new CManager;
	manger->start();

	while (true)
	{
		char c;
		scanf("%c", &c);

		if (c == 'q' || c == 'Q'){
			break;
		}
	}

QUIT:
	if (manger){
		delete manger;
	}

	system("pause");
	return 0;
}