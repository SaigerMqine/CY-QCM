#include "struct1.h"

Questions creerQuestions(){
	/// cet fonction permet la création de question qui seront implementer dans un QCM
	Questions q;
	
	printf("Saisi l'intituler de ta question ?\n");
	scanf("%s", &q.question);
	
	printf("Combien de propostition de reponse allez vous mettre ?\n");
	q.nb_reponse_propose = verifint();
	
	q.proposition = malloc(sizeof(char*)*nb_reponse_propose);
	if (q.proposition == NULL){
		exit(2);
	}
	for (int i=0; i<nb_reponse_propose; i++){
		q.proposition[i] = malloc(sizeof(char)*REPONSE);
		if (q.proposition[i] == NULL){
			exit(3);
		}
	}
	
	
	
	
	
	printf("Combien de point l'élève gagne si il repond VRAI\n");
	q.point_vrai = verifint();
	
	printf("Combien de point l'élève gagne si il repond FAUX\n");
	q.point_faux = verifint();
	
	printf("Combien de bonne reponse pour cet question ?\n");
	q.nb_reponse = verifint()
	
	q.question = malloc(sizeof(int)*nb_reponse);
	if (q.question == NULL){
		exit(1);
	}
	
}


