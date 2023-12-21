#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256 
#define TABLE_SIZE 10 
#define DELETED_NODE (person*)(0xFFFFFFFFFFFFFFFFUL)

typedef struct person
{
    char name[MAX_NAME];
    int age;
}person;

person * hash_table[TABLE_SIZE];

unsigned int hash(char *name)
{
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for(int i=0; i < length ; i++)
    {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void init_hash_table()
{
    for(int i=0; i<TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
}

void print_table()
{
    printf("Start\n");
    for(int i = 0; i< TABLE_SIZE; i++)
    {
        if(hash_table[i] == NULL)
        {
            printf("\t%i\t---\n",i);
        }else if (hash_table[i] == DELETED_NODE){
            printf("\t%i\t---<deleted>\n",i);
        }else{
            printf("\t%i\t%s\n",i,hash_table[i]->name);
        }
    }
    printf("End\n");
}

bool hash_table_insert(person *p)
{
    if (p==NULL) return false;
    int index = hash(p->name);
    for(int i=0; i< TABLE_SIZE; i++)
    {
        int try = (i+ index) % TABLE_SIZE;
        if(hash_table[try] == NULL || 
           hash_table[try] == DELETED_NODE)
        {
            hash_table[try] = p;
            return true;
        }
    }
    return false;
}

person *hash_table_lookup(char *name)
{
    int index = hash(name);
    for(int i=0; i< TABLE_SIZE; i++)
    {
        int try = (i+ index) % TABLE_SIZE;
        if (hash_table[try] == NULL)
        {
            return false;
        }
        if(hash_table[try] == DELETED_NODE) continue;
        if(hash_table[try] == NULL &&
           strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0)
        {
            return hash_table[try];
        }
    }
    return NULL;
}

person *hash_table_delete(char *name)
{
    int index = hash(name);
    for(int i=0; i< TABLE_SIZE; i++)
    {
        int try = (i+ index) % TABLE_SIZE;
        if(hash_table[try] == NULL) return NULL;
        if(hash_table[try] == DELETED_NODE) continue;
        if(strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0)
        {
            person* tmp = hash_table[try];
            hash_table[try] = DELETED_NODE;
            return tmp;
        }
    }
    return NULL;
}

int main (int argc, char *argv[])
{
    init_hash_table();
    print_table();

    person jacob = {.name="Jacob", .age=256};
    person nat = {.name="Nat", .age=27};
    person sarah = {.name="Sarah", .age=14};
    person salt = {.name="Salt", .age=25};
    person marie = {.name="Marie", .age=22};
    person moho = {.name="Moho", .age=33};
    person teruko = {.name="Teruko", .age=26};
    person evelyn = {.name="Evelyn", .age=25};
    person ariadne = {.name="Ariadne", .age=26};
    person elsa = {.name="Elsa", .age=36};
    
    hash_table_insert(&jacob);
    hash_table_insert(&nat);
    hash_table_insert(&sarah);
    hash_table_insert(&salt);
    hash_table_insert(&marie);
    hash_table_insert(&moho);
    hash_table_insert(&teruko);
    hash_table_insert(&evelyn);
    hash_table_insert(&ariadne);
    hash_table_insert(&elsa);

    print_table();

    person *tmp = hash_table_lookup("Nat");
    if (tmp == NULL)
    {
        printf("Not found!\n");
    }else{
        char *name;
        int index = hash(tmp->name);
        printf("Found %s at %i\n", tmp->name, index);
    }

    tmp = hash_table_lookup("George");
    if (tmp == NULL)
    {
        printf("Not found!\n");
    }else{
        char *name;
        int index = hash(tmp->name);
        printf("Found %s at %i\n", tmp->name, index);
    }

    hash_table_delete("Nat");
    tmp = hash_table_lookup("Nat");
    if (tmp == NULL)
    {
        printf("Not found!\n");
    }else{
        char *name;
        int index = hash(tmp->name);
        printf("Found %s at %i\n", tmp->name, index);
    }

    print_table();
    
    // printf("Jacob => %u\n", hash("Jacob"));
    // printf("Nat => %u\n", hash("Nat"));
    // printf("Sarah => %u\n", hash("Sarah"));
    // printf("Moho => %u\n", hash("Moho"));
    // printf("Teruko => %u\n", hash("Teruko"));
    // printf("Evelyn => %u\n", hash("Evelyn"));
    // printf("Ariadne => %u\n", hash("Ariadne"));
    // printf("Elsa => %u\n", hash("Elsa"));
    // printf("Marie => %u\n", hash("Marie"));
    // printf("Salt => %u\n", hash("Salt"));

    return 0;
}