#include <stdlib.h>
#include <stdio.h>
#include <string.h>


const size_t CAPACITY = 5000;

typedef struct Entity{
    int id;
    char* name;
}Entity;

typedef struct Hashtable{
    Entity** entities;
    int auto_increment;
    char* DELETED;
}Hashtable;


Hashtable* crt_hst(){
    Hashtable* hst = (Hashtable*)malloc(sizeof(Hashtable));
    hst->auto_increment = 0;
    hst->entities = (Entity**)malloc(sizeof(Entity*)*CAPACITY);
    for(int i=0;i<CAPACITY;i++)
        hst->entities[i]=NULL;
    hst->DELETED = (char*)malloc(sizeof(char)*10);
    strncpy(hst->DELETED,"@DELETED",10);
    return hst;
}

void dsry_hst(Hashtable* t){
    for(int i=0;i<CAPACITY;i++){
        if(t->entities[i] != NULL){
            free(t->entities[i]);
        }
    }
    free(t->entities);
    free(t->DELETED);
    free(t);
    t = NULL;
}

void resize_hst(Hashtable* hst){
    hst->entities = realloc(hst->entities, sizeof(Entity*)*hst->auto_increment*2);
}

int hash1(char *str){
    unsigned long hash = 7687;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    hash = hash%CAPACITY;
    return hash;
}

int hash2(char *str){
    unsigned long hash = 7687;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    hash = hash%(CAPACITY-1);
    return hash+1;
}

int double_hash(char* key, int i){
    int index = (hash1(key)+hash2(key)*i)%CAPACITY;
    return index;
}

Entity* search(Hashtable* t,char* entity_name){
    int i=0;
    int j=double_hash(entity_name,0);
    while(t->entities[j]!=NULL && i<CAPACITY){
        if(strcmp(t->entities[j]->name,entity_name)==0)
            return t->entities[j];
        i++;
        j=double_hash(entity_name,i);
    }
    return NULL;
}

void insert(Hashtable* t, char* new_entity){
    if(search(t,new_entity)!=NULL)
        return;
    int j,i=0;
    while(i<CAPACITY){
        j = double_hash(new_entity,i);
        if(t->entities[j]==NULL){
            Entity* ent = (Entity*)malloc(sizeof(Entity));
            ent->name=new_entity;
            ent->id=t->auto_increment;
            t->entities[j]=ent;
            t->auto_increment++;
            return;
        }
        else{
            i++;
            return;
        }
    }
}

void delete(Hashtable* t, char* del_entity){
    Entity* del = search(t,del_entity);
    if(del!=NULL){
        del->id=-1;
        del->name=t->DELETED;

    }
}

void resolve(Hashtable* t, char* line){
    char* cmd = strtok(line, " ");
    printf("%s ",cmd);
    char* token1 = strtok(NULL, " ");
    printf("%s\n",token1);
    if(strcmp(cmd, "addent")==0){
        insert(t,token1);
    }
    else{
        delete(t,token1);
    }
}

void hst_print(Hashtable* t ){
    int count=0;
    for(int i=0;i<CAPACITY;i++){
        if(t->entities[i]!=NULL){
            printf("%s : %d\n",t->entities[i]->name,count);
            count++;
        }
    }
}

void test(){
    const size_t BUFFER = 500;
    Hashtable* t = crt_hst();
    char line[BUFFER];
    while(fgets(line,BUFFER,stdin)!=NULL){
        line[strlen(line)-1] = 0;
        char* string = (char*)malloc(sizeof(char)*(strlen(line)+1));
        printf("%p : %p\n",line,string);
        strcpy(string,line);
        printf("%s\n",string);
        resolve(t,string);
    }
    hst_print(t);
    dsry_hst(t);
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}