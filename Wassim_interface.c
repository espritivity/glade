#include "gestionUtils.h"
#include "gestionPl.h"
//INTERFACE ADMIN
//MODIFIER (return modif_wadm)
FILE *f1;
UTILISATEUR u;
f1 = fopen("users.txt", "r");
if (f1 != NULL)
{
    while (fscanf(f1, "%s %s %s %s %s %s %s %s \n", u.log.cin, u.log.pw, u.nom, u.prenom, u.dateNaiss, u.numTel, u.sexe, u.role) != EOF)
    {
        if ((strcmp(u.role, "Admin")) == 0)
        {
            gtk_combo_box_append_text(GTK_COMBO_BOX(cbadmmodif_wadm), u.log.cin);
        }
        else if ((strcmp(u.role, "Employe")) == 0)
        {
            gtk_combo_box_append_text(GTK_COMBO_BOX(cbempmodif_wadm), u.log.cin);
        }
        else if ((strcmp(u.role, "Ouvrier")) == 0)
        {
            gtk_combo_box_append_text(GTK_COMBO_BOX(cbouvmodif_wadm), u.log.cin);
        }
    }
}
fclose(f1);

//ABSENCES ( return marqabs_wadm)
FILE *f1;
UTILISATEUR u;
f1 = fopen("users.txt", "r");
if (f1 != NULL)
{
    while (fscanf(f1, "%s %s %s %s %s %s %s %s \n", u.log.cin, u.log.pw, u.nom, u.prenom, u.dateNaiss, u.numTel, u.sexe, u.role) != EOF)
    {
        if ((strcmp(u.role, "Employe")) == 0)
        {
            gtk_combo_box_append_text(GTK_COMBO_BOX(cbempabs_wadm), u.log.cin);
        }
        else if ((strcmp(u.role, "Ouvrier")) == 0)
        {
            gtk_combo_box_append_text(GTK_COMBO_BOX(cbouvabs_wadm), u.log.cin);
        }
    }
}
fclose(f1);

//ABSENCES TAUX(return tauxabs_wadm)
FILE *f1;
UTILISATEUR u;
f1 = fopen("users.txt", "r");
if (f1 != NULL)
{
    while (fscanf(f1, "%s %s %s %s %s %s %s %s \n", u.log.cin, u.log.pw, u.nom, u.prenom, u.dateNaiss, u.numTel, u.sexe, u.role) != EOF)
    {
        if ((strcmp(u.role, "Employe")) == 0)
        {
            gtk_combo_box_append_text(GTK_COMBO_BOX(cbemptaux_wadm), u.log.cin);
        }
        else if ((strcmp(u.role, "Ouvrier")) == 0)
        {
            gtk_combo_box_append_text(GTK_COMBO_BOX(cbouvtaux_wadm), u.log.cin);
        }
    }
}
fclose(f1);

//INTERFACE EMPlOYE
//MODIFIER (return modif_wemp)
FILE *f1;
UTILISATEUR u;
f1 = fopen("users.txt", "r");
if (f1 != NULL)
{
    while (fscanf(f1, "%s %s %s %s %s %s %s %s \n", u.log.cin, u.log.pw, u.nom, u.prenom, u.dateNaiss, u.numTel, u.sexe, u.role) != EOF)
    {
        if ((strcmp(u.role, "Employe")) == 0)
        {
            gtk_combo_box_append_text(GTK_COMBO_BOX(cbempmodif_wemp), u.log.cin);
        }
        else if ((strcmp(u.role, "Ouvrier")) == 0)
        {
            gtk_combo_box_append_text(GTK_COMBO_BOX(cbouvmodif_wemp), u.log.cin);
        }
    }
}
fclose(f1);

////PLANTE
//MODIFIER (return modifsup_gpl)
FILE *f1;
PLANTE p;
f1 = fopen("plantes.txt", "r");
if (f1 != NULL)
{
    while (fscanf(f1, "%s %s %s %s %s %s %s \n", p.id, p.cat, p.type, p.recolte, p.stock, p.dtpl, p.dtrec) != EOF)
    {
        gtk_combo_box_append_text(GTK_COMBO_BOX(cbidmod_gpl), p.id);
    }
}
fclose(f1);