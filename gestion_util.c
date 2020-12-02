#include "gestion_util.h"
#include <string.h>
#include <stdlib.h>

//DEFINITION DES FONCTIONS
void ajouter(UTILISATEUR util, FILE *f1)
{
    f1 = fopen(USER, "a+");
    if (f1 != NULL)
    {
        fprintf(f1, "%s %s %s %s %s %s %s %s \n", util.CIN.CIN, util.CIN.password, util.nom, util.prenom, util.date_naiss, util.num_tel, util.sexe, util.role);
        fclose(f1);
    }
}

int verif_utils(char CINN[], FILE *f1)
{
    UTILISATEUR util;
    int test = 0;
    f1 = fopen(USER, "r");
    if (f1 != NULL)
    {
        while (fscanf(f1, "%s\n", util.CIN.CIN) != EOF)
        {
            if ((strcmp(util.CIN.CIN, CINN) == 0))
            {
                test = 1;
            }
        }
        fclose(f1);
        return test;
    }
}

void modifier(char CINN[], int rep, char amodif[])
{
    UTILISATEUR a;
    FILE *f1;
    FILE *f2;
    f1 = fopen(USER, "r");
    f2 = fopen("tmp.txt", "w");
    if ((f1 != NULL) && (f2 != NULL))
    {
        while (fscanf(f1, "%s %s %s %s %s %s %s %s \n", a.CIN.CIN, a.CIN.password, a.nom, a.prenom, a.date_naiss, a.num_tel, a.sexe, a.role) != EOF)
        {
            if ((strcmp(CINN, a.CIN.CIN)) == 0)
            {
                switch (rep)
                {
                case 1:
                    strcpy(a.nom, amodif);
                    break;
                case 2:
                    strcpy(a.prenom, amodif);
                    break;
                case 3:
                    strcpy(a.CIN.CIN, amodif);
                    break;
                case 4:
                    strcpy(a.date_naiss, amodif);
                    break;
                case 5:
                    strcpy(a.num_tel, amodif);
                    break;
                case 6:
                    strcpy(a.sexe, amodif);
                    break;
                case 7:
                    strcpy(a.role, amodif);
                    break;
                case 8:
                    strcpy(a.CIN.password, amodif);
                    break;
                }
                fprintf(f2, "%s %s %s %s %s %s %s %s \n", a.CIN.CIN, a.CIN.password, a.nom, a.prenom, a.date_naiss, a.num_tel, a.sexe, a.role);
            }
            else
            {
                fprintf(f2, "%s %s %s %s %s %s %s %s \n", a.CIN.CIN, a.CIN.password, a.nom, a.prenom, a.date_naiss, a.num_tel, a.sexe, a.role);
            }
        }
    }
    fclose(f1);
    fclose(f2);
    remove(USER);
    rename("tmp.txt", USER);
}

void supprimer(char CINN[])
{
    UTILISATEUR a;
    FILE *f1;
    FILE *f2;
    f1 = fopen(USER, "r");
    f2 = fopen("tmp.txt", "w");
    if ((f1 != NULL) && (f2 != NULL))
    {
        while (fscanf(f1, "%s %s %s %s %s %s %s %s \n", a.CIN.CIN, a.CIN.password, a.nom, a.prenom, a.date_naiss, a.num_tel, a.sexe, a.role) != EOF)
        {
            if ((strcmp(CINN, a.CIN.CIN)) != 0)
            {
                fprintf(f2, "%s %s %s %s %s %s %s %s \n", a.CIN.CIN, a.CIN.password, a.nom, a.prenom, a.date_naiss, a.num_tel, a.sexe, a.role);
            }
        }
    }
    fclose(f1);
    fclose(f2);
    remove(USER);
    rename("tmp.txt", USER);
}

void afficher_utils(FILE *f1)
{
    int ch;
    f1 = fopen(USER, "r");
    if (f1 != NULL)
    {
        ch = getc(f1);
        while (ch != EOF)
        {
            putchar(ch);
            ch = getc(f1);
        }
        fclose(f1);
    }
}

void afficher_absense(int id)
{
    float ctot = 0;
    float cabs = 0;
    float taux, taux_pres;
    int id_ouv, jour, mois, annee, val;
    FILE *f;
    f = fopen(ABS, "r");
    if (f != NULL)
    {
        while (fscanf(f, "%d %d %d %d %d\n", &id_ouv, &jour, &mois, &annee, &val) != EOF)
        {
            if (id_ouv == id)
            {
                if (val == 0)
                {
                    cabs++;
                }
            }
            ctot++;
        }
        fclose(f);
    }
    taux = (cabs / ctot) * 100;
    taux_pres = ((ctot - cabs) / ctot) * 100;
    printf("\nLe taux d'absenteisme de l'ouvrier %d est %.2f pourcent\n", id, taux);
    printf("\nLe taux de presence de l'ouvrier %d est %.2f pourcent\n", id, taux_pres);
}