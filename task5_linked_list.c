#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertHead(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void deleteValue(int value) {
    struct Node *temp = head, *prev = NULL;

    while(temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) return;

    if(prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
}

void display() {
    struct Node *temp = head;
    printf("List: ");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insertHead(10);
    insertHead(20);
    insertHead(30);
    display();

    deleteValue(20);
    display();

    return 0;
}
