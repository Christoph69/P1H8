// Header für die Dateiarbeit
#ifndef FILE_IO_H
#define FILE_IO_H
#include <cstdio>
#include "../inc/word_tree.h"

// Wortpuffergröße für das einlesen von Woertern, und maximale Laenge des Namens
// der Textdatei.
const unsigned int BUFFERSIZE = 100;

struct Textfile {
  FILE *datei;
  char  dateiname[BUFFERSIZE]; // ohne '.txt'
};

// zum einlesen einer Textdatei, die dabei eingelesen Woerter werden in die
// dafür bereitgestellte Wortliste eingetragen. Sollte kein Speicher reserviert
// werden können um die Woerter zu speichern so gibt die Funktion false zurück.
bool readTextfile(FILE  *datei,
                  Node **baum);

// zum angeben welche Datei denn bitte eingelesen werden soll, falls keine
// Aufrufparameter mit übergeben werden so soll über die Konsole die Datei
// abgefragt werden. Als Rückgabe soll die Funktion den Pointer auf die Datei
// zurückgeben.
Textfile selectTextfile(int         argc,
                        const char *argv[]);

// zum ausgeben der Wortliste in eine Textdatei, der Name für diese Datei wird
// entweder als zweiter Aufrufparameter mit uebergeben oder vom Name der
// eingelesenen Datei abgeleitet. Und Zwar wird ein '_wl' ergaenzt.
void writeWordlist(Node      **baum,
                   Textfile    datei,
                   int         argc,
                   const char *argv[]);

#endif /* ifndef FILE_IO_H */
