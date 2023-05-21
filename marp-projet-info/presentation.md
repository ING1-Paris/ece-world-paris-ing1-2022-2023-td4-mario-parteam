---
marp: true
theme: projet
paginate: true
_paginate: false
---

<script type="module">
  import mermaid from 'https://cdn.jsdelivr.net/npm/mermaid@10/dist/mermaid.esm.min.mjs';
    mermaid.initialize({ 
        startOnLoad: true,
        theme: 'base',
    });
</script>

<!--
# Style lead only for this slide
_class: lead
_footer: Algorithmique Avancée et Bibliothèque Graphique - 2022-2023
-->

![bg left](./images/fond_ece.png)

**ING1** Projet d'informatique


# ECE World

Equipe 47

---

# Equipe 47

![bg right:50%](./images/)

- Raphaël DUPORT
- Apolline JACQUIER
- Thibaut PUEL
- Laure PETIT

---

# ECE World

![bg right:50% 100%](./images/nintendo-logo.png)

## Thème

Nous avons choisis le thème Nintendo afin d'avoir assez de sprites. 

---

# Map `1/2`

*Réalisée par : **Raphaël**, **Apolline**.*
![bg right:78% 96%](./images/map.bmp)


---

# Carte `2/2`

Décrire ici les fonctionnalités implémentées : choix joueurs, saisie des noms, affichage des scores/classement... Comment avez-vous fait ? Quels étaient les problèmes rencontrés.

Suite si ça ne tient pas sur une slide. 

:bulb: *Vous pouvez faire comme ça à chaque fois qu'une slide ne suffit pas, il vaut mieux 5 slides légères qu'une surchargée.*

---

# Organisation des jeux

Précisez comment les jeux sont organisés ? Sont-ils dans des fichiers séparés ? Dans des dossiers ? Sont-ils éparpillés dans plusieurs fichiers ?

Quels paramètres prennent les jeux ?  La file d'événement par exemple ? Ou est-ce que chaque jeu crée sa propre file ?

Comment on lance un jeu et comment on revient à la carte à la fin de la partie ?
Comment le classement est-il mis à jour ?

---

![bg right:40%](images/)

# Guitar Hero

*Réalisé par : **Raphaël***

Décrire le fonctionnement du jeu dans les grandes lignes. Comment vous l'avez conçu.
- Les canards vont de la droite à la gauche.
- Lorsqu'ils ont disparu, ils ont 1 chance sur 50 de réapparaitre à droite.
- Les canards vont à une vitesse différente (tirée aléatoirement).
- La collision des canards est détectée.
- etc.

<sup>:bulb: Remplacez les images par des captures d'écran de votre jeu.</sup>

---

![bg right:40%](images/)

# Guitar Hero

Pour chaque jeu (bien détailler au moins un jeu par personne), précisez les structures de données (structures importantes, tableaux importants, listes chainées...) et les fonctions importantes (avec leur prototype).

### Structures

<div class="mermaid">
%%{init: {'theme':'neutral'}}%%
classDiagram
    class t_boutons
    t_boutons : BITMAP *vert[ANIMATION]
    t_boutons : BITMAP *rouge[ANIMATION]
    t_boutons : BITMAP *jaune[ANIMATION]
    t_boutons : BITMAP *bleu[ANIMATION]
    t_boutons : BITMAP *orange[ANIMATION]
    t_boutons : char clavier[5]
    t_boutons : int xboutons[5]
    t_boutons : int yboutons[5]
    t_boutons : int color[5]
    t_boutons : int txb, tyb
    class t_score
    t_score : long int score
    t_score : int xscore, yscore
    t_score : int combo
    t_score : int xcombo,ycombo
    t_score : int color
    
</div>

### Tableaux

- `Canard canards[20]`
---

![bg right:40%](images/)

# Guitar Hero

### Graphe d'appel

<br>

<div class="mermaid">
%%{init: {'theme':'neutral'}}%%
flowchart LR
    Gh --> initBoutons
    Gh --> initScore
    Gh --> Menu
    Gh --> guitareHero
    guitareHero --> detectScore
    guitareHero --> animationBoutons
</div>


---

![bg right:40%](images/)

# Guitar Hero

### Logigramme

---

![bg right:40%](images/bomberman.png)

# Bomberman

*Réalisé par : **Raphaël***

Les joueurs doivent se retrouver au sein d'une map avec des murs. Chacun dispose de :bomb: qu'il place sur les murs pour les faire :boom:. Autour de la bombe se trouve du :fire:.
Cependant il doit s'éloigner de la bombe avant qu'elle explose, du feu, sinon il perd une vie.
-Si un joueur passe sur une :izakaya_lantern: (un bonus de puissance) il gagne 1 de feu max
-Un :heart: = 1 vie supplémentaire

<sup>:bulb: Remplacez les images par des captures d'écran de votre jeu.</sup>

---

![bg right:40%](images/bomberman.png)

# Bomberman


### Structures

<div class="mermaid">
%%{init: {'theme':'neutral'}}%%
classDiagram
    class t_joueur
    t_joueur : int x, y
    t_joueur : int feu
    t_joueur : int nb_bombes
    t_joueur : int vie
    t_joueur : BITMAP *front[ANIMATION]
    t_joueur : BITMAP *back[ANIMATION]
    t_joueur : BITMAP *side[ANIMATION]
    class t_bombe
    t_bombe : int x, y
    t_bombe : int matrice[X][Y]
    t_bombe : time_t creation_time
    t_bombe : int explosion, explosion_now
</div>

### Tableaux

- `Canard canards[20]`
---


# Bomberman

### Graphe d'appel

<br>

<div class="mermaid">
%%{init: {'theme':'neutral'}}%%
flowchart LR
    Bomberman --> init_matrice
    Bomberman --> init_perso
    Bomberman --> init_bombe
    Bomberman --> affichage
    Bomberman --> Meenu
    Bomberman --> dplacement
    dplacement --> affichage
    Bomberman --> explosion
    explosion --> affichage
    explosion --> x_plus
    explosion --> x_minus
    explosion --> y_plus
    explosion --> y_minus
</div>


---

![bg right:40%](images/)

# Bomberman

### Logigramme

---

![bg right:40%](images/riv.png)

# Traversée de rivière

*Réalisé par : **Apolline***

Le but du jeu est comme son nom l'indique de traverser la rivière en sautant sur les bûches.
- Les bûches vont de la gauche vers la droite.
- Lorsqu'elles ont disparu, elles réaparaissent à gauche.
- Les bûches vont à une vitesse différente.

<sup>:bulb: Remplacez les images par des captures d'écran de votre jeu.</sup>

---

![bg right:40%](images/riv.png)

# Traversée de rivière

Pour chaque jeu (bien détailler au moins un jeu par personne), précisez les structures de données (structures importantes, tableaux importants, listes chainées...) et les fonctions importantes (avec leur prototype).

### Structures

<div class="mermaid">
%%{init: {'theme':'neutral'}}%%
classDiagram
    class lesrondins
    lesrondins : int x, y
    lesrondins : int dx
    lesrondins : int tmpdx
    lesrondins : int cptdx
    lesrondins : int tx, ty
    lesrondins : int etat
    lesrondins : int rayons
    
    class Canne
    Canne : int x, y
    Canne : Canard* canard
</div>

### Tableaux

- `Canard canards[20]`
---

![bg right:40%](images/)

# Traversée de rivière

### Graphe d'appel

<br>
<div class="mermaid">
%%{init: {'theme':'neutral'}}%%
flowchart LR
    lejeu --> remplirlesrondins
    remplirlesrondins --> creerRONDINS
    lejeu --> actualiserlesrondins
    actualiserlesrondins --> actualiserRondins
    lejeu --> dessinerlesrondins
    dessinerlesrondins --> dessinerRondins
</div>


---

![bg right:70% 90%](images/diagAppRiviere.png)

# Traversée de rivière

### Logigramme

---

![bg right:40%](images/taupe.png)

# Taupes

*Réalisé par : **Thibaut***

Décrire le fonctionnement du jeu dans les grandes lignes. Comment vous l'avez conçu.
- Les canards vont de la droite à la gauche.
- Lorsqu'ils ont disparu, ils ont 1 chance sur 50 de réapparaitre à droite.
- Les canards vont à une vitesse différente (tirée aléatoirement).
- La collision des canards est détectée.
- etc.

<sup>:bulb: Remplacez les images par des captures d'écran de votre jeu.</sup>

---

![bg right:40%](images/taupe.png)

# Taupes

Pour chaque jeu (bien détailler au moins un jeu par personne), précisez les structures de données (structures importantes, tableaux importants, listes chainées...) et les fonctions importantes (avec leur prototype).

### Structures

<div class="mermaid">
%%{init: {'theme':'neutral'}}%%
classDiagram
    class Canard
    Canard : int x, y
    Canard : int vitesse
    class Canne
    Canne : int x, y
    Canne : Canard* canard
</div>

### Tableaux

- `Canard canards[20]`
---

![bg right:40%](images/)

# Taupes

### Graphe d'appel

<br>

<div class="mermaid">
%%{init: {'theme':'neutral'}}%%
flowchart LR
    pecheAuxCanards --> initialiserCanards
    initialiserCanards --> positionnerCanard
    pecheAuxCanards --> deplacerCanards
    deplacerCanards --> deplacerCanard
    pecheAuxCanards --> detecterCollisionCanards
</div>


---

![bg right:70% 95%](images/taupes.png)

# Taupes

### Logigramme


---

![bg right:40%](images/pierre.png)

# Pierre Feuille Ciseaux

*Réalisé par : **Thibaut***

Décrire le fonctionnement du jeu dans les grandes lignes. Comment vous l'avez conçu.
- Les canards vont de la droite à la gauche.
- Lorsqu'ils ont disparu, ils ont 1 chance sur 50 de réapparaitre à droite.
- Les canards vont à une vitesse différente (tirée aléatoirement).
- La collision des canards est détectée.
- etc.

<sup>:bulb: Remplacez les images par des captures d'écran de votre jeu.</sup>

---

![bg right:40%](images/pierre.png)

# Pierre Feuille Ciseaux

Pour chaque jeu (bien détailler au moins un jeu par personne), précisez les structures de données (structures importantes, tableaux importants, listes chainées...) et les fonctions importantes (avec leur prototype).


### Structures

<div class="mermaid">
%%{init: {'theme':'neutral'}}%%
classDiagram
    class Canard
    Canard : int x, y
    Canard : int vitesse
    class Canne
    Canne : int x, y
    Canne : Canard* canard
</div>

### Tableaux

- `Canard canards[20]`
---

![bg right:40%](images/)

# Pierre Feuille Ciseaux

### Graphe d'appel

<br>

<div class="mermaid">
%%{init: {'theme':'neutral'}}%%
flowchart LR
    pecheAuxCanards --> initialiserCanards
    initialiserCanards --> positionnerCanard
    pecheAuxCanards --> deplacerCanards
    deplacerCanards --> deplacerCanard
    pecheAuxCanards --> detecterCollisionCanards
</div>


---

![bg right:70% 95%](images/Pfc.png)

# Pierre Feuille Ciseaux

### Logigramme


---

![bg right:45%](images/captureballons2.png)

# Tir aux ballons

*Réalisé par : **Laure***

- Les déplacements sont aléatoire.
- Les canards vont à une vitesse différente (tirée aléatoirement).
- La collision avec le clic de la souris est détectée.
- etc.


---

![bg right:40%](images/captureballons2.png)

# Tir aux ballons

Pour chaque jeu (bien détailler au moins un jeu par personne), précisez les structures de données (structures importantes, tableaux importants, listes chainées...) et les fonctions importantes (avec leur prototype).

### Structures

<div class="mermaid">
%%{init: {'theme':'neutral'}}%%
classDiagram
    class t_acteur
    t_acteur : int x, y
    t_acteur : int dx, dy
    t_acteur : int tx, ty
    
</div>

### Tableaux

- `t_acteur tab[NBALLONS]`
---

# Tir aux ballons

### Graphe d'appel

<br>

<div class="mermaid">
%%{init: {'theme':'neutral'}}%%
flowchart LR
    tirballons --> remplirTabActeurs
    remplirTabActeurs -->creerActeurs
    tirballons --> actualiserTabActeurs
    actualiserTabActeurs --> actualiseActeur
    actualiserTabActeurs --> collisionActeurs
    tirballons --> dessinerTabActeurs
    dessinerTabActeurs --> dessinerActeur
    tirballons --> tirSouris
</div>


---

![bg right:40%](images/)

# Tir aux ballons

### Logigramme

---

# Bilan collectif

---

<!--
_class: lead
-->

# Les slides suivantes ne seront pas présentées oralement lors de la soutenance mais doivent figurer dans la présentation. Nous les survolerons rapidement.

---

# Raphaël

## Tâches réalisées

- `✅ 100%` Jeu : Guitar Hero
- `✅ 100%` Jeu : Bomberman

- `❌ 50%` Déplacement de la map
    - *Développer ici pourquoi cette tâche n'a pas été terminée.*
---

# Apolline

## Tâches réalisées 

- `✅ 50%` Jeu : Traversée de rivière
- *Probème avec le déplacement du personnage*
- `✅ 80%` Conception de la map
    - *Développer ici pourquoi cette tâche n'est pas terminée à 100%. (exemple : on aurait pu améliorer...).*

---

# Thibaut

## Tâches réalisées

- `✅ 100%` Jeu : Taupe

- `✅ 95%` Jeu : Pierre feuille ciseau


---

# Laure

## Tâches réalisées 

- `❌ 50%` Jeu : Tir aux ballons
- `✅ 100%` Diapo Marp

---

# Investissement

Si vous deviez vous répartir des points, comment feriez-vous ?

<div class="mermaid">
%%{init: {'theme':'neutral'}}%%
pie showData
    "Raphaël" : 40
    "Apolline" : 40
    "Thibaut" : 20
    "Laure" : 10
</div>

---

# Récapitulatif des jeux

| Jeu | Avancement | Problèmes / reste |
| --- | --- | --- |
| Guitar Hero | 100% | - |
| Bomberman | 100% | - |
| Taupes | 100% | Actualisation des valeurs randomisées |
| Pierre feuille ciseaux | 95% | - |
| Tir aux ballons | 50% | - |
| Traversée de rivière | 50% |-|

Vous pouvez faire ce tableau sur plusieurs slides en dupliquant l'en-tête.

---

<!--
_class: lead
-->
# Quelques éléments que vous pouvez utiliser à votre guise dans votre présentation

---

# Schémas et Graphes

Vous pouvez utiliser [Mermaid.js](https://mermaid.js.org/) pour générer des schémas. Regardez la documentation.

---

# Slide avec du code


```C
for(int i = 0; i < 5; i++) {
    printf("%d ", i);
}
```

> 0 1 2 3 4 


---

# Emojis

https://gist.github.com/rxaviers/7360908

---

# Thème 

Vous pouvez personnaliser l'affichage de votre présentation avec le langage CSS en modifiant le fichier `theme.css`.

---

# Export PDF

Depuis récemment, l'export (**`Export Slide Deck...`**) en PDF oublie parfois des éléments. 
Si c'est le cas, nous vous conseillons d'exporter en fichier PowerPoint (pptx), puis de l'exporter en PDF depuis PowerPoint.