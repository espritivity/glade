#include "gestion_util.h"
#include <string.h>
#include <stdlib.h>

int main()
{
    UTILISATEUR util;
    FILE *f;
    int t, id;
    char CINN[10];
    char amodif[20];
    printf("Nom, Prenom : ");
    scanf("%s %s", util.nom, util.prenom);
    printf("CIN : ");
    scanf("%s", util.CIN.CIN);
    printf("Password : ");
    scanf("%s", util.CIN.password);
    printf("Date naissance (j/m/a) :");
    scanf("%s", util.date_naiss);
    printf("Num tel : ");
    scanf("%s", util.num_tel);
    printf("Sexe (1:Homme, 2:Femme) : ");
    scanf("%s", util.sexe);
    printf("Role (1: Admin, 2:Ouvrier, 3:Client): ");
    scanf("%s", util.role);
    ajouter(util, f);
    printf("\nModification : \n");
    printf("Utilisateur à modifier (CIN): ");
    scanf("%s", CINN);
    t = verif_utils(CINN, f);
    if (t)
    {
        int rep;
        printf("Les paramètres à modifier : (1:nom|2:prénom|3:CIN|4:Date naissance|5:num tel|6:sexe|7:role|8:password) : ");
        scanf("%d", &rep);
        printf("Le nouveau paramètre : ");
        scanf("%s", amodif);
        modifier(CINN, rep, amodif);
    }
    else
    {
        printf("L'utilisateur n'existe pas !\n");
    }
    printf("Utilisateur à supprimer (CIN): ");
    scanf("%s", CINN);
    t = verif_utils(CINN, f);
    if (t)
    {
        supprimer(CINN);
    }
    else
    {
        printf("L'utilisateur n'existe pas !\n");
    }
    afficher_utils(f);
    printf("\nAfficher les absences de quel ouvrier ? (de 1 à 9) : ");
    scanf("%d", &id);
    afficher_absense(id);
    return 0;
}