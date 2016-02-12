// Header für einen binären Baum
#ifndef TREE_H
#define TREE_H

// maximale Wortpuffergroeße
// const unsigned int WORDPUFFER = 100;

struct Data {
  char        *name;
  unsigned int anzahl;
};

struct Node {
  Data *data;
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
void iniTree(Node *wurzel);

// zum einhängen eines neuen Knoten in den Baaum
bool insertNewNode(Node        *wurzel,
                   char        *data,
                   unsigned int puffer_size);

// zum ausgeben eines ganzen Baumes
void outputTree(Node *wurzel);

#endif // ifndef TREE_H
