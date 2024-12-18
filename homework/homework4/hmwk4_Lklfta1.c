/*
 * Program to view files and directories in folder. shows info such as uid, gid, time of creation,
 * filetype, filesize, filename
 * Linn Klofta 2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>          // For open()
#include <sys/stat.h>       // For struct stat and file info
#include <sys/types.h>      // For data types
#include <dirent.h>         // For readdir()
#include <unistd.h>         // For close()
#include <time.h>           // For formatting modification time

#define MAX_FILENAME 256

void fatalError() {
    perror("Error");
    exit(1);
}

void print_file_info(const char *file_name, int short_format);
void process_directory(const char *dir_name, int short_format);

int main(int argc, char *argv[]) {
    int short_format = 0;
    const char *target = ".";
    int i; 

    for (i = 1; i < argc; i++) {  
        if (strcmp(argv[i], "-h") == 0) {
            printf("Usage: %s [-h] [-s] [file_or_directory]\n", argv[0]);
            printf("Options:\n");
            printf("  -h    Shows this help message\n");
            printf("  -s    Short output format showing just filename, filetype and filesize\n");
            return 0;
        } else if (strcmp(argv[i], "-s") == 0) {
            short_format = 1;
        } else {
            target = argv[i];
        }
    }

    struct stat path_stat;
    if (stat(target, &path_stat) != 0) {
        fprintf(stderr, "Error: file \"%s\" not found\n", target);
        return 1;
    }

    if (S_ISDIR(path_stat.st_mode)) {
        process_directory(target, short_format);
    } else {
        print_file_info(target, short_format);
    }

    return 0;
}

void process_directory(const char *dir_name, int short_format) {
    DIR *dir;
    struct dirent *entry;
    char fileName[MAX_FILENAME];

    dir = opendir(dir_name);  // FROM BOOK Open directory
    if (dir == NULL) fatalError();  // FROM BOOK Handle error

    while ((entry = readdir(dir)) != NULL) {  // Read each entry ADAPTED FROM BOOK
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {  // FROM BOOK
            snprintf(fileName, MAX_FILENAME, "%s/%s", dir_name, entry->d_name);  // FROM BOOK
            print_file_info(fileName, short_format);  // Process each file
        }
    }

    closedir(dir); // FROM BOOK
}

void print_file_info(const char *file_name, int short_format) {
    struct stat file_stat;
    char *type;
    char time_buf[20];

    if (stat(file_name, &file_stat) != 0) {
        perror(file_name);
        return;
    }

    if (S_ISREG(file_stat.st_mode)) type = "file";
    else if (S_ISDIR(file_stat.st_mode)) type = "directory";
    else type = "other";

    strftime(time_buf, sizeof(time_buf), "%b %d %H:%M", localtime(&file_stat.st_mtime));

    if (short_format) {
        // prints just the short format info
        printf("%s, %s, %ld bytes\n", file_name, type, (long)file_stat.st_size);
    } else {
        printf("%s, uid %d, gid %d, %s, %ld bytes, %s\n",
               file_name,
               file_stat.st_uid,                    
               file_stat.st_gid,                    
               type,
               (long)file_stat.st_size,
               time_buf);                          
    }
}
