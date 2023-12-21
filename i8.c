#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256 
#define TABLE_SIZE 10 

typedef struct person
{
    char name[MAX_NAME];
    int age;
    struct person *next;
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
        }else{
            printf("\t%i\t",i);
            person *tmp = hash_table[i];
            while(tmp != NULL)
            {
                printf("%s - ", tmp->name);
                tmp = tmp -> next;
            }
            printf("\n");
        }
    }
    printf("End\n");
}

bool hash_table_insert(person *p)
{
    if (p==NULL) return false;
    int index = hash(p->name);
    p->next = hash_table[index];
    hash_table[index] = p;
    return true;
}

person *hash_table_lookup(char *name)
{
    int index = hash(name);
    person *tmp = hash_table[index];
    while(tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0)
    {
        tmp = tmp->next;
    }
    return tmp;
}

person *hash_table_delete(char *name)
{
    int index = hash(name);
    person *tmp = hash_table[index];
    person *prev = NULL;
    while(tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    if(tmp == NULL) return NULL;
    if(prev == NULL)
    {
        hash_table[index] = tmp -> next;
    }else{
        prev->next = tmp->next;
    }
    return tmp;
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