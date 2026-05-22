#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define QUESTION 500
#define REPONSE 400
#define NOM 500


typedef struct {
    char question[QUESTION];
    
    int nb_reponse_propose;
    char **proposition;
    
    int point_vrai;
    int point_faux;
    
    int nb_reponse; 
    int *reponse; 
}Questions;
 
typedef struct {
    char Nom[NOM];
    int nb_questions;
    Questions* question_qcm;
}Qcm;


Questions creerQuestions();
Qcm creer_QCM();
int mode1();
int mode2();
void sauvegarder_QCM(Qcm qcm, char *fichier_qcm);
int verifint();
void afficherQCM(char *nom_Fichier);
int verif_mdp(int mdp1, int mdp2, int mdp3, int mdp4);
Qcm charger_QCM(char *nomFichier);

