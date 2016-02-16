// Header für die Dateiarbeit
#ifndef FILE_IO_H
#define FILE_IO_H
#include <cstdio>
#include "../inc/word_tree.h"

// Wortpuffergröße für das einlesen von Woertern, und maximale Laenge des Namens
// der Textdatei.
const unsigned int BUFFERSIZE = 100;

// verknüpft geoeffnete Datei mit ihrem Name, um diesen spaeter vielleicht noch
// einmal zum ableiten des Names für die Wortliste zu benutzen, falls für diese
// keine Name per Aufrufparameter übergeben wurde.
struct Textfile {
  FILE *datei;
  char  dateiname[BUFFERSIZE]; // ohne '.txt'
};

// zum einlesen einer Textdatei, die dabei eingelesen Woerter werden in die
// dafür bereitgestellte Wortliste eingetragen. Sollte kein Speicher reserviert
// werden können um die Woerter zu speichern so gibt die Funktion false zurück.
bool readTextfile(FILE  *datei, // Pointer der offenen Datei
                  Node **baum); // Einstiegspointer

// zum angeben welche Datei denn bitte eingelesen werden soll, falls keine
// Aufrufparameter mit übergeben werden so soll über die Konsole die Datei
// abgefragt werden. Als Rückgabe soll die Funktion den Pointer auf die Datei
// zurückgeben.
Textfile selectTextfile(int         argc,    // Anzahl der Parameter
                        const char *argv[]); // Zeichenketten die uebergeben
                                             // wurden

// zum ausgeben der Wortliste in eine Textdatei, der Name für diese Datei wird
// entweder als zweiter Aufrufparameter mit uebergeben oder vom Name der
// eingelesenen Datei abgeleitet. Und Zwar wird ein '_wl' ergaenzt.
void writeWordlist(Node      **baum,    // Einstiegspointer
                   Textfile    datei,   // Dateipointer und Name
                   int         argc,    // Anzahl der Parameter
                   const char *argv[]); // Zeichenketten die uebergeben wurden

#endif /* ifndef FILE_IO_H */
