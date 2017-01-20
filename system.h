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

//浮点数比较
#define EPS_1          ((float)0.000001)

#define A_GRB_B(a,b)   ((a>b) && (fabs(a-b) > EPS_1))
#define A_LES_B(a,b)   ((a<b) && (fabs(a-b) > EPS_1))
#define A_EQU_B(a,b)   (fabs(a-b) <= EPS_1)

#define IS_JZHW(a)      ((strstr(a, "江苏") != NULL) || (strstr(a, "浙江") != NULL) || (strstr(a, "上海") != NULL) || (strstr(a, "安徽") != NULL))
#define IS_NotJZHW(a)   ((strstr(a, "江苏") == NULL) && (strstr(a, "浙江") == NULL) && (strstr(a, "上海") == NULL) && (strstr(a, "安徽") == NULL))


//--------------------------------------------------
//==运单.txt
//运单编号	
//扫描类型	
//上一站或下一站	
//目的地点	
//重量
//客户标志
typedef struct BILL_DATA {
    char   id[20];      //运单编号  
    char   type[20];    //扫描类型
    char   name[24];    //站点名称  
    char   province[24];//目的省份  
    float  weight;      //重量  
    int    flag;
    
    //==========================================================
	//以下是数据处理后额外增加的字段：
    float  fee1;        //中转费
    float  fee2;        //应付派费
    float  fee3;        //大包费  
    float  fee4;        //保险费
    float  fee5;        //称重费
    float  fee6;        //大货费
    float  fee7;        //面单
    float  total;       //汇总，分办事处和客户两种方式
}BILL_DATA;
BILL_DATA bill_data[BILL_DATA_MAX];


//--------------------------------------------------
//==称重.txt
typedef struct CUSTOM_DATA {
    char   name[24];    //名称  
    float  price;       //价格
}CUSTOM_DATA;
CUSTOM_DATA custom_data[CUSTOM_DATA_MAX];

//--------------------------------------------------
//==成本.txt
typedef struct COST_DATA {
    char    name[24];   //名称  
    char    id[20];     //运单标识
    float   price;      //价格
}COST_DATA;
COST_DATA cost_data[COST_DATA_MAX];

//--------------------------------------------------
//==费率.txt
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
