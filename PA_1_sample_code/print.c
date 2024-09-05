#include "mp3.h"

extern node_t *head;  // Pointer to the head of the list
extern node_t *tail;  // Pointer to the tail of the list

void display(int from_start) {
    node_t *current;
    int i = 0;

    if (from_start == 1) {  // Display from start
        current = head;
        while (current != NULL) {
            printf("(%d) Artist: %s | Title: %s | Runtime: %d seconds\n", 
                   ++i, current->artist, current->title, current->runtime);
            current = current->next;
        }
    } else if (from_start == 2) {  // Display from end
        current = tail;
        while (current != NULL) {
            printf("(%d) Artist: %s | Title: %s | Runtime: %d seconds\n", 
                   ++i, current->artist, current->title, current->runtime);
            current = current->prev;
        }
    }
   
}
