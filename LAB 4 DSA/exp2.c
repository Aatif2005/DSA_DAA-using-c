/*
playlist management system using doubly linked list
1. insert song at the end
2. delete a song with particular song ID
3. display alll songs
4. exit
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int song_id;
    char song_name[20];
    char artist[20];
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void insertSong() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter song_id: ");
    scanf("%d", &newnode->song_id);

    printf("Enter song_name: ");
    scanf(" %[^\n]", newnode->song_name);   

    printf("Enter artist name: ");
    scanf(" %[^\n]", newnode->artist);    

    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }

    printf("Song added successfully\n");
}

void deleteSong() {
    int id;
    printf("Enter the song_id to delete: ");
    scanf("%d", &id);

    if (head == NULL) {
        printf(" Playlist is empty\n");
        return;
    }

    struct node *ptr = head;

    while (ptr != NULL && ptr->song_id != id) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf(" Song not found!\n");
        return;
    }

    if (head == tail) {
        head = tail = NULL;
    }
    else if (ptr == head) {
        head = head->next;
        head->prev = NULL;
    }
    else if (ptr == tail) {
        tail = tail->prev;
        tail->next = NULL;
    }
    else {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
    }

    free(ptr);
    printf("Song deleted successfully!\n");
}

void displaySongs() {
    if (head == NULL) {
        printf("\n🎧 Playlist is empty!\n");
        return;
    }

    struct node *temp = head;
    printf("\n🎶 Playlist Songs:\n");

    while (temp != NULL) {
        printf("ID: %d\n", temp->song_id);
        printf("Song: %s\n", temp->song_name);
        printf("Artist: %s\n", temp->artist);
        temp = temp->next;
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n===== PLAYLIST MANAGEMENT SYSTEM =====\n");
        printf("1. Insert Song at End\n");
        printf("2. Delete Song by Song ID\n");
        printf("3. Display All Songs\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                insertSong();
                break;
            case 2:
                deleteSong();
                break;
            case 3:
                displaySongs();
                break;
            case 4:
                printf("\nExiting Playlist System...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
