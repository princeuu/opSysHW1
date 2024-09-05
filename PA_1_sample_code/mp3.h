#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct node {
    char *artist;       // Name of the artist
    char *title;        // Title of the song
    int runtime;        // Runtime in seconds
    struct node *next;  // Pointer to the next node
    struct node *prev;  // Pointer to the previous node
} node_t;







