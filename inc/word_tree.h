// Header für einen binären Baum
#ifndef WORD_TREE_H
#define WORD_TREE_H

// struct, speichert den Namen des Worter, sowie die Position des ersten
// Vorkommens im Text, und natuerlich auch die Haeufigkeit des Vorkommens.
struct Data {
  char        *name;
  unsigned int anzahl, erstesVorkommen;
};

// struct, eines Knoten des Baumes mit den Pointer auf die zwei UnterKnoten
struct Node {
  Data  data;
  Node *left;
  Node *right;
};

///////////////////////////////////////
// Funktionen zum Umgang mit dem Baum.
///////////////////////////////////////

// zum initialisieren des Baumes, setzt den Einstiegspointer auf NULL
void iniWordlist(Node **wurzel); // Einstiegspointer

// zum einhängen eines neuen Knoten in den Baum, vergleicht dabei anhand der
// alphabetischen Reihenfolge und fügt danach den Knoten links oder rechts ein.
bool insertNewNode(Node       **wurzel,      // Einstiegspointer
                   char        *data,        // Einzutragender Name
                   unsigned int puffer_size, // Laenge des Wortes
                   unsigned int wpos);       // Position des Wortes im Text

// zum ausgeben eines ganzen Baumes, es werden alle Knoten alphabetisch sortiert
// ausgegeben.
void outputWordlist(Node **wurzel); // Einstiegspointer

// zum loeschen bzw. freigeben eines ganzen Baumes
void deleteWordlist(Node **wurzel); // Einstiegspointer

#endif /* ifndef WORD_TREE_H */
