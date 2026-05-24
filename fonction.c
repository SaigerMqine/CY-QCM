#include "fonction.h"

void tri(int *tab, int n){
	for(int i = 0; i < n-1; i++){
		int min = i;
		for(int j = i + 1; j < n; j++){
			if(tab[j] < tab[min]){
				min = j;
			}
		}
		int temp = tab[i];
		tab[i] = tab[min];
		tab[min] = temp;
	}
}

Questions creerQuestions(){
	// cette fonction permet la creation de questions qui seront implementées dans un QCM
	Questions q;
	
	printf("Saisis l intitule de ta question. (ATTENTION il y a 500 caractere maximum!!!!!)\n");
	fgets(q.question, QUESTION, stdin);
	q.question[strcspn(q.question, "\n")] =  '\0' ;
	
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
	
	
	printf("Combien de point l eleve gagne si il repond VRAI ?\n");
	q.point_vrai = verifint();
	
	printf("Combien de point l eleve perds si il repond FAUX ?\n");
	q.point_faux = verifint()*(-1);
	
	printf("Combien de bonne reponse pour cette question ?\n");
	q.nb_reponse = verifint();
	
	q.reponse = malloc(sizeof(int)*q.nb_reponse);
	if (q.reponse == NULL){
		exit(1);
	}
	for (int i=0; i<q.nb_reponse_propose; i++){
	printf("Proposition %d : ", i+1);
fgets(q.proposition[i], REPONSE, stdin);
	q.proposition[i][strcspn(q.proposition[i], "\n")] =  '\0' ;
	}
	for(int i = 0; i<q.nb_reponse; i++){
		printf("Quelle(s) est(sont) la(es) bonne(s) reponse ? (Rentrer le numero des reponses justes une par une.\n)");
		q.reponse[i] = verifint();
	}
	return q;
}

Qcm creer_QCM(){
	// cette fonction permet la creation d'un QCM elle appelle la fonction -creerQuestions-
	Qcm f;
	printf("Saisis le nom du QCM (ATTENTION il y a 400 caractere maximum!!!!!)\n");
	fgets(f.Nom, NOM, stdin);
	f.Nom[strcspn(f.Nom, "\n")] =  '\0' ;

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
		printf("Erreur dans l ouverture du fichier");
		exit(8);
	}
	fprintf(fichier, "%s\n", f.Nom);
	fclose(fichier);
	
	
	sauvegarder_QCM(f, f.Nom);		// sauvegarde du qcm créé dans un fichier texte
	return f;
}
	
	
	
int mode1(){
	// Cette fonction permet d'afficher l'interface qui va permettre de choisir entre le mode prof et élève
    int n = 0;
    printf("1. Mode eleve\n2. Mode prof\n3. Sortir de l application\n");
    n= verifint();
        while (n!=1 && n!=2 && n!= 3){
            printf("la saisie n est pas valide, choisis 1, 2 ou 3");
            n= verifint();
		}
}


int mode2(){
	// Cette fonction permet d'afficher l'interface qui va permettre de choisir entre les possibles actions dans le mode prof
    int n = 0;
    printf("1. Afficher les qcm\n2. Creer un qcm\n3. Changer le mot de passe\n");
    n= verifint();
        while (n!=1 && n!=2 && n!=3){
            printf("la saisie n est pas valide, choisis 1, 2, ou 3");
            n= verifint();
		}
}


void sauvegarder_QCM(Qcm qcm, char *fichier_qcm) {
	//Cette fonction permet de sauvgarder les qcm dans des fichiers texte dans un format particulier qui nous permettera de le recuperer plus tard 
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
    printf("QCM sauvegarde avec succes !\n");
}

int verif_mdp(int mdp1, int mdp2, int mdp3, int mdp4){
	//Cette fonction permet de verifier le mot de passe pour accéder au mode prof 
	int verif_mdp1,verif_mdp2,verif_mdp3,verif_mdp4;
	printf("Rentrer le mot de passe : (Entrez les 4 chiffres un par un).\n");
	scanf("%d", &verif_mdp1);
	scanf("%d", &verif_mdp2);
	scanf("%d", &verif_mdp3);
	scanf("%d", &verif_mdp4);
	if(verif_mdp1 !=mdp1||verif_mdp2 !=mdp2||verif_mdp3 !=mdp3||verif_mdp4 !=mdp4){
		printf("le mot de passe est faux, ressayez\n");
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
        if(scanf("%d%c", &d, &c) == 2 && c ==  '\n' ){ 
            return d;
        }
        else{
            printf("L entree n est pas valide, tape un entier :'\n'");
            while ((c = getchar()) !=  '\n'  && c != EOF);
        }
    }
}

void afficher_question(char *nomFichier){
	// Cette fonction permet d'affichier les questions quand un élève passe un qcm
	FILE *f = fopen(nomFichier, "r");
	if (f == NULL){
		printf("Le fichier ne s ouvre pas!!! \n");
		exit(6);
	}
	Qcm q;
	char ligne[500];
	if (fgets(ligne, sizeof(ligne), f) != NULL) {
		strcpy(q.Nom, ligne + 4); 
		q.Nom[strcspn(q.Nom, "\n")] =  '\0' ;
    }
}

Qcm charger_QCM(char *nomFichier) {
	//Cette fonction permet de récupérer depuis les fichiers texte les infos des qcm et les mettre sous forme de structure
    FILE *f = fopen(nomFichier, "r");
    if (f == NULL) {
        printf("Erreur : Impossible d ouvrir le fichier %s\n", nomFichier);
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
            if (q->proposition[j] == NULL) {
				exit(3); 
			}
            fscanf(f, "%399[^\n]\n", q->proposition[j]);
        }

        fscanf(f, "NbBonnes:%d\n", &q->nb_reponse);
        q->reponse = malloc(sizeof(int) * q->nb_reponse);
        if (q->reponse == NULL) { 
			exit(1); 
		}

        for (int j = 0; j < q->nb_reponse; j++) {
            fscanf(f, "%d\n", &q->reponse[j]);
        }

        fscanf(f, "PointsVrai:%d\n", &q->point_vrai);
        fscanf(f, "PointsFaux:%d\n\n", &q->point_faux);
    }

    fclose(f);
    printf("QCM charge avec succes !\n");
    return qcm;
}

void choix_qcm(){
	//Cette fonction affiche le nom de tout les qcm existants et permet de choisir auquel repondre 
    FILE *fichier = fopen("nom_qcm.txt", "r");
    if (fichier == NULL){
        printf("Erreur ouverture fichier\n");
        exit(7);
    }
    char noms[20][NOM];
    int c = 0;

    printf("Liste des QCM disponibles :\n");
    while (fgets(noms[c], NOM, fichier) != NULL){
        noms[c][strcspn(noms[c], "\n")] =  '\0' ;
        printf("%d) %s\n", c+1, noms[c]);
        c++;
    }
    fclose(fichier);
    printf("Choisis un QCM (numero) :\n");
    int choix = verifint();
    if (choix < 1 || choix > c){
        printf("Choix invalide\n");
        return;
    }
    Qcm qcm = charger_QCM(noms[choix-1]);
    faire_QCM(qcm);
}

void faire_QCM(Qcm qcm){
	//Cette fonction permet de passer les qcm dans le mode élève 
	int score = 0;
	int total = 0;
    printf("\n=== %s ===\n", qcm.Nom);

    for(int i = 0; i < qcm.nb_questions; i++){
    	Questions q = qcm.question_qcm[i];
    	total = total + q.point_vrai;

        printf("\nQuestion %d :\n\n%s\n", i+1, q.question);
        for(int j = 0; j < q.nb_reponse_propose; j++){
			if(j==2){
				printf("\n");
			}
        	printf("%d) %s	  ", j+1, q.proposition[j]);
        }
        printf("\nCombien de reponses veux-tu donner ?\n");
        int rep = verifint();
		int *correction = malloc(sizeof(int)*rep);
		int vrai = 0;
        for(int k = 0; k < rep; k++){
        	printf("Reponse %d : ", k+1);
            correction[k] = verifint();
			while(correction[k] < 1 || correction[k] > q.nb_reponse_propose){
				printf("\nCe numéro de réponse n'est pas proposé, recommence : ");
				correction[k] = verifint();
			}
			for(int m = 0; m < k; m++){
	    		if(correction[k] == correction[m]){
	        		printf("Tu as déjà donné cette réponse, choisis en une autre\n");
	        		k--;
	        		break;
				}
			}
        }
		tri(correction, rep);
        for(int l = 0; l < q.nb_reponse; l++){
        	if(correction[l] == q.reponse[l]){
                vrai=1;
            }
            else{
                vrai = 0;
            }
        }
        if(vrai == 1){
            printf("Bonne reponse, tu gagnes %d points !\n", q.point_vrai);
            score = score + q.point_vrai;
        }
	    else {
            printf("Mauvaise reponse ! %d points.. dommage\n", q.point_faux);
            score = score + q.point_faux;
        }
    }
    int score_final = (score/total)*20;
	printf("\nFin du QCM !\nTon score : %d/%d\n", score_final, 20);
}

void changer_mdp(int *a1,int *a2,int *a3,int *a4){
	//Cette fonction permet de changer le mot de passe pour acceder au mode prof 
	printf("Entree le mot de passe actuel pour le changer.\n");
	if (verif_mdp (*a1, *a2, *a3, *a4) == 1){
    	printf("quel est le nouveau mdp ?\n");
    	scanf("%d",a1);
    	scanf("%d",a2);
        scanf("%d",a3);
        scanf("%d",a4);
        printf("le nouveau mot de passe est : %d %d %d %d \n",*a1,*a2,*a3,*a4);
    }
	else {
		printf("Vous ne pouvez pas changer le mot de passe sans connaitre l ancien !!!!!! \n");
	}
}
