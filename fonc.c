#include "struct1.h"

Questions creerQuestions(){
	/// cet fonction permet la création de question qui seront implementer dans un QCM
	Questions q;
	
	printf("Saisi l'intituler de ta question ?\n");
	scanf("%s", &q.question);
	
	printf("Combien de propostition de reponse allez vous mettre ?\n");
	q.nb_reponse_propose = verifint();
	
	q.proposition = malloc(sizeof(char*)*nb_reponse_propose);
	if (q.proposition == NULL){
		exit(2);
	}
	for (int i=0; i<nb_reponse_propose; i++){
		q.proposition[i] = malloc(sizeof(char)*REPONSE);
		if (q.proposition[i] == NULL){
			exit(3);
		}
	}
	
	
	
	
	
	printf("Combien de point l'élève gagne si il repond VRAI\n");
	q.point_vrai = verifint();
	
	printf("Combien de point l'élève gagne si il repond FAUX\n");
	q.point_faux = verifint();
	
	printf("Combien de bonne reponse pour cet question ?\n");
	q.nb_reponse = verifint()
	
	q.question = malloc(sizeof(int)*nb_reponse);
	if (q.question == NULL){
		exit(1);
	}
	
}

int mode2(){
    int n = 0;
    printf("tape 1 pour afficher les qcm\ntape 2 pour créer un qcm\ntape 3 pour changer le mot de passe\n");
    n= verifint();
        while (n!=1 && n!=2 && n!=3){
            printf("la saisie n'est pas valide, choisis 1, 2, ou 3");
            n= verifint();
		}
}



			
         }
}

void sauvegarder_qcm(Refuge *refuge) {
    // cette fonction nous permet de mettre a jour notre fichier texte avec le stockage des habitant du chenYl
    FILE *f = fopen("EffectifChenYl.txt", "w");
    if (!f) {
        printf("Erreur : impossible d'ouvrir le fichier pour sauvegarder.\n");
        return;
    }

    for (int i = 0; i < refuge->nombre_animaux; i++) {
        Animal *a = &refuge->animaux[i];
        fprintf(f, "%ld\n", a->identifiant);
        fprintf(f, "%s\n", a->nom);
        fprintf(f, "%s\n", a->espece);
        fprintf(f, "%d\n", a->anneeNaissance);
        fprintf(f, "%.2f\n", a->poids);
        fprintf(f, "%s\n", strlen(a->commentaire) > 0 ? a->commentaire : "aucun");
        fprintf(f, "__________________________________________________\n");
        
    }

    fclose(f);
    printf("Sauvegarde reussie (%d animaux).\n", refuge->nombre_animaux);
}

