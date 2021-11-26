#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <strings.h>



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
    
    printf("Nom: ");
    scanf(" %s", &utilisateur.nom);
    
    printf("Prenom: ");
    scanf(" %s", &utilisateur.prenom);

    printf("CIN: ");
    scanf("%s", &utilisateur.cin);
    
    printf("Montant: ");
    scanf("%d",&utilisateur.montant);
    
    fprintf(fichier, "%s %s %s %d\n", utilisateur.nom, utilisateur.prenom,utilisateur.cin,utilisateur.montant);

    fclose(fichier);
}

void recherche()
{
    char cinR[20];
    char holder[100];
    char cin[20],nom[20],pre[20];
    float mon;
    
    fichier = fopen("db.txt", "r");

    printf("Entrez CIN a rechercher:");
    scanf("%s", &cinR);

    while (fgets(holder, 100, fichier)) {
        sscanf(holder, "%s %s %s %f" ,nom, pre, cin, &mon );
        if (strcmp(cinR,cin) == 0){
            printf("vos informations:\n");
            printf("CIN: %s\n", cin);
            printf("Nom: %s\n", nom);
            printf("Prenom: %s\n", pre);
            printf("Montant: %f\n", mon); 

            break;
        }

        else
        {
            printf("Not found");
        }
    }
}

void retrait()
{
    char cinR[20];
    char holder[100];
    char cin[20],nom[20],pre[20];
    float mon;
    float mont;
    
    fichier = fopen("db.txt", "r");

    printf("Entrez CIN:");
    scanf("%s", &cinR);

    while (fgets(holder, 100, fichier)) {
        sscanf(holder, "%s %s %s %f" ,nom, pre, cin, &mon );
        if (strcmp(cinR,cin) == 0){
            
            printf("Montant: %f\n", mon); 
            printf("entrez solde:");
            scanf("%f",&mont);

            printf("le retrait est:%f Dh\n.",mon - mont );

        }
    }
}

void depot()
{
    char cinR[20];
    char holder[100];
    char cin[20],nom[20],pre[20];
    float mon;
    float mont;
    
    fichier = fopen("db.txt", "r");

    printf("Entrez CIN:");
    scanf("%s", &cinR);

    while (fgets(holder, 100, fichier)) {
        sscanf(holder, "%s %s %s %f" ,nom, pre, cin, &mon );
        if (strcmp(cinR,cin) == 0){
            
            printf("Montant: %f\n", mon); 
            printf("entrez solde:");
            scanf("%f",&mont);

            printf(" le depot est:%f Dh\n.",mon + mont );

        }
    }
}

void ascendant()
{
    
}

void descendant()
{

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

            do{
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
                    
                }
                                
            } while (choixOperation == 1);
            
			break;

        case 4:
            printf("Affichage:\n");
            
            do{
                printf("1. Recherche par CIN\n");
                printf("2. QUITTER !\n");

                scanf("%d", &choixAffichage);
                
                if (choixAffichage == 1)
                {
                    recherche();

                    printf("1. Voulez-vous revenir au menu principal ?\n");
                    printf("2. QUITTER !\n");

                    if(quitterReMenu == 1)
                    {
                        Menu();
                    }
                    else
                    {
                        printf("A bientot!");
                    }
                }

                else
                {
                    printf("A bientot!");
                }
                
            } while (choixAffichage == 1);
            
            break;

		case 5:
			printf("Fedilisation\n");
			break;

		case 6:
            printf("Quitter\n");
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