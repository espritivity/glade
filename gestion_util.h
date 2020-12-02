#include <stdio.h>
#ifndef GESTION_UTIL_H_
#define GESTION_UTIL_H_
#define USER "utilisateur.txt"
#define ABS "absenteisme.txt"

//DEFINITION DES STRUCTURES
typedef struct
{
    char password[50];
    char CIN[10];
} LOGIN;

typedef struct
{
    char nom[50];
    char prenom[50];
    LOGIN CIN;
    char num_tel[12];
    char date_naiss[20];
    char sexe[2];
    char role[2];
} UTILISATEUR;

//PROTOTYPES DES FONCTIONS
void ajouter(UTILISATEUR util, FILE *f1);
int verif_utils(char CINN[], FILE *f1);
void modifier(char CINN[], int rep, char amodif[]);
void supprimer(char CINN[]);
void afficher_utils(FILE *f1);
void afficher_absense(int id);
#endif
