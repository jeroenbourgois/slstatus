/* See LICENSE file for copyright and license details. */
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "../slstatus.h"
#include "../util.h"

#define PERF_MODE "/sys/firmware/acpi/platform_profile"

const char *
perf_mode(const char *path)
{
  // Open the file for reading
  FILE *file = fopen(PERF_MODE, "r");
  if (file == NULL) {
    perror("Error opening file");
    return NULL;
  }

  // Read and print the file contents
  char buffer[256]; // Adjust the buffer size as needed
  /* while (fgets(buffer, sizeof(buffer), file) != NULL) {
    printf("Value read from %s: %s", PERF_MODE, buffer);
  } */
  fgets(buffer, sizeof(buffer), file);

  // Close the file
  fclose(file);

  return bprintf("%s", buffer);
}
