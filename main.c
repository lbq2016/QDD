#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "system.h"


int main()
{
	//��ȡ����
	printf("\n��ȡ����-ING!\n");
    get_bill_data();
    get_custom_data();
    get_cost_data();
    get_rate_data();
	printf("��ȡ�������!\n");

	//��������
	printf("\n��������-ING!\n");
	data_analysis();
	printf("�����������!\n");

	//��������
    report_forms();
	printf("\n��������-ING!\n");
	printf("�����������!\n");

	return 0;
}
