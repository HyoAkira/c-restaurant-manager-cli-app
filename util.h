#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct MENU_ITEM {
    char name[30];
    int price;
};

typedef struct MENU_ITEM item;

  struct Table
  {
    char name[30];
    item items[100];
    int price;
    int itemCount;
  };
  typedef struct Table Table;

void writeMenu(item menuItem,FILE *menuFile){
  fseek(menuFile,0,SEEK_SET);
  fprintf(stdout,"%-30s %-5s %05s\n","NAME","|","PRICE");
printf("----------------------------------------------\n");
while(fread(&menuItem,sizeof(item),1,menuFile)){
static int number=0;
fprintf(stdout,"%2d.%-30s %-5s %05d$\n",++number,menuItem.name,"-",menuItem.price);
}
}


void writeTable(Table table,FILE *tableFile){
  fseek(tableFile,0,SEEK_SET);
  fprintf(stdout,"%-30s %-5s %05s\n","NAME","|","PRICE");
printf("----------------------------------------------\n");
while(fread(&table,sizeof(Table),1,tableFile)){
static int number=0;
fprintf(stdout,"%2d.%-30s %-5s %05d$\n",++number,table.name,"-",table.price);
}
};


item findItem(int id,FILE *menuFile){
  fseek(menuFile,sizeof(item)*(id-1),SEEK_SET);
  item buffer;
  fread(&buffer,sizeof(item),1,menuFile);
  return buffer;
  
}