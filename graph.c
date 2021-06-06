#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.c"

const size_t ROWS = 500;
const size_t COLUMNS = 500;


_Bool** crt_matrix(){
    _Bool** matrix = (_Bool**)malloc(sizeof(_Bool*)*ROWS);
    for(int i=0;i<ROWS;i++){
        matrix[i] = (_Bool*)malloc(sizeof(_Bool)*COLUMNS);
        for(int j=0;j<COLUMNS;j++){
            matrix[i][j] = 0;
        }
    }

    return matrix;
}

int getIdFromHash(Hashtable* t, char* entity){
    Entity* ent = search(t,entity);
    if(ent != NULL)
        return ent->id;
    return -1;
}

void addrel(Hashtable* t, _Bool** matrix, char* receiver, char* giver){
    int rec_id = getIdFromHash(t,receiver);
    int giv_id = getIdFromHash(t, giver);
    if(rec_id != -1 && giv_id != -1)
        matrix[rec_id][giv_id] = 1;
}


void delrel(Hashtable t*, _Bool** matrix, char* receiver, char* giver){
    int rec_id = getIdFromHash(t,receiver);
    int giv_id = getIdFromHash(t, giver);
    if(rec_id != -1 && giv_id != -1)
        matrix[rec_id][giv_id] = 0;
}

void del_entity(Hashtable t*, _Bool** matrix, char* entity ){
    int id = getIdFromHash(t, entity);
    for(int i=0;i<COLUMNS;i++){
        matrix[id][i] = 0;
    }
    for(int i=0;i<ROWS;i++){
        matrix[i][id] = 0;
    }
    delete(t,entity)
}


void report(_Bool* matrix){
    int max=0;
    for(int i=0;i<ROWS){
        int counter=0
        for(int j=0;j<COLUMNS;j++){
            counter++;
        }
        if(counter>max){
            max=counter;
        }
    }
    printf("%d",max);
}