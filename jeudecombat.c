#include <stdio.h>
#include <stdlib.h>
 int attaquedumonstre(int atkmonstre) {
   atkmonstre = rand()%40 + 1;
   return atkmonstre;
 }
 int attaquejoueur(int atkj){
  atkj = rand()%30 + 4;
  return atkj;
 }

 int choixdumonstre(int choixm) {
   choixm = rand()%1 + 1;
   return choixm;
 }
int main() {

  int pv;
  int pvactuel;
  int pmonstre;
  int actuelmonstre;
  int atk;
  int def;
  int choix;
  int atkmonstre;
  int atkj;
  int choixm;
  int atkmonstresave;
  int atkjsave;
  int choixsave;
pv=100;
pvactuel=pv;
pmonstre=100;
actuelmonstre=pmonstre;

while (pvactuel>0 && actuelmonstre>0){
printf("Vous avez %d",pvactuel);
printf(" de point de vie. \n ");

printf("Le monstre a %d",actuelmonstre);
printf(" de point de vie. \n");

printf("Que voulez vous faire? Attaquez?\n Ou se defendre? 1=Atk 0=Def \n \n");
scanf("%d",&choix);
if (choix==0){
  printf("Vous vous defendez ! La prochaine attaque de votre ennemie sera divise par 3 ! \n");
  def=1;
}
if (choix==1){
  printf("Vous ATTAQUEZ ! VOUS LANCEZ STORMBREAKER SUR VOTRE OPPOSANT ! Peut être il y'aura un coup critique??? \n");
    atk=1;
}
if (atk==1) {
  atkjsave=attaquejoueur(atkj);
  actuelmonstre=actuelmonstre-atkjsave;
  printf("%d ont ete donne au monstre \n",atkjsave);
  printf("Le monstre a prit cher, il a %d",actuelmonstre);
  printf(" de point de vie. \n");
  atk=0;
}
choixsave=choixdumonstre(choixm);
if (choixsave==1){

printf("Le monstre va attaquer ! Attention ! \n");
if (def==1){
  printf("Le monstre attaque ! \n \n");
  atkmonstresave=attaquedumonstre(atkmonstre)/3;
  pvactuel=pvactuel-atkmonstresave;
  printf("Vous avez réduit les degats ! Vous avez subi seulement %d",atkmonstresave);
  printf(" de degats \n");
  def=0;
}
else{
  printf("Le monstre attaque! \n \n");
  atkmonstresave=attaquedumonstre(atkmonstre);
  pvactuel=pvactuel-atkmonstresave;
  printf("Vous avez prit plein pot ! Vous avez subi %d",atkmonstresave);
  printf(" de degats \n");
  def=0;
}
if (choixsave==0) {
 printf("Le monstre se defend");
  }
  if (pvactuel<=0 && actuelmonstre>0){
    printf("Vous avez ete vaincu ! Dommage... \n");
  }
  if (actuelmonstre<=0){
    printf("Vous avez vaincu le monstre, bien joue \n");
  }
}
  }
}
