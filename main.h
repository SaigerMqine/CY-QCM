int mode(){
    int n = 0;
    printf("tape 1 pour répondre a un qcm \ntape 2 pour afficher les qcm\ntape 3 pour créer un qcm\n");
    n= verifint();
        while (n!=1 && n!=2 && n!=3){
            printf("t a pas taper 1 2 ou 3 mon reuf peut tu reessayer");
            n= verifint();
         }
}
        
