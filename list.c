
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char* word;
    struct Node* next;
};

void add(struct Node** head, char* newWord) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->word = (char*)malloc(strlen(newWord)+1);
    strcpy(newNode->word, newWord);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL)
        current = current->next;

    current->next = newNode;
}

void print(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    
    printf("%s ", head->word);
    print(head->next);
}

int main() {
    struct Node* head = NULL;
    char fileName[100];
    printf("Enter the name of the file to read: ");
    scanf("%s", fileName);

    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char word[100];
    while (fscanf(file, "%s", word) != EOF)
        add(&head, word);

    fclose(file);

    print(head);

    return 0;
}
