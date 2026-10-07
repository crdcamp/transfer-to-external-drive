#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void check_if_external_drive_exists(void);
void transfer_research_to_external_drive(char *research_directory_path, char *external_drive_path);

int main(int argc, char *argv[]) {
    // Some input validation before getting started
    if (argc != 2) {
        printf("Error: expected one argument, the external drive's name as shown in Finder\nUsage: %s <name-of-external-drive>\n", argv[0]);
    }

    // Path handling
    const char *research_directory_path = "/Users/christiancamp/Desktop";

    // Allocate buffer for combining file paths to define external drive location
    const char *volumes_path = "/Volumes/";
    const char *external_drive_name = argv[1];

    // Combine file paths
    size_t external_drive_path_size = strlen(volumes_path) + strlen(external_drive_name) + 1; // Buffer size for external drive file path
    char *external_drive_path = malloc(external_drive_path_size); // Buffer for external drive file path


    printf("Research path: %s\n", research_directory_path);
    printf("External drive path: %s\n", external_drive_path);

    return 0;
}

// Transfer the contents of the `Research` directory into
// an external drive
void transfer_research_to_external_drive(char *research_directory_path, char *external_drive_path) {
    printf("Not implemented\n");
}
