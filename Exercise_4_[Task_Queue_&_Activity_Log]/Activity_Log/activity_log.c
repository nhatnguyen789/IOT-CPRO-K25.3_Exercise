#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"activity_log.h"


// Just the head pointer is enough to manage this list 
// since we always add to the head
static HistoryNode_t* g_log_head = NULL;

void history_log_activity(const char* entry)
{
    // 1. Allocate memory for the new log node
    HistoryNode_t* new_node = (HistoryNode_t*)malloc(1 * sizeof(HistoryNode_t));
    if(new_node == NULL)
    {
        printf("ERROR: Memory allocation failed for new log entry!\n");
        return;
    }

    // 2. Copy the description and set the cursors
    strncpy(new_node->log_entry, entry, sizeof(new_node->log_entry) - 1);
    new_node->log_entry[sizeof(new_node->log_entry) - 1] = '\0';

    new_node->prev = NULL; // The new node is always the first node, so prev is NULL
    new_node->next = g_log_head; // Next of new node points to old head

    // 3. Update the 'prev' pointer of the old head (if any)
    // This is an important step in adding to the doubly linked list
    if(g_log_head != NULL)
    {
        g_log_head->prev = new_node;
    }
    
    // 4. Update head to point to the new node
    g_log_head = new_node;
}

void history_navigate(void)
{
    if(g_log_head == NULL)
    {
        printf("Activity Log is empty...\n");
        return;
    }

    HistoryNode_t* current_node = g_log_head;
    char command;

    printf("\n--- Navigating Activity Log ---\n");
    printf("Enter 'n' for next, 'p' for previous, 'q' to quit.\n");

    while(1)
    {
        printf("Log Entry: [%s]\n", current_node->log_entry);
        printf("Navigate >");

        //Read a character and clear the buffer
        command = getchar();
        while(getchar() != '\n' && command != '\n');

        if(command == 'n')
        {
            if(current_node->next != NULL)
            {
                current_node = current_node->next;
            }
            else
            {
                printf("Already at the oldest entry.\n");
            }
        }
        else if(command == 'p')
        {
            if(current_node->prev != NULL)
            {
                current_node = current_node->prev;
            }
            else
            {
                printf("Already at the newest entry.\n");
            }
        }
        else if(command == 'q')
        {
            break;
        }
    }
    printf("--- Exiting Log Navigation ---\n");
}

void history_shutdown(void)
{
    HistoryNode_t* current = g_log_head;
    HistoryNode_t* next_node;
    while(current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    g_log_head = NULL;
}