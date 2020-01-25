#include <stdio.h>
#include <stdlib.h>
 int attaquedumonstre(int atkmonstre) {
	srand(time( NULL ) );
   atkmonstre = rand()%40 + 1;
   return atkmonstre;
 }
 int attaquejoueur(int atkj){
	 srand(time( NULL ) );
  atkj = rand()%30 + 4;
  return atkj;
 }
int attaquejoueurP(int atkjP){
	 srand(time( NULL ) );
  atkjP = rand()%50 + 2;
  return atkjP;
 }
 int choixdumonstre(int choixm) {
	  srand(time( NULL ) );
   choixm = rand()%4 + 1;
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
  int defm;
  int soin;
  int atkPnb;
  int atkjP;
  int soinM;
pv=100;
pvactuel=pv;
pmonstre=100;
actuelmonstre=pmonstre;
defm=0;
soin=3;
atkPnb=3;
soinM=3;
while (pvactuel>0 && actuelmonstre>0){
printf(" \n \n =========================== \n");
printf("Vous avez %d",pvactuel);
printf(" de point de vie. \n ");

printf("Le monstre a %d",actuelmonstre);
printf(" de point de vie. \n");

printf("Vous avez %d",soin);
printf(" bandage. \n");

printf("Vous avez %d",atkPnb);
printf(" d'attaque percante. \n");
printf("=========================== \n");

printf("Que voulez vous faire? Attaquez?\n Ou se defendre? 1=Atk 0=Def 2=soin 3=Attaque Percante (Attention si le monstre ne s'est pas défendu l'epee rebondira sur sa peau elastique et vous subirez les degats!) \n \n");
scanf("%d",&choix);
if (choix==0){
  printf("Vous vous defendez ! La prochaine attaque de votre ennemie sera divise par 3 ! \n");
  def=1;
}
if (choix==1){
  printf("Vous ATTAQUEZ ! VOUS LANCEZ STORMBREAKER SUR VOTRE OPPOSANT ! Peut être il y'aura un coup critique??? \n");
    atk=1;
}
if (choix==2 && soin<=0) {
  printf("Vous avez plus de bandage, vous avez gaché une opportunité dommage...");
}
if (choix==2 && pvactuel==100) {
  printf("Vous etes full vie, vous avez gache une opportunite dommage...");
}
if (choix==2 && soin>0 && pvactuel!=100){
  printf("Vous vous soignez !  \n");
  pvactuel=pvactuel+10;
  soin=soin-1;
}
if (choix==3 && atkPnb<=0) {
 printf("Vous ne pouvez pas faire cette attaque...Vous allez donc attaquer normalement!! \n");
 atk=1;
}
if (choix==3 && atkPnb>0) {
  printf("Vous provoquez une attaque qui va percer la defense de l'ennemi si il la utilise... \n");	
  atk=2;
  atkPnb=atkPnb-1;
}
if (atk==1) {
  if (defm==0) {
  atkjsave=attaquejoueur(atkj);
  actuelmonstre=actuelmonstre-atkjsave;
  printf("%d ont ete donne au monstre \n",atkjsave);
  printf("Le monstre a prit cher, il a %d",actuelmonstre);
  printf(" de point de vie. \n");
  atk=0;
  }
 
  if (defm==1) {
  atkjsave=attaquejoueur(atkj)/3;
  actuelmonstre=actuelmonstre-atkjsave;
  printf("%d ont ete donne au monstre \n",atkjsave);
  printf("Le monstre a reduit les degats de 3, il a %d",actuelmonstre);
  printf(" de point de vie. \n");
  atk=0;
  defm=0;
  }
}
if (atk==2) {
	if (defm==0) {
	atkjsave=attaquejoueurP(atkjP);
	pvactuel=pvactuel-atkjsave;
	printf("Vous avez voulu donner %d de degats au monstre mais celui-ci ne s'etait pas defendu...L'epee rebondit sur vous dommage... \n",atkjsave);
	printf("Vous avez subit %d de degat \n",atkjsave);
	printf("Vous avez maintenant %d",pvactuel);
	printf(" de points de vie... \n \n");
	
	atk=0;
}
   if (defm==1) {
	atkjsave=attaquejoueurP(atkjP);
	actuelmonstre=actuelmonstre-atkjsave;
	printf("WOW Vous avez perce l'armure de l'ennemi !! Bravo, vous lui infligez LE MAXIMUM de dégats \n");
	printf("Vous avez mit %d",atkjsave);
	printf(" de degats... \n");
	printf("Le monstre a %d",actuelmonstre);
	printf(" de point de vie \n");
	atk=0;
    defm=0;	
   }
}
choixsave=choixdumonstre(choixm);
if (choixsave>3 && actuelmonstre<75 && soinM>0 || choixsave==2 && actuelmonstre<75 && soinM>0 ) {
	printf("Le monstre va se soigner de 25PV! \n");
	actuelmonstre=actuelmonstre+25;
	soinM=soinM-1;
}
else{
if (choixsave==1 || choixsave==2){

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
}
if (choixsave>2) {
 printf("Le monstre se defend \n");
 defm=1;
  }

}
  if (pvactuel<=0 && actuelmonstre>0){
    printf("Vous avez ete vaincu ! Dommage... \n");
  }
  if (actuelmonstre<=0){
    printf("Vous avez vaincu le monstre, bien joue \n");
  }

  }
}
