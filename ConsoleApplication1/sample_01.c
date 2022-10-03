#include <stdio.h>
int main()
{
	int 点数;//変数
	if (scanf_s("%d", &点数) == 1) {
		//入力成功
		/**/ if (90 <= 点数) printf("秀\n");
		else if (80 <= 点数) printf("優  , あと%d点で秀\n", 90 - 点数);
		else if (70 <= 点数) printf("良  , あと%d点で優\n", 80 - 点数);
		else if (60 <= 点数) printf("可  , あと%d点で良\n", 70 - 点数);
		else                 printf("不可, あと%d点で可\n", 60 - 点数);
	}
}
