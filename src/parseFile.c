#include "parseFile.h"

uint8_t parseInformationFile(void) {

    char *line;
    items_t items[MAX_ITEMS];
    uint8_t itemsCounter = 0;
    uint8_t status = 0;

    FILE* file = fopen("items.txt", "r");

    if (file == NULL) {
        return 1;
    }

    while (fgets(line, MAX_STRING, file) != NULL && status == 0) {
        status = separateItems(line, MAX_STRING, &items[itemsCounter]);
        itemsCounter++;
    }

}

uint8_t separateItems(char* itemsLine, uint8_t itemsLineSize, items_t* items) {
    char* token = NULL;
    uint8_t attributesCounter = 0;

    token = strtok(itemsLine, ";");
    while (token != NULL && attributesCounter <= NUMBER_ATTRIBUTES) {
        attributesCounter++;

        switch (attributesCounter) {
            case ORDER_NAME:
                if (strcpy(items->name, token) == NULL) {
                    printf("ERROR PARSING NAME OF ITEM");
                    return 1;
                }
                break;
            case ORDER_UNITS:
                items->units = (int)token;
                break;
            case ORDER_UNITPRICE:
                items->unitPrice = (int)token;
                break;
            case ORDER_TOTALPRICE:
                items->totalPrice = (int)token;
                break;
            default:
                printf("ERROR PARSING ITEM");
                return 1;
        }
    }

    return 0;

}