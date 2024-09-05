#include "mp3.h"

extern node_t *head;
extern node_t *tail;

void freeList() {
    node_t *temp;
    int i = 0;

    while (head != NULL) {
        temp = head;
        head = head->next; // Move to the next node in the list
        
        // Free dynamically allocated memory for artist and title
        free(temp->artist);
        free(temp->title);
        
        // Free the node itself
        free(temp);
        
        i++;
    }

    // After freeing all nodes, set tail to NULL as well
    tail = NULL;

    printf("Freed %d MP3 records...\n", i);
}
