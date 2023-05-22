//
// Created by Scotch on 25/04/2023.
//
#include "bomberman.h"

void init_bombe(t_bombe bombe[]){
    for(int i=0;i<10;i++){
        bombe[i].explosion=0;
        for(int x=0;x<X;x++){
            for(int y=0;y<Y;y++){
                    bombe[i].matrice[x][y]=0;
                }
            }
        }
    }

void init_perso(t_joueur perso[]){
    for(int i=0;i<2;i++){
        perso[i].feu=2;
        perso[i].nb_bombes=1;
        perso[i].vie=1;
    }
    perso[0].front[0]= load_bitmap("images/Link_Green_front0.bmp",NULL);
    perso[0].front[1]= load_bitmap("images/Link_Green_front1.bmp",NULL);
    perso[0].front[2]= load_bitmap("images/Link_Green_front2.bmp",NULL);

    perso[0].back[0]= load_bitmap("images/Link_Green_back0.bmp",NULL);
    perso[0].back[1]= load_bitmap("images/Link_Green_back1.bmp",NULL);
    perso[0].back[2]= load_bitmap("images/Link_Green_back2.bmp",NULL);

    perso[0].side[0]= load_bitmap("images/Link_Green_side0.bmp",NULL);
    perso[0].side[1]= load_bitmap("images/Link_Green_side1.bmp",NULL);
    perso[0].side[2]= load_bitmap("images/Link_Green_side2.bmp",NULL);


    perso[1].front[0]= load_bitmap("images/Link_Blue_front0.bmp",NULL);
    perso[1].front[1]= load_bitmap("images/Link_Blue_front1.bmp",NULL);
    perso[1].front[2]= load_bitmap("images/Link_Blue_front2.bmp",NULL);

    perso[1].back[0]= load_bitmap("images/Link_Blue_back0.bmp",NULL);
    perso[1].back[1]= load_bitmap("images/Link_Blue_back1.bmp",NULL);
    perso[1].back[2]= load_bitmap("images/Link_Blue_back2.bmp",NULL);

    perso[1].side[0]= load_bitmap("images/Link_Blue_side0.bmp",NULL);
    perso[1].side[1]= load_bitmap("images/Link_Blue_side1.bmp",NULL);
    perso[1].side[2]= load_bitmap("images/Link_Blue_side2.bmp",NULL);


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

    matrice[6][5]=7;    matrice[1][5]=5;    matrice[11][5]=5;   matrice[6][1]=5;    matrice[6][9]=5;

    matrice[4][5]=5;    matrice[6][3]=5;    matrice[6][7]=5;    matrice[9][5]=5;
}


void dplacement(int matrice[X][Y],t_joueur perso[],int *animation,bool touchePressed1[5], bool touchePressed2[5],int toucheIsPress1[5],int toucheIsPress2[5],BITMAP *page,BITMAP *Object[NBOBJECTS],BITMAP *stage,int *u1,int *d1,int *r1,int *l1,int *u2,int *d2,int *r2,int *l2,BITMAP *mortj1,BITMAP *mortj2){
    int x1=perso[0].x;
    int y1=perso[0].y;

    int x2=perso[1].x;
    int y2=perso[1].y;

    if(perso[0].vie!=0){
        for(int i=0;i<5;i++){
            if(touchePressed1[i]){
                if(!toucheIsPress1[i]){
                    if(i==0){
                        y1--;
                        *u1+=1;
                        *u1%=ANMATION;
                        *d1=*r1=*l1=4;
                    }
                    if(i==1){
                        y1++;
                        *d1+=1;
                        *d1%=ANMATION;
                        *u1=*r1=*l1=4;
                    }
                    if(i==2){
                        x1++;
                        *r1+=1;
                        *r1%=ANMATION;
                        *d1=*u1=*l1=4;
                    }
                    if(i==3){
                        x1--;
                        *l1+=1;
                        *l1%=ANMATION;
                        *d1=*u1=*r1=4;
                    }
                    if(matrice[x1][y1]!=1 && matrice[x1][y1]!=2 && matrice[x1][y1]!=3 && (x1!=perso[1].x || y1!=perso[1].y)) {
                        if(matrice[x1][y1]==0){
                            //matrice[perso[0].x][perso[0].y]=0;
                            //matrice[x1][y1]=7;
                            perso[0].y=y1;
                            perso[0].x=x1;
                            toucheIsPress1[i]=1;
                            affichage(matrice,perso,Object,page,stage,mortj1,mortj2,*u1,*d1,*r1,*l1,*u2,*d2,*r2,*l2);
                        }else if(matrice[x1][y1]==4){
                            //matrice[perso[0].x][perso[0].y]=0;
                            //matrice[x1][y1]=7;
                            perso[0].y=y1;
                            perso[0].x=x1;
                            perso[0].vie-=1;
                            //*animation=0; //ANIMATION DE MORT
                            //FIN?
                            toucheIsPress1[i]=1;
                            affichage(matrice,perso,Object,page,stage,mortj1,mortj2,*u1,*d1,*r1,*l1,*u2,*d2,*r2,*l2);
                        }else if(matrice[x1][y1]==5){
                            //matrice[perso[0].x][perso[0].y]=0;
                            //matrice[x1][y1]=7;
                            perso[0].y=y1;
                            perso[0].x=x1;
                            perso[0].feu+=1;
                            matrice[x1][y1]=0;
                            toucheIsPress1[i]=1;
                            affichage(matrice,perso,Object,page,stage,mortj1,mortj2,*u1,*d1,*r1,*l1,*u2,*d2,*r2,*l2);
                        }else if(matrice[x1][y1]==6){
                            //matrice[perso[0].x][perso[0].y]=0;
                            //matrice[x1][y1]=7;
                            perso[0].y=y1;
                            perso[0].x=x1;
                            perso[0].nb_bombes+=1;
                            matrice[x1][y1]=0;
                            toucheIsPress1[i]=1;
                            affichage(matrice,perso,Object,page,stage,mortj1,mortj2,*u1,*d1,*r1,*l1,*u2,*d2,*r2,*l2);
                        }else if(matrice[x1][y1]==7){
                            perso[0].y=y1;
                            perso[0].x=x1;
                            perso[0].vie+=1;
                            matrice[x1][y1]=0;
                            toucheIsPress1[i]=1;
                            affichage(matrice,perso,Object,page,stage,mortj1,mortj2,*u1,*d1,*r1,*l1,*u2,*d2,*r2,*l2);
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
                    if(j==0){
                        y2--;
                        *u2+=1;
                        *u2%=ANMATION;
                        *d2=*r2=*l2=4;
                    }
                    if(j==1){
                        y2++;
                        *d2+=1;
                        *d2%=ANMATION;
                        *u2=*r2=*l2=4;
                    }
                    if(j==2){
                        x2++;
                        *r2+=1;
                        *r2%=ANMATION;
                        *d2=*u2=*l2=4;
                    }
                    if(j==3){
                        x2--;
                        *l2+=1;
                        *l2%=ANMATION;
                        *d2=*u2=*r2=4;
                    }
                    if(matrice[x2][y2]!=1 && matrice[x2][y2]!=2 && matrice[x2][y2]!=3  && (x2!=perso[0].x || y2!=perso[0].y)){
                        if(matrice[x2][y2]==0){
                            //matrice[perso[1].x][perso[1].y]=0;
                            //matrice[x2][y2]=8;
                            perso[1].y=y2;
                            perso[1].x=x2;
                            toucheIsPress2[j]=1;
                            affichage(matrice,perso,Object,page,stage,mortj1,mortj2,*u1,*d1,*r1,*l1,*u2,*d2,*r2,*l2);
                        }else if(matrice[x2][y2]==4){
                            //matrice[perso[1].x][perso[1].y]=0;
                            //matrice[x2][y2]=8;
                            perso[1].y=y2;
                            perso[1].x=x2;
                            perso[1].vie-=1;
                            //*animation=0; //ANIMATION DE MORT
                            //FIN?
                            toucheIsPress2[j]=1;
                            affichage(matrice,perso,Object,page,stage,mortj1,mortj2,*u1,*d1,*r1,*l1,*u2,*d2,*r2,*l2);
                        }else if(matrice[x2][y2]==5){
                            //matrice[perso[1].x][perso[1].y]=0;
                            //matrice[x2][y2]=8;
                            perso[1].y=y2;
                            perso[1].x=x2;
                            perso[1].feu+=1;
                            matrice[x2][y2]=0;
                            toucheIsPress2[j]=1;
                            affichage(matrice,perso,Object,page,stage,mortj1,mortj2,*u1,*d1,*r1,*l1,*u2,*d2,*r2,*l2);
                        }else if(matrice[x2][y2]==6){
                            //matrice[perso[1].x][perso[1].y]=0;
                            //matrice[x2][y2]=8;
                            perso[1].y=y2;
                            perso[1].x=x2;
                            perso[1].nb_bombes+=1;
                            matrice[x2][y2]=0;
                            toucheIsPress2[j]=1;
                            affichage(matrice,perso,Object,page,stage,mortj1,mortj2,*u1,*d1,*r1,*l1,*u2,*d2,*r2,*l2);
                        }else if(matrice[x1][y1]==7){
                            perso[1].y=y2;
                            perso[1].x=x2;
                            perso[1].vie+=1;
                            matrice[x2][y2]=0;
                            toucheIsPress1[j]=1;
                            affichage(matrice,perso,Object,page,stage,mortj1,mortj2,*u1,*d1,*r1,*l1,*u2,*d2,*r2,*l2);
                        }
                    }
                }
            }else
                toucheIsPress2[j]=0;
        }
    } //DEPLACEMENT J2
}

void explosion(t_joueur perso[],t_bombe bombej1[],t_bombe bombej2[],int matrice[X][Y],int *nbbombe1,int *nbbombe2,BITMAP *page,BITMAP *Object[NBOBJECTS],BITMAP *stage,int u1,int d1,int r1,int l1,int u2,int d2,int r2,int l2,bool touchePressed1, bool touchePressed2,int *toucheIsPress1,int *toucheIsPress2,BITMAP *mortj1,BITMAP *mortj2){
    if(touchePressed1){
        if(!*toucheIsPress1){
            if(*nbbombe1 < perso[0].nb_bombes){
                bombej1[*nbbombe1].x=perso[0].x;
                bombej1[*nbbombe1].y=perso[0].y;
                bombej1[*nbbombe1].creation_time= time(NULL);
                bombej1[*nbbombe1].explosion=0;
                matrice[bombej1[*nbbombe1].x][bombej1[*nbbombe1].y]=3;
                *nbbombe1+=1;
                *toucheIsPress1=1;

            }
        }
    }else
        *toucheIsPress1=0;

    if(touchePressed2){
        if(!*toucheIsPress2){
            if(*nbbombe2 < perso[1].nb_bombes){
                bombej2[*nbbombe2].x=perso[1].x;
                bombej2[*nbbombe2].y=perso[1].y;
                bombej2[*nbbombe2].creation_time= time(NULL);
                bombej2[*nbbombe2].explosion=0;
                matrice[bombej2[*nbbombe2].x][bombej2[*nbbombe2].y]=3;
                *nbbombe2+=1;
                *toucheIsPress2=1;
            }
        }
    }else
        *toucheIsPress2=0;
    time_t atm= time(NULL);
    // -> ON PLACE LE FEU SUR LES CASE VIDE JUSQU'AU MOMENT OU ON TROUVE UNE CASE AVEC BLOCK OU MUR
    // -> ON DETRUIT LE BLOCK OU ON S'ARRETE AU MUR
    // -> ON ENREGISTRE LA POSITION DE LA FLAMME POUR PLUS TARD REMETTRE CETTE POSITION A 0
    for(int i=0;i<*nbbombe1;i++){
        if(atm - bombej1[i].creation_time >=2 && bombej1[i].explosion!=1){
            bombej1[i].explosion=1;

            //code d'explosion de bombe
            x_plus(bombej1,matrice,perso,i,0,page,*nbbombe1);
            x_minus(bombej1,matrice,perso,i,0,page,*nbbombe1);
            y_plus(bombej1,matrice,perso,i,0,page,*nbbombe1);
            y_minus(bombej1,matrice,perso,i,0,page,*nbbombe1);
            affichage(matrice,perso,Object,page,stage,mortj1,mortj2,u1,d1,r1,l1,u2,d2,r2,l2);

        }
        if(atm - bombej1[i].creation_time >= 4 && bombej1[i].explosion==1){
            for(int x=0;x<X;x++){
                for(int y=0;y<Y;y++){
                    if(bombej1[i].matrice[x][y]==4){
                        matrice[x][y]=0;
                        bombej1[i].matrice[x][y]=0;
                    }
                }
            }
            *nbbombe1-=1;
        }
    }
    for(int i=0;i<*nbbombe2;i++){
        if(atm - bombej2[i].creation_time >=2 && bombej2[i].explosion!=1){
            bombej2[i].explosion=1;

            //code d'explosion de bombe
            x_plus(bombej2,matrice,perso,i,1,page,*nbbombe2);
            x_minus(bombej2,matrice,perso,i,1,page,*nbbombe2);
            y_plus(bombej2,matrice,perso,i,1,page,*nbbombe2);
            y_minus(bombej2,matrice,perso,i,1,page,*nbbombe2);
            affichage(matrice,perso,Object,page,stage,mortj1,mortj2,u1,d1,r1,l1,u2,d2,r2,l2);

        }
        if(atm - bombej2[i].creation_time >= 4 && bombej2[i].explosion==1){
            for(int x=0;x<X;x++){
                for(int y=0;y<Y;y++){
                    if(bombej2[i].matrice[x][y]==4){
                        matrice[x][y]=0;
                    }
                }
            }
            affichage(matrice,perso,Object,page,stage,mortj1,mortj2,u1,d1,r1,l1,u2,d2,r2,l2);
            *nbbombe2-=1;
        }
    }
}

void x_plus(t_bombe bombe[],int matrice[X][Y],t_joueur perso[],int i,int p,BITMAP *page,int nbbombe){
    ///AXE X+
    int j=0;

    do{
        if(matrice[bombe[i].x+j][bombe[i].y]!=1 && matrice[bombe[i].x+j][bombe[i].y]!=2){
            matrice[bombe[i].x+j][bombe[i].y]=4;
            bombe[i].matrice[bombe[i].x+j][bombe[i].y]=4;
            if(bombe[i].x+j==perso[0].x && bombe[i].y==perso[0].y){
                perso[0].vie=0;
                /// RAJOUTER UNE VARIABLE POUR FINIR LA PARTIE (VOIR UN DRAW SPRITE)
            }
            if(bombe[i].x+j==perso[1].x && bombe[i].y==perso[1].y){
                perso[1].vie=0;
                /// RAJOUTER UNE VARIABLE POUR FINIR LA PARTIE (VOIR UN DRAW SPRITE)
            }
        }

        if(matrice[bombe[i].x+j][bombe[i].y]==2){
            matrice[bombe[i].x+j][bombe[i].y]=4;
            bombe[i].matrice[bombe[i].x+j][bombe[i].y]=4;
            j=perso[p].feu;
            break;
        }
        if(matrice[bombe[i].x+j][bombe[i].y]==1){
            j=perso[p].feu;
            break;
        }
        j++;
        if(j==perso[p].feu)
            break;
    }while(j<=perso[p].feu);
}
void x_minus(t_bombe bombe[],int matrice[X][Y],t_joueur perso[],int i,int p,BITMAP *page,int nbbombe){
    ///AXE X-
    int j=0;

    do{
        if(matrice[bombe[i].x-j][bombe[i].y]!=1 && matrice[bombe[i].x-j][bombe[i].y]!=2){
            matrice[bombe[i].x-j][bombe[i].y]=4;
            bombe[i].matrice[bombe[i].x-j][bombe[i].y]=4;
            if(bombe[i].x-j==perso[0].x && bombe[i].y==perso[0].y){
                perso[0].vie=0;
                /// RAJOUTER UNE VARIABLE POUR FINIR LA PARTIE (VOIR UN DRAW SPRITE)
            }
            if(bombe[i].x-j==perso[1].x && bombe[i].y==perso[1].y){
                perso[1].vie=0;
                /// RAJOUTER UNE VARIABLE POUR FINIR LA PARTIE (VOIR UN DRAW SPRITE)
            }
        }
        if(matrice[bombe[i].x-j][bombe[i].y]==2){
            matrice[bombe[i].x-j][bombe[i].y]=4;
            bombe[i].matrice[bombe[i].x-j][bombe[i].y]=4;
            j=perso[p].feu;
            break;
        }
        if(matrice[bombe[i].x-j][bombe[i].y]==1){
            j=perso[p].feu;
            break;
        }
        j++;
        if(j==perso[p].feu)
            break;
    }while(j<=perso[p].feu);
}
void y_plus(t_bombe bombe[],int matrice[X][Y],t_joueur perso[],int i,int p,BITMAP *page,int nbbombe){

    ///AXE Y+
    int j=0;

    do{
        if(matrice[bombe[i].x][bombe[i].y+j]!=1 && matrice[bombe[i].x][bombe[i].y+j]!=2){
            matrice[bombe[i].x][bombe[i].y+j]=4;
            bombe[i].matrice[bombe[i].x][bombe[i].y+j]=4;
            if(bombe[i].x==perso[0].x && bombe[i].y+j==perso[0].y){
                perso[0].vie=0;
                /// RAJOUTER UNE VARIABLE POUR FINIR LA PARTIE (VOIR UN DRAW SPRITE)
            }
            if(bombe[i].x==perso[1].x && bombe[i].y+j==perso[1].y){
                perso[1].vie=0;
                /// RAJOUTER UNE VARIABLE POUR FINIR LA PARTIE (VOIR UN DRAW SPRITE)
            }

        }
        if(matrice[bombe[i].x][bombe[i].y+j]==2){
            matrice[bombe[i].x][bombe[i].y+j]=4;
            bombe[i].matrice[bombe[i].x][bombe[i].y+j]=4;
            j=perso[p].feu;
            break;
        }
        if(matrice[bombe[i].x][bombe[i].y+j]==1){
            j=perso[p].feu;
            break;
        }
        j++;
        if(j==perso[p].feu)
            break;
    }while(j<=perso[p].feu);
}
void y_minus(t_bombe bombe[],int matrice[X][Y],t_joueur perso[],int i,int p,BITMAP *page,int nbbombe){

    ///AXE Y-
    int j=0;

    do{
        if(matrice[bombe[i].x][bombe[i].y-j]!=1 && matrice[bombe[i].x][bombe[i].y-j]!=2){
            matrice[bombe[i].x][bombe[i].y-j]=4;
            bombe[i].matrice[bombe[i].x][bombe[i].y-j]=4;
            if(bombe[i].x==perso[0].x && bombe[i].y-j==perso[0].y){
                perso[0].vie=0;
                /// RAJOUTER UNE VARIABLE POUR FINIR LA PARTIE (VOIR UN DRAW SPRITE)
            }
            if(bombe[i].x==perso[1].x && bombe[i].y-j==perso[1].y){
                perso[1].vie=0;
                /// RAJOUTER UNE VARIABLE POUR FINIR LA PARTIE (VOIR UN DRAW SPRITE)
            }
        }
        if(matrice[bombe[i].x][bombe[i].y-j]==2){
            matrice[bombe[i].x][bombe[i].y-j]=4;
            bombe[i].matrice[bombe[i].x][bombe[i].y-j]=4;
            j=perso[p].feu;
            break;
        }
        if(matrice[bombe[i].x][bombe[i].y-j]==1){
            j=perso[p].feu;
            break;
        }
        j++;
        if(j==perso[p].feu)
            break;
    }while(j<=perso[p].feu);
}


void affichage(int matrice[X][Y],t_joueur perso[],BITMAP *objects[NBOBJECTS],BITMAP *page,BITMAP *stage,BITMAP *mortj1,BITMAP *mortj2,int u1,int d1,int r1,int l1,int u2,int d2,int r2,int l2){
    clear(page);
    blit(stage,page,0,0,0,0,SCREEN_W,SCREEN_H);
    for(int i=0;i<X;i++){
        for(int j=0;j<Y;j++){
            draw_sprite(page,objects[matrice[i][j]],i*50,j*50);
        }
    }

    rect(page,680,10,1100,170, makecol(56,144,104));
    textprintf_ex(page,font,850,20, makecol(56,144,104),-1,"JOUEUR 1 ");
    textprintf_ex(page,font,700,70, makecol(255,255,255),-1,"Mouvement : fleches directionnelles");
    textprintf_ex(page,font,700,100, makecol(255,255,255),-1,"Placer une bombe : RSHIFT");
    textprintf_ex(page,font,700,130, makecol(255,255,255),-1,"Puissance : %d",perso[0].feu-1);
    textprintf_ex(page,font,700,150, makecol(255,255,255),-1,"HP : %d",perso[0].vie);


    rect(page,680,190,1100,350, makecol(0,96,208));
    textprintf_ex(page,font,850,200, makecol(0,96,208),-1,"JOUEUR 2 ");
    textprintf_ex(page,font,700,250, makecol(255,255,255),-1,"Mouvement : Z Q S D");
    textprintf_ex(page,font,700,280, makecol(255,255,255),-1,"Placer une bombe : ESPACE");
    textprintf_ex(page,font,700,310, makecol(255,255,255),-1,"Puissance : %d",perso[1].feu-1);
    textprintf_ex(page,font,700,330, makecol(255,255,255),-1,"HP : %d",perso[1].vie);

    draw_sprite(page,objects[5],700,390);
    textprintf_ex(page,font,750,415, makecol(255,255,255),-1,": damage up");


    draw_sprite(page,objects[7],700,460);
    textprintf_ex(page,font,760,480, makecol(255,255,255),-1,": HP up");

    textprintf_ex(page,font,700,550, makecol(255,255,255),-1,"QUITTER = ESC");


    if(perso[0].vie!=0){
        if(u1!=4)
            draw_sprite(page,perso[0].back[u1],perso[0].x*50,perso[0].y*50);
        if(d1!=4)
            draw_sprite(page,perso[0].front[d1],perso[0].x*50,perso[0].y*50);
        if(r1!=4)
            draw_sprite(page,perso[0].side[r1],perso[0].x*50,perso[0].y*50);
        if(l1!=4)
            draw_sprite_h_flip(page,perso[0].side[l1],perso[0].x*50,perso[0].y*50);
    }else
        draw_sprite(page,mortj1,perso[0].x*50,perso[0].y*50);


    if(perso[1].vie!=0){
        if(u2!=4)
            draw_sprite(page,perso[1].back[u2],perso[1].x*50,perso[1].y*50);
        if(d2!=4)
            draw_sprite(page,perso[1].front[d2],perso[1].x*50,perso[1].y*50);
        if(r2!=4)
            draw_sprite(page,perso[1].side[r2],perso[1].x*50,perso[1].y*50);
        if(l2!=4)
            draw_sprite_h_flip(page,perso[1].side[l2],perso[1].x*50,perso[1].y*50);
    }else
        draw_sprite(page,mortj2,perso[1].x*50,perso[1].y*50);





    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
}

int Meenu(BITMAP *page,BITMAP *fond,int *x1, int *x2, int *y1, int *y2){
    if(key[KEY_DOWN] && getpixel(screen,250,50)== makecol(0,0,0)){
        *x1=250;
        *x2=1200;
        *y1=400;
        *y2=600;
    }
    if(key[KEY_UP] && getpixel(screen,250,700)==makecol(0,0,0)){
        *x1=250;
        *x2=1200;
        *y1=400;
        *y2=600;
    }
    if(key[KEY_UP] && getpixel(screen,250,400)==makecol(0,0,0)){
        *x1=250;
        *x2=1200;
        *y1=50;
        *y2=250;

    }if(*y1==400 && key[KEY_SPACE]){
        return 2;
    }

    if(*y1==50 && key[KEY_SPACE]){
        return 1;
    }

    blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);
    rect(page,*x1,*y1,*x2,*y2, makecol(0,0,0));
    rect(page,*x1-1,*y1-1,*x2+1,*y2+1, makecol(0,0,0));
    rect(page,*x1-2,*y1-2,*x2+2,*y2+2, makecol(0,0,0));
    textprintf_ex(page,font,750,146, makecol(0,0,0),-1,"Jouer");
    textprintf_ex(page,font,750,500, makecol(0,0,0),-1,"Quitter");

    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    clear_bitmap(page);
    return 3;
}

void Bomberman(){
    int matrice[X][Y];
    t_joueur perso[2];
    t_bombe bombej1[10];
    t_bombe bombej2[10];
    BITMAP *Object[NBOBJECTS];
    BITMAP *Stage;
    BITMAP *page;
    BITMAP *mortj1;
    BITMAP *mortj2;
    BITMAP *Background;
    SAMPLE *MenuMusic;

    int u1,d1,r1,l1;
    int u2,d2,r2,l2;
    int x1=250;
    int x2=1200;
    int y1=50;
    int y2=250;
    u1=r1=l1=u2=r2=l2=0;
    d1=d2=1;
    int animation=0;
    bool TouchePressed1[5];
    bool TouchePressed2[5];
    bool spacepress;
    bool rshiftpress;
    int spacepIsPress = 0;
    int shiftIsPress = 0;
    int toucheIsPress1[5] = {0};
    int toucheIsPress2[5] = {0};
    int nbbombe1,nbbombe2;
    nbbombe1 = nbbombe2 = 0;



    page= create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(page);
    MenuMusic= load_sample("Music/Lost Woods - The Legend of Zelda Ocarina Of Time.wav");
    Object[0]= load_bitmap("images/Vide.bmp",NULL);
    Object[1]= load_bitmap("images/Mur.bmp",NULL);
    Object[2]= load_bitmap("images/Block.bmp",NULL);
    Object[3]= load_bitmap("images/Bombe1.bmp",NULL);
    Object[4]= load_bitmap("images/Fire_start.bmp",NULL);
    Object[5]= load_bitmap("images/Fire_up.bmp",NULL);
    Object[6]= load_bitmap("images/Bombe_Up.bmp",NULL);
    Object[7]= load_bitmap("images/Hp_up.bmp",NULL);

    mortj1= load_bitmap("images/Link_Green_Death.bmp",NULL);
    mortj2= load_bitmap("images/Link_Blue_Death.bmp",NULL);



    Stage= load_bitmap("images/Stage.bmp",NULL);
    Background= load_bitmap("images/PixelArtBackgroundZelda.bmp",NULL);


    init_matrice(matrice);
    init_perso(perso);
    init_bombe(bombej1);
    init_bombe(bombej2);
    affichage(matrice,perso,Object,page,Stage,mortj1,mortj2,u1,d1,r1,l1,u2,d2,r2,l2);
    play_sample(MenuMusic,255,122,1000,1);

    while(Meenu(page,Background,&x1,&x2,&y1,&y2)!=2 && Meenu(page,Background,&x1,&x2,&y1,&y2)!=1){
        Meenu(page,Background,&x1,&x2,&y1,&y2);
    }
    if(Meenu(page,Background,&x1,&x2,&y1,&y2)==1){
        destroy_sample(MenuMusic);
        affichage(matrice,perso,Object,page,Stage,mortj1,mortj2,u1,d1,r1,l1,u2,d2,r2,l2);
        rest(1000);
        install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL);
        SAMPLE *GerudoValley;
        SAMPLE *Victory;
        GerudoValley= load_sample("Music/Gerudo Valley - The Legend of Zelda Ocarina Of Time.wav");
        play_sample(GerudoValley,255,122,1000,1);

        while(!key[KEY_ESC] && perso[0].vie!=0 && perso[1].vie!=0){
            TouchePressed1[0]=key[KEY_UP];
            TouchePressed1[1]=key[KEY_DOWN];
            TouchePressed1[2]=key[KEY_RIGHT];
            TouchePressed1[3]=key[KEY_LEFT];

            TouchePressed2[0]=key[KEY_W];
            TouchePressed2[1]=key[KEY_S];
            TouchePressed2[2]=key[KEY_D];
            TouchePressed2[3]=key[KEY_A];

            spacepress=key[KEY_SPACE];
            rshiftpress=key[KEY_RSHIFT];
            textprintf_ex(page,font,550,20, makecol(255,255,255),-1,"JOUEUR 1 ");
            textprintf_ex(page,font,500,70, makecol(255,255,255),-1,"Mouvement : fleches directionnelles");
            textprintf_ex(page,font,550,100, makecol(255,255,255),-1,"Placer une bombe : RSHIFT");
            textprintf_ex(page,font,550,130, makecol(255,255,255),-1,"Puissance : %d",perso[0].feu);
            textprintf_ex(page,font,550,150, makecol(255,255,255),-1,"HP : %d",perso[0].vie);

            dplacement(matrice,perso,&animation,TouchePressed1,TouchePressed2,toucheIsPress1,toucheIsPress2,page,Object,Stage,&u1,&d1,&r1,&l1,&u2,&d2,&r2,&l2,mortj1,mortj2);
            explosion(perso,bombej1,bombej2,matrice,&nbbombe1,&nbbombe2,page,Object,Stage,u1,d1,r1,l1,u2,d2,r2,l2,rshiftpress,spacepress,&spacepIsPress,&shiftIsPress,mortj1,mortj2);
            affichage(matrice,perso,Object,page,Stage,mortj1,mortj2,u1,d1,r1,l1,u2,d2,r2,l2);
        }

        if(perso[0].vie<=0){
            rest(1000);
            destroy_sample(GerudoValley);
            clear(page);
            Victory= load_sample("Music/Zelda Get Item - Sound Effect.wav");
            play_sample(Victory,255,122,1000,0);
            textprintf_ex(page,font,700,400, makecol(255,255,255),-1,"JOUEUR 2 A GAGNE !");
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            rest(5000);
            destroy_sample(Victory);

        }

        if(perso[1].vie<=0){
            rest(1000);
            destroy_sample(GerudoValley);
            clear(page);
            Victory= load_sample("Music/Zelda Get Item - Sound Effect.wav");
            play_sample(Victory,255,122,1000,0);
            textprintf_ex(page,font,700,400, makecol(255,255,255),-1,"JOUEUR 1 A GAGNE !");
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            rest(5000);
            destroy_sample(Victory);
        }
    }
    for(int m=0;m<NBOBJECTS;m++){
        destroy_bitmap(Object[m]);
    }
    destroy_bitmap(Stage);
    destroy_bitmap(page);
}
