#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Website {
    char url[100];
    struct Website* next;
};


void addWebsite(struct Website** history, const char* url) {
    struct Website* newNode = (struct Website*)malloc(sizeof(struct Website));
    strcpy(newNode->url, url);
    newNode->next = *history;
    *history = newNode;
}

void displayHistory(const struct Website* history) {
    const struct Website* current = history;
    while (current != NULL) {
        printf("%s\n", current->url);
        current = current->next;
    }
}

// Function to free the memory allocated for the history
void freeHistory(struct Website** history) {
    struct Website* current = *history;
    while (current != NULL) {
        struct Website* next = current->next;
        free(current);
        current = next;
    }
    *history = NULL;
}

int main() {
    struct Website* history = NULL;

   
    addWebsite(&history, "www.KJSCE.com");
    addWebsite(&history, "www.NMIMS.com");
    addWebsite(&history, "www.IIT.com");


    printf("Visited Websites:\n");
    displayHistory(history);

    freeHistory(&history);

    return 0;
}