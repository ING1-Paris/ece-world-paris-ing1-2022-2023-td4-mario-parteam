//
// Created by Scotch on 25/04/2023.
//
#include "bomberman.h"

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

void explosion(t_joueur perso[],int matrice[X][Y],int *restebombe){
    if(key[KEY_SPACE] && *restebombe < perso[0].nb_bombes){
        matrice[perso[0].x][perso[0].y]=9;
        *restebombe+=1;
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
