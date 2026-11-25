#include "Year_Data.h"

int max (int a, int b){
/*La fonction max est une fonction qui renvoi le
nombre le plus grand entre a et b ou a si a=b*/	
	if (a >= b){
		return a;
	}
	else{
		return b;
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

void affiche_tab_annee(int  tab[20][5]){
/* Cet procedure permet d'afficher de manière lisible les information du tableau triée par année */	
	int i = 100;
	do{
		printf("\nDe quelle année voulez vous afficher les stat (nous disposons des statistiques entre 				 2005 et 2024) : ");
		scanf("%d", &i);
	}while(i<2005||i>2024);
	printf("\n En %d il y a eu %d accident : \nils on impliqué ; %d indemne👍, %d mort ⚰️ , %d blessé grave🩸 et %d blessé leger🤕.\n\n", i, tab[i-2005][0], tab[i-2005][1], tab[i-2005][2], tab[i-2005][3], tab[i-2005][4]);
}


void telecharge_fichier(int tab[20][5]){
/* Cet procedure permet de telechrger les donné du fichier sous forme d'un tableau.*/
	int year, b, c, d, e, g, h, i, j;
	for (int k = 0; k<20; k++){
		for (int l = 0; l<5; l++){
			tab[k][l]=0;
		}
	}
	
	FILE *f=fopen("cy_crash_tech_big_shuffled.csv", "r");
	if(f == NULL){
		exit(1);
	}
	char debut[1000];
	fgets(debut, 999, f);
	while(fscanf(f,"%d;%d;%d;%d;%d;%d;%d;%d;%d;", &year,&b,&c,&d,&e,&g,&h,&i,&j)==9){
		tab[year-2005][0] = max(tab[year-2005][0], b);
		switch(g){
			case (1):
				tab[year-2005][1] = tab[year-2005][1]+1;
				break;
			case (2):
				tab[year-2005][2] = tab[year-2005][2]+1;
				break;
			case (3):
				tab[year-2005][3] = tab[year-2005][3]+1;
				break;
			case (4):
				tab[year-2005][4] = tab[year-2005][4]+1;
				break;
		}
	}
	fclose(f);

}




int main(){
	int tab[20][5];
	telecharge_fichier(tab);
	affiche_tab_annee(tab);
	
	
	
	return 0;
}



