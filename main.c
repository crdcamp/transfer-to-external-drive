#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void check_if_external_drive_exists(void);
char *concatenate_external_drive_file_paths(const char *volumes_path, const char *external_drive_name);
void transfer_research_to_external_drive(char *research_directory_path, char *external_drive_path);

int main(int argc, char *argv[]) {
    // Some input validation before getting started
    if (argc != 2) {
        printf("Error: expected one argument, the external drive's name as shown in Finder\nUsage: %s <name-of-external-drive>\n", argv[0]);
    }

    // Path handling
    const char *research_directory_path = "/Users/christiancamp/Desktop";
    const char *external_drive_name = argv[1];
    char *external_drive_path = concatenate_external_drive_file_paths("/Volumes/", external_drive_name);
    if (external_drive_path == NULL) {
        return 1;
    }

    printf("Copying documents to external drive located at: %s\n", external_drive_path);

    free(external_drive_path);

    return 0;
}

// Transfer the contents of the `Research` directory into
// an external drive
void transfer_research_to_external_drive(char *research_directory_path, char *external_drive_path) {
    printf("Not implemented\n");
}

// Concatenate the user's external drive's name parameter to create
// the external drive's file path
char *concatenate_external_drive_file_paths(const char *volumes_path, const char *external_drive_name) {
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
