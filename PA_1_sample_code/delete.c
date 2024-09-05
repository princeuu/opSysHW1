#include "mp3.h"

extern node_t *head;  // Pointer to the head of the list
extern node_t *tail;  // Pointer to the tail of the list

void deleteByArtist(char *artist) {
    node_t *current = head;
    node_t *to_delete = NULL;
    int found = 0;

    while (current != NULL) {
        if (strcmp(current->artist, artist) == 0) {
            found = 1;
            to_delete = current;

            // Adjust pointers
            if (to_delete->prev != NULL) {
                to_delete->prev->next = to_delete->next;
            } else {
                head = to_delete->next;  // Deleting the head node
            }

            if (to_delete->next != NULL) {
                to_delete->next->prev = to_delete->prev;
            } else {
                tail = to_delete->prev;  // Deleting the tail node
            }

            // Move to the next node before deleting the current one
            current = current->next;

            // Free the memory for the artist, title, and node
            free(to_delete->artist);
            free(to_delete->title);
            free(to_delete);
        } else {
            current = current->next;
        }
    }

    if (!found) {
        printf("No MP3 records found for artist: %s\n", artist);
    } else {
        printf("Deleted MP3 records for artist: %s\n", artist);
    }
}