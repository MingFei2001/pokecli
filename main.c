#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_DIR "ascii/" // set ascii art directory
#define MAX_PATH 256       // set max buffer size for path

void print_ascii(const char *filename) {
  FILE *fp = fopen(filename, "r"); // save file path as variable
  if (!fp) {
    printf("could not open %s\n", filename);
    return;
  }

  printf("\033[1;32m"); // set green color
  char line[1024];
  while (fgets(line, sizeof(line), fp)) {
    printf("%s", line);
  };
  printf("\033[0m\n"); // reset color
  fclose(fp);
}

int main(int argc, char *argv[]) {
  if (argc < 2){
    printf("Usage: %s <pokemon-name>", argv[0]);
    return 1;
  }

  char filepath[MAX_PATH];
  snprintf(filepath, sizeof(filepath), "%s%s.txt", ASCII_DIR, argv[1]);

  print_ascii(filepath);
  return 0;
};
