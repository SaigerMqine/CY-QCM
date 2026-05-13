int main(){
    int mdp1=0;
    int mpd2=0;
    int mdp3=6;
    int mdp4=7;
    int valide;

    switch(mode1()){ 
        case 1:
            choix_qcm();
        break;
        case 2 :
            do{
                valide =verif_mdp(mdp1,mdp2,mpd3,mpd3);
            }while(valide !=1);
            switch(mode2()){ 
                case 1 :
                    afficher_qcm();
                break;
                case 2 :
                    creer_qcm();
                break;
                case 3 :
                    changer_mdp(&mdp1,&mdp2,&mdp3,&mdp4);
                break;  
        }
        break;
    }

    
   
    return 0;
}
