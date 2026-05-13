int main(){
    int mdp1=0;
    int mpd2=0;
    int mdp3=6;
    int mdp4=7;

    switch(mode()){ 
        case 1:
        choix_qcm();
        break;
        case 2 :
        verif_mdp(mdp1,mdp2,mpd3,mpd3);
        afficher_qcm();
        break;
        case 3 :
        verif_mdp(mdp1,mdp2,mpd3,mpd3);
        creer_qcm();
        break;
        case 4:
        verif_mdp(mdp1,mdp2,mpd3,mpd3);
        changer_mdp(&mdp1,&mdp2,&mdp3,&mdp4);
        break;
        
    }
    return 0;
}

}
