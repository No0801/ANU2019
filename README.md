# ANU2019

Barbarroux Pierrick,                            
Rioust Lucas,
Pillonel Matthis
                                                          **ENSIIE 2019**
                                                        **Rapport Projet ANU**
                                                         **Pictionary.iie**


**Idée du projet initial** : 
Tout d’abord, nous voulions créer une station météo. L’idée était d’acquérir un ensemble de données météorologiques du territoire français via une API. Les données devaient être traitées via notre programme arduino. Un écran devait alors retranscrire ces informations sous la forme d’animation. Par exemple, si le temps était clément, un personnage apparaissait en tenue légère d’été. S’il pleuvait, le personnage sortait un parapluie. C’est pourquoi nous avons commandé un écran. Néanmoins, des problèmes nous ont amenés à repenser notre projet.


**Problèmes rencontrés** : 
Le premier problème rencontré fut la difficulté de trouver un sujet qui nous intéressait tous les trois. Étant tous trois habitué à utiliser Unity pour nos créations, nous devions penser un projet faisable sur Arduino, dans le temps qui nous était imparti. Une fois notre première idée trouvé, nous nous sommes confrontés à des problèmes techniques. Premièrement, l’écran acheté avait des problèmes de surchauffes, et nous avons passé beaucoup de temps à essayer de le faire fonctionner, sans succès. De plus, nous avons récupéré une ESP32 appartenant à un camarade, mais au moment de l’utiliser, Matthis s’est électrocuté, et la carte ne recevais aucun téléversement. 
    


**Projet final réalisé** :
Finalement, nous nous sommes dirigés vers un pictionary. Nous avions à disposition un écran, deux potentiomètres, deux arduinos, des câbles et un bouton. Nous avons pensé à utiliser les potentiomètres pour pouvoir dessiner sur un écran d’ordinateur. L’autre écran donne un mot aléatoire au joueur. Ce dernier doit alors dessiner le mot en question à l’aide des potentiomètres en reprenant le concept du télécran . La difficulté est d’arriver à dessiner sans “lever le crayon”. En effet, on utilise un curseur sur l’écran d’ordinateur pour dessiner. Les potentiomètres ne font que déplacer ce curseur. Le bouton quant à lui permet d’effacer ce que l’on vient de dessiner. Une première arduino contrôle le choix du mot à dessiner et son affichage ainsi que l'affichage du temps. Une deuxième arduino reçoit les inputs des deux potentiomètres et du bouton reset et les communique avec Processing pour afficher le dessin.

**Instructions d'instalations** :
Le jeu se joue comme un pictionnary. Une personne reçoit un mot choisit aléatoirement parmis une liste prédéfinie. 
Il doit alors le dessiner à l'aide des deux potentiometres et le faire deviner aux autres joueurs. Une fois le temps imparti dépassé un autre jouer prend la place du dessinateur.

Une premiere arduino contrôle le choix du mot à dessiner et son affichage ainsi que l'affichage du temps. 
Une deuxieme arduino reçoit les inputs des deux potentiometres et du bouton reset et les communique avec Proccessing pour afficher le dessin. 

Mise en place :  
1. Téléverser le code d'affichage dans la première carte et l'installer du côté du dessinateur. 
2. Téléverser le code de dessin dans la deuxième en la laissant connectée au PC. 
3. Lancer l'application proccessing. 
4. Jouer.

