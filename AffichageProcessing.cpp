
/*
oscilloscope minimaliste avec un arduino
récupère les valeurs via une liaison serie
*/
import processing.serial.*; // importation de la librairie de communication serie
//variables
Serial maConnection; // Crée un objet de communication série
int tensiony=0; // variable ou sera stockée la valeur de la tension
int tensionx=0; // variable ou sera stockée la valeur de la tension
//affichage
int fenetreTemps=4800; // temps pour parcourir la largeur de l'écran en millisecondes
int x=0;
int y=0;
int oldx=0;
int oldy=0;
int currentTime = 0;
int buttonPressed = 0;
boolean value = false;

void setup() {
    size(1920, 1080); // taille de l'ecran
    String NomDuPort = Serial.list()[0]; // récupère la première interface serie trouvée
    println("connection a "+NomDuPort);
    maConnection = new Serial(this, NomDuPort, 9600); // création de la connexion série
    background(255); // fond d'écran blanc
    smooth(); // lisser les dessins
    strokeWeight(2); // largeur de trait
    stroke(40); // couleur du trait gris
}

void draw() { //boucle de dessin principale
 //Phase 1
 //détermination du X actuel 
 
 if (buttonPressed == 1){
   background(255);
 }
 
   
 int newTime = millis();
 
 if (newTime > currentTime){
   currentTime = newTime;
 }
 
 noStroke();
 rect(0, 0, 10, 1080);
 rect(0,0,1920,10);
 stroke(#000000);
 rect(0,y,5,5);
 rect(x,0,5,5);
 
 oldx=x;
 x=int(map(tensionx, 0, 1023, 20, 1900));
 
 /*if (oldx>x) { 
 //reprise au debut de l'écran 
 oldx=0; //background(255); 
 //fond d'écran blanc 
 } */
 //determination de la valeur de Y 
 oldy=y;
 y=int(map(tensiony, 0, 1023, 1060, 20)); // mise à l'échelle de la tension pour entrer dans l'écran 
 line(oldx, oldy, x, y); // dessine le trait
 
 
}

void serialEvent (Serial maConnection) { // si des données arrivent par la connexion série
    String retour=maConnection.readStringUntil('\n'); // lit la donnée jusqu'à la fin de ligne
    if (retour != null) { //si le retour n'est pas vide
        retour = trim(retour); // enlever les espaces
        int inputs[] = int(split(retour,','));
        tensiony = int(inputs[0]); // converti le texte en nombre entier
        tensionx = int(inputs[1]); // converti le texte en nombre entier
        buttonPressed = int(inputs[2]);
    }
}

void keyPressed() {
  if (value) {
    value = false;
  } else {
    value = true;
  }
}