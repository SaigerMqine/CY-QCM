#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define QUESTION 250
#define REPONSE 200
#define Nom_qcm 200


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
char Nom[Nom_qcm];
int nb_questions;
Questions* question_qcm;
}Qcm;


Questions creerQuestions();
Qcm creer_QCM();
int mode1();
int mode2();
void sauvegarder_qcm();
int verif_mdp(int mdp1, int mdp2, int mdp3, int mdp4);


