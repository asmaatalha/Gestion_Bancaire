#include <stdio.h>
#include <stdlib.h>
#include <math.h>



//creation de compte ... 

int choixMulti, quitterReMenu, choixOperation, mul;
struct gestion
{
    char cin[20], nom[20], prenom[20]; 
    int montant, montant2, montant3;
}utilisateur;

//déclaration de fichier..
FILE * fichier = NULL;

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

    printf("Entrez votre CIN: ");
    scanf("%d", &utilisateur.cin);

    printf("Entrez le montant: ");
    scanf("%d", &utilisateur.montant2);

    mul = utilisateur.montant - utilisateur.montant2;

    printf("Montant reste: %d", mul);

    // printf("Le retrait a ete avec succes\n");

}

void depot()
{
    printf("Entrez votre CIN: ");
    scanf("%d", &utilisateur.cin);

    printf("Entrez le montant: ");
    scanf("%d", &utilisateur.montant3);

    mul = utilisateur.montant - utilisateur.montant3;

    printf("Montant: %d", mul);

    // printf("Le depot a ete avec succes");

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
            printf("1. Retrait\n");
            printf("2. Depot\n");
            printf("3. QUITTER !\n");
            
            do
            {
                scanf("%d", &choixOperation);

                if (choixOperation == 1)
                {
                    retrait();

                    if (utilisateur.cin == 1)
                    {
                        printf("coco");
                    }
                    
                    
            
                    printf("bien\n");

                    printf("2. Depot\n");
                    printf("3. QUITTER !\n");

                }
                else if (choixOperation == 2)
                {
                    depot();

                    printf("1. Retrait\n");
                    printf("3. QUITTER !\n");
                }
                else
                {
                    printf("A bientot!\n");
                    break;
                }
                                
            } while (choixOperation);
            
			break;

		case 4:
			printf("Affichage\n");
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