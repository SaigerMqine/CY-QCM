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
int verif_mdp(int mdp1, int mdp2, int mdp3, int mdp4);
void afficherQCM(char *nomFichier);
int verifint();
void afficher_question(char *nomFichier);
Qcm charger_QCM(char *nomFichier);
void choix_qcm();
void faire_QCM(Qcm qcm);
void changer_mdp(int * a1,int * a2,int * a3,int * a4);