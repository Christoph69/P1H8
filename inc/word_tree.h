// Header für einen binären Baum
#ifndef WORD_TREE_H
#define WORD_TREE_H

// maximale Wortpuffergroeße
// const unsigned int WORDPUFFER = 100;

struct Data {
  char        *name;
  unsigned int anzahl, erstesVorkommen;
};

struct Node {
  Data  data;
  Node *left;
  Node *right;
};

// struct Root {
//   Node *first;
// };

///////////////////////////////////////
// Funktionen zum Umgang mit dem Baum.
///////////////////////////////////////

// zum initialisieren des Baumes
void iniWordlist(Node **wurzel);

// zum einhängen eines neuen Knoten in den Baaum
bool insertNewNode(Node       **wurzel,
                   char        *data,
                   unsigned int puffer_size,
                   unsigned int wpos);

// zum ausgeben eines ganzen Baumes
void outputWordlist(Node **wurzel);

// zum loeschen bzw. freigeben eines ganzen Baumes
void deleteWordlist(Node **wurzel);

#endif /* ifndef WORD_TREE_H */
