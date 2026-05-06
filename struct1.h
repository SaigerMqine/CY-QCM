#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define QUESTION 250
#define REPONSE 200


typedef struct {
    char question[QUESTION];
    
    int nb_reponse_propose;
    char **proposition;
    
    int point_vrai;
    int point_faux;
    
    int nb_reponse; 
    int *reponse; 
}Questions;


