#include <stdio.h>
#include <stdlib.h>
#include <math.h>



//creation de compte ... 


// void insert()
// {
//     struct gestion
//     {
//         char cin[20]; 
//         char nom[20]; 
//         char prenom[20];
//         int montant;
//     }users;
    
//     FILE * fichier;
//     fichier = fopen("db.txt", "a");

//     printf("CIN: ");
//     scanf("%s", &users.cin);

//     printf("Nom: ");
//     scanf("%s", &users.nom);

//     printf("Prenom: ");
//     scanf("%s", &users.prenom);

//     printf("Montant: ");
//     scanf("%s", &users.montant);

//     fwrite(&users, sizeof(users), 1, fichier);
//     fclose(fichier);
    
// }

int choixMulti, quitterReMenu;

//déclaration de fichier
FILE * fichier = NULL;

void creationCompte()
{
    fichier = fopen("db.txt", "a");
    
    struct gestion
    {
        char cin[20]; 
        char nom[20]; 
        char prenom[20];
        int montant;
    }utilisateur;
    
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
        
}
void Menu()
{
    int menu;
    
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
                    Menu();
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
		    Menu();
		    break;
	}
}

int main()
{
    

    Menu() ;
}