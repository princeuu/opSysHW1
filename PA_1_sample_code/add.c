#include "mp3.h"

extern node_t *head;  
extern node_t *tail;  

void insert(char *artist, char *title, int runtime) {
    node_t *mp3 = (node_t *)malloc(sizeof(node_t));
    if (!mp3) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Allocate memory and copy the artist name
    mp3->artist = (char *)malloc(strlen(artist) + 1);
    if (!mp3->artist) {
        printf("Memory allocation failed for artist name!\n");
        free(mp3);
        return;
    }
    strcpy(mp3->artist, artist);

    // Allocate memory and copy the song title
    mp3->title = (char *)malloc(strlen(title) + 1);
    if (!mp3->title) {
        printf("Memory allocation failed for song title!\n");
        free(mp3->artist);
        free(mp3);
        return;
    }
    strcpy(mp3->title, title);

    // Set the runtime and initialize next and prev pointers
    mp3->runtime = runtime;
    mp3->next = NULL;
    mp3->prev = NULL;

    if (tail == NULL) {
        // If the list is empty, set both head and tail to the new node
        head = tail = mp3;
    } else {
        // Add the new node to the end of the list
        tail->next = mp3;
        mp3->prev = tail;
        tail = mp3;  // Update the tail pointer to the new node
    }
}
