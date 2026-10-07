#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

int check_if_directory_exists(const char *external_drive_path);
char *concatenate_external_drive_path(const char *volumes_path, const char *external_drive_name);
void transfer_research_to_external_drive(char *research_directory_path, char *external_drive_path);

int main(int argc, char *argv[]) {
    // Input argument validation. Only accepts one argument: The name of the external drive
    if (argc != 2) {
        printf("Error: expected one argument - the external drive's name as shown in Finder\nUsage: %s <name-of-external-drive>\n", argv[0]);
    }

    // Define your research directory to copy to the external drive
    const char *research_directory_path = "~/Desktop/Research";
    int research_directory_existence_check = check_if_directory_exists(research_directory_path);
    if (research_directory_existence_check != 0) {
        printf("Error: The specified research directory was not found. Please ensure the directory exist\n");
        return 1;
    }

    // External drive path concatenation and path definition
    char *external_drive_path = concatenate_external_drive_path("/Volumes/", argv[1]);
    if (external_drive_path == NULL) {
        return 1;
    }
    printf("External drive path: %s\n", external_drive_path);
    int external_drive_existence_check = check_if_directory_exists(external_drive_path);
    if (external_drive_existence_check != 0) {
        printf("Error: The specified external drive not found. Please ensure you are inputting the correct name and that the external drive is connected\n");
        return 1;
    }

    free(external_drive_path);

    return 0;
}

// Check if the input directory exists.
// Returns 0 if the path is a directory and exists. Otherwise, return 1
int check_if_directory_exists(const char *external_drive_path) {
    struct stat stats;
    if (stat(external_drive_path, &stats) == 0 && S_ISDIR(stats.st_mode)) {
        return 0;
    }
    else {
        return 1;
    }
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

    // Concatenate the volumes path with the external drive's name
    strcpy(external_drive_path, volumes_path);
    strcat(external_drive_path, external_drive_name);

    return external_drive_path;
}

// Transfer the contents of the `Research` directory into an external drive
void transfer_research_to_external_drive(char *research_directory_path, char *external_drive_path) {
    printf("Meow\n");
}
