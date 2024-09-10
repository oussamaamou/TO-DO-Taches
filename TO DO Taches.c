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
    char Chng[50];
    char Status[20];
    int Identifiant;
    char Titre[50];
    int i,j;
    int Choix, Fcts, NbrAjt;
    char Stts[15];
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
                //Demande a l'utilisateur l'ajout d'une seul ou plusieur taches.//
                printf("Appuyer sur 1 pour un Ajout Simple et sur 2 pour un Ajout Multiple :");
                scanf("%d",&Fcts);
                switch(Fcts){
                //Ajout simple//
                case 1:
                    printf("Veuillez entrer le titre de la tache :");
                    scanf(" %[^\n]%*c",&Taches[NbrTache].Titre);
                    printf("Veuillez entrer la description de la tache :");
                    scanf(" %[^\n]%*c",&Taches[NbrTache].Description);
                    printf("Veuillez entrer le status de la tache:\n");
                    printf(" --1-- <a realiser> // --2-- <en cours de realisation> // --3-- <finalisee> \n");
                    scanf("\t%d",&Fcts);
                    switch(Fcts){
                        case 1:
                            strcpy(Stts,"a realiser\n");
                            printf("\t %s",Stts);
                            break;
                        case 2:
                            strcpy(Stts,"en cours de realisation\n");
                            printf("\t %s",Stts);
                            break;
                        case 3:
                            strcpy(Stts,"finalisee\n");
                            printf("\t %s",Stts);
                            break;
                    }
                    printf("Veuillez entrer la date de la tache :\n");
                    printf("Veuillez entrer le jour :");
                    scanf("%d",&Date[NbrTache].Jour);
                    printf("Veuillez entrer le mois :");
                    scanf("%d",&Date[NbrTache].Mois);
                    printf("Veuillez entrer l'annee :");
                    scanf("%d",&Date[NbrTache].Annee);
                    Taches[NbrTache].Identifiant = NbrTache + 1;
                    NbrTache ++;
                    printf("\t La tache a ete ajouter avec succes.\n");
                break;

                case 2:
                    //Ajout multiple//
                    printf("Veuillez entrer le nombre des taches que vous voulez ajouter :");
                    scanf("%d",&NbrAjt);
                    for(i=0;i<NbrAjt;i++){
                        printf("Veuillez entrer le titre de la tache :");
                        scanf(" %[^\n]%*c",&Taches[i].Titre);
                        printf("Veuillez entrer la description de la tache :");
                        scanf(" %[^\n]%*c",&Taches[i].Description);
                        printf("Veuillez entrer le status de la tache:\n");
                        printf(" --1-- <a realiser> // --2-- <en cours de realisation> // --3-- <finalisee> \n");
                        scanf("\t%d",&Fcts);
                        switch(Fcts){
                        case 1:
                            strcpy(Stts,"a realiser\n");
                            printf("\t %s",Stts);
                            break;
                        case 2:
                            strcpy(Stts,"en cours de realisation\n");
                            printf("\t %s",Stts);
                            break;
                        case 3:
                            strcpy(Stts,"finalisee\n");
                            printf("\t %s",Stts);
                            break;
                        }
                        printf("Veuillez entrer la date de la tache :\n");
                        printf("Veuillez entrer le jour :");
                        scanf("%d",&Date[i].Jour);
                        printf("Veuillez entrer le mois :");
                        scanf("%d",&Date[i].Mois);
                        printf("Veuillez entrer l'annee :");
                        scanf("%d",&Date[i].Annee);
                        Taches[i].Identifiant = NbrTache + 1;
                        NbrTache ++;
                        printf("\t Les taches ont ete ajouter avec succes.\n"); 
                    
                    }
                break;
                }
             
            break;

            
            case 2:
                    //Affichage de la liste de toute les tache.//
                    if (NbrTache  == 0) {
                    //Dans le cas ou il n'y a pas de taches.//
                    printf("Aucune taches n'existent !! \n");
                    }
                   
                    //Boucle pour Afficher les taches dans un ordre alphabetique.//                 
                        for(i=0;i<NbrTache - 1;i++)
                            for (j=i;j<NbrTache;j++){
                                if(strcmp(Taches[j].Titre,Taches[i].Titre)< 0){
                                    Tache Chng  = Taches[i];
                                    Taches[i] = Taches[j];
                                    Taches[j] = Chng ;
                                }
                            }                                      
                        //L'Affichage des taches.//
                        for (int i = 0; i < NbrTache; i++) {
                            printf("Le Titre: %s\n", Taches[i].Titre);
                            printf("La Description: %s\n", Taches[i].Description);
                            printf("L'Identifiant: %d\n", Taches[i].Identifiant);
                            printf("Le Status: %s\n",Stts);    
                            printf("La Date: %d - %d - %d\n", Date[i].Jour,Date[i].Mois,Date[i].Annee);                     
                            printf("---------------------------------------------------------------------------------------\n");
                        }
                    
            break;
            
            
            case 3:
                //Demander a l'utilisateur d'entrer la tache à modifier.//
                printf("Entrer le titre de la tache que vous voulez modifier :");
                scanf("%s",&Titre);
                //Modification de la tache par l'utilisateur.//
                for(i=0;i<NbrTache;i++){
                    if(strcmp(Taches[i].Titre,Titre)==0){
                        printf("Entrer la nouvelle description : ");
                        scanf(" %[^\n]%*c",&Taches[i].Description);
                        printf("Entrer le nouveau statut :\n ");
                        printf(" --1-- <a realiser> // --2-- <en cours de realisation> // --3-- <finalisee> //\n");
                        scanf("\t%d",&Fcts);
                        switch(Fcts){
                        case 1:
                            strcpy(Stts,"a realiser\n");
                            printf("\t %s",&Stts);
                            break;
                        case 2:
                            strcpy(Stts,"en cours de realisation\n");
                            printf("\t %s",&Stts);
                            break;
                        case 3:
                            strcpy(Stts,"finalisee\n");
                            printf("\t %s",&Stts);
                            break;
                        }
                        printf("Entrer la nouvelle date :\n ");
                        printf("Entrer le jour :");
                        scanf("%d",&Date[i].Jour);
                        printf("Entrer le mois :");
                        scanf("%d",&Date[i].Mois);
                        printf("Entrer l'annee :");
                        scanf("%d",&Date[i].Jour);                 
                    
                    break;
                    }                   
                     
                        //Dans le cas ou le titre entrer par l'utilisateur est incorrect.//
                        printf("\nCette tache n'existe pas !!!");
                                                             
                }    
                
            break;
            
            case 4:
                //Demander à l'utilisateur d'entrer le titre de la tache à supprimer.//
                printf("Veuillez entrer le titre de la tache que vous voulez supprimer :");
                scanf("%s",&Titre);
                //Donner a l'utilisateur une chance a reflechir avant la suppression de la tache.//
                printf("Si vous voulez comfirmer la suppression de cette tache :\n");
                printf("Veuillez appuyer sur 1 si non appuyer sur 2 :");
                scanf("%d",&Fcts);
                switch(Fcts){
                    case 1:
                        //Boucle qui permet de supprimer la tache.//
                        for(i=0;i<NbrTache;i++)
                            if(strcmp(Taches[i].Titre,Titre)==0){
                                for(i=0;i<NbrTache;i++)
                                    for(j=i;j<NbrTache-1;j++)
                                        Taches[j] = Taches[j+1];
                                        NbrTache --;
                                        printf("\tLa tache a ete supprimer avec succes.\n");                          
                                                
                            }
                            break;
                             
                            //Dans le cas ou le titre entrer par l'utilisateur est incorrect.//
                            printf("Le titre de la tache est incorrect !!!");               
                         
                    
                    case 2:
                        //Pour Annuler la suppression de la tache et retourner au menu principale.//
                        printf("\nRetour au menu principale.\n");
                        break;     
                }
            break;
            
            case 5:
                 printf("Si vous voulez chercher par identifiant cliquer 1 si par titre cliquer 2 : ");
                 scanf("%d",&Fcts);
                 switch(Fcts){
                    //Recherche par identifiant//
                    case 1:
                         printf("Veuillez entrer  l'identifiant de la tache :");
                         scanf("%d",&Identifiant);
                         for(i=0;i<NbrTache;i++){
                            if(Taches[i].Identifiant == Identifiant){
                                printf("Le Titre: %s\n", Taches[i].Titre);
                                printf("La Description: %s\n", Taches[i].Description);
                                printf("L'Identifiant: %d\n", Taches[i].Identifiant);
                                printf("Le Status: %s\n",Stts);    
                                printf("La Date: %d - %d - %d\n", Date[i].Jour,Date[i].Mois,Date[i].Annee);                     
                                printf("---------------------------------------------------------------------------------------\n");
                            }
                         }
                         break;
                         printf("L'identifiant de la tache est incorrect !!!");
                    break;

                    //Recherche par titre//
                    case 2:
                    printf("Veuillez entrer  le titre de la tache :");
                         scanf("%s",&Titre);
                         for(i=0;i<NbrTache;i++){
                            if(strcmp(Taches[i].Titre,Titre)==0){
                                printf("Le Titre: %s\n", Taches[i].Titre);
                                printf("La Description: %s\n", Taches[i].Description);
                                printf("L'Identifiant: %d\n", Taches[i].Identifiant);
                                printf("Le Status: %s\n",Stts);    
                                printf("La Date: %d - %d - %d\n", Date[i].Jour,Date[i].Mois,Date[i].Annee);                     
                                printf("---------------------------------------------------------------------------------------\n");
                            }
                         }
                         break;
                         printf("Le titre de la tache est incorrect !!!");
                    break;                
                 }
            break;
            
                      
            case 6:
                           
                printf("Le nombre totale des taches est : %d \n",NbrTache);
                break;

                
            break;
            
            case 7:
                printf("\tLe programme est ferme :)\n");
                break;
            default:
                printf("\nChoix invalide!! Choisissez un autre choix.\n");
                break;

        }
        
    }while( Choix != 7);
    

  









 return 0;
}
