// HA Nr. 8
#include <cstdio>
#include <ctype.h>
#include <cstring>
#include "../inc/tree.h"

int main(int argc, char const *argv[]) {
  FILE *file01 = std::fopen("The_Chaos_I.txt", "r");

  if (!file01) {
    perror("fopen()");
    return 0;
  }

  // Einlesen des Textes, Zeichen für Zeichen!
  int   ch, i = 0;
  char  puffer[100] = { 0 };
  Node *baum        = nullptr;

  while ((ch = fgetc(file01)) != EOF) {
    // Testen was es den für ein Zeichen ist! Entweder ein Buchstabe oder >>'<<
    if (isalpha(ch) || (ch == '\'')) {
      if (ch != '\'') {
        puffer[i] = toupper(ch);
        i++;
      }
    }
    else if (puffer[0] != 0) {
      // printf("%s\n", puffer);
      char *name = new char[20];
      std::strncpy(name, puffer, 19);
      printf("%s\n", name);
      insertNewNode(baum, name, 19);

      for (size_t k = 0; k < i; k++) {
        puffer[k] = { 0 };
      }
      i = 0;
    }
  }

  // outputTree(baum);

  // Datein wieder schliesen!
  std::fclose(file01);
  return 0;
}
