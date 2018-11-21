#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//This is the typedef struct that consists of data which is a string of a given element and a link to the next
//node
typedef struct node {
    char data[1000];
    struct node * next;
} node;


//Global variables that contain the beginning of the linked list with head
//A pointer to travel through the list called p
//and a boolean to signal when the linked list has no more elements
bool endOfLL = false;
node * head = NULL;
node * p = NULL;


//A function to count the length of the linked list and return the number as an int
int countLength(){
    int count = 0;
    p = head;

    while(p != NULL){
        count++;
        p = p->next;
    }
    return count;
}


//The push function that puts another node on the end of the linked list
void push(char element[]){
    int len = countLength();
    if (len == 3){
        printf("The stack is full and can not take anymore elements\n");
        return;
    }
    //Makes a temporary node to be placed in the linked list
    node * temp = NULL;
    temp = (node*)malloc(sizeof(node));
    strcpy(temp->data, element);
    temp->next = NULL;

    //If the linked list is empty before then make the head the temporary node
    if (head == NULL){
        head = temp;
    }
    //Else go to the end of the list and add the node on there
    else{
        p = head;
        while(p->next != NULL)
            p = p->next;
        p->next = temp;
    }
}

//The pop function that gets rid of the last node in the linked list and then frees the space that the
//last element took up
void pop(){
    int len = countLength();
    if(endOfLL){
        printf("Cannot pop an empty stack\n");
    }
    else if(len == 1){
        endOfLL = true;
        free(head);
        printf("The stack is empty\n");
    }
    else if ( len > 1) {
        node * popper = head;
        node * popperFront = head->next;
        while(popperFront->next != NULL) {
            popper = popper->next;
            popperFront = popperFront->next;
        }
        free(popperFront);
        popper->next = NULL;

    }


}




//This prints off the entire linked list
void printLL(){
    node * p = head;
    int len = countLength();
    int i = 0;
    printf("{ ");
    while(i < len){
        printf("\"%s\"", p->data);
        if ( i < len-1){
            printf(", ");
        }
        p = p->next;
        i++;

    }
    printf(" }");
    printf("\n");
}

int main() {

    char ArrayFirst[] = "First Element";
    char ArraySecond[] = "Second Element";
    char ArrayThird[] = "Third Element";
    char ArrayFourth[] = "Fourth Element";

    printf("Creating a Stack that can take only 3 string elements\n");

    printf("Pushing\n");
    push(ArrayFirst);
    printf("Here is the stack now: ");
    printLL();

    printf("Pushing\n");
    push(ArraySecond);
    printf("Here is the stack now: ");
    printLL();

    printf("Pushing\n");
    push(ArrayThird);
    printf("Here is the stack now: ");
    printLL();

    printf("Pushing\n");
    push(ArrayFourth);


    printf("Popping\n");
    pop();
    printf("Here is the stack now: ");
    printLL();

    printf("Popping\n");
    pop();
    printf("Here is the stack now: ");
    printLL();

    printf("Popping\n");
    pop();

    printf("Popping\n");
    pop();

    printf("End of program\n");
}