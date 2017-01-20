#ifndef   _SYSTEM_H
#define   _SYSTEM_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define BILL_DATA_MAX       1000000
#define CUSTOM_DATA_MAX     10000
#define RATE_DATA_MAX       10000
#define COST_DATA_MAX       10000  

typedef enum tagDATA_TYPE
{
    DATA_TYPE_MIN     = 0x00,
    DATA_TYPE_BILL    = 0x01,
    DATA_TYPE_CUSTOM  = 0x02,
    DATA_TYPE_COST    = 0x03,
    DATA_TYPE_RATE    = 0x04,
    DATA_TYPE_MAX     = 0x05
}QDD_DATA_TYPE;


#define NOTETYPE_NULL       0
#define NOTETYPE_TMALL      1
#define NOTETYPE_WITHHOLD   2
#define NOTETYPE_CC         3
#define NOTETYPE_HB         4
#define NOTETYPE_CUSTOM     5
#define NOTETYPE_JHS        6
#define NOTETYPE_FREIGHT    7
#define NOTETYPE_TMALL_BZJ  8


#define ISNOTEND(a)    ((a != '\0') && (a != '\t') && (a != '\r') && (a != '\n'))
#define ISEND(a)       ((a == '\0') || (a == '\t') || (a == '\r') || (a == '\n'))
#define ISTAB(a)       (a == '\t')
#define ISNULL(a)      (a == NULL)
#define ISNOTNULL(a)   (a != NULL)

//�������Ƚ�
#define EPS_1          ((float)0.000001)

#define A_GRB_B(a,b)   ((a>b) && (fabs(a-b) > EPS_1))
#define A_LES_B(a,b)   ((a<b) && (fabs(a-b) > EPS_1))
#define A_EQU_B(a,b)   (fabs(a-b) <= EPS_1)

#define IS_JZHW(a)      ((strstr(a, "����") != NULL) || (strstr(a, "�㽭") != NULL) || (strstr(a, "�Ϻ�") != NULL) || (strstr(a, "����") != NULL))
#define IS_NotJZHW(a)   ((strstr(a, "����") == NULL) && (strstr(a, "�㽭") == NULL) && (strstr(a, "�Ϻ�") == NULL) && (strstr(a, "����") == NULL))


//--------------------------------------------------
//==�˵�.txt
//�˵����	
//ɨ������	
//��һվ����һվ	
//Ŀ�ĵص�	
//����
//�ͻ���־
typedef struct BILL_DATA {
    char   id[20];      //�˵����  
    char   type[20];    //ɨ������
    char   name[24];    //վ������  
    char   province[24];//Ŀ��ʡ��  
    float  weight;      //����  
    int    flag;
    
    //==========================================================
	//���������ݴ����������ӵ��ֶΣ�
    float  fee1;        //��ת��
    float  fee2;        //Ӧ���ɷ�
    float  fee3;        //�����  
    float  fee4;        //���շ�
    float  fee5;        //���ط�
    float  fee6;        //�����
    float  fee7;        //�浥
    float  total;       //���ܣ��ְ��´��Ϳͻ����ַ�ʽ
}BILL_DATA;
BILL_DATA bill_data[BILL_DATA_MAX];


//--------------------------------------------------
//==����.txt
typedef struct CUSTOM_DATA {
    char   name[24];    //����  
    float  price;       //�۸�
}CUSTOM_DATA;
CUSTOM_DATA custom_data[CUSTOM_DATA_MAX];

//--------------------------------------------------
//==�ɱ�.txt
typedef struct COST_DATA {
    char    name[24];   //����  
    char    id[20];     //�˵���ʶ
    float   price;      //�۸�
}COST_DATA;
COST_DATA cost_data[COST_DATA_MAX];

//--------------------------------------------------
//==����.txt
typedef struct RATE_DATA {
    char    province[24];
    float   price1;
    float   price2;
    float   price3;
}RATE_DATA;
RATE_DATA rate_data[RATE_DATA_MAX];



//--------------------------------------------------

void get_bill_data();
void get_custom_data();
void get_cost_data();
void get_rate_data();

void data_analysis();
void report_forms();


#endif
