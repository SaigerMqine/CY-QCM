#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define QUESTION 150
#define REPONSE 100


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

