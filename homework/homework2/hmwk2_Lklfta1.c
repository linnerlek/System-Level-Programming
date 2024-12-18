/*
 * This program retrieves and displays process IDs, user and group IDs, 
 * shows a welcome message if the UID matches my personal UID, and lists processes 
 * before and after a 3-second sleep.
 *
 * Linn Klofta 2024
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
    printf("Starting C program\n");
    
    pid_t process_id, parent_process_id;
    gid_t group_id;
    uid_t user_id, current_user_id;

    process_id = getpid();
    printf("Process ID: %d\n", process_id);

    parent_process_id = getppid();
    printf("Parent Process ID: %d\n", parent_process_id);

    group_id = getgid();
    printf("Group ID: %d\n", group_id);
   
    user_id = 1331089166;
    current_user_id = getuid();

    if (current_user_id == user_id) {
        printf("Welcome Linn!\n");
        system("grep 1331089166 /etc/passwd");  // this gives no output due to the system handling authentication in another way
    }   else {
        printf("User ID: %d did not match the expected UID.\n", current_user_id);
    }

    printf("First list of processes:\n");
    system("ps");

    printf("Sleeping for 3 seconds...\n");
    sleep(3);

    printf("Second list of processes after sleeping:\n");
    system("ps");
 
    printf("Ending C program\n");
}
