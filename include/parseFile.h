#include "stdio.h"
#include "stdint.h"
#include "string.h"

#define MAX_STRING          255
#define MAX_ITEMS           200
#define NUMBER_ATTRIBUTES   4
#define ORDER_NAME          1
#define ORDER_UNITS         2
#define ORDER_UNITPRICE     3
#define ORDER_TOTALPRICE    4



typedef struct items {
    char name[MAX_STRING];
    int units;
    int unitPrice;
    int totalPrice;
} items_t;

/* return 0 ok, 1 error
*/
uint8_t parseInformationFile(void);

/*
*   Items will come in txt file separated by ';'
*   NameProduct;Units;unitPrice;totalPrice
*   return 0 ok, 1 error
*
*/
uint8_t separateItems(char* itemsLine, uint8_t itemsLineSize, items_t* items);