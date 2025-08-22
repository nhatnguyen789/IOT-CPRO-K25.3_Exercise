#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../Task_Queue/task_queue.h"
#include"../Activity_Log/activity_log.h"


void print_help()
{
    printf("\n--- Command Menu ---\n");
    printf("add <description>   - Add a new task to the queue\n");
    printf("run                 - Run the next task from the queue\n");
    printf("list                - List all pending tasks\n");
    printf("history             - Navigate the activity log\n");
    printf("exit                - EXit the program\n");
    printf("-------------------------\n");
}
int main()
{
    char input_buffer[100];
    char* command;
    char* argument;

    print_help();

    while(1)
    {
        printf("\nEnter command >");
        if(fgets(input_buffer, sizeof(input_buffer), stdin) == NULL)
        {
            break; // Error or EOF
        }

        // Remove the newline character at the end if present
        input_buffer[strcspn(input_buffer, "\n")] = 0;

        // Command and parameter analysis
        command = strtok(input_buffer, " ");
        if(command == NULL)
        {
            continue;
        }

        if(strcmp(command, "add" ) == 0)
        {
            argument = strtok(NULL, ""); // Get the rest of the string 
            if(argument == NULL)
            {
                printf("ERROR: 'add' command requires a description.\n");
            }
            else
            {
                queue_add_task(argument);
                printf("Task added: '%s'\n", argument);
            }
        }
        else if(strcmp(command, "list") == 0)
        {
            print_task_queue();
        }
        else if(strcmp(command, "run") == 0)
        {
            TaskNode_t* task = queue_get_next_task();
            if(task == NULL)
            {
                printf("No task to run.\n");
            }
            else
            {
                char log_message[100];
                snprintf(log_message, sizeof(log_message), "Executed task: %s", task->task_description);

                printf("Running-> %s\n", log_message);

                // Log activities into history
                history_log_activity(log_message);

                // Important: Free memory for processed task nodes
                free(task);
            }
        }
        else if( strcmp(command, "history") == 0)
        {
            history_navigate();
        }
        else if(strcmp(command, "exit") == 0)
        {
            printf("Exiting program. Cleaning up memory...\n");
            break;
        }
        else if(strcmp(command, "help") == 0)
        {
            print_help();
        }
        else
        {
            printf("Unknown command: '%s'\n", command);
        }
    }
    // Clean up memory before exiting 
    queue_shutdown();
    history_shutdown();
    
    printf("Cleanup complete. Goodbye!\n");
    return 0;        
}