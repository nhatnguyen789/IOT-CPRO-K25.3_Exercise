
#ifndef __TASK_QUEUE_H__
#define __TASK_QUEUE_H__

//Include header file

//constant

//Data type
typedef struct TaskNode
{
    char task_description[50];
    struct TaskNode* next;
}TaskNode_t;

//Function prototype
// void queue_init(void);

/**
* @brief Add a new task to the end of the queue
* @param description Description of the task to add
*/
void queue_add_task(const char* description);

/**
* @brief Get and remove the task at the head of the queue for processing.
* @return A pointer to the task node that was retrieved, or NULL if the queue is empty.
* The caller is responsible for freeing the memory for this node.
*/
TaskNode_t* queue_get_next_task(void);

/**
* @brief Prints all tasks currently in the queue 
*/
void print_task_queue(void);

/**
* @brief Clean up and release all remaining nodes in the queue 
*/
void queue_shutdown(void);

#endif