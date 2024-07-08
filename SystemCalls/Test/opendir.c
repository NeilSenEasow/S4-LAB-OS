#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
    DIR *dir;
    struct dirent *entry;

    // Open the current directory
    dir = opendir(".");
    if (dir == NULL) {
        perror("Error opening directory");
        exit(1);
    }

    // Read directory entries
    while ((entry = readdir(dir)) != NULL) {
        printf("Entry name: %s\n", entry->d_name);
    }

    // Close the directory
    closedir(dir);

    return 0;
}
