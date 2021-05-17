#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Entity
{
    char* id;

}Entity;

typedef struct Relationship
{
    Entity* giver;
    Entity* receiver;

}Relationship;


char* cmd_crop(char* string){

    char* cmd = (char *) malloc(sizeof(char) * 10);
    strncpy(cmd,"deafult",10);
    int i=0;
    while(string[i] != ' ') {
        i++;
    }
    strncpy(cmd, string, i);
    cmd[i] = 0;

    return cmd;
}


void cmd_dispatcher(char* cmd) {

    char line[] = "default";

    while(scanf("%s",line));
}


int main(int argc, char const *argv[])
{
    char test[] = "string test charachtaer";
    char* result = cmd_crop(test);
    printf("%s\n",result);
    return 0;
}