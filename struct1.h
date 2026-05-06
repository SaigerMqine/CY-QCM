#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define QUESTION 150
#define REPONSE 100
#define NOM_QCM 200


typedef struct {
    char question[QUESTION];
    char un[REPONSE];
    char deux[REPONSE];
    char trois[REPONSE];
    char quatre[REPONSE];
    
    int point_vrai;
    int point_faux;
    
    int nb_reponse; 
    int *reponse; 
}Questions;

 typedef struct {
char Nom[nom_qcm];
int nb_questions;
Questions* question_qcm;
}Qcm;

