
#ifndef __ACTIVITY_LOG_H__
#define __ACTIVITY_LOG_H__

//include header file

//constant

//Data type: Define a structure for a node in the log
//This is a doubly linked list because it has both next and prev pointer
typedef struct HistoryNode
{
    char log_entry[50];
    struct HistoryNode* next;
    struct HistoryNode* prev; //pointer to previous node
}HistoryNode_t;

//Function prototype

/**
 * @brief Logs a new activity at the beginning of the log list.
 * @param entry Description of the activity.
*/
void history_log_activity(const char* entry);

/**
 * @brief Starts the log browsing mode, allowing the user to move forward/backward.
*/
void history_navigate(void);

/**
 * @brief Clean up and free all nodes in the log
 *
*/
void history_shutdown();

#endif