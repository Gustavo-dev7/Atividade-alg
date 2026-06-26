#ifndef SPELLBOOK_H
#define SPELLBOOK_H

// Definição da struct Spell
typedef struct spell {
    int id;
    char name[50];
    int mana_cost;
} Spell;

// Definição do nó da lista encadeada
typedef struct no {
    Spell spell;
    struct no* prox;
} No;

// Definição do grimório (lista encadeada)
typedef struct spellbook {
    No* inicio;
} Spellbook;

// Protótipos das funções públicas do módulo
Spellbook* create_spellbook();
void add_spell(Spellbook* book, int id, const char* name, int mana_cost);
void display_spellbook(Spellbook* book);
void destroy_spellbook(Spellbook* book);

#endif
