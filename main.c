#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* deleteNode(Node* head, int data) {
    Node* dummyHead = (Node*)malloc(sizeof(Node));
    dummyHead->next=head;
    Node* temp = dummyHead;

    while (temp->next != NULL) {
        if (temp->next->data == data) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            free(toDelete);
            break;
        }
        temp = temp->next;
    }

    Node* newHead = dummyHead->next;
    free(dummyHead);
    return newHead;
}

Node* createLinkedList(int arr[], int size) {
    if (size == 0) return NULL;

    Node* head = (Node*)malloc(sizeof(Node));
    head->data = arr[0];
    head->next = NULL;

    Node* current = head;
    for (int i = 1; i < size; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = arr[i];
        newNode->next = NULL;
        current->next = newNode;
        current = newNode;
    }
    return head;
}

void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int arr[] = {10,20,40};
    Node* head = createLinkedList(arr, 3);

    printf("Initial List: \n");
    printLinkedList(head);

    head = deleteNode(head, 20);

    printf("Updated List: \n");
    printLinkedList(head);

    return 0;
}
