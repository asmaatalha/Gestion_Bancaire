#include <stdio.h>
#include <stdlib.h>
#include <math.h>



//creation de compte ... 
int choixMulti, quitterReMenu;
void creationCompte()
{

    FILE * fichier = NULL;


    fichier = fopen("db.txt", "a");

    if (fichier == NULL)
    {
        printf("ce fichier n'existe pas.\n");
    }

    else
    {
       fputs("asmaa talha", fichier); 
    }
    
    

    char cin[20], nom[20], prenom[20];
    int montant;
    
    printf("CIN: ");
    scanf("%s", &cin);
    
    printf("Nom: ");
    scanf(" %s", &nom);
    
    printf("Prenom: ");
    scanf(" %s", &prenom);
    
    printf("Montant: ");
    scanf("%d",&montant);
    
 	printf("vos informations :\n");
    printf("Nom: %s\n", nom);
    printf("Prenom: %s\n", prenom);
    printf("CIN: %s\n", cin);
    printf("Montant: %d\n", montant); 


 ////////////////////////////////
    fputs("Nom: %s\n", fichier);
    fputs("Prenom: %s\n", fichier);
    fputs("CIN: %s\n", fichier);
    fputs("Montant: %d\n", fichier);    
    
}
void menuFonction()
{
    int menu;
    // clean ecran 
	printf("1. Creation de compte\n");
	printf("2. Creation de plusiers comptes\n");
	printf("3. Operations\n");
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
                menuFonction();
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
			
                ///After creating the first account, giving the user 3 choices : if he hopes to create an other account, back to the principal menu or just leave ..

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
                    menuFonction();
                }
                else 
                {
                    printf("A bientot!");
                }
            } while(choixMulti == 1);	
        
			break;
		case 3:
			printf("Operations\n");
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
		    menuFonction();
		    break;
	}
}

int main()
{
    

    menuFonction() ;
}