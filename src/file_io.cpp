// file_io.cpp
#include "../inc/file_io.h"
#include <cctype>
#include <cstring>

bool readTextfile(FILE *datei, Node **baum) {
  bool gflag = true;
  int  ch;
  unsigned int i          = 0, wpos = 1;
  char buffer[BUFFERSIZE] = { 0 };

  while (((ch = fgetc(datei)) != EOF) && gflag) {
    if (std::isalpha(ch) || (ch == '\'')) {
      if ((ch != '\'') && (i < BUFFERSIZE)) {
        buffer[i] = toupper(ch);
        i++;
      }
    }
    else if (buffer[0] != 0) {
      char *name = new char[i + 1];
      std::strncpy(name, buffer, i + 1);
      gflag = insertNewNode(baum, name, i, wpos);

      for (size_t k = 0; k < i && k < BUFFERSIZE; k++) {
        buffer[k] = { 0 };
      }
      i = 0;
      wpos++;
    }
  }

  // Datei wieder schliesen!
  std::fclose(datei);
  return gflag;
}

Textfile selectTextfile(int argc, const char *argv[]) {
  Textfile file;

  file.datei = nullptr;
  char eingabe[BUFFERSIZE] = { 0 };
  int  zeichen             = 0;

  if (argc > 1) {
    file.datei = std::fopen(argv[1], "r");

    if (!file.datei) {
      perror(argv[1]);
      printf("Weiter mit Eingabe über Konsole!\n");
    } else {
      if (std::strlen(argv[1]) < BUFFERSIZE) {
        std::strncpy(file.dateiname, argv[1], std::strlen(argv[1]) - 4);
      }
      else std::strncpy(file.dateiname, argv[1], 92);
    }
  }

  if (!file.datei) {
    do {
      printf("Bitte Name der einzulesenden Textdateieingeben(ohne \".txt\"): ");
      scanf("%s", eingabe);
      zeichen = std::strlen(eingabe);

      if (zeichen < (BUFFERSIZE - 4)) {
        std::strcpy(file.dateiname, eingabe);
        std::strcat(eingabe, ".txt");

        // printf("Name der Datei: %s\n", eingabe);
        file.datei = std::fopen(eingabe, "r");
      }
      else printf("Name der Datei ist zu lang!\n");

      if (!file.datei) perror(eingabe);
    } while (!file.datei);
  }

  return file;
}

static void writeTree(Node **baum, FILE *wfile) {
  if (*baum != nullptr) {
    writeTree(&(*baum)->left, wfile);
    std::fprintf(wfile, "%s\t%d\t%d\n",
                 (*baum)->data.name,
                 (*baum)->data.erstesVorkommen,
                 (*baum)->data.anzahl);
    writeTree(&(*baum)->right, wfile);
  }
}

void writeWordlist(Node **baum, Textfile datei, int argc, const char *argv[]) {
  FILE *wfile = nullptr;

  if (argc > 2) wfile = std::fopen(argv[2], "w");

  if (!wfile) {
    char wlname[BUFFERSIZE + 3] = { 0 };
    std::strcpy(wlname, datei.dateiname);
    std::strcat(wlname, "_wl.txt");
    wfile = std::fopen(wlname, "w");
  }
  writeTree(baum, wfile);
}
