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
    while (token != NULL) {
        attributesCounter++;

        switch (attributesCounter) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                return 1;
        }
    }

}