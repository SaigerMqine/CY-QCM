#include "fonction.h"

Questions creerQuestions(){
	/// cet fonction permet la création de question qui seront implementer dans un QCM
	Questions q;
	
	printf("Saisis l'intitulé de ta question. (ATTENTION il y a 500 caractère maximum!!!!!)\n");
	fgets(q.question, QUESTION, stdin);
	q.question[strcspn(q.question, "\n")] = '\0';
	
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
	
	
	printf("Combien de point l'élève gagne si il répond VRAI ?\n");
	q.point_vrai = verifint();
	
	printf("Combien de point l'élève perds si il répond FAUX ?\n");
	q.point_faux = verifint()*(-1);
	
	printf("Combien de bonne réponse pour cette question ?\n");
	q.nb_reponse = verifint();
	
	q.reponse = malloc(sizeof(int)*q.nb_reponse);
	if (q.reponse == NULL){
    	exit(1);
    }
	for (int i=0; i<q.nb_reponse_propose; i++){
    	printf("Proposition %d : ", i+1);
        fgets(q.proposition[i], REPONSE, stdin);
	q.proposition[i][strcspn(q.proposition[i], "\n")] = '\0';
	}
	for(int i = 0; i<q.nb_reponse; i++){
		printf("Quelle(s) est(sont) la(es) bonne(s) reponse ?\n (Rentrer le numéro des réponses justes une par une.)");
		q.reponse[i] = verifint();
	}
	return q;
}

Qcm creer_QCM(){
	/// cet fonction permet la créatoin d'un QCM elle appelle la fonction -creerQuestions-
	Qcm f;
	printf("Saisis le nom du QCM (ATTENTION il y a 400 caractère maximum!!!!!)\n");
	fgets(f.Nom, NOM, stdin);
	f.Nom[strcspn(f.Nom, "\n")] = '\0';

	printf("Combien de questions le QCM va avoir ?\n");
	f.nb_questions = verifint();
	
	f.question_qcm = malloc(sizeof(Questions)*f.nb_questions);
	if (f.question_qcm == NULL){
		exit(2);
	}
	for(int i = 0; i<f.nb_questions; i++){
		f.question_qcm[i] = creerQuestions();
	}
	
	FILE *fichier = fopen("nom_qcm.txt", "a");
	if (fichier == NULL){
		printf("Erreur dans l'ouverture du fichier");
		exit(8);
	}
	fprintf(fichier, "%s\n", f.Nom);
	fclose(fichier);
	
	
	sauvegarder_QCM(f, f.Nom);
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


void sauvegarder_QCM(Qcm qcm, char *fichier_qcm) {
    FILE *f = fopen(fichier_qcm, "w");
    if (f == NULL) {
        printf("Erreur fichier\n");
        exit(5);
    }

    fprintf(f, "Nom:%s\n", qcm.Nom);
    fprintf(f, "NbQuestions:%d\n\n", qcm.nb_questions);

    for (int i = 0; i < qcm.nb_questions; i++) {
        Questions *q = &qcm.question_qcm[i];
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
	printf("Rentrer le mot de passe : (Entrez les 4 chiffres un par un).\n");
	scanf("%d", &verif_mdp1);
	scanf("%d", &verif_mdp2);
	scanf("%d", &verif_mdp3);
	scanf("%d", &verif_mdp4);
	if(verif_mdp1 !=mdp1||verif_mdp2 !=mdp2||verif_mdp3 !=mdp3||verif_mdp4 !=mdp4){
		printf("le mot de passe est faux, réssayez\n");
		return 0;
	}
	return 1;
}

void afficherQCM(char *nomFichier){
    Qcm qcm = charger_QCM(nomFichier);

    printf("Nom : %s\n", qcm.Nom);

    for(int i=0;i<qcm.nb_questions;i++){
        Questions q = qcm.question_qcm[i];

        printf("\nQuestion %d : %s\n", i+1, q.question);

        for(int j=0;j<q.nb_reponse_propose;j++){
            printf("%d) %s\n", j+1, q.proposition[j]);
        }
    }
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

void afficher_question(char *nomFichier){
	FILE *f = fopen(nomFichier, "r");
	if (f == NULL){
		printf("Le fichier ne s'ouvre pas!!! \n");
		exit(6);
	}
	Qcm q;
	char ligne[500];
	if (fgets(ligne, sizeof(ligne), f) != NULL) {
		strcpy(q.Nom, ligne + 4); 
		q.Nom[strcspn(q.Nom, "\n")] = '\0';
    }
}

Qcm charger_QCM(char *nomFichier) {
    FILE *f = fopen(nomFichier, "r");
    if (f == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier %s\n", nomFichier);
        exit(7);
    }

    Qcm qcm;
    

    if (fscanf(f, "Nom:%499[^\n]\n", qcm.Nom) != 1) {
        printf("Erreur de format : Nom du QCM introuvable\n");
        fclose(f);
        exit(8);
    }

    if (fscanf(f, "NbQuestions:%d\n\n", &qcm.nb_questions) != 1) {
        printf("Erreur de format : Nombre de questions introuvable\n");
        fclose(f);
        exit(8);
    }

    qcm.question_qcm = malloc(sizeof(Questions) * qcm.nb_questions);
    if (qcm.question_qcm == NULL) {
        fclose(f);
        exit(2);
    }

    for (int i = 0; i < qcm.nb_questions; i++) {
        Questions *q = &qcm.question_qcm[i];

        fscanf(f, "Question:%499[^\n]\n", q->question);
        fscanf(f, "NbRep:%d\n", &q->nb_reponse_propose);
        q->proposition = malloc(sizeof(char*) * q->nb_reponse_propose);
        if (q->proposition == NULL) {
			exit(2); 
		}

        for (int j = 0; j < q->nb_reponse_propose; j++) {
            q->proposition[j] = malloc(sizeof(char) * REPONSE);
            if (q->proposition[j] == NULL) { exit(3); }
            
            fscanf(f, "%399[^\n]\n", q->proposition[j]);
        }

        fscanf(f, "NbBonnes:%d\n", &q->nb_reponse);
        q->reponse = malloc(sizeof(int) * q->nb_reponse);
        if (q->reponse == NULL) { exit(1); }

        for (int j = 0; j < q->nb_reponse; j++) {
            fscanf(f, "%d\n", &q->reponse[j]);
        }

        fscanf(f, "PointsVrai:%d\n", &q->point_vrai);
        fscanf(f, "PointsFaux:%d\n\n", &q->point_faux);
    }

    fclose(f);
    printf("QCM chargé avec succès !\n");
    return qcm;
}
