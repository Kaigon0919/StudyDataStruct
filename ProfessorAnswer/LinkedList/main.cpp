#include <stdio.h>
#include "LinkedList.h"

CLinkedList myList;

int main(void) {

    char command;
    float num;
    while(1) {
        printf("command> ");
        scanf("%c", &command);
        if(command=='a') {
            printf("value to be added: ");
            scanf("%f", &num);
            myList.add(num);
            myList.show();
        }
        else if(command=='r') {
            float removedValue = myList.remove();
            printf("removed %f\n", removedValue);
            myList.show();
        }

        printf("\n");
    }


    return 0;
}