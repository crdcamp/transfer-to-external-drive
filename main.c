#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

int check_if_directory_exists(char *external_drive_path);
char *concatenate_external_drive_path(char *volumes_path, char *external_drive_name);
int transfer_input_to_external_drive(char *input_directory_path, char *external_drive_path);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error: Expected one argument (the external drive's name as shown in Finder)\nUsage: %s <name-of-external-drive>\n", argv[0]);
        return 1;
    }

    // Define your input directories to copy to the external drive and confirm if they
    // NEED TO SURROUND FILE PATHS IN QUOTES
    char *input_directory_paths[] = {"/Users/christiancamp/Documents/External", "/Users/christiancamp/Desktop/Code"};
    int input_array_len = sizeof(input_directory_paths) / sizeof(input_directory_paths[0]);
    for (int i = 0; i < input_array_len; i++) {
        int input_directory_existence_check = check_if_directory_exists(input_directory_paths[i]);
        if (input_directory_existence_check != 0) {
            printf("Error: The specified input directory was not found. Please ensure the directory exist\n");
            return 1;
        }
    }

    // Concatenate external drive name with path to external drives
    char *external_drive_path = concatenate_external_drive_path("/Volumes/", argv[1]);
    if (external_drive_path == NULL) {
        free(external_drive_path);
        return 1;
    }
    printf("External drive path: %s\n", external_drive_path);

    // Check if the external drive exists
    int external_drive_existence_check = check_if_directory_exists(external_drive_path);
    if (external_drive_existence_check != 0) {
        printf("Error: The external drive was not found. Please ensure you are inputting the correct name and that the external drive is connected\n");
        free(external_drive_path);
        return 1;
    }

    // Copy the contents of the input directory into the external drive
    for (int i = 0; i < input_array_len; i++) {
        int result = transfer_input_to_external_drive(input_directory_paths[i], external_drive_path);
        if (result != 0) {
            free(external_drive_path);
            return 1;
        }

    }

    free(external_drive_path);

    return 0;
}

// Check if the input directory exists.
// Returns 0 if the path is a directory and exists. Otherwise, return 1.
int check_if_directory_exists(char *external_drive_path) {
    struct stat stats;
    if (stat(external_drive_path, &stats) == 0 && S_ISDIR(stats.st_mode)) {
        return 0;
    }
    else {
        return 1;
    }
}

// Concatenate the user's input (the name of their external drive) with the
// path to the external drive's directory.
char *concatenate_external_drive_path(char *volumes_path, char *external_drive_name) {
    // Buffer for external drive file path
    char *external_drive_path = malloc(strlen(volumes_path) + strlen(external_drive_name) + 1);
    if (external_drive_path == NULL) {
        printf("Error: Could not allocate memory for external drive name buffer\n");
        return NULL;
    }

    // Concatenate the volumes path with the external drive's name
    strcpy(external_drive_path, volumes_path);
    strcat(external_drive_path, external_drive_name);

    return external_drive_path;
}

// Transfer the contents of the `input` directory into the external drive.
int transfer_input_to_external_drive(char *input_directory_path, char *external_drive_path) {
    // Define bash arguments for copying
    char *rsync = "rsync -a -h --progress ";
    char *space = " ";

    // Allocate buffer for command
    // CONVERT THE COMMAND TO AN ARRAY AND ITERATE OVER
    // IT INSTEAD OF ALLOCATING MEMORY
    char *command = malloc(strlen(rsync) + strlen(input_directory_path) + strlen(space) + strlen(external_drive_path) + 1);
    if (command == NULL) {
        printf("Error: Could not allocate memory for command line buffer\n");
        return 1;
    }

    // Copy and concatenate the strings into the buffer
    strcpy(command, rsync);
    strcat(command, input_directory_path);
    strcat(command, space);
    strcat(command, external_drive_path);

    // Call the command and free the memory
    // ADD CHECK FOR SUCCESSFUL/UNSUCCESSFUL SYSTEM CALL
    // Otherwise, this print statement is meaningless
    system(command);
    free(command);

    printf("Files for directory `%s` successfully copied\n", input_directory_path);

    return 0;
}
