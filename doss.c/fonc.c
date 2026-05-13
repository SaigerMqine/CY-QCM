#include "struct1.h"

Questions creerQuestions(){
	/// cet fonction permet la création de question qui seront implementer dans un QCM
	Questions q;
	
	printf("Saisi l'intituler de ta question ? (ATTENTION il y a 500 caractère maximum!!!!!)\n");
	scanf("%s", &q.question);
	
	printf("Combien de propostition de reponse allez vous mettre ?\n");
	q.nb_reponse_propose = verifint();
	
	q.proposition = malloc(sizeof(char*)*q.nb_reponse_propose);
	if (q.proposition == NULL){
		exit(2);
	}
	for (int i=0; i<q.nb_reponse_propose; i++){
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
	q.nb_reponse = verifint();
	
	q.reponse = malloc(sizeof(int)*q.nb_reponse);
	if (q.reponse == NULL){
		exit(1);
	}
	for(int i = 0; i<q.nb_reponse; i++){
		printf("quelle(s) est(sont) la(es) bonne(s) reponse \n");
		scanf("%d", &q.reponse[i]);
	}
	return q;
}


Qcm creer_QCM(){
	/// cet fonction permet la créatoin d'un QCM elle appelle la fonction -creerQuestions-
	Qcm f;
	printf("Saisi le nom du QCM ? (ATTENTION il y a 400 caractère maximum!!!!!)\n");
	scanf("%s", &f.Nom);

	printf("Combien de questions le QCM va avoir de questions\n");
	f.nb_questions = verifint();
	
	f.question_qcm = malloc(sizeof(Questions)*f.nb_questions);
	if (f.question_qcm == NULL){
		exit(2);
	}
	for(int i = 0; i<f.nb_questions; i++){
		f.question_qcm[i] = creerQuestions();
	}
	return f;
}
	
	
	
int mode1(){
    int n = 0;
    printf("tape 1 si tu es élève\ntape 2 si tu es prof\n");
    n= verifint();
        while (n!=1 && n!=2){
            printf("la saisie n'est pas valide, choisis 1, ou 2");
            n= verifint();
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

int verif_mdp(int mdp1, int mdp2, int mdp3, int mdp4){
	int verif_mdp1,verif_mdp2,verif_mdp3,verif_mdp4;
	printf("mot de passe\n");
	scanf("%d", &verif_mdp1);
	scanf("%d", &verif_mdp2);
	scanf("%d", &verif_mdp3);
	scanf("%d", &verif_mdp4);
	if(verif_mdp1 !=mdp1||verif_mdp2 !=mdp2||verif_mdp3 !=mdp3||verif_mdp4 !=mdp4){
	printf("le mot de passe est faux\n");
	return 0;
	}
	return 1;
	}
