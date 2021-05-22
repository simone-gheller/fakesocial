#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const size_t BUFFER = 2000;

typedef struct Entity
{
    char* id;

}Entity;

typedef struct Relationship
{
    Entity* giver;
    Entity* receiver;

}Relationship;


char* cmd_resolve(char* string){

    char* cmd = strtok(string, " ");
    printf("%s ",cmd);
    char* token1 = strtok(NULL, " ");
    printf("%s ",token1);

    if(strcmp(cmd, "addent")==0){
        
    }
    else if(strcmp(cmd, "addrel")==0){
        char* token2 = strtok(NULL, " ");
        printf("%s ",token2);
        char* token3 = strtok(NULL, " ");
        printf("%s ",token3);
        
    }
    else if(strcmp(cmd, "delent")==0){
        
    }
    else if(strcmp(cmd, "delrel")==0){
        char* token2 = strtok(NULL, " ");
        printf("%s ",token2);
        char* token3 = strtok(NULL, " ");
        printf("%s ",token3);
        
    }
    else if(strcmp(cmd, "report")==0){
        
    }
    else if(strcmp(cmd, "end")==0){

    }
    else{
        //wrong command format
    }
    printf("\n");
}


void cmd_reader() {

    char line[BUFFER];
    while(fgets(line,BUFFER,stdin)!=NULL){
        line[strlen(line)-1] = 0;
        cmd_resolve(line);
    }
}


int main(int argc, char const *argv[])
{
    cmd_reader();
    return 0;
}