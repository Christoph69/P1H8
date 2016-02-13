// HA Nr. 8
#include "../inc/file_io.h"

int main(int argc, char const *argv[]) {
  Textfile datei = selectTextfile(argc, argv);
  Node    *baum;

  iniWordlist(&baum);
  readTextfile(datei.datei, &baum);
  outputWordlist(&baum);
  writeWordlist(&baum, datei, argc, argv);
  deleteWordlist(&baum);

  return 0;
}
