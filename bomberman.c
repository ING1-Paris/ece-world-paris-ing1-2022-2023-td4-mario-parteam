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
        perso[i].feu=2;
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
    matrice[1][1]=0;    matrice[2][1]=0;    matrice[1][2]=0;

    matrice[1][8]=0;    matrice[2][9]=0;    matrice[1][9]=0;

    matrice[10][1]=0;    matrice[11][1]=0;    matrice[11][2]=0;

    matrice[11][8]=0;    matrice[11][9]=0;    matrice[10][9]=0;
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
                    if(matrice[x1][y1]!=1 && matrice[x1][y1]!=2 && matrice[x1][y1]!=3 && (x1!=perso[1].x && y1!=perso[1].y)){
                        if(matrice[x1][y1]==0){
                            //matrice[perso[0].x][perso[0].y]=0;
                            //matrice[x1][y1]=7;
                            perso[0].y=y1;
                            perso[0].x=x1;
                            toucheIsPress1[i]=1;
                            affichage(matrice,perso,page);
                        }else if(matrice[x1][y1]==4){
                            //matrice[perso[0].x][perso[0].y]=0;
                            //matrice[x1][y1]=7;
                            perso[0].y=y1;
                            perso[0].x=x1;
                            perso[0].vie=0;
                            //*animation=0; //ANIMATION DE MORT
                            //FIN?
                            toucheIsPress1[i]=1;
                            affichage(matrice,perso,page);
                        }else if(matrice[x1][y1]==5){
                            //matrice[perso[0].x][perso[0].y]=0;
                            //matrice[x1][y1]=7;
                            perso[0].y=y1;
                            perso[0].x=x1;
                            perso[0].feu+=1;
                            toucheIsPress1[i]=1;
                            affichage(matrice,perso,page);
                        }else if(matrice[x1][y1]==6){
                            //matrice[perso[0].x][perso[0].y]=0;
                            //matrice[x1][y1]=7;
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
    } //DEPLACEMENT J1

    if(perso[1].vie!=0){
        for(int j=0;j<5;j++){
            if(touchePressed2[j]){

                if(!toucheIsPress2[j]){
                    if(j==0)
                        y2--;
                    if(j==1)
                        y2++;
                    if(j==2)
                        x2--;
                    if(j==3)
                        x2++;
                    if(matrice[x2][y2]!=1 && matrice[x2][y2]!=2 && matrice[x2][y2]!=3  && (x2!=perso[0].x && y2!=perso[0].y)){
                        if(matrice[x2][y2]==0){
                            //matrice[perso[1].x][perso[1].y]=0;
                            //matrice[x2][y2]=8;
                            perso[1].y=y2;
                            perso[1].x=x2;
                            toucheIsPress2[j]=1;
                            affichage(matrice,perso,page);
                        }else if(matrice[x2][y2]==4){
                            //matrice[perso[1].x][perso[1].y]=0;
                            //matrice[x2][y2]=8;
                            perso[1].y=y2;
                            perso[1].x=x2;
                            perso[1].vie=0;
                            //*animation=0; //ANIMATION DE MORT
                            //FIN?
                            toucheIsPress2[j]=1;
                            affichage(matrice,perso,page);
                        }else if(matrice[x2][y2]==5){
                            //matrice[perso[1].x][perso[1].y]=0;
                            //matrice[x2][y2]=8;
                            perso[1].y=y2;
                            perso[1].x=x2;
                            perso[1].feu+=1;
                            toucheIsPress2[j]=1;
                            affichage(matrice,perso,page);
                        }else if(matrice[x2][y2]==6){
                            //matrice[perso[1].x][perso[1].y]=0;
                            //matrice[x2][y2]=8;
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
    } //DEPLACEMENT J2
}

void explosion(t_joueur perso[],t_bombe bombej1[],t_bombe bombej2[],int matrice[X][Y],int *nbbombe1,int *nbbombe2,BITMAP *page){

    if(*nbbombe1 < perso[0].nb_bombes && key[KEY_RSHIFT]){
        bombej1[*nbbombe1].x=perso[0].x;
        bombej1[*nbbombe1].y=perso[0].y;
        bombej1[*nbbombe1].creation_time= time(NULL);
        bombej1[*nbbombe1].explosion=0;
        matrice[bombej1[*nbbombe1].x][bombej1[*nbbombe1].y]=3;
        *nbbombe1+=1;
    }

    if(*nbbombe2 < perso[1].nb_bombes && key[KEY_SPACE]){
        bombej2[*nbbombe2].x=perso[1].x;
        bombej2[*nbbombe2].y=perso[1].y;
        bombej2[*nbbombe2].creation_time= time(NULL);
        bombej2[*nbbombe2].explosion=0;
        matrice[bombej2[*nbbombe2].x][bombej2[*nbbombe2].y]=3;
        *nbbombe2+=1;
    }
    time_t atm= time(NULL);
    // -> ON PLACE LE FEU SUR LES CASE VIDE JUSQU'AU MOMENT OU ON TROUVE UNE CASE AVEC BLOCK OU MUR
    // -> ON DETRUIT LE BLOCK OU ON S'ARRETE AU MUR
    // -> ON ENREGISTRE LA POSITION DE LA FLAMME POUR PLUS TARD REMETTRE CETTE POSITION A 0
    for(int i=0;i<*nbbombe1;i++){
        if(atm - bombej1[i].creation_time >=2 && bombej1[i].explosion!=1){
            bombej1[i].explosion=1;

            //code d'explosion de bombe
            x_plus(bombej1,matrice,perso,i,0,page);
            x_minus(bombej1,matrice,perso,i,0,page);
            y_plus(bombej1,matrice,perso,i,0,page);
            y_minus(bombej1,matrice,perso,i,0,page);
            affichage(matrice,perso,page);

        }
        if(atm - bombej1[i].creation_time >= 4 && bombej1[i].explosion==1){
            for(int z=0;z<10;z++){
                if(matrice[bombej1[i].x_plus_feu[z]][bombej1[i].y]==4){
                    matrice[bombej1[i].x_plus_feu[z]][bombej1[i].y]=0;
                }
                if(matrice[bombej1[i].x_minus_feu[z]][bombej1[i].y]==4){
                    matrice[bombej1[i].x_minus_feu[z]][bombej1[i].y]=0;
                }
                if(matrice[bombej1[i].x][bombej1[i].y_plus_feu[z]]==4){
                    matrice[bombej1[i].x][bombej1[i].y_plus_feu[z]]=0;
                }
                if(matrice[bombej1[i].x][bombej1[i].y_minus_feu[z]]==4){
                    matrice[bombej1[i].x][bombej1[i].y_minus_feu[z]]=0;
                }
            }
            *nbbombe1-=1;
        }
    }
    for(int i=0;i<*nbbombe2;i++){
        if(atm - bombej2[i].creation_time >=2 && bombej2[i].explosion!=1){
            bombej2[i].explosion=1;

            //code d'explosion de bombe
            x_plus(bombej2,matrice,perso,i,1,page);
            x_minus(bombej2,matrice,perso,i,1,page);
            y_plus(bombej2,matrice,perso,i,1,page);
            y_minus(bombej2,matrice,perso,i,1,page);
            affichage(matrice,perso,page);

        }
        if(atm - bombej2[i].creation_time >= 4 && bombej2[i].explosion==1){
            for(int z=0;z<10;z++){
                if(matrice[bombej2[i].x_plus_feu[z]][bombej2[i].y]==4){
                    matrice[bombej2[i].x_plus_feu[z]][bombej2[i].y]=0;
                }
                if(matrice[bombej2[i].x_minus_feu[z]][bombej2[i].y]==4){
                    matrice[bombej2[i].x_minus_feu[z]][bombej2[i].y]=0;
                }
                if(matrice[bombej2[i].x][bombej2[i].y_plus_feu[z]]==4){
                    matrice[bombej2[i].x][bombej2[i].y_plus_feu[z]]=0;
                }
                if(matrice[bombej2[i].x][bombej2[i].y_minus_feu[z]]==4){
                    matrice[bombej2[i].x][bombej2[i].y_minus_feu[z]]=0;
                }
            }
            affichage(matrice,perso,page);
            *nbbombe2-=1;
        }
    }
}

void x_plus(t_bombe bombe[],int matrice[X][Y],t_joueur perso[],int i,int p,BITMAP *page){
    ///AXE X+
    for(int j=0;j<perso[p].feu;j++){
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
            textprintf_ex(screen,font,700,100, makecol(255,255,255),-1,"joueur : %d",i); // test
            textprintf_ex(screen,font,700,20*j, makecol(255,255,255),-1,"Bomb.x_plus_feu : %d",bombe[i].x_plus_feu[j]); // test


        }else if(matrice[bombe[i].x+j][bombe[i].y]==2){
            matrice[bombe[i].x+j][bombe[i].y]=0;
            break;
        }else if(matrice[bombe[i].x+j][bombe[i].y]==1){
            break;
        }
    }
}
void x_minus(t_bombe bombe[],int matrice[X][Y],t_joueur perso[],int i,int p,BITMAP *page){
    ///AXE X-
    for(int j=0;j<perso[p].feu;j++){
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
void y_plus(t_bombe bombe[],int matrice[X][Y],t_joueur perso[],int i,int p,BITMAP *page){

    ///AXE Y+
    for(int j=0;j<perso[p].feu;j++){
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
void y_minus(t_bombe bombe[],int matrice[X][Y],t_joueur perso[],int i,int p,BITMAP *page){

    ///AXE Y-
    for(int j=0;j<perso[p].feu;j++){
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
    textprintf_ex(page,font,perso[0].x*20,perso[0].y*20, makecol(255,255,255),-1,"7");
    textprintf_ex(page,font,perso[1].x*20,perso[1].y*20, makecol(255,255,255),-1,"8");

    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
}

void Bomberman(){
    int matrice[X][Y];
    t_joueur perso[2];
    t_bombe bombej1[10];
    t_bombe bombej2[10];

    //BITMAP *objects[ANMATION];
    BITMAP *page;
    int animation=0;
    bool TouchePressed1[5];
    bool TouchePressed2[5];
    int toucheIsPress1[5] = {0};
    int toucheIsPress2[5] = {0};
    int nbbombe1,nbbombe2;
    nbbombe1 = nbbombe2 = 0;



    page= create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(page);
    init_matrice(matrice);
    init_perso(perso);
    init_bombe(bombej1);
    init_bombe(bombej2);
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
        textprintf_ex(page,font,500,0, makecol(255,255,255),-1,"Bombj1.explosion : %d",bombej1[0].explosion); // test
        textprintf_ex(page,font,500,20, makecol(255,255,255),-1,"BombJ1.x_plus_feu : %d",bombej1[0].x_plus_feu[0]); // test
        textprintf_ex(page,font,500,40, makecol(255,255,255),-1,"Bombj1.x_minus_feu : %d",bombej1[0].x_minus_feu[0]); // test
        textprintf_ex(page,font,500,60, makecol(255,255,255),-1,"Bombj1.y_plus_feu : %d",bombej1[0].y_plus_feu[0]); // test
        textprintf_ex(page,font,500,80, makecol(255,255,255),-1,"Bombj1.y_minus_feu : %d",bombej1[0].y_minus_feu[0]); // test
        //blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        dplacement(matrice,perso,&animation,TouchePressed1,TouchePressed2,toucheIsPress1,toucheIsPress2,page);
        explosion(perso,bombej1,bombej2,matrice,&nbbombe1,&nbbombe2,page);
    }
}
