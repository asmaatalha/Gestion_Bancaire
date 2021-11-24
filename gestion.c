#include <stdio.h>
#include <stdlib.h>
#include <math.h>



//creation de compte ... 

int choixMulti, quitterReMenu, choixOperation, choixAffichage;
struct
{
    char cin[20], nom[20], prenom[20]; 
    int montant, montantRetrait, montantDepot;
}utilisateur;

//déclaration de fichier..
FILE * fichier = NULL;

FILE * fichierRetrait = NULL;

FILE * fichierDepot = NULL;

void creationCompte()
{
    fichier = fopen("db.txt", "a");
    
    printf("CIN: ");
    scanf("%s", &utilisateur.cin);
    
    printf("Nom: ");
    scanf(" %s", &utilisateur.nom);
    
    printf("Prenom: ");
    scanf(" %s", &utilisateur.prenom);
    
    printf("Montant: ");
    scanf("%d",&utilisateur.montant);
    
 	printf("vos informations :\n");

    fprintf(fichier, "Nom: %s\n", utilisateur.nom);
    fprintf(fichier, "Prenom: %s\n", utilisateur.prenom);
    fprintf(fichier, "CIN: %s\n", utilisateur.cin);
    fprintf(fichier, "Montant: %d\n", utilisateur.montant); 
    fprintf(fichier, "********************\n"); 
    
}

void retrait()
{
    fichierRetrait = fopen("retrait.txt", "a");

    printf("Entrez votre CIN: ");
    scanf("%s", &utilisateur.cin);

    printf("Entrez le montant: ");
    scanf("%d", &utilisateur.montantRetrait);

    fprintf(fichierRetrait, "CIN: %s\n", utilisateur.cin);
    fprintf(fichierRetrait, "Montant Retrait: %d\n", utilisateur.montantRetrait);
    fprintf(fichierRetrait, "********************\n"); 

}

void depot()
{
    fichierDepot = fopen("depot.txt", "a");

    printf("Entrez votre CIN: ");
    scanf("%s", &utilisateur.cin);

    printf("Entrez le montant: ");
    scanf("%d", &utilisateur.montantDepot);

    fprintf(fichierDepot, "CIN: %s\n", utilisateur.cin);
    fprintf(fichierDepot, "Montant Depot: %d\n", utilisateur.montantDepot);
    fprintf(fichierDepot, "********************\n"); 

}

void recherche()
{
    char cinR[20];
    
    fichier = fopen("db.txt", "r");

    printf("Entrez CIN a rechercher:");
    scanf("%s", &cinR);

    fscanf(fichier, "%s %s %s %d", &utilisateur.cin, &utilisateur.nom, &utilisateur.prenom, &utilisateur.montant);
    if (cinR == utilisateur.cin)
    {
        printf("vos informations:\n");
        printf("CIN: %s\n", utilisateur.cin);
        printf("Nom: %s\n", utilisateur.nom);
        printf("Prenom: %s\n", utilisateur.prenom);
        printf("Montant: %d\n", utilisateur.montant); 
    }
    else
    {
        printf("Not found!");
    }

}

void Menu()
{
    int menu;
    
	printf("1. Creation de compte\n");
	printf("2. Creation de plusiers comptes\n");
	printf("3. Operations:\n");
	printf("4. Affichage\n");
	printf("5. Fedilisation\n");
	printf("6. QUITTER\n");

	printf("Veuillez entrer le num de votre operation\t");
	scanf("%d", &menu);
	
	switch (menu)
	{
		case 1:
			printf("Creation de compte\n");
			creationCompte();
			printf("Le compte a ete cree avec succes !\n");
			
    		printf("1. Voulez-vous revenir au menu principal ?\n");
    		printf("2. QUITTER !\n");
			scanf("%d", &quitterReMenu);
            if(quitterReMenu == 1)
            {
                Menu();
            }
            else 
            {
                printf("A bientot!");
            }
			break;

		case 2:			
            printf("Creation de plusiers comptes\n");
            creationCompte();
            printf("Le compte a ete cree avec succes !\n");
			
            do{
                printf("1. Voulez-vous creer un autre compte ?\n");
                printf("2. Revenir au Menu Principal !\n");
                printf("3. QUITTER !\n");
                scanf("%d", &choixMulti);
        
                if(choixMulti == 1)
                {
                    creationCompte();
                    printf("Le compte a ete cree avec succes !\n");
                }
                else if (choixMulti == 2)
                {
                    Menu();
                }
                else 
                {
                    printf("A bientot!");
                }
            } while(choixMulti == 1);	
        
			break;

		case 3:
			printf("Operations:\n");

            do
            {
                printf("1. Retrait\n");
                printf("2. Depot\n");
                printf("3. QUITTER !\n");

                scanf("%d", &choixOperation);

                if (choixOperation == 1)
                {
                    retrait();
		            printf("Retire avec succes.");

                    printf("2. Depot\n");
                    printf("3. QUITTER !\n");

                }
                else if (choixOperation == 2)  
                {
                    depot();
		            printf("Depot avec succes.");

                    printf("2. Retrait\n");
                    printf("3. QUITTER !\n");
                }
                else
                {
                    printf("A bientot!");
                    break;
                }
                                
            } while (choixOperation == 1);
            
			break;

		// case 4:

		// 	printf("Affichage\n");
        //     printf("Entrez CIN a rechercher:");
        //     scanf("%s", &utilisateur.cinR);
            
        //     fichier = fopen("db.txt", "r");
        //     do
        //     {
        //         fscanf(fichier, "%s %s %s %d", &utilisateur.cin, &utilisateur.nom, &utilisateur.prenom, &utilisateur.montant);
        //         if (utilisateur.cinR == utilisateur.cin)
        //         {
        //             printf("vos informations:\n");
        //             printf("CIN: %s\n", utilisateur.cin);
        //             printf("Nom: %s\n", utilisateur.nom);
        //             printf("Prenom: %s\n", utilisateur.prenom);
        //             printf("Montant: %d\n", utilisateur.montant); 
        //         }
        //         else
        //         {
        //             printf("Not found!");
        //         }
                
        //     } while (utilisateur.cinR == utilisateur.cin);

		// 	break;

        case 4:
            printf("Affichage:\n");
            do
            {
                printf("1. Par Ordre Ascendant\n");
                printf("1. Par Ordre Descendant\n");
                printf("3. Recherche par CIN\n");

                scanf("%d", &choixAffichage);

                if (choixAffichage == 3)
                {
                    recherche();
                }
                
                
            } while (choixAffichage == 1);
            
            break;

		case 5:
			printf("Fedilisation\n");
			break;

		case 6:
			printf("QUITTER\n");
			break;

		default:
		    Menu();
		    break;
	}
}

int main()
{
    
    Menu() ;
}