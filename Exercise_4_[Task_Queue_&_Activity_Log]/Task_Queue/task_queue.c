#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"task_queue.h"

// Using both head and tail makes the add/delete operations have O(1) complexity
// The head pointer points to the first element of the queue 
// (where the task will be take from)
static TaskNode_t* g_head = NULL;

// The tail pointer pointer points to the last element
// (where the new task will be added)
static TaskNode_t* g_tail = NULL;

void queue_add_task(const char* description)
{
    // 1. Allocate memory for the new node
    TaskNode_t* new_node = (TaskNode_t*)malloc(sizeof(TaskNode_t));
    if(new_node == NULL)
    {
        printf("ERROR: Memory allocation failed for new task!\n");
        return;
    }

    // 2. Copy the description into the node and set the next pointer to NULL
    strncpy(new_node->task_description, description, sizeof(new_node->task_description) - 1);
    new_node->task_description[sizeof(new_node->task_description) - 1] = '\0'; //Ensure string the ends with null
    new_node->next = NULL;

    // 3. Add node to the end of the list 
    if(g_tail == NULL)
    {
        // If the queue is empty, both head and tail point to the new node
        g_head = new_node;
        g_tail = new_node;
    }
    else
    {
        // if the queue is not empty, append the new node after the old tail...
        g_tail->next = new_node;
        //... and update tail to point to this new node
        g_tail = new_node;
    }
}

TaskNode_t* queue_get_next_task(void)
{
    // If the queue is empty, there is nothing to retrieve
    if(g_head == NULL)
    {
        return NULL;
    }

    // Keep a pointer to the first node to return
    TaskNode_t* node_to_process = g_head;
    // "Retrieve" by moving the head pointing to the next element
    g_head = g_head->next;

    // Special case: if after taking out the queue is empty 
    // must update the tail pointer to NULL
    if(g_head == NULL)
    {
        g_tail = NULL;
    }
    return node_to_process;
}

void print_task_queue(void)
{
    printf("---Current Task Queue---\n");
    if(g_head == NULL)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        TaskNode_t* current = g_head;
        int index = 1;
        while(current != NULL)
        {
            printf("Task[%d]: %s\n", index++, current->task_description);
            current = current->next;
        }
    }
    printf("--------------------------\n");
}

void queue_shutdown(void)
{
    TaskNode_t* current = g_head;
    TaskNode_t* next_node;
    while(current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    g_head= NULL;
    g_tail = NULL;
}