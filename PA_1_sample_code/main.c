//
// adapted from http://www.cprogramming.com/snippets/source-code/singly-linked-list-insert-remove-add-count
//

#include "mp3.h"
#define BUFFERSIZE 128

node_t *head = NULL;  // Pointer to head 
node_t *tail = NULL;  // Pointer to tail 

void insert(char *artist, char *title, int runtime);
void display(int from_start);
void deleteByArtist(char *artist);
void freeList();

int main() {
    int choice, runtime, direction;
    char artist[BUFFERSIZE], title[BUFFERSIZE], c;

    while (1) {
        printf("\nList of Operations\n");
        printf("===================\n");
        printf("(1) Insert\n");
        printf("(2) Display\n");
        printf("(3) Delete\n");
        printf("(4) Exit\n");
        printf("Enter your choice : ");
        if (scanf("%d%c", &choice, &c) <= 0) { // Use c to capture \n
            printf("Enter only an integer...\n");
            exit(0);
        } else {
            switch (choice) {
                case 1: // Insert MP3
                    printf("Enter artist name: ");
                    if (fgets(artist, BUFFERSIZE, stdin) != NULL) {
                        artist[strcspn(artist, "\n")] = '\0'; // Remove newline
                    } else {
                        printf("Error reading artist name...\n");
                        exit(-1);
                    }
                    
                    printf("Enter song title: ");
                    if (fgets(title, BUFFERSIZE, stdin) != NULL) {
                        title[strcspn(title, "\n")] = '\0'; // Remove newline
                    } else {
                        printf("Error reading song title...\n");
                        exit(-1);
                    }
                    
                    printf("Enter runtime (in seconds): ");
                    if (scanf("%d%c", &runtime, &c) <= 0) { // Use c to capture \n
                        printf("Enter a valid integer for runtime...\n");
                        exit(0);
                    }

                    insert(artist, title, runtime);
                    break;

                case 2: // Display
                    if (head == NULL) {
                    printf("List is Empty\n");
                    } else {
                      printf("Enter 1 to display from start, 2 to display from end: ");
                        if (scanf("%d%c", &direction, &c) <= 0) {
                          printf("Enter only an integer...\n");
                            exit(0);
                          }

                    if (direction == 1 || direction == 2) {
                    display(direction);  // Call the display function with the chosen direction
                    } else {  
                        printf("Invalid option. Please enter 1 or 2.\n");
                        }
                    }
                    break;
                case 3: // Delete 
                    printf("Enter artist name to delete: ");
                    if (fgets(artist, BUFFERSIZE, stdin) != NULL) {
                        artist[strcspn(artist, "\n")] = '\0'; // Remove newline
                    } else {
                        printf("Error reading artist name...\n");
                        exit(-1);
                    }
                    deleteByArtist(artist);
                    break;

                case 4: // Exit
                    freeList();
                    return 0;

                default:
                    printf("Invalid option\n");
            }
        }
    }
    return 0;
}
