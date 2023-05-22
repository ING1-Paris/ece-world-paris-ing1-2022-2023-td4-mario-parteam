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

# Map

*Réalisée par : **Raphaël** et **Apolline**.*
![bg right:78% 96%](./images/map.bmp)

---

# Organisation des jeux


- Les jeux sont dans des fichiers séparés. 
- Chaque jeu a son fichier et son header. L'accès aux jeux s'effectue par la map.
- (Chaque jeu devait prendre en paramètre le joueur pour les stats et les tickets.)
Les bâtiments ont une couleur associée: on entre dans un bâtiment lorsque la couleur sur la BITMAP collision est détectée.


---

![bg right:50%](images/gh.png)

# Guitar Hero

*Réalisé par : **Raphaël***

- Appuyer sur les boutons en même temps que la mélodie
- But Guitare Hero : Marquer le plus haut score possible

---

![bg right:50%](images/gh.png)

# Guitar Hero

### Structures

![w:500 h:400](images/structgh.PNG)

---

![bg right:60% 90%](images/appelgh.PNG)

# Guitar Hero

### Graphe d'appel




---

![bg right:70% 70%](images/logigh.png)

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


![auto](images/structbomber.png)



---
![bg right:50% 60%](images/appelbomber.PNG)

# Bomberman

### Graphe d'appel

---

![bg right:60% 100%](images/logibomberman.png)

# Bomberman

### Logigramme


---

![bg right:40%](images/riv.png)

# Traversée de rivière

*Réalisée par : **Apolline***

Le but du jeu est comme son nom l'indique de traverser la rivière en sautant sur les bûches.
- Les bûches vont de la gauche vers la droite.
- Lorsqu'elles ont disparu, elles réaparaissent à gauche.
- Les bûches vont à une vitesse différente.

<sup>:bulb: Remplacez les images par des captures d'écran de votre jeu.</sup>

---

![bg right:40%](images/riv.png)

# Traversée de rivière


### Structure

![w:150 h:350](images/structriv.png)

---

![bg right:70% 90%](images/appelriv.PNG)

# Traversée de rivière

### Graphe d'appel

---

![bg right:70% 90%](images/diagAppRiviere.png)

# Traversée de rivière

### Logigramme

---

![bg right:50%](images/taupe.png)

# Taupes

*Réalisé par : **Thibaut***

-But : Le joueur doit toucher le plus de taupes possibles avant la fin du temps imparti.
-La partie dure une minute.

---

![bg right:60% 80%](images/appeltaupe.png)

# Taupes

### Graphe d'appel




---

![bg right:70% 100%](images/taupes.png)

# Taupes

### Logigramme


---

![bg right:40%](images/pierre.png)

# Pierre Feuille Ciseaux

*Réalisé par : **Thibaut***

Le joueur se retrouve dans un ring afin de se "battre" avec l'ordinateur. 
Il choisi son coup avant de découvrir ce que le hasard à choisi pour l'ordinateur.

---

![bg right:60% 80%](images/appelpfc.PNG)

# Pierre Feuille Ciseaux

### Graphe d'appel



---

![bg right:70% 100%](images/Pfc.png)

# Pierre Feuille Ciseaux

### Logigramme


---

![bg right:50%](images/captureballons2.png)

# Tir aux ballons

*Réalisé par : **Laure***

- But : Faire éclater tous les ballons le plus rapidement possible
- Les déplacements des ballons sont aléatoires.
- La collision avec le clic de la souris est détectée.

---

![bg right:50%](images/captureballons2.png)

# Tir aux ballons

### Structures

![w:170 h:300](images/structballon.png)

---
![bg right:60% 90%](images/appelballon.png)
# Tir aux ballons

### Graphe d'appel


---

![bg right:50% 28%](images/logiballon.png)

# Tir aux Ballons

### Logigramme


---

# Bilan collectif

---

<!--
_class: lead
-->

# Merci de votre attention

---

# Raphaël

## Tâches réalisées

- `✅ 100%` Jeu : Guitar Hero
- `✅ 100%` Jeu : Bomberman

- `❌ 100%` Déplacement de la map
    - Problème suite à un "Update" -> programme perdu
---

# Apolline

## Tâches réalisées 

- `50%` Jeu : Traversée de rivière
    - Problème avec le déplacement du personnage
- `✅ 100%` Conception de la map
   

---

# Thibaut

## Tâches réalisées

- `✅ 100%` Jeu : Taupe

- `✅ 90%` Jeu : Pierre feuille ciseau


---

# Laure

## Tâches réalisées 

- `50%` Jeu : Tir aux ballons
- `✅ 100%` Diapo Marp

---

# Investissement
![auto ](images/repartition.png)

--- 

# Git
![w:900 h:570 ](images/git.png)


---
# Récapitulatif des jeux

| Jeux | Avancement | Problèmes / reste |
| --- | --- | --- |
| Guitar Hero | 100% | - |
| Bomberman | 100% | - |
| Taupes | 100% ||
| Pierre feuille ciseaux | 90% | Récursivité pour relancer une partie + afficher l'écran de fin |

---
# Récapitulatif des jeux

| Jeux | Avancement | Problèmes / reste |
| --- | --- | --- |
| Tir aux ballons | 50% | Problème avec le tableau de ballons -> impact sur tout le reste du programme|
| Traversée de rivière | 50% | Problème d'affichage du personnage + mouvements |

---