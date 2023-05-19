//
// Created by Scotch on 25/04/2023.
//
#include "bomberman.h"

void init_bombe(t_bombe bombe[]){
    for(int i=0;i<4;i++){
        bombe[i].explosion=0;
        for(int z=0;z<10;z++){
            bombe[i].x_plus_feu[z]=0;
            bombe[i].x_minus_feu[z]=0;
            bombe[i].y_plus_feu[z]=0;
            bombe[i].y_minus_feu[z]=0;
        }
    }
}

void init_perso(t_joueur perso[]){
    for(int i=0;i<2;i++){
        perso[i].feu=1;
        perso[i].nb_bombes=1;
        perso[i].vie=1;
    }
    perso[0].x=1;      perso[1].x=11;
    perso[0].y=1;      perso[1].y=9;
}
void init_matrice(int matrice[X][Y]){
    for(int i=0;i<X;i++){
        matrice[i][0]=1;
        matrice[i][Y-1]=1;
    }
    for(int j=0;j<Y;j++){
        matrice[0][j]=1;
        matrice[X-1][j]=1;
    }
    for(int k=0;k<X;k++){
        for(int l=0;l<Y;l++){
            if(k!=0 && k!=X-1 && k%2==0 && l!=0 && l!=Y-1 && l%2==0){
                matrice[k][l]=1;
            }
        }
    }
    for(int m=1;m<X-1;m++){
        for(int n=1;n<Y-1;n++){
            if(n%2-1==0){
                matrice[m][n]=2;
            }if(m%2-1==0){
                matrice[m][n]=2;
            }

        }
    }
    matrice[1][1]=7;    matrice[2][1]=0;    matrice[1][2]=0;

    matrice[1][8]=0;    matrice[2][9]=0;    matrice[1][9]=0;

    matrice[10][1]=0;    matrice[11][1]=0;    matrice[11][2]=0;

    matrice[11][8]=0;    matrice[11][9]=8;    matrice[10][9]=0;
}


void dplacement(int matrice[X][Y],t_joueur perso[],int *animation,bool touchePressed1[5], bool touchePressed2[5],int toucheIsPress1[5],int toucheIsPress2[5],BITMAP *page){
    int x1=perso[0].x;
    int y1=perso[0].y;

    int x2=perso[1].x;
    int y2=perso[1].y;
    textprintf_ex(screen,font,600,300, makecol(255,255,255),-1,"x : %d",perso[1].x);
    textprintf_ex(screen,font,600,320, makecol(255,255,255),-1,"y : %d",perso[1].y);

    textprintf_ex(screen,font,600,340, makecol(255,255,255),-1,"vie : %d",perso[1].vie);




    if(perso[0].vie!=0){
        for(int i=0;i<5;i++){
            if(touchePressed1[i]){
                if(!toucheIsPress1[i]){
                    if(i==0)
                        y1--;
                    if(i==1)
                        y1++;
                    if(i==2)
                        x1--;
                    if(i==3)
                        x1++;
                    if(matrice[x1][y1]!=1 && matrice[x1][y1]!=2 && matrice[x1][y1]!=3 && matrice[x1][y1]!=8){
                        if(matrice[x1][y1]==0){
                            matrice[perso[0].x][perso[0].y]=0;
                            matrice[x1][y1]=7;
                            perso[0].y=y1;
                            perso[0].x=x1;
                            toucheIsPress1[i]=1;
                            affichage(matrice,perso,page);
                        }else if(matrice[x1][y1]==4){
                            matrice[perso[0].x][perso[0].y]=0;
                            matrice[x1][y1]=7;
                            perso[0].y=y1;
                            perso[0].x=x1;
                            perso[0].vie=0;
                            //*animation=0; //ANIMATION DE MORT
                            //FIN?
                            toucheIsPress1[i]=1;
                            affichage(matrice,perso,page);
                        }else if(matrice[x1][y1]==5){
                            matrice[perso[0].x][perso[0].y]=0;
                            matrice[x1][y1]=7;
                            perso[0].y=y1;
                            perso[0].x=x1;
                            perso[0].feu+=1;
                            toucheIsPress1[i]=1;
                            affichage(matrice,perso,page);
                        }else if(matrice[x1][y1]==6){
                            matrice[perso[0].x][perso[0].y]=0;
                            matrice[x1][y1]=7;
                            perso[0].y=y1;
                            perso[0].x=x1;
                            perso[0].nb_bombes+=1;
                            toucheIsPress1[i]=1;
                            affichage(matrice,perso,page);

                        }
                    }
                }
            }else
                toucheIsPress1[i]=0;
        }
    }

    if(perso[1].vie!=0){
        for(int j=0;j<5;j++){
            if(touchePressed2[j]){
                textprintf_ex(screen,font,600,400, makecol(255,255,255),-1,"x2 : %d",x2);

                if(!toucheIsPress2[j]){
                    if(j==0)
                        y2--;
                    if(j==1)
                        y2++;
                    if(j==2)
                        x2--;
                    if(j==3)
                        x2++;
                    textprintf_ex(screen,font,600,400, makecol(255,255,255),-1,"x2 : %d",x2);
                    textprintf_ex(screen,font,600,420, makecol(255,255,255),-1,"y2 : %d",y2);

                    if(matrice[x2][y2]!=1 && matrice[x2][y2]!=2 && matrice[x2][y2]!=3 && matrice[x2][y2]!=8){
                        if(matrice[x2][y2]==0){
                            matrice[perso[1].x][perso[1].y]=0;
                            matrice[x2][y2]=8;
                            perso[1].y=y2;
                            perso[1].x=x2;
                            toucheIsPress2[j]=1;
                            affichage(matrice,perso,page);
                        }else if(matrice[x2][y2]==4){
                            matrice[perso[1].x][perso[1].y]=0;
                            matrice[x2][y2]=8;
                            perso[1].y=y2;
                            perso[1].x=x2;
                            perso[1].vie=0;
                            //*animation=0; //ANIMATION DE MORT
                            //FIN?
                            toucheIsPress2[j]=1;
                            affichage(matrice,perso,page);
                        }else if(matrice[x2][y2]==5){
                            matrice[perso[1].x][perso[1].y]=0;
                            matrice[x2][y2]=8;
                            perso[1].y=y2;
                            perso[1].x=x2;
                            perso[1].feu+=1;
                            toucheIsPress2[j]=1;
                            affichage(matrice,perso,page);
                        }else if(matrice[x2][y2]==6){
                            matrice[perso[1].x][perso[1].y]=0;
                            matrice[x2][y2]=8;
                            perso[1].y=y2;
                            perso[1].x=x2;
                            perso[1].nb_bombes+=1;
                            toucheIsPress2[j]=1;
                            affichage(matrice,perso,page);
                        }
                    }
                }
            }else
                toucheIsPress2[j]=0;
        }
    }
}

void explosion(t_joueur perso[],t_bombe bombe[],int matrice[X][Y],int *nbbombe){

    if(*nbbombe < perso[0].nb_bombes && key[KEY_SPACE]){
        bombe[*nbbombe].x=perso[0].x;
        bombe[*nbbombe].y=perso[0].y;
        bombe[*nbbombe].creation_time= time(NULL);
        bombe[*nbbombe].explosion=0;
        *nbbombe+=1;
    }

    time_t atm= time(NULL);
    int nbbombee = *nbbombe;



    // -> ON PLACE LE FEU SUR LES CASE VIDE JUSQU'AU MOMENT OU ON TROUVE UNE CASE AVEC BLOCK OU MUR
    // -> ON DETRUIT LE BLOCK OU ON S'ARRETE AU MUR
    // -> ON ENREGISTRE LA POSITION DE LA FLAMME POUR PLUS TARD REMETTRE CETTE POSITION A 0
    for(int i=0;i<nbbombee;i++){
        if(atm - bombe[i].creation_time >=2 && bombe[i].explosion!=1){
            bombe[i].explosion=1;

            //code d'explosion de bombe
            x_plus(bombe,matrice,perso,i);
            x_minus(bombe,matrice,perso,i);
            y_plus(bombe,matrice,perso,i);
            y_minus(bombe,matrice,perso,i);
        }
        if(atm - bombe[i].creation_time >= 4 && bombe[i].explosion==1){
            for(int z=0;z<10;z++){
                if(matrice[bombe[i].x_plus_feu[z]][bombe[i].y]==4){
                    matrice[bombe[i].x_plus_feu[z]][bombe[i].y]=0;
                }
                if(matrice[bombe[i].x_minus_feu[z]][bombe[i].y]==4){
                    matrice[bombe[i].x_minus_feu[z]][bombe[i].y]=0;
                }
                if(matrice[bombe[i].x][bombe[i].y_plus_feu[z]]==4){
                    matrice[bombe[i].x][bombe[i].y_plus_feu[z]]=0;
                }
                if(matrice[bombe[i].x][bombe[i].y_minus_feu[z]]==4){
                    matrice[bombe[i].x][bombe[i].y_minus_feu[z]]=0;
                }
            }
            *nbbombe-=1;
        }
    }
    /*int i=0;
    time_t begin[i];
    time_t end[i];
    int tabx[10];
    int taby[10];
    if(key[KEY_SPACE] && *restebombe < perso[0].nb_bombes){
        matrice[perso[0].x][perso[0].y]=9;
        *restebombe+=1;
        tabx[i]=perso[0].x;
        taby[i]=perso[0].y;
        begin[i]= time(NULL);
        i++;
    }
    end[i]= time(NULL);
    if(end[i]-begin[i]>=2 && end[i]-begin[i]){
        ///FEU AXE X +
        for(int s=0;s<perso[0].feu;s++){
            if(matrice[tabx[i]+s][taby[i]]!=1 && matrice[tabx[i]+s][taby[i]]!=2 && matrice[tabx[i]+s][taby[i]]!=7 && matrice[tabx[i]+s][taby[i]]!=8 && matrice[tabx[i]+s][taby[i]]!=9 && matrice[tabx[i]+s][taby[i]]!=10){
                matrice[tabx[i]+s][taby[i]]=4;
            }else if(matrice[tabx[i]+s][taby[i]]==1){
                matrice[tabx[i]+s][taby[i]]=1;
                break;
            }else if(matrice[tabx[i]+s][taby[i]]==2){
                matrice[tabx[i]+s][taby[i]]=0;
                break;
            }else if(matrice[tabx[i]+s][taby[i]]==7 || matrice[tabx[i]+s][taby[i]]==9){
                perso[0].vie=0;
            }else if(matrice[tabx[i]+s][taby[i]]==8 || matrice[tabx[i]+s][taby[i]]==10){
                perso[1].vie=0;
            }
        }
        ///FEU AXE X-
        for(int s=0;s>-perso[0].feu;s--){
            if(matrice[tabx[i]+s][taby[i]]!=1 && matrice[tabx[i]+s][taby[i]]!=2 && matrice[tabx[i]+s][taby[i]]!=7 && matrice[tabx[i]+s][taby[i]]!=8 && matrice[tabx[i]+s][taby[i]]!=9 && matrice[tabx[i]+s][taby[i]]!=10){
                matrice[tabx[i]+s][taby[i]]=4;
            }else if(matrice[tabx[i]+s][taby[i]]==1){
                matrice[tabx[i]+s][taby[i]]=1;
                break;
            }else if(matrice[tabx[i]+s][taby[i]]==2){
                matrice[tabx[i]+s][taby[i]]=0;
                break;
            }else if(matrice[tabx[i]+s][taby[i]]==7 || matrice[tabx[i]+s][taby[i]]==9){
                perso[0].vie=0;
            }else if(matrice[tabx[i]+s][taby[i]]==8 || matrice[tabx[i]+s][taby[i]]==10){
                perso[1].vie=0;
            }
        }
        ///FEU AXE Y+
        for(int s=0;s<perso[0].feu;s++){
            if(matrice[tabx[i]][taby[i]+s]!=1 && matrice[tabx[i]][taby[i]+s]!=2 && matrice[tabx[i]][taby[i]+s]!=7 && matrice[tabx[i]][taby[i]+s]!=8 && matrice[tabx[i]][taby[i]+s]!=9 && matrice[tabx[i]][taby[i]+s]!=10){
                matrice[tabx[i]][taby[i]+s]=4;
            }else if(matrice[tabx[i]][taby[i]+s]==1){
                matrice[tabx[i]][taby[i]+s]=1;
                break;
            }else if(matrice[tabx[i]][taby[i]+s]==2){
                matrice[tabx[i]][taby[i]+s]=0;
                break;
            }else if(matrice[tabx[i]][taby[i]+s]==7 || matrice[tabx[i]][taby[i]+s]==9){
                perso[0].vie=0;
            }else if(matrice[tabx[i]][taby[i]+s]==8 || matrice[tabx[i]][taby[i]+s]==10){
                perso[1].vie=0;
            }
        }
        ///FEU AXE Y-
        for(int s=0;s>-perso[0].feu;s--){
            if(matrice[tabx[i]][taby[i]+s]!=1 && matrice[tabx[i]][taby[i]+s]!=2 && matrice[tabx[i]][taby[i]+s]!=7 && matrice[tabx[i]][taby[i]+s]!=8 && matrice[tabx[i]][taby[i]+s]!=9 && matrice[tabx[i]][taby[i]+s]!=10){
                matrice[tabx[i]][taby[i]+s]=4;
            }else if(matrice[tabx[i]][taby[i]+s]==1){
                matrice[tabx[i]][taby[i]+s]=1;
                break;
            }else if(matrice[tabx[i]][taby[i]+s]==2){
                matrice[tabx[i]][taby[i]+s]=0;
                break;
            }else if(matrice[tabx[i]][taby[i]+s]==7 || matrice[tabx[i]][taby[i]+s]==9){
                perso[0].vie=0;
            }else if(matrice[tabx[i]][taby[i]+s]==8 || matrice[tabx[i]][taby[i]+s]==10){
                perso[1].vie=0;
            }
        }
    }*/

}

void x_plus(t_bombe bombe[],int matrice[X][Y],t_joueur perso[],int i){
    ///AXE X+
    for(int j=0;j<perso[0].feu;j++){
        if(matrice[bombe[i].x+j][bombe[i].y]!=1 && matrice[bombe[i].x+j][bombe[i].y]!=2){
            matrice[bombe[i].x+j][bombe[i].y]=4;
            if(bombe[i].x+j==perso[0].x && bombe[i].y==perso[0].y){
                perso[0].vie=0;
                /// RAJOUTER UNE VARIABLE POUR FINIR LA PARTIE (VOIR UN DRAW SPRITE)
            }
            if(bombe[i].x+j==perso[1].x && bombe[i].y==perso[1].y){
                perso[1].vie=0;
                /// RAJOUTER UNE VARIABLE POUR FINIR LA PARTIE (VOIR UN DRAW SPRITE)
            }
            bombe[i].x_plus_feu[j]=bombe[i].x+j;
            bombe[i].y_plus_feu[j]=bombe[i].y;

        }else if(matrice[bombe[i].x+j][bombe[i].y]==2){
            matrice[bombe[i].x+j][bombe[i].y]=0;
            break;
        }else if(matrice[bombe[i].x+j][bombe[i].y]==1){
            break;
        }
    }
}
void x_minus(t_bombe bombe[],int matrice[X][Y],t_joueur perso[],int i){
    ///AXE X-
    for(int j=0;j<perso[0].feu;j++){
        if(matrice[bombe[i].x-j][bombe[i].y]!=1 && matrice[bombe[i].x-j][bombe[i].y]!=2){
            matrice[bombe[i].x-j][bombe[i].y]=4;
            if(bombe[i].x-j==perso[0].x && bombe[i].y==perso[0].y){
                perso[0].vie=0;
                /// RAJOUTER UNE VARIABLE POUR FINIR LA PARTIE (VOIR UN DRAW SPRITE)
            }
            if(bombe[i].x-j==perso[1].x && bombe[i].y==perso[1].y){
                perso[1].vie=0;
                /// RAJOUTER UNE VARIABLE POUR FINIR LA PARTIE (VOIR UN DRAW SPRITE)
            }
            bombe[i].x_plus_feu[j]=bombe[i].x-j;
            bombe[i].y_plus_feu[j]=bombe[i].y;
        }else if(matrice[bombe[i].x-j][bombe[i].y]==2){
            matrice[bombe[i].x-j][bombe[i].y]=0;
            break;
        }else if(matrice[bombe[i].x-j][bombe[i].y]==1){
            break;
        }
    }
}
void y_plus(t_bombe bombe[],int matrice[X][Y],t_joueur perso[],int i){

    ///AXE Y+
    for(int j=0;j<perso[0].feu;j++){
        if(matrice[bombe[i].x][bombe[i].y+j]!=1 && matrice[bombe[i].x][bombe[i].y+j]!=2){
            matrice[bombe[i].x][bombe[i].y+j]=4;
            if(bombe[i].x==perso[0].x && bombe[i].y+j==perso[0].y){
                perso[0].vie=0;
                /// RAJOUTER UNE VARIABLE POUR FINIR LA PARTIE (VOIR UN DRAW SPRITE)
            }
            if(bombe[i].x==perso[1].x && bombe[i].y+j==perso[1].y){
                perso[1].vie=0;
                /// RAJOUTER UNE VARIABLE POUR FINIR LA PARTIE (VOIR UN DRAW SPRITE)
            }

            bombe[i].x_plus_feu[j]=bombe[i].x;
            bombe[i].y_plus_feu[j]=bombe[i].y+j;
        }else if(matrice[bombe[i].x][bombe[i].y+j]==2){
            matrice[bombe[i].x][bombe[i].y+j]=0;
            break;
        }else if(matrice[bombe[i].x][bombe[i].y+j]==1){
            break;
        }
    }
}
void y_minus(t_bombe bombe[],int matrice[X][Y],t_joueur perso[],int i){

    ///AXE Y-
    for(int j=0;j<perso[0].feu;j++){
        if(matrice[bombe[i].x][bombe[i].y-j]!=1 && matrice[bombe[i].x][bombe[i].y-j]!=2){
            matrice[bombe[i].x][bombe[i].y-j]=4;
            if(bombe[i].x==perso[0].x && bombe[i].y-j==perso[0].y){
                perso[0].vie=0;
                /// RAJOUTER UNE VARIABLE POUR FINIR LA PARTIE (VOIR UN DRAW SPRITE)
            }
            if(bombe[i].x==perso[1].x && bombe[i].y-j==perso[1].y){
                perso[1].vie=0;
                /// RAJOUTER UNE VARIABLE POUR FINIR LA PARTIE (VOIR UN DRAW SPRITE)
            }

            bombe[i].x_plus_feu[j]=bombe[i].x;
            bombe[i].y_plus_feu[j]=bombe[i].y-j;
        }else if(matrice[bombe[i].x][bombe[i].y-j]==2){
            matrice[bombe[i].x][bombe[i].y-j]=0;
            break;
        }else if(matrice[bombe[i].x][bombe[i].y-j]==1){
            break;
        }
    }
}


void affichage(int matrice[X][Y],t_joueur perso[]/*,BITMAP *objects[NBOBJECTS]*/,BITMAP *page){
    clear(page);
    for(int i=0;i<X;i++){
        for(int j=0;j<Y;j++){
            //draw_sprite(page,objects[matrice[i][j]],i*50,j*50);
            textprintf_ex(page,font,i*20,j*20, makecol(255,255,255),-1,"%d",matrice[i][j]); // test
        }
    }
    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
}

void Bomberman(){
    int matrice[X][Y];
    t_joueur perso[2];
    t_bombe bombe[4];
    //BITMAP *objects[ANMATION];
    BITMAP *page;
    int animation=0;
    bool TouchePressed1[5];
    bool TouchePressed2[5];
    int toucheIsPress1[5] = {0};
    int toucheIsPress2[5] = {0};



    page= create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(page);
    init_matrice(matrice);
    init_perso(perso);
    init_bombe(bombe);
    affichage(matrice,perso/*,objects*/,page);




    while(!key[KEY_ESC]){
        TouchePressed1[0]=key[KEY_UP];
        TouchePressed1[1]=key[KEY_DOWN];
        TouchePressed1[2]=key[KEY_LEFT];
        TouchePressed1[3]=key[KEY_RIGHT];

        TouchePressed2[0]=key[KEY_W];
        TouchePressed2[1]=key[KEY_S];
        TouchePressed2[2]=key[KEY_A];
        TouchePressed2[3]=key[KEY_D];

        dplacement(matrice,perso,&animation,TouchePressed1,TouchePressed2,toucheIsPress1,toucheIsPress2,page);
    }
}
