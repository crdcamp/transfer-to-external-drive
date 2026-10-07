#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

char *concatenate_external_drive_path(const char *volumes_path, const char *external_drive_name);
void check_if_external_drive_exists(const char *external_drive_path);
void transfer_research_to_external_drive(char *research_directory_path, char *external_drive_path);

int main(int argc, char *argv[]) {
    // Input argument validation. Only accepts one argument: The name
    // of the external drive as listed in Finder on the user's Mac
    if (argc != 2) {
        printf("Error: expected one argument - the external drive's name as shown in Finder\nUsage: %s <name-of-external-drive>\n", argv[0]);
    }

    // Define your research directory to copy to the external drive
    const char *research_directory_path = "~/Desktop/Research";

    // External drive path concatenation and path definition
    char *external_drive_path = concatenate_external_drive_path("/Volumes/", argv[1]);
    if (external_drive_path == NULL) {
        return 1;
    }
    printf("External drive path: %s\n", external_drive_path);

    // Determine if the external drive exists
    check_if_external_drive_exists(external_drive_path);

    free(external_drive_path);

    return 0;
}

// Concatenate the user's external drive's name parameter to create
// the external drive's file path
char *concatenate_external_drive_path(const char *volumes_path, const char *external_drive_name) {
    // Buffer size for external drive file path
    size_t external_drive_path_size = strlen(volumes_path) + strlen(external_drive_name) + 1;
    // Buffer for external drive file path
    char *external_drive_path = malloc(external_drive_path_size);
    if (external_drive_path == NULL) {
        printf("Error allocating memory for external drive path buffer\n");
        return NULL;
    }

    // Concatenate volumes path with external drive name
    strcpy(external_drive_path, volumes_path);
    strcat(external_drive_path, external_drive_name);

    return external_drive_path;
}

// Check if the external drive exists.
// Returns 0 if the path is a directory and exists.
// Otherwise, return 1
void check_if_external_drive_exists(const char *external_drive_path) {
    struct stat stats;
    if (stat(external_drive_path, &stats) == 0 && S_ISDIR(stats.st_mode)) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
}

// Transfer the contents of the `Research` directory into an external drive
void transfer_research_to_external_drive(char *research_directory_path, char *external_drive_path) {
    printf("Not implemented\n");
}
