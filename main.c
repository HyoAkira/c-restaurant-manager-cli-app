#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MENU_ITEM {
    char name[30];
    int price;
};

typedef struct MENU_ITEM item;
int main(int argc, char *argv[]) {


if(!(strcmp("read",argv[1])) && !(strcmp("menu",argv[2]))){

FILE *menuFile = fopen("menu.h1m","rb");
item menuItem;
fprintf(stdout,"%-30s %-5s %05s\n","NAME","|","PRICE");
printf("----------------------------------------------\n");
while(fread(&menuItem,sizeof(item),1,menuFile)){
static int number=0;
fprintf(stdout,"%2d.%-30s %-5s %05d$\n",++number,menuItem.name,"-",menuItem.price);
}

return 0;
}

if(!(strcmp("edit",argv[1])) && !(strcmp("menu",argv[2]))){

FILE *menuFile = fopen("menu.h1m","r+b");
item menuItem;
fprintf(stdout,"%-30s %-5s %05s\n","NAME","|","PRICE");
printf("----------------------------------------------\n");
while(fread(&menuItem,sizeof(item),1,menuFile)){
static int number=0;
fprintf(stdout,"%2d.%-30s %-5s %05d$\n",++number,menuItem.name,"-",menuItem.price);
}

int itemNumber;
printf("item number to edit: ");
scanf("%d",&itemNumber);
fseek(menuFile,sizeof(item)*(itemNumber-1),SEEK_SET);
char name[30];
int price;
printf("item name: ");
scanf(" %[^\n]",name);
printf("item price: ");
scanf("%d",&price);
 menuItem =(item) {"",price};
sprintf(menuItem.name,name);
fwrite(&menuItem,sizeof(item),1,menuFile);
return 0;
}

if(!(strcmp("add",argv[1])) && !(strcmp("item",argv[2]))){
FILE *menuFile = fopen("menu.h1m","ab");
char name[30];
int price;
printf("item name: ");
scanf(" %[^\n]",name);
printf("item price: ");
scanf("%d",&price);
item menuItem = {"",price};
sprintf(menuItem.name,name);
fwrite(&menuItem,sizeof(item),1,menuFile);
return 0;
}

    return 0;
}
