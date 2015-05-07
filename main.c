#include <stdio.h>
int main(int argc, char *argv[]){

    //Check the number of command line arguments should be 2
    if(argc < 3){
        printf("Usage of application is: app.exe -switch\n");
        printf("Switches are:\n");
        printf("-p name_of_poem : This will load the poem with the given name for you\n");
        printf("-l list :all poems in application.\n");
	printf("-s name_of_poem : This will load the poem with the given name. Stop writig with esc.\n");
        return 0;
    }
    
    loadPoems();
    
    if(strcmp(argv[1],"-p") == 0){
        if(3 > argc){
            printf("The name of the poem must be also given!\n");
            return 0;
        }
        else{
            printPoem(argv[2]);
        }
    }
    else if(strcmp(argv[1],"-l") == 0){
        printf("List all poems\n");
        listPoems();
    }
    else if(strcmp(argv[1],"-s") == 0){
        if(3 > argc){
            printf("The name of the poem must be also given!\n");
            return 0;
        }
        else{
            savePoem(argv[2], argv[3]);
        }
    }
    else{
        printf("No such switch in this application\n");
    }
    
    return 0;
}
