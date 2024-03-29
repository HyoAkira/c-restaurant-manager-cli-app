#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MENU_ITEM {
    char name[30];
    int price;
};

typedef struct MENU_ITEM item;

struct Table {
    char name[30];
    item *items;
    int price;
    int itemCount;
};

typedef struct Table Table;

int main() {
    Table table1;
    strcpy(table1.name, "masa1");
    table1.price = 300;
    table1.itemCount = 2;
    table1.items = (item *)malloc(sizeof(item) * table1.itemCount);

    table1.items[0] = (item){"ahem", 150};
    table1.items[1] = (item){"ahem2", 350};

    // Access and print the items for verification
    for (int i = 0; i < table1.itemCount; i++) {
        printf("Item %d: Name: %s, Price: %d\n", i+1, table1.items[i].name, table1.items[i].price);
    }

    // Don't forget to free the dynamically allocated memory
    free(table1.items);

    return 0;
}