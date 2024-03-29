#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

int main(int argc, char *argv[]) {
    FILE *menuFile = fopen("menu.h1m", "r+b");
    FILE *tableFile = fopen("tables.h1m", "r+b");

    if (menuFile == NULL) {
        menuFile = fopen("menu.h1m", "wb");
    }
    if (tableFile == NULL) {
        tableFile = fopen("tables.h1m", "wb");
    }

    if (argc < 2) {
      anaMenu:
        while (1) {
            system("clear");
            printf("-----------\n");
            printf("1- add item\n");
            printf("2- delete item\n");
            printf("3- edit menu\n");
            printf("4- read menu\n");
            printf("5- create table\n");
            printf("6- delete table\n");
            printf("7- list tables\n");
            char key;
            printf("Select input: ");
            scanf(" %c", &key);
            if (key == 'q') {
                break;
            }
            int x = atoi(&key);
            system("clear");
            switch (x) {
                case 1: {
                    goto addItem;
                    break;
                }
                case 2: {
                    goto deleteItem;
                    break;
                }
                case 3: {
                    goto editMenu;
                    break;
                }
                case 4: {
                    goto readMenu;
                    break;
                }
                case 5: {
                    goto createTable;
                    break;
                }
                case 6: {
                    goto deleteTable;
                    break;
                }
                case 7: {
                    goto listTables;
                    break;
                }
            }
        }
        return 0;
    }

    /**
     * MENU OPERATIONS
     */

    if (!(strcmp("read", argv[1])) && !(strcmp("menu", argv[2]))) {
    readMenu:
        item menuItem;
        writeMenu(menuItem, menuFile);
        fclose(menuFile);
        return 0;
    }

    if (!(strcmp("edit", argv[1])) && !(strcmp("menu", argv[2]))) {
    editMenu:
        item menuItem;
        writeMenu(menuItem, menuFile);

        int itemNumber;
        printf("item number to edit: ");
        scanf("%d", &itemNumber);
        fseek(menuFile, sizeof(item) * (itemNumber - 1), SEEK_SET);
        char name[30];
        int price;
        printf("item name: ");
        scanf(" %[^\n]", name);
        printf("item price: ");
        scanf("%d", &price);
        menuItem = (item){"", price};
        sprintf(menuItem.name, "%s", name);
        fwrite(&menuItem, sizeof(item), 1, menuFile);
        fclose(menuFile);
        fseek(tableFile, 0, SEEK_SET);
        fseek(menuFile, 0, SEEK_SET);
        return 0;
    }

    if (!(strcmp("delete", argv[1])) && !(strcmp("item", argv[2]))) {
    deleteItem:
        item menuItem;
        writeMenu(menuItem, menuFile);
        printf("Select item to delete: ");
        int x;
        scanf(" %d", &x);

        FILE *gecici = fopen("cnckwqe.dat", "wb");
        if (gecici == NULL) {
            return 1;
        }

        item buffer;
        int i = 0;
        rewind(menuFile);

        while (fread(&buffer, sizeof(item), 1, menuFile)) {
            if (i != (x - 1)) {
                fwrite(&buffer, sizeof(item), 1, gecici);
            }
            i++;
        }

        fclose(gecici);
        fclose(menuFile);

        if (remove("menu.h1m") != 0) {
            return 1;
        }

        if (rename("cnckwqe.dat", "menu.h1m") != 0) {
            return 1;
        }

        menuFile = fopen("menu.h1m", "r+b");
        if (menuFile == NULL) {
            return 1;
        }
    }

    if (!(strcmp("delete", argv[1])) && !(strcmp("table", argv[2]))) {
    deleteTable:
        Table selTable;
        writeTable(selTable, tableFile);
        printf("Select table to delete: ");
        int x;
        scanf(" %d", &x);
        if (x == 'q') {
            return 0;
        }

        FILE *gecici = fopen("cnckwqe.dat", "wb");
        if (gecici == NULL) {
            return 1;
        }

        int i = 0;
        rewind(tableFile);
        Table buffer;
        while (fread(&buffer, sizeof(Table), 1, tableFile)) {
            if (i != (x - 1)) {
                fwrite(&buffer, sizeof(Table), 1, gecici);
            }
            i++;
        }

        fclose(gecici);
        fclose(tableFile);

        if (remove("tables.h1m") != 0) {
            return 1;
        }

        if (rename("cnckwqe.dat", "tables.h1m") != 0) {
            return 1;
        }

        tableFile = fopen("tables.h1m", "r+b"); // Yeniden aç
        if (tableFile == NULL) {
            return 1;
        }
    }

    if (!(strcmp("add", argv[1])) && !(strcmp("item", argv[2]))) {
    addItem:
        fseek(menuFile, 0, SEEK_END);
        char name[30];
        int price;

        printf("item name: ");
        scanf(" %[^\n]", name);
        printf("item price: ");
        scanf("%d", &price);
        item menuItem = (item){"", price};
        sprintf(menuItem.name, "%s", name);
        fwrite(&menuItem, sizeof(item), 1, menuFile);
        fclose(menuFile);

        return 0;
    }

    /**
     * TABLE OPERATIONS
     */

    if (!(strcmp("create", argv[1])) && !(strcmp("table", argv[2]))) {
    createTable:
        int itemCount = 0;
        int y = 0;
        Table table;
        table.price = 0;
        table.itemCount = 0;
      
        if (table.items == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        fseek(tableFile, 0, SEEK_END);
        printf("table name: ");
        scanf(" %[^\n]", table.name);
        system("clear");
        printf("table name: %s\n", table.name);

        item menuItem;
        writeMenu(menuItem, menuFile);

        while (1) {
            char key[150000];
            scanf("%s", key);
            if (!(strcmp("q", key))) {
                break;
            }

            int x = atoi(key);
            item fItem = findItem(x, menuFile);
            table.items[table.itemCount] = fItem;
            table.itemCount++;
            fseek(menuFile, sizeof(item) * (x - 1), SEEK_SET);
            fread(&menuItem, sizeof(item), 1, menuFile);
            y += menuItem.price;
            table.price = y;
        }

        fwrite(&table, sizeof(Table), 1, tableFile);
        fclose(menuFile);
        fclose(tableFile);
        printf("Price: %d\n",table.price);    
        return 0;
    }

    if (!(strcmp("list", argv[1])) && !(strcmp("tables", argv[2]))) {
    listTables:
        system("clear");
        fseek(tableFile, 0, SEEK_END);
        int tableLen = ftell(tableFile) / sizeof(Table);
        fseek(tableFile, 0, SEEK_SET);

        Table bufferTable;
        printf("Tables:\n");
        for (int i = 0; i < tableLen; i++) {
            fread(&bufferTable, sizeof(Table), 1, tableFile);
            printf("%d - %s\n", i + 1, bufferTable.name);
        }

        char key;
        printf("\nSelect a table (q to quit): ");
        while (1) {
            scanf(" %c", &key);
            if (key == 'q') {
                break;
            }
            int x = atoi(&key);
            system("clear");

            Table selTable;
            fseek(tableFile, sizeof(Table) * (x - 1), SEEK_SET);
            fread(&selTable, sizeof(Table), 1, tableFile);
            printf("Table Name: %s\n", selTable.name);
            printf("Price: %d\n\n", selTable.price);
            printf("RECEIPT\n");
            for (int i = 0; i < selTable.itemCount; i++) {
                printf("%d: Name: %s, Price: %d\n", i + 1, selTable.items[i].name, selTable.items[i].price);
            }
        }

        fclose(tableFile);
        return 0;
    }

    return 0;
}
