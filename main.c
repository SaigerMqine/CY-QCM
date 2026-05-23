#include "fonction.h"


int main(){
    int mdp1=0;
    int mdp2=0;
    int mdp3=6;
    int mdp4=7;
    int valide;
    char nom[200];
    
    while(1) { 
        
        switch(mode1()) { 
            
            case 1: 
                choix_qcm();
                break; 

            case 2: 
                do {
                    valide = verif_mdp(mdp1, mdp2, mdp3, mdp4);
                } while(valide != 1);

                switch(mode2()) { 
                    case 1:
                        printf("Entrez le nom du QCM que vous voulez voir :\n");
                        fgets(nom, 200, stdin);
                        nom[strcspn(nom, "\n")] = '\0';
                        afficherQCM(nom);
                        break;
                        
                    case 2:
                        creer_QCM();
                        break;
                        
                    case 3:
                        changer_mdp(&mdp1, &mdp2, &mdp3, &mdp4);
                        break;  
                }
                break; 

            case 3:
                printf("\nMerci d'avoir utilise l application ! Au revoir.\n");
                return 0; 
        }
        
        printf("\n--------------------------------------------------------------\n\n");
    }

    return 0;
}