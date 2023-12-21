#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int stack[256];
int count = 0;

void push(int x){
    stack[count] = x;
    count++;
}

int pop(){
    count--;
    return stack[count];
    // int res = stack[count -1];
    // count --;
    // return res;
}
int main (int argc, char *argv[])
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    for(int i =0; i<5; i++){
        printf("%d ", pop());
    }

    return 0;
}