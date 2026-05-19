#include "struct1.h"

Questions creerQuestions(){
	/// cet fonction permet la création de question qui seront implementer dans un QCM
	Questions q;
	
	printf("Saisi l'intitulé de ta question ? (ATTENTION il y a 500 caractère maximum!!!!!)\n");
	scanf("%s", q.question);
	
	printf("Combien de propostition de réponse allez vous mettre ?\n");
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
	
	
	printf("Combien de point l'élève gagne si il repond VRAI ?\n");
	q.point_vrai = verifint();
	
	printf("Combien de point l'élève perds si il repond FAUX ?\n");
	q.point_faux = verifint()*(-1);
	
	printf("Combien de bonne reponse pour cet question ?\n");
	q.nb_reponse = verifint();
	
	for (int i=0; i<q.nb_reponse_propose; i++){
    	q.reponse = malloc(sizeof(int)*q.nb_reponse);
    	if (q.reponse == NULL){
    		exit(1);
    	}
    		printf("Proposition %d : ", i+1);
            scanf(" %s", q.proposition[i]);
	}
	for(int i = 0; i<q.nb_reponse; i++){
		printf("Quelle(s) est(sont) la(es) bonne(s) reponse ?\n");
		q.reponse[i] = verifint();
	}
	return q;
}

Qcm creer_QCM(){
	/// cet fonction permet la créatoin d'un QCM elle appelle la fonction -creerQuestions-
	Qcm f;
	printf("Saisi le nom du QCM ? (ATTENTION il y a 400 caractère maximum!!!!!)\n");
	scanf("%s", &f.Nom);

	printf("Combien de questions le QCM va avoir ?\n");
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


void sauvegarder_QCM(Qcm *qcm, char *fichier_qcm) {
    FILE *f = fopen(fichier_qcm, "w");
    if (f == NULL) {
        printf("Erreur fichier\n");
        exit(5);
    }

    fprintf(f, "Nom:%s\n", qcm->Nom);
    fprintf(f, "NbQuestions:%d\n\n", qcm->nb_questions);

    for (int i = 0; i < qcm->nb_questions; i++) {
        Questions *q = &qcm->question_qcm[i];
        fprintf(f, "Question:%s\n", q->question);
        fprintf(f, "NbRep:%d\n", q->nb_reponse_propose);
        for (int j = 0; j < q->nb_reponse_propose; j++) {
            fprintf(f, "%s\n", q->proposition[j]);
        }
        fprintf(f, "NbBonnes:%d\n", q->nb_reponse);
        for (int j = 0; j < q->nb_reponse; j++) {
            fprintf(f, "%d\n", q->reponse[j]);
        }
        fprintf(f, "PointsVrai:%d\n", q->point_vrai);
        fprintf(f, "PointsFaux:%d\n\n", q->point_faux);
    }
    fclose(f);
    printf("QCM sauvegardé avec succès !\n");
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

void afficherQCM(char *nomFichier) {
    FILE *f = fopen(nomFichier, "r");
    if (f == NULL) {
        printf("Erreur ouverture fichier\n");
        return;
    }

    char ligne[500];

    while (fgets(ligne, sizeof(ligne), f) != NULL) {
        printf("%s", ligne);
    }
    fclose(f);
}

int verifint(){            
	//verifie les int
    int d=0;
    char c;
    while(1){
        if(scanf("%d%c", &d, &c) == 2 && c == '\n'){ 
            return d;
        }
        else{
            printf("L'entrée n'est pas valide, tape un entier :\n");
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }
}

void afficher_question()










