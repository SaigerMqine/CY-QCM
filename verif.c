int verifint(){            //verifie les int
    int d=0;
    char c;
    char err;
    if(scanf("%d%c", &d, &c) == 2 && c == '\n'){ 
        return d;
    }
     else {
            while ((c = getchar()) != '\n' && c != EOF);
    }
}


char* verif_nom_qcm(){            //verifie les noms
char* name = malloc(Nom_qcm* sizeof(char)); 
    if (name == NULL) {
        printf("erreur malloc\n");
        exit(1);
    }
     if (fgets(name, Nom_qcm, stdin) != NULL) {
        size_t len = strlen(name);
    }
else {
        printf("rentre un nom correct\n");
        free(name);
        return 0;
    }
    return name;
}

    
