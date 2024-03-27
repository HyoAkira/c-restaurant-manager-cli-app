#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"



int main(int argc, char *argv[]) {
FILE *menuFile = fopen("menu.h1m","r+b");
FILE *tableFile = fopen("tables.h1m","r+b");

/**
 * arg check
*/
if(argc<2){

while(1){
  system("clear");
printf("parameter error!\n");
printf("-----------\n");
printf("1- add item\n");
printf("2- edit menu\n");
printf("3- read menu\n");
printf("4- create table\n");
  char key;
  printf("Select input: ");
  scanf("%c",&key);
if(key=='q'){
  break;
}
  int x = atoi(&key);
  switch(key){
    case 1:{

      break;
    }
    case 2:{
      break;
    }
    case 3:{
      break;
    }
    case 4:{
      break;
    }
  }
}

return 0;
}

/**
 * MENU OPERATIONS
*/

if(!(strcmp("read",argv[1])) && !(strcmp("menu",argv[2]))){
item menuItem;
writeMenu(menuItem,menuFile);
fclose(menuFile);
return 0;
}

if(!(strcmp("edit",argv[1])) && !(strcmp("menu",argv[2]))){

item menuItem;
writeMenu(menuItem,menuFile);

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
fclose(menuFile);
return 0;
}

if(!(strcmp("add",argv[1])) && !(strcmp("item",argv[2]))){
 fseek(menuFile,0,SEEK_END);
char name[30];
int price;

printf("item name: ");
scanf(" %[^\n]",name);
printf("item price: ");
scanf("%d",&price);
item menuItem = {"",price};
sprintf(menuItem.name,name);
fwrite(&menuItem,sizeof(item),1,menuFile);
fclose(menuFile);
return 0;
}

/**
 * TABLE OPERATIONS
*/
struct Table{
char name[30];
int items[100];
int price;
}table;
 int itemCount =0;
 table.price=0;
 int y =0;
if(!(strcmp("create",argv[1])) && !(strcmp("table",argv[2]))){
fseek(tableFile,0,SEEK_END);
printf("table name: ");
scanf(" %[^\n]",table.name);
system("clear");
printf("table name: %s\n", table.name);

item menuItem;
writeMenu(menuItem,menuFile);
 

while(1){
char key[150000];
scanf("%s",key);
if(!(strcmp("q",key))){
  break;
}
   
  int x = atoi(key);

table.items[itemCount] = x;
itemCount++;
  fseek(menuFile,sizeof(item)*(x-1),SEEK_SET);
fread(&menuItem,sizeof(item),1,menuFile);
y+=menuItem.price;
table.price=y;

}


fclose(menuFile);
printf("%s price: %d\n",table.name,table.price);
return 0;
}


    return 0;
}
