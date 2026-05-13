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

