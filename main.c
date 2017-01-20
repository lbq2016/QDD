#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "system.h"


int main()
{
	//获取数据
	printf("\n获取数据-ING!\n");
    get_bill_data();
    get_custom_data();
    get_cost_data();
    get_rate_data();
	printf("获取数据完成!\n");

	//处理数据
	printf("\n处理数据-ING!\n");
	data_analysis();
	printf("处理数据完成!\n");

	//保存数据
    report_forms();
	printf("\n保存数据-ING!\n");
	printf("保存数据完成!\n");

	return 0;
}
