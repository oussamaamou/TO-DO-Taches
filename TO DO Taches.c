#include<stdio.h>
#include<string.h>

typedef struct{
    int Jour;
    int Mois;
    int Annee;

}Deadline;

typedef struct{
    char Titre[50];
    char Description[500];
    int Identifiant;
    char Status[20];
    Deadline DdLine;

}Tache;

Deadline Date[100];

Tache Taches[100];

int main(){
    
    char Titre[50];
    int i,j;
    int Choix, Fcts, NbrAjt;
    int NbrTache = 0;

    printf("\t ------------------------ TO DO Taches ------------------------ \n");

    do {
        printf("---------------------------------------------------------------------------------------\n");
        printf("Appuyer sur 1 pour Ajouter une nouvelle tache :\n");
        printf("Appuyer sur 2 pour Afficher la liste de toute les taches :\n");
        printf("Appuyer sur 3 pour Modifier une tache :\n");
        printf("Appuyer sur 4 pour Supprimer une tache :\n");
        printf("Appuyer sur 5 pour Rechercher une tache :\n");
        printf("Appuyer sur 6 pour Voir les statistiques de tout votre taches :\n");
        printf("Appuyer sur 7 pour Sortir du programme :\n");
        printf("---------------------------------------------------------------------------------------\n");
        printf("Veuillez entrer votre choix : ");
        scanf("%d",&Choix);
        getchar();

        switch(Choix){
            case 1:
                printf("Appuyer sur 1 pour un Ajout Simple et sur 2 pour un Ajout Multiple :");
                scanf("%d",&Fcts);
                switch(Fcts){
                case 1:
                    printf("Veuillez entrer le titre de la tache :");
                    scanf(" %[^\n]%*c",&Taches[NbrTache].Titre);
                    printf("Veuillez entrer la description de la tache :");
                    scanf(" %[^\n]%*c",&Taches[NbrTache].Description);
                    printf("Veuillez entrer l'identifiant de la tache :");
                    scanf("%d",&Taches[NbrTache].Identifiant);
                    printf("Veuillez entrer le status de la tache:");
                    scanf(" %[^\n]%*c",&Taches[NbrTache].Status);
                    printf("Veuillez entrer la date de la tache :\n");
                    printf("Veuillez entrer le jour :");
                    scanf("%d",&Date[NbrTache].Jour);
                    printf("Veuillez entrer le mois :");
                    scanf("%d",&Date[NbrTache].Mois);
                    printf("Veuillez entrer l'annee :");
                    scanf("%d",&Date[NbrTache].Annee);
                    NbrTache ++;
                    printf("\t La tache a ete ajouter avec succes.\n");
                break;

                case 2:
                    printf("Veuillez entrer le nombre des taches que vous voulez ajouter :");
                    scanf("%d",&NbrAjt);
                    for(i=0;i<NbrAjt;i++){
                        printf("Veuillez entrer le titre de la tache :");
                        scanf(" %[^\n]%*c",&Taches[i].Titre);
                        printf("Veuillez entrer la description de la tache :");
                        scanf(" %[^\n]%*c",&Taches[i].Description);
                        printf("Veuillez entrer l'identifiant de la tache :");
                        scanf("%d",&Taches[i].Identifiant);
                        printf("Veuillez entrer le status de la tache:");
                        scanf(" %[^\n]%*c",&Taches[i].Status);
                        printf("Veuillez entrer la date de la tache :\n");
                        printf("Veuillez entrer le jour :");
                        scanf("%d",&Date[i].Jour);
                        printf("Veuillez entrer le mois :");
                        scanf("%d",&Date[i].Mois);
                        printf("Veuillez entrer l'annee :");
                        scanf("%d",&Date[i].Annee);
                        NbrTache ++;
                        printf("\t La tache a ete ajouter avec succes.\n"); 
                    }
                    break;
                }
             
                break;

            
            case 2:
                if (NbrTache  == 0) {
                printf("Aucune taches n'existent !! \n");
                  }
                  for(i=0;i<NbrTache - 1;i++){
                        for (j=i+1;j<NbrTache ;j++){
                            if(Taches[j].Titre<Taches[i].Titre){
                                Tache temp = Taches[i];
                                Taches[i] = Taches[j];
                                Taches[j] = temp;
                            }
                        }
                   }
                  
                  
                     for (int i = 0; i < NbrTache; i++) {
                        printf("Le Titre: %s\n", Taches[i].Titre);
                        printf("La Description: %s\n", Taches[i].Description);
                        printf("L'Identifiant: %d\n", Taches[i].Identifiant);
                        printf("Le Status: %s\n", Taches[i].Status);    
                        printf("La Date: %d - %d - %d\n", Date[i].Jour,Date[i].Mois,Date[i].Annee);                     
                        printf("---------------------------------------------------------------------------------------\n");
                    }
                
                break;
            
            
            case 3:
                printf("Entrer le titre de la tache que vous voulez modifier :");
                scanf("%s",&Titre);
                for(i=0;i<NbrTache;i++){
                    if(strcmp(Taches[i].Titre,Titre)==0){
                        printf("Entrer la nouvelle description : ");
                        scanf(" %[^\n]%*c",&Taches[i].Description);
                        printf("Entrer le nouveau statut : ");
                        scanf(" %[^\n]%*c",&Taches[i].Status);
                        printf("Entrer la nouvelle date :\n ");
                        printf("Entrer le jour :");
                        scanf("%d",&Date[i].Jour);
                        printf("Entrer le mois :");
                        scanf("%d",&Date[i].Mois);
                        printf("Entrer l'annee :");
                        scanf("%d",&Date[i].Jour);                 
                    
                    break;
                    }
                   
                    else
                        printf("Cette tache n'existe pas !!!");
                    break;    
                        
                
                }    
                
                break;
            
            case 4:
                printf("Veuillez entrer le titre de la tache que vous voulez supprimer :")
                scanf("%s",&Titre);
                for(i=0;i<NbrTache:i++){
                    if(strcmp(Taches[i].Titre,Titre)==0){
                        for(i=0;i<NbrTache:i++){
                            for(j=i;j<NbrTache-1;j++){
                                Taches[j] = Taches[j+1];
                                NbrTache --;
                                printf("La tache a ete supprimer avec succes.");
                                
                            }
                    
                        }                 
                    }
                    else 
                        printf("Le titre de la tache est incorrect !!!");
                } 
            case 5:
            case 6:
            case 7:
            default:
                printf("Choix invalide!! Choisissez un autre choix.\n");
                break;

        }
        
    }while( Choix != 7);
    

  









 return 0;
}
