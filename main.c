///////////////////////////////////////////////
//     ____        __        ________    ____
//    / __ \____  / /_____  / ____/ /   /  _/
//   / /_/ / __ \/ //_/ _ \/ /   / /    / /
//  / ____/ /_/ / ,< /  __/ /___/ /____/ /
// /_/    \____/_/|_|\___/\____/_____/___/
///////////////////////////////////////////////
//           Author: MingFei2001
///////////////////////////////////////////////

#include <dirent.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ASCII_DIR "ascii/" // set ascii art directory
#define MAX_PATH 256       // set max buffer size for path

// read the ascii file from ASCII DIR and print them line by line
void print_ascii(const char *filename) {
  FILE *fp = fopen(filename, "r"); // save file path as variable
  if (!fp) {
    printf("could not open %s\n", filename);
    return;
  }

  char line[1024];
  while (fgets(line, sizeof(line), fp)) {
    printf("%s", line);
  };
  fclose(fp);
}

// random ascii art selector
char *get_random_ascii_file(char *buffer, size_t size) {
  struct dirent *entry;
  DIR *dir = opendir(ASCII_DIR);
  if (!dir) {
    perror("failed to open ascii directory.");
    return NULL;
  }

  // create an array to store filename
  char *files[1024];
  int count = 0;

  while ((entry = readdir(dir)) != NULL) {
    if (strstr(entry->d_name, ".txt")) {
      files[count] = strdup(entry->d_name);
      count++;
      if (count >= 1024)
        break;
    }
  }
  closedir(dir);

  if (count == 0)
    return NULL;

  srand(time(NULL));
  int idx = rand() % count;
  snprintf(buffer, size, "%s%s", ASCII_DIR, files[idx]);

  // Free memory of other filenames
  for (int i = 0; i < count; i++) {
    if (i != idx)
      free(files[i]);
  }

  return buffer;
}

// main function
int main(int argc, char *argv[]) {
  char filepath[MAX_PATH];

  if (argc < 2) {
    if (!get_random_ascii_file(filepath, sizeof(filepath))) {
      printf("No ascii files found in %s\n", ASCII_DIR);
      return 1;
    }
  } else {
    snprintf(filepath, sizeof(filepath), "%s%s.txt", ASCII_DIR, argv[1]);
  }

  print_ascii(filepath);
  return 0;
};
