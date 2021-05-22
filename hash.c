#include <stdlib.h>
#include <stdio.h>
#include <string.h>


const size_t CAPACITY = 5000;

typedef struct Entity{
    int id;
    char* name;
}Entity;

typedef struct Hashtable{
    Entity* entities;
    int auto_increment;
}Hashtable;


Hashtable crt_hst(){
    Hashtable hst = (Hashtable*)malloc(sizeof(Hashtable));
    hst->auto_increment = 0;
    hst->entities = (Entity*)malloc(sizeof(Entity)*CAPACITY);
    return hst;
}

void dsry_hst(Hashtable* t){
    for(int i=0;i<CAPACITY;i++){
        if(t->entities[i].name != NULL){
            free(t->entities[i].name);
        }
    }
    free(t->entities);
    free(t);
    t = NULL;
}

void resize_hst(Hashtable* hst){
    realloc(hst->entities, sizeof(Entity)*hst->auto_increment*2);
}

int hash1(char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    hash = hash%CAPACITY;
    return hash;
}

int hash2(char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    hash = hash%CAPACITY;
    return hash;
}

Entity* search(Hashtable* t,char* entity_name){
    int index=hash1(new_entity);
    while(t->entities[index]!=NULL && strcmp(t->entities[index].name,entity_name)!=0 && index<CAPACITY){
        index=hash2();
    }
    if(index<CAPACITY)
        return t->entities[index];
}

void insert(Hashtable* t, char* new_entity){
    if(search(t,new_entity)!=NULL)
        return;
    int index=hash1(new_entity);
    while(t->entities[index]!=NULL && index<CAPACITY){
        index=hash2();
    }
    if(index<CAPACITY){
        Entity* ent = (Entity*)malloc(sizeof(Entity));
        ent->name=new_entity;
        ent->id=t->auto_increment;
        t->entities[index]=ent;
        t->auto_increment++;
    }
}

void delete(Hashtable* t, char* del_entity){
    Entity* del = search(t,del_entity);
    if(del!=NULL){
        del->id=-1;
        free(del->name);
        del->name=NULL;
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}