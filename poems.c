#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
static char line[MAX_LINE_LENGTH];
static FILE *file = NULL;
/**
  *This function loads the file poems.txt for later use
  *
  */

void listPoems(){
    int findEnd = 0;

    while(fgets(line,MAX_LINE_LENGTH,file) != NULL){
        if(!findEnd && strncmp(line,"\n",1) != 0){
	  printf("%s",line);
          findEnd = 1;  
        }
        else if(strncmp(line,"end",strlen("end")) == 0){
           findEnd = 0;
        }
    }

}

void loadPoems(){
    
    file = fopen("poems.txt","r+");
    
    //Did we get the file pointer?
    if(NULL == file){
        //No print error message and return
        printf("Failed to open file poems.txt for reading.\n");
        return;
    }
    
    
}

void printPoem(char * poem_name){
    int found = 0;
    
    while(fgets(line,MAX_LINE_LENGTH,file) != NULL){

        if(strncmp(line,poem_name,strlen(poem_name)) == 0){
            //printf("%s",line);
            found = 1;
        }
        
        if(found == 1){
            if(strncmp(line,"end",strlen("end")) == 0){
                break;
            }
            printf("%s",line);
        }
      
    }
 
}

void savePoem(char * poem_name, char * poem){
    int end = 1;
    // FILE *outPutFile = NULL;
    //char inputStr[100];

    if (file){
       fclose(file);
    }

    file = fopen("poems.txt","a+");
    fputs("\n", file);
    fputs(poem_name, file);
    fputs("\n\n", file);
    fputs(poem, file);
    fputs("\n\n", file);
    fputs("end", file);
 
#if 0   
    do{
        printf("Write poem. Stop with #!");
        scanf("%s",inputStr);
	if(inputStr[0] == "#")
        {
            end = 1;
        }
        else
           {
           fputs(inputStr, file);
           }
	
    }while(end);

    fputs("\n", file);
    fputs("end", file);
#endif
#if 0
    while(fgets(line,MAX_LINE_LENGTH,file) != NULL){

        if(strncmp(line,poem_name,strlen(poem_name)) == 0){
	    //char *fileName = malloc(strlen(poem_name)+4);
            //printf("%s",line);
            found = 1;
            outPutFile = fopen("poem.txt","w+");
        }
        
        if(found == 1){
            if(strncmp(line,"end",strlen("end")) == 0){
                break;
            }
            fputs(line, outPutFile);
            printf("%s",line);
        }
      
    }
#endif
    fclose(file);
 
}
