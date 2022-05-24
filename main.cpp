#include<stdio.h>
#include<stdlib.h>
#include<SDL\SDL.h>
#include<SDL_image.h>
#include<SDL\SDL_ttf.h>

#define largeur 1440
#define hauteur 480

//delai aim
#define aimt 100
//end
#define optifin 3
//jump
#define timejumpfinal 400
#define timejumpmax 300
#define timegravitamax 100
#define delaijumptop 20
//delai run/jump
#define delaijump 100
#define vitessex1 6
#define vitessey1 5
#define vitessex2 6
#define vitessey2 3
//jump normal
#define vitesseyn1 5
#define vitesseyn2 4
//player
#define constvieplayer 66
//mana
#define constmanaplayer 53
#define costmana 1
#define delaimana_up 500
//velkoz
#define stdvel 250
#define constvievel 35
#define speedvel 5
#define stdvelmove 20
#define timevelsp 10000
#define scorevel 50
//ghost
#define ghosttime 150
#define ghostmovetime 15
#define ghostvitesse 3
#define ghosttimespawn 1500
#define ghostialmax 200
#define ghostial 100
#define constvieghost 5
#define ghostdamage 1
#define scoreghost 10
//animation du spawn ghost
#define ghosttimespawns 40


//delai stand
#define standa 210
//delai back
#define backk 600
//delai run
#define run 150
#define runvitesse 6
//delai dash
#define dash 250
#define dashvitesse 8
//attack
#define delaiattack 75
#define attackdamage 3
//mage
#define constviemage 35
#define magetimespawn 10500
#define magetime 60
#define nombremage 4
#define amagetime 3000
#define firetimemage 100
#define scoremage 30

//fire
#define firevitesse 10
#define firetime 150
#define firetimespeed 30
#define firedamage 2
#define firemovetime 20
#define delaifire_up 6000
//position x du shadow fire
#define xfireshadow 58
//coin
#define delaicoin 2500
#define delaicoinanim 100
#define scorecoin 50
#define nombrecoin 13

//back
#define delaiback 3000

#define sol 365

//variable inc
	int up=0,vu=0,e=1,vel=1,control=0,exite=1,timevel=0,W=0,CC=1,Coi=1,accel=0,Co[nombrecoin]={0,0,0,0,0,0},mag[nombremage]={0,0,0,0},tempsvel=0,plat=0,sortir=0,vieplayer=constvieplayer,mana=constmanaplayer,manaa=0,menuu=1,pausee=1,vughost[9]={0,0,0,0,0,0,0,0,0};
	int vievel=constvievel,vieghost[9]={2,2,2,2,2,2,2,2,2},viemage[nombremage]={2,2,2,2};
	int iaghost[9]={0,0,0,0,0,0,0,0,0},ve=1,vuvel=1,runn=0,sup=0,a=1,attackk=0,j=1,aimm=0;
	int bou=0,bou1=0,md[9]={0,0,0,0,0,0,0,0},magef[nombremage]={0,0,0,0},dashh=0,k=1,f=1,ff[9]={1,1,1,1,1,1,1,1,1},ffmage[nombremage]={1,1,1,1},d=1,i=1,rom=0;
	int gg[9]={1,1,1,1,1,1,1,1,1},ggs[9]={1,1,1,1,1,1,1,1,1},ggd[9]={15,15,15,15,15,15,15,15,15},mm[5]={1,1,1,1,1};
	int firegauchemenu=5,firedroitmenu=5,score=0;
	int ghost[9]={0,0,0,0,0,0,0,0,0},ggmage[nombremage]={1,1,1,1},ma[nombremage]={0,0,0,0},mageattack[nombremage]={-1,-1,-1,-1},vufiremage[nombremage]={-1,-1,-1,-1};
	//variable temp
   int tempsactuel=0,tempvelmoveg=0,tempfiremove[9]={0,0,0,0,0,0,0,0,0},tempfiremovegmage[nombremage]={0,0,0,0},tempfiremoveg[9]={0,0,0,0,0,0,0,0,0},timejump1=0,tempsjump=0;
   int tempvelmove=0,tempsinitial=0,tfire[9],tfire1[9]={0,0,0,0,0,0,0,0,0},tempsfire=0,tempsattack=0;
   int tempsfire1=0,tempsprerun=0,tempsprecedent=0,tempsback=0,tempsaim=0,tempsvel1=0,tghost[9]={0,0,0,0,0,0,0,0,0};
   int tghost1[9]={0,0,0,0,0,0,0,0,0},tfiremage[nombremage]={0,0,0,0},tfire1mage[nombremage]={0,0,0,0};;
   int tempghostmove[9]={0,0,0,0,0,0,0,0,0},tghostspawn[9]={0,0,0,0,0,0,0,0,0},tghostdeads1[9]={0,0,0,0,0,0,0,0,0};
   int tghostspawns1[9]={0,0,0,0,0,0,0,0,0},tghostspawn1=0,exitspawnghost=0,exitspawnmage=0,timemana=0,timefire_up[9]={0,0,0,0,0,0,0,0,0};
   int tmagespawn[nombremage]={0,0,0,0},tmagespawn1[nombremage]={0,0,0,0},vumage[nombremage]={0,0,0,0},tmage[nombremage]={0,0,0,0},tmage1[nombremage]={0,0,0,0};
   int tattackmag[nombremage]={0,0,0,0},tattackmag1[nombremage]={0,0,0,0},tempscoin=0,tempscoin1=0,tempscoin2=0,tempscoin3=0;

    SDL_Rect posplayer,posplayerrun,posvelkoz;

void initialiser()
{

	 up=0;vu=0;e=1;vel=1;control=0;plat=0;vieplayer=constvieplayer;sortir=0;mana=constmanaplayer;manaa=0;menuu=1;pausee=1;timevel=0;tempsvel=0;
	 ve=1;vuvel=1;runn=0;sup=0;a=1;attackk=0;j=1;aimm=0;firegauchemenu=5;firedroitmenu=5;
	 bou=0;bou1=0;dashh=0;k=1;f=1;d=1;i=1;rom=0;timejump1=0;tempsjump=0;CC=1;vievel=constvievel;Coi=1;exitspawnmage=0;score=0;
	 tempscoin=SDL_GetTicks();tempscoin1=SDL_GetTicks();tempscoin2=SDL_GetTicks();tempscoin3=SDL_GetTicks();accel=0;W=0;
	for(bou=1;bou<10;bou++)
    {
        ghost[bou]=0;
        ff[bou]=1;
        vieghost[bou]=2;
        vughost[bou]=0;
        iaghost[bou]=0;
        gg[bou]=1;
        ggs[bou]=1;
        md[bou]=0;
        timefire_up[bou]=SDL_GetTicks();
        tempghostmove[bou]=SDL_GetTicks();
        tghost1[bou]=SDL_GetTicks();
        tghostspawn[bou]=SDL_GetTicks();
        tghostdeads1[bou]=SDL_GetTicks();
        tghostspawns1[bou]=SDL_GetTicks();
        tempfiremove[bou]=SDL_GetTicks();
        tempfiremoveg[bou]=SDL_GetTicks();
        tfire1[bou]=SDL_GetTicks();
        tghost[bou]=SDL_GetTicks();
        ggd[bou]=15;
    }
    for(bou=1;bou<nombremage;bou++)
    {
        mm[bou]=1;
        mag[bou]=0;
        magef[bou]=0;
        ffmage[bou]=1;
        tempfiremovegmage[bou]=SDL_GetTicks();
        tfiremage[bou]=SDL_GetTicks();
        tfire1mage[bou]=SDL_GetTicks();
        viemage[bou]=2;
        tmagespawn[bou]=SDL_GetTicks();
        tmagespawn1[bou]=SDL_GetTicks();
        vumage[bou]=0;
        tmage[bou]=SDL_GetTicks();
        ma[bou]=0;
        tmage1[bou]=SDL_GetTicks();
        ggmage[bou]=1;
        vufiremage[bou]=-1;
        mageattack[bou]=-1;
        tattackmag[bou]=SDL_GetTicks();
        tattackmag1[bou]=SDL_GetTicks();
    }
    for(bou=6;bou<nombrecoin;bou++)
        Co[bou]=0;


    tempsactuel=SDL_GetTicks();tempvelmoveg=SDL_GetTicks();
    tempvelmove=SDL_GetTicks();tempsinitial=SDL_GetTicks();tempsfire=SDL_GetTicks();tempsattack=SDL_GetTicks();
    tempsfire1=SDL_GetTicks();tempsprerun=SDL_GetTicks();tempsprecedent=SDL_GetTicks();timemana=SDL_GetTicks();tempsback=SDL_GetTicks();tempsvel1=SDL_GetTicks();
    tghostspawn1=SDL_GetTicks(),exitspawnghost=0;
    //velkoz
           posvelkoz.x=largeur-540;
           posvelkoz.y=sol-60;

   posplayer.x=50;
   posplayer.y=sol;
   posplayerrun.x=posplayer.x+18;
}
int main(int argc,char *argv[])
{
	SDL_Event eve;
    exite=1;

   SDL_Init(SDL_INIT_VIDEO);
   TTF_Init();
   char ok[200]="";
   SDL_Surface *screen=NULL,*backe[6],*player[14],*playerg[14],*vie[36],*viemob[36],*attack[9],*attackg[9],*fire[9],*fireg[9],*shadowrun=NULL;
   SDL_Surface *shadowaim[4],*shadow[5],*playerrun[7],*playerjump[5],*playerjumpg[5],*aim[12],*aimg[12];
   SDL_Surface *playerdash[7],*playerdashg[7],*playerrung[7],*coin[10];
   SDL_Surface *ghostspawng[12],*ghostspawn[12],*ghosthit[3],*ghosthitg[3],*ghostg[4],*vieplayer_img[66],*manaplayer_img[55],*ghostd[4],*ghostdead[16];
   SDL_Surface *ghostdeadg[16],*magie[27],*magieg[27],*magieattack[20],*magieattackg[20];
   SDL_Surface *velkozg[17],*velkoz[17],*menu[4],*pause[4],*gameover,*fireg_up[6],*fire_up[6],*firemage[10],*firemageg[10],*sscore=NULL;
   SDL_Rect posback,posshadowfire[9],posback2,posvelkoz1,posvie,posattack,posshadowrun,posplayerjump;
   SDL_Rect posfire[9],posfiremage[nombremage],posshadowaim,posshadow,posghost[9],posghostvie[9],posghostdead[9];
   SDL_Rect posvieplayer,posmanaplayer,posfireg_up,posfire_up,posmage[nombremage],posmagevie[nombremage],posscore,poscoin[nombrecoin];
   TTF_Font *police=NULL;
   police=TTF_OpenFont("8514oem.fon",10);
   SDL_Color blanc={255,255,255},noir={0,0,0};
   sprintf(ok,"%d",score);
   sscore=TTF_RenderText_Shaded(police,ok,blanc,noir);



posscore.x=1100;
posscore.y=10;

poscoin[12].x=380;
poscoin[12].y=299;
poscoin[7].x=518;
poscoin[7].y=226;
poscoin[5].x=700;
poscoin[5].y=187;
poscoin[9].x=1060;
poscoin[9].y=215;
poscoin[2].x=186;
poscoin[2].y=207;
poscoin[6].x=103;
poscoin[6].y=389;
poscoin[10].x=637;
poscoin[10].y=336;
poscoin[8].x=984;
poscoin[8].y=398;
poscoin[11].x=899;
poscoin[11].y=130;
poscoin[1].x=620;
poscoin[1].y=237;
poscoin[4].x=391;
poscoin[4].y=215;
poscoin[3].x=192;
poscoin[3].y=134;


   //screen
   screen=SDL_SetVideoMode(largeur,hauteur,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
   SDL_WM_SetCaption("Half jump",NULL);
   //vie
   posvieplayer.x=10;
   posvieplayer.y=10;
   //mana
   posmanaplayer.x=10;
   posmanaplayer.y=29;
   //fire info pos
   posfireg_up.x=10;
   posfire_up.x=60;
   posfireg_up.y=55;
   posfire_up.y=55;

//pause
   pause[1]=IMG_Load("pic/pause.png");
   pause[2]=IMG_Load("pic/pause1.png");
   pause[3]=IMG_Load("pic/pause2.png");
//menu
      menu[1]=IMG_Load("pic/menu.png");
      menu[2]=IMG_Load("pic/menu1.png");
      menu[3]=IMG_Load("pic/menu2.png");
      //game over
      gameover=IMG_Load("pic/gameover.png");

   //back

       backe[1]=IMG_Load("pic/nightjump.jpg");
       backe[2]=IMG_Load("pic/nightjump1.jpg");
       backe[3]=IMG_Load("pic/nightjump2.jpg");

       //velkoz
           posvelkoz.x=largeur-540;
           posvelkoz.y=sol-60;

   posplayer.x=50;
   posplayer.y=sol;
   posplayerrun.x=posplayer.x+18;
   //shadow
   shadowrun=IMG_Load("pic/shadowrun.png");
//shadow
   shadow[1]=IMG_Load("pic/shadow.png");
   shadow[2]=IMG_Load("pic/shadow1.png");
   shadow[3]=IMG_Load("pic/shadow2.png");
   //shadowaim

   shadowaim[2]=IMG_Load("pic/shadowaim1.png");
   shadowaim[1]=IMG_Load("pic/shadowaim.png");
    shadowaim[3]=IMG_Load("pic/shadowaim.png");
//coin
coin[1]=IMG_Load("pic/coin.png");
coin[2]=IMG_Load("pic/coin1.png");
coin[3]=IMG_Load("pic/coin2.png");
coin[4]=IMG_Load("pic/coin3.png");
coin[5]=IMG_Load("pic/coin4.png");
coin[6]=IMG_Load("pic/coin5.png");
coin[7]=IMG_Load("pic/coin6.png");
coin[8]=IMG_Load("pic/coin7.png");

  // player
  player[1]=IMG_Load("pic/player.png");
  player[2]=IMG_Load("pic/player1.png");
  player[3]=IMG_Load("pic/player2.png");
  player[4]=IMG_Load("pic/player3.png");
  player[5]=IMG_Load("pic/player4.png");
  player[6]=IMG_Load("pic/player5.png");
  player[7]=IMG_Load("pic/player6.png");
  player[8]=IMG_Load("pic/player7.png");
  player[9]=IMG_Load("pic/player8.png");
  player[10]=IMG_Load("pic/player9.png");
  player[11]=IMG_Load("pic/player10.png");
  player[12]=IMG_Load("pic/player11.png");
  player[13]=IMG_Load("pic/player12.png");

  //playerg
  playerg[1]=IMG_Load("pic/playerg.png");
  playerg[2]=IMG_Load("pic/playerg1.png");
  playerg[3]=IMG_Load("pic/playerg2.png");
  playerg[4]=IMG_Load("pic/playerg3.png");
  playerg[5]=IMG_Load("pic/playerg4.png");
  playerg[6]=IMG_Load("pic/playerg5.png");
  playerg[7]=IMG_Load("pic/playerg6.png");
  playerg[8]=IMG_Load("pic/playerg7.png");
  playerg[9]=IMG_Load("pic/playerg8.png");
  playerg[10]=IMG_Load("pic/playerg9.png");
  playerg[11]=IMG_Load("pic/playerg10.png");
  playerg[12]=IMG_Load("pic/playerg11.png");
  playerg[13]=IMG_Load("pic/playerg12.png");
  //vie player
  vieplayer_img[1]=IMG_Load("pic/vieplayer65.png");
  vieplayer_img[2]=IMG_Load("pic/vieplayer64.png");
  vieplayer_img[3]=IMG_Load("pic/vieplayer63.png");
  vieplayer_img[4]=IMG_Load("pic/vieplayer62.png");
  vieplayer_img[5]=IMG_Load("pic/vieplayer61.png");
  vieplayer_img[6]=IMG_Load("pic/vieplayer60.png");
  vieplayer_img[7]=IMG_Load("pic/vieplayer59.png");
  vieplayer_img[8]=IMG_Load("pic/vieplayer58.png");
  vieplayer_img[9]=IMG_Load("pic/vieplayer57.png");
  vieplayer_img[10]=IMG_Load("pic/vieplayer56.png");
  vieplayer_img[11]=IMG_Load("pic/vieplayer55.png");
  vieplayer_img[12]=IMG_Load("pic/vieplayer54.png");
  vieplayer_img[13]=IMG_Load("pic/vieplayer53.png");
  vieplayer_img[14]=IMG_Load("pic/vieplayer52.png");
  vieplayer_img[15]=IMG_Load("pic/vieplayer51.png");
  vieplayer_img[16]=IMG_Load("pic/vieplayer50.png");
  vieplayer_img[17]=IMG_Load("pic/vieplayer49.png");
  vieplayer_img[18]=IMG_Load("pic/vieplayer48.png");
  vieplayer_img[19]=IMG_Load("pic/vieplayer47.png");
  vieplayer_img[20]=IMG_Load("pic/vieplayer46.png");
  vieplayer_img[21]=IMG_Load("pic/vieplayer45.png");
  vieplayer_img[22]=IMG_Load("pic/vieplayer44.png");
  vieplayer_img[23]=IMG_Load("pic/vieplayer43.png");
  vieplayer_img[24]=IMG_Load("pic/vieplayer42.png");
  vieplayer_img[25]=IMG_Load("pic/vieplayer41.png");
  vieplayer_img[26]=IMG_Load("pic/vieplayer40.png");
  vieplayer_img[27]=IMG_Load("pic/vieplayer39.png");
  vieplayer_img[28]=IMG_Load("pic/vieplayer38.png");
  vieplayer_img[29]=IMG_Load("pic/vieplayer37.png");
  vieplayer_img[30]=IMG_Load("pic/vieplayer36.png");
  vieplayer_img[31]=IMG_Load("pic/vieplayer35.png");
  vieplayer_img[32]=IMG_Load("pic/vieplayer34.png");
  vieplayer_img[33]=IMG_Load("pic/vieplayer33.png");
  vieplayer_img[34]=IMG_Load("pic/vieplayer32.png");
  vieplayer_img[35]=IMG_Load("pic/vieplayer31.png");
  vieplayer_img[36]=IMG_Load("pic/vieplayer30.png");
  vieplayer_img[37]=IMG_Load("pic/vieplayer29.png");
  vieplayer_img[38]=IMG_Load("pic/vieplayer28.png");
  vieplayer_img[39]=IMG_Load("pic/vieplayer27.png");
  vieplayer_img[40]=IMG_Load("pic/vieplayer26.png");
  vieplayer_img[41]=IMG_Load("pic/vieplayer25.png");
  vieplayer_img[42]=IMG_Load("pic/vieplayer24.png");
  vieplayer_img[43]=IMG_Load("pic/vieplayer23.png");
  vieplayer_img[44]=IMG_Load("pic/vieplayer22.png");
  vieplayer_img[45]=IMG_Load("pic/vieplayer21.png");
  vieplayer_img[46]=IMG_Load("pic/vieplayer20.png");
  vieplayer_img[47]=IMG_Load("pic/vieplayer19.png");
  vieplayer_img[48]=IMG_Load("pic/vieplayer18.png");
  vieplayer_img[49]=IMG_Load("pic/vieplayer17.png");
  vieplayer_img[50]=IMG_Load("pic/vieplayer16.png");
  vieplayer_img[51]=IMG_Load("pic/vieplayer15.png");
  vieplayer_img[52]=IMG_Load("pic/vieplayer14.png");
  vieplayer_img[53]=IMG_Load("pic/vieplayer13.png");
  vieplayer_img[54]=IMG_Load("pic/vieplayer12.png");
  vieplayer_img[55]=IMG_Load("pic/vieplayer11.png");
  vieplayer_img[56]=IMG_Load("pic/vieplayer10.png");
  vieplayer_img[57]=IMG_Load("pic/vieplayer9.png");
  vieplayer_img[58]=IMG_Load("pic/vieplayer8.png");
  vieplayer_img[59]=IMG_Load("pic/vieplayer7.png");
  vieplayer_img[60]=IMG_Load("pic/vieplayer6.png");
  vieplayer_img[61]=IMG_Load("pic/vieplayer5.png");
  vieplayer_img[62]=IMG_Load("pic/vieplayer4.png");
  vieplayer_img[63]=IMG_Load("pic/vieplayer3.png");
  vieplayer_img[64]=IMG_Load("pic/vieplayer2.png");
  vieplayer_img[65]=IMG_Load("pic/vieplayer1.png");
  vieplayer_img[66]=IMG_Load("pic/vieplayer.png");
//mana player
  manaplayer_img[1]=IMG_Load("pic/manaplayer53.png");
  manaplayer_img[2]=IMG_Load("pic/manaplayer52.png");
  manaplayer_img[3]=IMG_Load("pic/manaplayer51.png");
  manaplayer_img[4]=IMG_Load("pic/manaplayer50.png");
  manaplayer_img[5]=IMG_Load("pic/manaplayer49.png");
  manaplayer_img[6]=IMG_Load("pic/manaplayer48.png");
  manaplayer_img[7]=IMG_Load("pic/manaplayer47.png");
  manaplayer_img[8]=IMG_Load("pic/manaplayer46.png");
  manaplayer_img[9]=IMG_Load("pic/manaplayer45.png");
  manaplayer_img[10]=IMG_Load("pic/manaplayer44.png");
  manaplayer_img[11]=IMG_Load("pic/manaplayer43.png");
  manaplayer_img[12]=IMG_Load("pic/manaplayer42.png");
  manaplayer_img[13]=IMG_Load("pic/manaplayer41.png");
  manaplayer_img[14]=IMG_Load("pic/manaplayer40.png");
  manaplayer_img[15]=IMG_Load("pic/manaplayer39.png");
  manaplayer_img[16]=IMG_Load("pic/manaplayer38.png");
  manaplayer_img[17]=IMG_Load("pic/manaplayer37.png");
  manaplayer_img[18]=IMG_Load("pic/manaplayer36.png");
  manaplayer_img[19]=IMG_Load("pic/manaplayer35.png");
  manaplayer_img[20]=IMG_Load("pic/manaplayer34.png");
  manaplayer_img[21]=IMG_Load("pic/manaplayer33.png");
  manaplayer_img[22]=IMG_Load("pic/manaplayer32.png");
  manaplayer_img[23]=IMG_Load("pic/manaplayer31.png");
  manaplayer_img[24]=IMG_Load("pic/manaplayer30.png");
  manaplayer_img[25]=IMG_Load("pic/manaplayer29.png");
  manaplayer_img[26]=IMG_Load("pic/manaplayer28.png");
  manaplayer_img[27]=IMG_Load("pic/manaplayer27.png");
  manaplayer_img[28]=IMG_Load("pic/manaplayer26.png");
  manaplayer_img[29]=IMG_Load("pic/manaplayer25.png");
  manaplayer_img[30]=IMG_Load("pic/manaplayer24.png");
  manaplayer_img[31]=IMG_Load("pic/manaplayer23.png");
  manaplayer_img[32]=IMG_Load("pic/manaplayer22.png");
  manaplayer_img[33]=IMG_Load("pic/manaplayer21.png");
  manaplayer_img[34]=IMG_Load("pic/manaplayer20.png");
  manaplayer_img[35]=IMG_Load("pic/manaplayer19.png");
  manaplayer_img[36]=IMG_Load("pic/manaplayer18.png");
  manaplayer_img[37]=IMG_Load("pic/manaplayer17.png");
  manaplayer_img[38]=IMG_Load("pic/manaplayer16.png");
  manaplayer_img[39]=IMG_Load("pic/manaplayer15.png");
  manaplayer_img[40]=IMG_Load("pic/manaplayer14.png");
  manaplayer_img[41]=IMG_Load("pic/manaplayer13.png");
  manaplayer_img[42]=IMG_Load("pic/manaplayer12.png");
  manaplayer_img[43]=IMG_Load("pic/manaplayer11.png");
  manaplayer_img[44]=IMG_Load("pic/manaplayer10.png");
  manaplayer_img[45]=IMG_Load("pic/manaplayer9.png");
  manaplayer_img[46]=IMG_Load("pic/manaplayer8.png");
  manaplayer_img[47]=IMG_Load("pic/manaplayer7.png");
  manaplayer_img[48]=IMG_Load("pic/manaplayer6.png");
  manaplayer_img[49]=IMG_Load("pic/manaplayer5.png");
  manaplayer_img[50]=IMG_Load("pic/manaplayer4.png");
  manaplayer_img[51]=IMG_Load("pic/manaplayer3.png");
  manaplayer_img[52]=IMG_Load("pic/manaplayer2.png");
  manaplayer_img[53]=IMG_Load("pic/manaplayer1.png");
  manaplayer_img[54]=IMG_Load("pic/manaplayer.png");




//rung
  playerrung[1]=IMG_Load("pic/rungauche.png");
  playerrung[2]=IMG_Load("pic/rungauche1.png");
  playerrung[3]=IMG_Load("pic/rungauche2.png");
  playerrung[4]=IMG_Load("pic/rungauche3.png");
  playerrung[5]=IMG_Load("pic/rungauche4.png");
  playerrung[6]=IMG_Load("pic/rungauche5.png");
//jump
  playerjump[1]=IMG_Load("pic/jump.png");
  playerjump[2]=IMG_Load("pic/jump1.png");
  playerjump[3]=IMG_Load("pic/jump2.png");
  playerjump[4]=IMG_Load("pic/jump3.png");
//jumpg
  playerjumpg[1]=IMG_Load("pic/jumpg.png");
  playerjumpg[2]=IMG_Load("pic/jumpg1.png");
  playerjumpg[3]=IMG_Load("pic/jumpg2.png");
  playerjumpg[4]=IMG_Load("pic/jumpg3.png");

//run
  playerrun[1]=IMG_Load("pic/rundroit.png");
  playerrun[2]=IMG_Load("pic/rundroit1.png");
  playerrun[3]=IMG_Load("pic/rundroit2.png");
  playerrun[4]=IMG_Load("pic/rundroit3.png");
  playerrun[5]=IMG_Load("pic/rundroit4.png");
  playerrun[6]=IMG_Load("pic/rundroit5.png");
//dash
  playerdash[1]=IMG_Load("pic/dash.png");
  playerdash[2]=IMG_Load("pic/dash1.png");
  playerdash[3]=IMG_Load("pic/dash2.png");
  playerdash[4]=IMG_Load("pic/dash1.png");
  playerdash[5]=IMG_Load("pic/dash.png");
  playerdash[6]=IMG_Load("pic/dash1.png");

//dashg
  playerdashg[1]=IMG_Load("pic/dashg.png");
  playerdashg[2]=IMG_Load("pic/dashg1.png");
  playerdashg[3]=IMG_Load("pic/dashg2.png");
  playerdashg[4]=IMG_Load("pic/dashg1.png");
  playerdashg[5]=IMG_Load("pic/dashg.png");
  playerdashg[6]=IMG_Load("pic/dashg1.png");
//aim
 aim[1]=IMG_Load("pic/aim.png");
 aim[2]=IMG_Load("pic/aim1.png");
 aim[3]=IMG_Load("pic/aim2.png");
 aim[4]=IMG_Load("pic/aim3.png");
 aim[5]=IMG_Load("pic/aim4.png");
 aim[6]=IMG_Load("pic/aim5.png");
 aim[7]=IMG_Load("pic/aim6.png");
 aim[8]=IMG_Load("pic/aim7.png");
 aim[9]=IMG_Load("pic/aim8.png");
 aim[10]=IMG_Load("pic/aim9.png");
 aim[11]=IMG_Load("pic/aimrun.png");

  //aimg
 aimg[1]=IMG_Load("pic/aimg.png");
 aimg[2]=IMG_Load("pic/aimg1.png");
 aimg[3]=IMG_Load("pic/aimg2.png");
 aimg[4]=IMG_Load("pic/aimg3.png");
 aimg[5]=IMG_Load("pic/aimg4.png");
 aimg[6]=IMG_Load("pic/aimg5.png");
 aimg[7]=IMG_Load("pic/aimg6.png");
 aimg[8]=IMG_Load("pic/aimg7.png");
 aimg[9]=IMG_Load("pic/aimg8.png");
 aimg[10]=IMG_Load("pic/aimg9.png");
 aimg[11]=IMG_Load("pic/aimrung.png");
 //fire droite
  fire[1]=IMG_Load("pic/fire.png");
  fire[2]=IMG_Load("pic/fire1.png");
  fire[3]=IMG_Load("pic/fire2.png");
  fire[4]=IMG_Load("pic/fire3.png");
  fire[5]=IMG_Load("pic/fire4.png");
  fire[6]=IMG_Load("pic/fire5.png");
  fire[7]=IMG_Load("pic/fire6.png");
  fire[8]=IMG_Load("pic/fire7.png");

  //fire gauche

  fireg[1]=IMG_Load("pic/fireg.png");
  fireg[2]=IMG_Load("pic/fireg1.png");
  fireg[3]=IMG_Load("pic/fireg2.png");
  fireg[4]=IMG_Load("pic/fireg3.png");
  fireg[5]=IMG_Load("pic/fireg4.png");
  fireg[6]=IMG_Load("pic/fireg5.png");
  fireg[7]=IMG_Load("pic/fireg6.png");
  fireg[8]=IMG_Load("pic/fireg7.png");
  //fire up droit
  fire_up[1]=IMG_Load("pic/fireicone.png");
  fire_up[2]=IMG_Load("pic/fireicone1.png");
  fire_up[3]=IMG_Load("pic/fireicone2.png");
  fire_up[4]=IMG_Load("pic/fireicone3.png");
  fire_up[5]=IMG_Load("pic/fireicone4.png");
  //fire up gauche
  fireg_up[1]=IMG_Load("pic/firegicone.png");
  fireg_up[2]=IMG_Load("pic/firegicone1.png");
  fireg_up[3]=IMG_Load("pic/firegicone2.png");
  fireg_up[4]=IMG_Load("pic/firegicone3.png");
  fireg_up[5]=IMG_Load("pic/firegicone4.png");



  //attack droit
 attack[1]=IMG_Load("pic/attack.png");
 attack[2]=IMG_Load("pic/attack1.png");
 attack[3]=IMG_Load("pic/attack2.png");
 attack[4]=IMG_Load("pic/attack3.png");
 attack[5]=IMG_Load("pic/attack4.png");
 attack[6]=IMG_Load("pic/attack5.png");
 attack[7]=IMG_Load("pic/attack6.png");
 attack[8]=IMG_Load("pic/attack7.png");
 //attack gauche
 attackg[1]=IMG_Load("pic/attackg.png");
 attackg[2]=IMG_Load("pic/attackg1.png");
 attackg[3]=IMG_Load("pic/attackg2.png");
 attackg[4]=IMG_Load("pic/attackg3.png");
 attackg[5]=IMG_Load("pic/attackg4.png");
 attackg[6]=IMG_Load("pic/attackg5.png");
 attackg[7]=IMG_Load("pic/attackg6.png");
 attackg[8]=IMG_Load("pic/attackg7.png");
 //velkoz gauche
 velkozg[1]=IMG_Load("pic/velgauche.png");
 velkozg[2]=IMG_Load("pic/velgauche1.png");
 velkozg[3]=IMG_Load("pic/velgauche2.png");
 velkozg[4]=IMG_Load("pic/velgauche3.png");
 velkozg[5]=IMG_Load("pic/velgauche4.png");
 velkozg[6]=IMG_Load("pic/velgauche5.png");
 velkozg[7]=IMG_Load("pic/velgauche6.png");
 velkozg[8]=IMG_Load("pic/velgauche7.png");
 velkozg[9]=IMG_Load("pic/velgauche8.png");
 velkozg[10]=IMG_Load("pic/velgauche9.png");
 velkozg[11]=IMG_Load("pic/velgauche10.png");
 velkozg[12]=IMG_Load("pic/velgauche11.png");
 velkozg[13]=IMG_Load("pic/velgauche12.png");
 velkozg[14]=IMG_Load("pic/velgauche13.png");
 velkozg[15]=IMG_Load("pic/velgauche14.png");
 velkozg[16]=IMG_Load("pic/velgauche15.png");
 //velkoz droit

 //velkoz gauche
 velkoz[1]=IMG_Load("pic/veldroit.png");
 velkoz[2]=IMG_Load("pic/veldroit1.png");
 velkoz[3]=IMG_Load("pic/veldroit2.png");
 velkoz[4]=IMG_Load("pic/veldroit3.png");
 velkoz[5]=IMG_Load("pic/veldroit4.png");
 velkoz[6]=IMG_Load("pic/veldroit5.png");
 velkoz[7]=IMG_Load("pic/veldroit6.png");
 velkoz[8]=IMG_Load("pic/veldroit7.png");
 velkoz[9]=IMG_Load("pic/veldroit8.png");
 velkoz[10]=IMG_Load("pic/veldroit9.png");
 velkoz[11]=IMG_Load("pic/veldroit10.png");
 velkoz[12]=IMG_Load("pic/veldroit11.png");
 velkoz[13]=IMG_Load("pic/veldroit12.png");
 velkoz[14]=IMG_Load("pic/veldroit13.png");
 velkoz[15]=IMG_Load("pic/veldroit14.png");
 velkoz[16]=IMG_Load("pic/veldroit15.png");

//vie
vie[1]=IMG_Load("pic/vie.png");
vie[2]=IMG_Load("pic/vie1.png");
vie[3]=IMG_Load("pic/vie2.png");
vie[4]=IMG_Load("pic/vie3.png");
vie[5]=IMG_Load("pic/vie4.png");
vie[6]=IMG_Load("pic/vie5.png");
vie[7]=IMG_Load("pic/vie6.png");
vie[8]=IMG_Load("pic/vie7.png");
vie[9]=IMG_Load("pic/vie8.png");
vie[10]=IMG_Load("pic/vie9.png");
vie[11]=IMG_Load("pic/vie10.png");
vie[12]=IMG_Load("pic/vie11.png");
vie[13]=IMG_Load("pic/vie12.png");
vie[14]=IMG_Load("pic/vie13.png");
vie[15]=IMG_Load("pic/vie14.png");
vie[16]=IMG_Load("pic/vie15.png");
vie[17]=IMG_Load("pic/vie16.png");
vie[18]=IMG_Load("pic/vie17.png");
vie[19]=IMG_Load("pic/vie18.png");
vie[20]=IMG_Load("pic/vie19.png");
vie[21]=IMG_Load("pic/vie20.png");
vie[22]=IMG_Load("pic/vie21.png");
vie[23]=IMG_Load("pic/vie22.png");
vie[24]=IMG_Load("pic/vie23.png");
vie[25]=IMG_Load("pic/vie24.png");
vie[26]=IMG_Load("pic/vie25.png");
vie[27]=IMG_Load("pic/vie26.png");
vie[28]=IMG_Load("pic/vie27.png");
vie[29]=IMG_Load("pic/vie28.png");
vie[30]=IMG_Load("pic/vie29.png");
vie[31]=IMG_Load("pic/vie30.png");
vie[32]=IMG_Load("pic/vie31.png");
vie[33]=IMG_Load("pic/vie32.png");
vie[34]=IMG_Load("pic/vie33.png");
vie[35]=IMG_Load("pic/vie34.png");
//vie mob
viemob[1]=IMG_Load("pic/viem.png");
viemob[2]=IMG_Load("pic/viem1.png");
viemob[3]=IMG_Load("pic/viem2.png");
viemob[4]=IMG_Load("pic/viem3.png");
viemob[5]=IMG_Load("pic/viem4.png");
viemob[6]=IMG_Load("pic/viem5.png");
viemob[7]=IMG_Load("pic/viem6.png");
viemob[8]=IMG_Load("pic/viem7.png");
viemob[9]=IMG_Load("pic/viem8.png");
viemob[10]=IMG_Load("pic/viem9.png");
viemob[11]=IMG_Load("pic/viem10.png");
viemob[12]=IMG_Load("pic/viem11.png");
viemob[13]=IMG_Load("pic/viem12.png");
viemob[14]=IMG_Load("pic/viem13.png");
viemob[15]=IMG_Load("pic/viem14.png");
viemob[16]=IMG_Load("pic/viem15.png");
viemob[17]=IMG_Load("pic/viem16.png");
viemob[18]=IMG_Load("pic/viem17.png");
viemob[19]=IMG_Load("pic/viem18.png");
viemob[20]=IMG_Load("pic/viem19.png");
viemob[21]=IMG_Load("pic/viem20.png");
viemob[22]=IMG_Load("pic/viem21.png");
viemob[23]=IMG_Load("pic/viem22.png");
viemob[24]=IMG_Load("pic/viem23.png");
viemob[25]=IMG_Load("pic/viem24.png");
viemob[26]=IMG_Load("pic/viem25.png");
viemob[27]=IMG_Load("pic/viem26.png");
viemob[28]=IMG_Load("pic/viem27.png");
viemob[29]=IMG_Load("pic/viem28.png");
viemob[30]=IMG_Load("pic/viem29.png");
viemob[31]=IMG_Load("pic/viem30.png");
viemob[32]=IMG_Load("pic/viem31.png");
viemob[33]=IMG_Load("pic/viem32.png");
viemob[34]=IMG_Load("pic/viem33.png");
viemob[35]=IMG_Load("pic/viem34.png");
//magie
magie[1]=IMG_Load("pic/magie.png");
magie[2]=IMG_Load("pic/magie1.png");
magie[3]=IMG_Load("pic/magie2.png");
magie[4]=IMG_Load("pic/magie3.png");
magie[5]=IMG_Load("pic/magie4.png");
magie[6]=IMG_Load("pic/magie5.png");
magie[7]=IMG_Load("pic/magie6.png");
magie[8]=IMG_Load("pic/magie7.png");
magie[9]=IMG_Load("pic/magie8.png");
magie[10]=IMG_Load("pic/magie9.png");
magie[11]=IMG_Load("pic/magie10.png");
magie[12]=IMG_Load("pic/magie11.png");
magie[13]=IMG_Load("pic/magie12.png");
magie[14]=IMG_Load("pic/magie13.png");
magie[15]=IMG_Load("pic/magie14.png");
magie[16]=IMG_Load("pic/magie15.png");
magie[17]=IMG_Load("pic/magie16.png");
magie[18]=IMG_Load("pic/magie17.png");
magie[19]=IMG_Load("pic/magie18.png");
magie[20]=IMG_Load("pic/magie19.png");
magie[21]=IMG_Load("pic/magie20.png");
magie[22]=IMG_Load("pic/magie21.png");
magie[23]=IMG_Load("pic/magie22.png");
magie[24]=IMG_Load("pic/magie23.png");
magie[25]=IMG_Load("pic/magie24.png");
magie[26]=IMG_Load("pic/magie25.png");
magie[27]=IMG_Load("pic/magie26.png");
//magie gauche
magieg[1]=IMG_Load("pic/magieg.png");
magieg[2]=IMG_Load("pic/magieg1.png");
magieg[3]=IMG_Load("pic/magieg2.png");
magieg[4]=IMG_Load("pic/magieg3.png");
magieg[5]=IMG_Load("pic/magieg4.png");
magieg[6]=IMG_Load("pic/magieg5.png");
magieg[7]=IMG_Load("pic/magieg6.png");
magieg[8]=IMG_Load("pic/magieg7.png");
magieg[9]=IMG_Load("pic/magieg8.png");
magieg[10]=IMG_Load("pic/magieg9.png");
magieg[11]=IMG_Load("pic/magieg10.png");
magieg[12]=IMG_Load("pic/magieg11.png");
magieg[13]=IMG_Load("pic/magieg12.png");
magieg[14]=IMG_Load("pic/magieg13.png");
magieg[15]=IMG_Load("pic/magieg14.png");
magieg[16]=IMG_Load("pic/magieg15.png");
magieg[17]=IMG_Load("pic/magieg16.png");
magieg[18]=IMG_Load("pic/magieg17.png");
magieg[19]=IMG_Load("pic/magieg18.png");
magieg[20]=IMG_Load("pic/magieg19.png");
magieg[21]=IMG_Load("pic/magieg20.png");
magieg[22]=IMG_Load("pic/magieg21.png");
magieg[23]=IMG_Load("pic/magieg22.png");
magieg[24]=IMG_Load("pic/magieg23.png");
magieg[25]=IMG_Load("pic/magieg24.png");
magieg[26]=IMG_Load("pic/magieg25.png");
magieg[27]=IMG_Load("pic/magieg26.png");
//magie attack gauche
magieattackg[1]=IMG_Load("pic/magieattackg.png");
magieattackg[2]=IMG_Load("pic/magieattackg1.png");
magieattackg[3]=IMG_Load("pic/magieattackg2.png");
magieattackg[4]=IMG_Load("pic/magieattackg3.png");
magieattackg[5]=IMG_Load("pic/magieattackg4.png");
magieattackg[6]=IMG_Load("pic/magieattackg5.png");
magieattackg[7]=IMG_Load("pic/magieattackg6.png");
magieattackg[8]=IMG_Load("pic/magieattackg7.png");
magieattackg[9]=IMG_Load("pic/magieattackg8.png");
magieattackg[10]=IMG_Load("pic/magieattackg9.png");
magieattackg[11]=IMG_Load("pic/magieattackg10.png");
magieattackg[12]=IMG_Load("pic/magieattackg11.png");
magieattackg[13]=IMG_Load("pic/magieattackg12.png");
magieattackg[14]=IMG_Load("pic/magieattackg13.png");
magieattackg[15]=IMG_Load("pic/magieattackg14.png");
magieattackg[16]=IMG_Load("pic/magieattackg15.png");
magieattackg[17]=IMG_Load("pic/magieattackg16.png");
magieattackg[18]=IMG_Load("pic/magieattackg17.png");
magieattackg[19]=IMG_Load("pic/magieattackg18.png");
magieattackg[20]=IMG_Load("pic/magieattackg19.png");

//magie attack droit
magieattack[1]=IMG_Load("pic/magieattack.png");
magieattack[2]=IMG_Load("pic/magieattack1.png");
magieattack[3]=IMG_Load("pic/magieattack2.png");
magieattack[4]=IMG_Load("pic/magieattack3.png");
magieattack[5]=IMG_Load("pic/magieattack4.png");
magieattack[6]=IMG_Load("pic/magieattack5.png");
magieattack[7]=IMG_Load("pic/magieattack6.png");
magieattack[8]=IMG_Load("pic/magieattack7.png");
magieattack[9]=IMG_Load("pic/magieattack8.png");
magieattack[10]=IMG_Load("pic/magieattack9.png");
magieattack[11]=IMG_Load("pic/magieattack10.png");
magieattack[12]=IMG_Load("pic/magieattack11.png");
magieattack[13]=IMG_Load("pic/magieattack12.png");
magieattack[14]=IMG_Load("pic/magieattack13.png");
magieattack[15]=IMG_Load("pic/magieattack14.png");
magieattack[16]=IMG_Load("pic/magieattack15.png");
magieattack[17]=IMG_Load("pic/magieattack16.png");
magieattack[18]=IMG_Load("pic/magieattack17.png");
magieattack[19]=IMG_Load("pic/magieattack18.png");
magieattack[20]=IMG_Load("pic/magieattack19.png");
//fire mage
firemage[1]=IMG_Load("pic/firemage.png");
firemage[2]=IMG_Load("pic/firemage1.png");
firemage[3]=IMG_Load("pic/firemage2.png");
firemage[4]=IMG_Load("pic/firemage3.png");
firemage[5]=IMG_Load("pic/firemage4.png");
firemage[6]=IMG_Load("pic/firemage5.png");
firemage[7]=IMG_Load("pic/firemage6.png");
firemage[8]=IMG_Load("pic/firemage7.png");
//gauche fire mage
firemageg[1]=IMG_Load("pic/firemageg.png");
firemageg[2]=IMG_Load("pic/firemageg1.png");
firemageg[3]=IMG_Load("pic/firemageg2.png");
firemageg[4]=IMG_Load("pic/firemageg3.png");
firemageg[5]=IMG_Load("pic/firemageg4.png");
firemageg[6]=IMG_Load("pic/firemageg5.png");
firemageg[7]=IMG_Load("pic/firemageg6.png");
firemageg[8]=IMG_Load("pic/firemageg7.png");

ghostg[1]=IMG_Load("pic/ghostgauche.png");
ghostg[2]=IMG_Load("pic/ghostgauche1.png");
ghostg[3]=IMG_Load("pic/ghostgauche2.png");
//ghost droit
ghostd[1]=IMG_Load("pic/ghost.png");
ghostd[2]=IMG_Load("pic/ghost1.png");
ghostd[3]=IMG_Load("pic/ghost2.png");
//ghost dead gauche
ghostdeadg[1]=IMG_Load("pic/ghostgauhespawn.png");
ghostdeadg[2]=IMG_Load("pic/ghostgauhespawn1.png");
ghostdeadg[3]=IMG_Load("pic/ghostgauhespawn2.png");
ghostdeadg[4]=IMG_Load("pic/ghostgauhespawn3.png");
ghostdeadg[5]=IMG_Load("pic/ghostgauhespawn4.png");
ghostdeadg[6]=IMG_Load("pic/ghostspawng5.png");
ghostdeadg[7]=IMG_Load("pic/ghostspawng6.png");
ghostdeadg[8]=IMG_Load("pic/ghostspawng7.png");
ghostdeadg[9]=IMG_Load("pic/ghostspawng8.png");
ghostdeadg[10]=IMG_Load("pic/ghostspawng9.png");
ghostdeadg[11]=IMG_Load("pic/ghostspawng10.png");
ghostdeadg[12]=IMG_Load("pic/ghostspawng11.png");
ghostdeadg[13]=IMG_Load("pic/ghostspawng12.png");
ghostdeadg[14]=IMG_Load("pic/ghostspawng13.png");
ghostdeadg[15]=IMG_Load("pic/ghostspawng14.png");
//ghost dead droit
ghostdead[1]=IMG_Load("pic/ghostspawn.png");
ghostdead[2]=IMG_Load("pic/ghostspawn1.png");
ghostdead[3]=IMG_Load("pic/ghostspawn2.png");
ghostdead[4]=IMG_Load("pic/ghostspawn3.png");
ghostdead[5]=IMG_Load("pic/ghostspawn4.png");
ghostdead[6]=IMG_Load("pic/ghostspawn5.png");
ghostdead[7]=IMG_Load("pic/ghostspawn6.png");
ghostdead[8]=IMG_Load("pic/ghostspawn7.png");
ghostdead[9]=IMG_Load("pic/ghostspawn8.png");
ghostdead[10]=IMG_Load("pic/ghostspawn9.png");
ghostdead[11]=IMG_Load("pic/ghostspawn10.png");
ghostdead[12]=IMG_Load("pic/ghostspawn11.png");
ghostdead[13]=IMG_Load("pic/ghostspawn12.png");
ghostdead[14]=IMG_Load("pic/ghostspawn13.png");
ghostdead[15]=IMG_Load("pic/ghostspawn14.png");

//ghost spawn gauche
ghostspawng[1]=IMG_Load("pic/ghostgauchedead11.png");
ghostspawng[2]=IMG_Load("pic/ghostgauchedead10.png");
ghostspawng[3]=IMG_Load("pic/ghostgauchedead9.png");
ghostspawng[4]=IMG_Load("pic/ghostgauchedead8.png");
ghostspawng[5]=IMG_Load("pic/ghostgauchedead7.png");
ghostspawng[6]=IMG_Load("pic/ghostgauchedead6.png");
ghostspawng[7]=IMG_Load("pic/ghostgauchedead5.png");
ghostspawng[8]=IMG_Load("pic/ghostgauchedead4.png");
ghostspawng[9]=IMG_Load("pic/ghostgauchedead3.png");
ghostspawng[10]=IMG_Load("pic/ghostgauchedead2.png");
ghostspawng[11]=IMG_Load("pic/ghostgauchedead1.png");
ghostspawng[12]=IMG_Load("pic/ghostgauchedead.png");
//ghost spawn droit
ghostspawn[1]=IMG_Load("pic/ghostdead11.png");
ghostspawn[2]=IMG_Load("pic/ghostdead10.png");
ghostspawn[3]=IMG_Load("pic/ghostdead9.png");
ghostspawn[4]=IMG_Load("pic/ghostdead8.png");
ghostspawn[5]=IMG_Load("pic/ghostdead7.png");
ghostspawn[6]=IMG_Load("pic/ghostdead6.png");
ghostspawn[7]=IMG_Load("pic/ghostdead5.png");
ghostspawn[8]=IMG_Load("pic/ghostdead4.png");
ghostspawn[9]=IMG_Load("pic/ghostdead3.png");
ghostspawn[10]=IMG_Load("pic/ghostdead2.png");
ghostspawn[11]=IMG_Load("pic/ghostdead1.png");
ghostspawn[12]=IMG_Load("pic/ghostdead.png");
//ghost hit gauche
ghosthitg[1]=IMG_Load("pic/ghostgauchehit");
ghosthitg[2]=IMG_Load("pic/ghostgauchehit1");
//ghost hit droit
ghosthit[1]=IMG_Load("pic/ghosthit");
ghosthit[2]=IMG_Load("pic/ghosthit1");








   posback.x=0;
   posback.y=0;
   //fermer le jeu
   while(exite!=2)
   {
   //menu
    while(exite==1)
   {   SDL_Delay(15);




       switch(eve.type)
       {
       case SDL_QUIT:
        exite=2;
        break;
        case SDL_MOUSEMOTION:
            if(eve.motion.y>=124 && eve.motion.y<=184)
            {
            if(eve.motion.x>=76 && eve.motion.x<=335)
                menuu=2;
                else{
                    menuu=1;
                   }
            }
            else
            if(eve.motion.y>=240 && eve.motion.y<=280)
            {
            if(eve.motion.x>=76 && eve.motion.x<=190)
                menuu=3;
                else
                {
                    menuu=1;
                }
            }
                else{
                    menuu=1;
                    }
            break;
        case SDL_MOUSEBUTTONDOWN:
            if(menuu==2)
            {
                initialiser();
                exite=0;
            }
            else if(menuu==3)
                exite=2;

        case SDL_KEYDOWN:
        switch(eve.key.keysym.sym)
        {
        case SDLK_ESCAPE:
            exite=2;
        break;
        case SDLK_KP_ENTER:

                initialiser();
                exite=0;
                break;

       case SDLK_RETURN:
            initialiser();
                exite=0;
                break;
        }
       }

       SDL_BlitSurface(menu[menuu],NULL,screen,&posback);

       SDL_Flip(screen);
       SDL_WaitEvent(&eve);
   }
   while(exite==5)
   {
       SDL_BlitSurface(gameover,NULL,screen,&posback);
       SDL_Flip(screen);
       SDL_Delay(5000);
       exite=1;
   }

   while(exite==4 || exite==0)
    //pause
   {  if(exite==4)
   {  SDL_Delay(15);
       SDL_WaitEvent(&eve);
       switch(eve.type)
       {
       case SDL_QUIT:
        exite=1;
        break;
        case SDL_MOUSEMOTION:
            if(eve.motion.y>=190 && eve.motion.y<=246)
            {
            if(eve.motion.x>=608 && eve.motion.x<=780)
                pausee=2;
                else{
                    pausee=1;
                   }
            }
            else
            if(eve.motion.y>=270 && eve.motion.y<=330)
            {
            if(eve.motion.x>=633 && eve.motion.x<=740)
                pausee=3;
                else
                {
                    pausee=1;
                }
            }
                else{
                    pausee=1;
                    }
            break;
        case SDL_MOUSEBUTTONDOWN:
            if(pausee==2)
                exite=0;
            else if(pausee==3)
            {
                exite=1;

            }

        case SDL_KEYDOWN:
        switch(eve.key.keysym.sym)
        {
        case SDLK_ESCAPE:
            exite=1;

        break;


       }
       }

   }
    //jeu
    else
    if(exite==0)
    {
        tempsinitial=SDL_GetTicks();
      rom=0;
      exitspawnghost=0;
      exitspawnmage=0;
      runn=0;
      aimm=0;
      dashh=0;
      attackk=0;
       SDL_PollEvent(&eve);
    SDL_EventState(SDL_KEYDOWN,SDL_ENABLE);
       switch(eve.type)
       {
       	case SDL_QUIT:
        exite=4;
            break;
        case SDL_KEYDOWN:
        switch(eve.key.keysym.sym)
        {
        case SDLK_ESCAPE:
        exite=4;

        break;
        case SDLK_p:
            exite=1;
        break;

 case SDLK_UP:
     tempsactuel=SDL_GetTicks();

     if(sup==0)
           tempsjump=SDL_GetTicks();
     if(up>0 || sup>0)
     {
        SDL_EventState(SDL_KEYDOWN,SDL_DISABLE);

     }
  else
   if(tempsactuel-tempsprecedent<delaijump)
            sup=2;
      else
            sup=1;



         break;
  case SDLK_RIGHT:
      if(up==0 && sup==0)
      {
         tempsprecedent=SDL_GetTicks();
       if(tempsprecedent-tempsprerun>run)
       {
       	k++;
       	tempsprerun=SDL_GetTicks();
       }


              vu=0;
              rom=1;
              runn=1;
            posplayerrun.x=posplayer.x+=runvitesse;
            posshadowrun.x=posplayer.x-10;

            posplayerrun.y=posplayer.y+18;
            posshadowrun.y=posplayer.y+20;
       if(k>=6)
        k=1;
      }
      else
      {
      posplayer.x+=vitessex2-2;
      control=1;
      }



         break;
  case SDLK_LEFT:
      if(up==0 && sup==0)
      {
               tempsprecedent=SDL_GetTicks();
       if(tempsprecedent-tempsprerun>run)
       {
       	k++;
       	tempsprerun=SDL_GetTicks();
       }

              vu=1;
              rom=1;
              runn=1;
            posplayer.x-=runvitesse;
            posplayerrun.x=posplayer.x;
            posshadowrun.x=posplayer.x+10;
            posshadowrun.y=posplayer.y+20;
            posplayerrun.y=posplayer.y+18;
       if(k>=6)
        k=1;
      }
      else
      {
        posplayer.x-=vitessex2-2;
        control=1;
      }

         break;


  case SDLK_f:
      if(mana>costmana)
      {
            tempsprecedent=SDL_GetTicks();
       if(tempsprecedent-tempsprerun>dash)
       {
       	d++;
       	tempsprerun=SDL_GetTicks();
       }

              vu=0;
              rom=1;
                dashh=1;
            posplayer.x+=dashvitesse;
           posplayerrun.x=posplayer.x;
            posplayerrun.y=posplayer.y+18;
            mana-=costmana;
            manaa=0;
            timemana=SDL_GetTicks();
       if(d>=6)
        d=2;
        if(mana<1)
            mana=1;

      }
        break;
  case SDLK_d:
      if(mana>=costmana)
      {
             tempsprecedent=SDL_GetTicks();
       if(tempsprecedent-tempsprerun>dash)
       {
       	d++;
       	tempsprerun=SDL_GetTicks();
       }

              vu=1;
              rom=1;
              dashh=1;
            posplayer.x-=dashvitesse;
           posplayerrun.x=posplayer.x;
            posplayerrun.y=posplayer.y+18;
            mana-=costmana;
            timemana=SDL_GetTicks();
            manaa=0;
       if(d>=6)
        d=2;
        if(mana<1)
            mana=1;
        }
        break;
  case SDLK_e:
         tempsaim=SDL_GetTicks();
       if(tempsaim-tempsprerun>aimt)
       {

       	tempsprerun=SDL_GetTicks();
        	k++;
       f=1;

              bou=1;
            posplayerrun.y=posplayer.y+7;
            posshadowaim.y=sol+55;
            posshadowaim.x=posplayer.x-15;
            posplayerrun.x=posplayer.x-5;
            while(bou<5)
            {
                if(md[bou]==0)
                {
            posfire[bou].x=posplayer.x+19;
            posfire[bou].y=posplayer.y+20;
            md[bou]=1;
            timefire_up[bou]=SDL_GetTicks();
            firedroitmenu--;
            bou=5;
                }

                bou++;
            }
       if(k>=10)
        k=1;
       }
       vu=0;
        rom=1;
       aimm=1;
        if(sup>0 || up>0)
        {
         k=11;
         aimm=1;
         vu=0;
         rom=1;
        }



         break;

  case SDLK_w:

         tempsaim=SDL_GetTicks();
       if(tempsaim-tempsprerun>aimt)
       {
       	k++;
       	tempsprerun=SDL_GetTicks();

      f=1;


                bou=5;
            posplayerrun.y=posplayer.y+7;
            posplayerrun.x=posplayer.x-15;
            posshadowaim.y=sol+55;
            posshadowaim.x=posplayer.x-8;
            while(bou<9)
            {
                if(md[bou]==0)
                {
           posfire[bou].x=posplayer.x-40;
            posfire[bou].y=posplayer.y+20;
            md[bou]=1;
             timefire_up[bou]=SDL_GetTicks();
            firegauchemenu--;
            bou=9;
                }
                bou++;
            }
       if(k>=10)
        k=1;
       }
       vu=1;
       rom=1;
       aimm=2;
        if(sup>0 || up>0)
        {
         k=11;
         aimm=2;
         vu=1;
         rom=1;
        }


    break;
         case SDLK_q:
            if(tempsinitial-tempsattack>=delaiattack)
            {
                a++;
                tempsattack=SDL_GetTicks();
            }

            attackk=1;
            rom=1;
            if(a>8)
                a=1;

                break;

         default:

            break;


         }
       }

       //velkoz spawn
       if(vel==0)
       {
        timevel=SDL_GetTicks();
       	    if(timevel-tempsvel>=timevelsp)
            {
            vel=1;
            vievel=constvievel;
            tempsvel=SDL_GetTicks();
            posvelkoz.x=largeur-540;
           posvelkoz.y=sol-60;
            }
       }
       else{
            timevel=SDL_GetTicks();
            tempsvel=SDL_GetTicks();
       }

       //gravit
       if(up==1)
       {
            timejump1=SDL_GetTicks();
       	    if(timejump1-tempsjump>timegravitamax)
       	    {
       	        e=3;
       	  posplayer.y+=vitesseyn1;
       	    }
       	  if(timejump1-tempsjump<=timegravitamax)
       	  {
            posplayer.y+=vitesseyn2;
           e=4;
       	  }
              rom=1;
              posplayerjump.y=posplayer.y;
              if(posplayer.x<=60)
                {
                  posplayer.x=60;
                 }
             if(posplayer.x>=largeur-94)
               {
                posplayer.x=largeur-94;
               }


       }
       //fin gravité

       //gravité diago
       else if(up==2 )
       {
           timejump1=SDL_GetTicks();

       		if(vu==0)
       		{
       	    if(timejump1-tempsjump<timegravitamax)
       	    {
       	        e=3;
       	    if(control==0)
       	    	posplayer.x+=vitessex2;
       	  		posplayer.y+=vitessey2;
       	    }
       	    else
       	  if(timejump1-tempsjump>=timegravitamax)
       	  {
       	       e=4;
       	  if(control==0)
       	  	posplayer.x+=vitessex1;
            posplayer.y+=vitessey1;
          }
         }
         if(vu==1)
       		{
       	    if(timejump1-tempsjump<timegravitamax)
       	    {
       	        e=3;
       	        if(control==0)
       	    	posplayer.x-=vitessex2;
       	        posplayer.y+=vitessey2;
       	    }
       	    else
       	  if(timejump1-tempsjump>=timegravitamax)
       	  {
       	      e=4;
       	      if(control==0)
       	  	posplayer.x-=vitessex1;
            posplayer.y+=vitessey1;
          }
         }
              rom=1;
              posplayerjump.y=posplayer.y;
              if(posplayer.x<=60)
               {
                posplayer.x=60;
               }
             if(posplayer.x>=largeur-94)
               {
                posplayer.x=largeur-94;
               }


              }

       //fin de gravité diag

        if(posplayer.y>sol && plat==0 )
              {

               rom=0;
               up=0;
               sup=0;
               control=0;
               posplayerjump.y=posplayer.y=sol;
              }
              else
                if(posplayer.y>263 && plat==1)
              {

               rom=0;
               up=0;
               sup=0;
               control=0;
               posplayerjump.y=posplayer.y=263;

              }
              else
                 if(posplayer.y>188 && plat==2)
              {

               rom=0;
               up=0;
               sup=0;
               control=0;
               posplayerjump.y=posplayer.y=188;
              }
              else
              if(posplayer.y>151 && plat==3)
              {

               rom=0;
               up=0;
               sup=0;
               control=0;
               posplayerjump.y=posplayer.y=151;
              }
               else
              if(posplayer.y>180 && plat==4)
              {

               rom=0;
               up=0;
               sup=0;
               control=0;
               posplayerjump.y=posplayer.y=180;
              }
               else
              if(posplayer.y>171 && plat==5)
              {

               rom=0;
               up=0;
               sup=0;
               control=0;
               posplayerjump.y=posplayer.y=171;
              }



       //platforms
       if(sup==0)
       {//platform 1
       if(posplayer.y<=300 && sortir==0)
       {
        if(posplayer.x<440 && posplayer.x>=325)
       {
               plat=1;
            posplayerjump.y=posplayer.y;
            sortir=1;

       }
        else
        {
        plat=0;
       }
       }
       //platform 2
        if(posplayer.y<=209 && sortir==0)
       {
        if(posplayer.x<585 && posplayer.x>=445)
       {
               plat=2;
            posplayerjump.y=posplayer.y;
            sortir=1;

       }
       else
        {
        plat=0;
       }
       }
       //platform 3
        if(posplayer.y<=163 && sortir==0)
       {
        if(posplayer.x<786 && posplayer.x>=636)
       {
               plat=3;
            posplayerjump.y=posplayer.y;
            sortir=1;

       }
       else
        {
        plat=0;
       }
       }
       //platform 4
        if(posplayer.y<=192 && sortir==0)
       {
        if(posplayer.x<1147 && posplayer.x>=990)
       {
               plat=4;
            posplayerjump.y=posplayer.y;
            sortir=1;

       }
       else
        {
        plat=0;
       }
       }
       //platform 5
        if(posplayer.y<=181 && sortir==0)
       {
        if(posplayer.x<276 && posplayer.x>=126)
       {
               plat=5;
            posplayerjump.y=posplayer.y;
            sortir=1;

       }
       else
        {
        plat=0;
       }
       }
       sortir=0;
      if(posplayer.y>300)
       {
        plat=0;
       }

       //sortir de la platform sans sauter
       if(plat==0 && up==0 && posplayer.y<sol)
       {
           tempsjump=SDL_GetTicks();
          up=1;
       }
       }

     if(posplayer.y<sol || posplayer.y>sol )
        if (up==0 && sup==0 && plat==0)
           posplayer.y=sol;

       //jump
       if(sup==1)
       {
           timejump1=SDL_GetTicks();
            if(timejump1-tempsjump<=timejumpmax)
                { e=1;
                 posplayer.y-=vitesseyn1;
                }
              if(timejump1-tempsjump>timejumpmax )
              {   e=2;
               posplayer.y-=vitesseyn2;
              }

             rom=1;

             if(posplayer.x<=46)
              {
                 posplayer.x=46;
              }
        if(posplayer.x>=largeur-100)
              {
                 posplayer.x=largeur-100;
              }
            posplayerjump.y=posplayer.y;



       if(timejump1-tempsjump>=timejumpfinal)
       {
            SDL_Delay(delaijumptop);
           sup=0;
           up=1;
           tempsjump=SDL_GetTicks();
       }
    }
       //jump diag
          else  if(sup==2)
             { timejump1=SDL_GetTicks();
                if(timejump1-tempsjump<=timejumpmax && vu==0)
                {
                	e=1;
                 posplayer.y-=vitessey1;
                 if(control==0)
                 posplayer.x+=vitessex1;

              	}
              	else
              if(timejump1-tempsjump>timejumpmax && vu==0 )
              { e=2;
               posplayer.y-=vitessey2;
               if(control==0)
 				posplayer.x+=vitessex2;

               }
               else
           	if(timejump1-tempsjump<timejumpmax && vu==1)
                { e=1;
                 posplayer.y-=vitessey1;
                 if(control==0)
                 posplayer.x-=vitessex1;

              	}
              	else
              if(timejump1-tempsjump>timejumpmax && vu==1 )
              { e=2;
               posplayer.y-=vitessey2;
               if(control==0)
 				posplayer.x-=vitessex2;
 				}
             rom=1;
             if(posplayer.x<=60)
              {
                posplayer.x=60;
              }
             if(posplayer.x>=largeur-94)
              {
               posplayer.x=largeur-94;
              }
            posplayerjump.y=posplayer.y;

       if(timejump1-tempsjump>=timejumpfinal)
       {
           SDL_Delay(delaijumptop);
           sup=0;
           up=2;
           tempsjump=SDL_GetTicks();
       }
    }
    //mana
    if(manaa==1)
    {
        mana+=costmana;
        if(mana>=constmanaplayer)
        {
            mana=constmanaplayer;
            manaa=0;
        }
    }

    if(tempsinitial-timemana>delaimana_up)
    {
        manaa=1;
    }

       //fire droit speed
      for(bou=1;bou<5;bou++)
      {
           if(md[bou]==1)
           {
            tfire[bou]=SDL_GetTicks();
       if(tfire[bou]-tfire1[bou]>firetime)
       {
       	ff[bou]++;
       	tfire1[bou]=SDL_GetTicks();
       }
       if(tfire[bou]-tempfiremove[bou]>firemovetime)
       {
       	tempfiremove[bou]=SDL_GetTicks();
       	posfire[bou].x+=firevitesse;
       }

                if(ff[bou]>=8)
               ff[bou]=3;

            posshadowfire[bou].y=sol+xfireshadow;
            posshadowfire[bou].x=posfire[bou].x;
            //fire damage velkoz
        if(posfire[bou].x>=largeur-100 )
           md[bou]=2;
           if(posfire[bou].y>=posvelkoz1.y && posfire[bou].y<=posvelkoz1.y+111 )
           if(posfire[bou].x>=posvelkoz1.x && posfire[bou].x<=posvelkoz1.x+125)
           {
             md[bou]=2;
             vievel-=firedamage;
           }
           //fire damage ghost
           for(bou1=1;bou1<9;bou1++)
           {if(ghost[bou1]==1)
           if(posfire[bou].y>=posghost[bou1].y && posfire[bou].y<=posghost[bou1].y+30)
           if(posfire[bou].x>=posghost[bou1].x-44 && posfire[bou].x<=posghost[bou1].x)
           {
             md[bou]=2;
            vieghost[bou1]-=firedamage;
           }
           }
            //fire damage mage
           for(bou1=1;bou1<nombremage;bou1++)
           {if(mag[bou1]==1)
           if(posfire[bou].y>=posmage[bou1].y && posfire[bou].y<=posmage[bou1].y+130)
           if(posfire[bou].x>=posmage[bou1].x && posfire[bou].x<=posmage[bou1].x+100)
           {
             md[bou]=2;
            viemage[bou1]-=firedamage;
           }
           }


       }
       if(md[bou]==2)
       {
           if(tempsinitial-timefire_up[bou]>=delaifire_up)
           {
            md[bou]=0;
            firedroitmenu++;
           }
       }

      }
      if(firedroitmenu>5)
        firedroitmenu=5;
        if(firedroitmenu<1)
        firedroitmenu=1;


       //fire gauche speed
        for(bou=5;bou<9;bou++)
        {
           if(md[bou]==1)
           {
               tfire[bou]=SDL_GetTicks();
       if(tfire[bou]-tfire1[bou]>firetime)
       {
       	ff[bou]++;
       	tfire1[bou]=SDL_GetTicks();
       }

           if(tfire[bou]-tempfiremoveg[bou]>firemovetime)
       {
       	tempfiremoveg[bou]=SDL_GetTicks();
       	posfire[bou].x-=firevitesse;
       }

            if(ff[bou]>=8)
            ff[bou]=3;
            posshadowfire[bou].y=sol+xfireshadow;
            posshadowfire[bou].x=posfire[bou].x;

        if(posfire[bou].x<=50)
           md[bou]=2;
           //fire damage vel
           if(posfire[bou].y>=posvelkoz1.y && posfire[bou].y<=posvelkoz1.y+111)
           if(posfire[bou].x>=posvelkoz1.x && posfire[bou].x<=posvelkoz1.x+125)
           {
             md[bou]=2;
            vievel-=firedamage;
           }
           //fire damage ghost
           for(bou1=1;bou1<9;bou1++)
           {if(ghost[bou1]==1)
           if(posfire[bou].y>=posghost[bou1].y && posfire[bou].y<=posghost[bou1].y+30)
           if(posfire[bou].x>=posghost[bou1].x && posfire[bou].x<=posghost[bou1].x+44)
           {
             md[bou]=2;
            vieghost[bou1]-=firedamage;
           }
           }
          //fire damage mage
           for(bou1=1;bou1<nombremage;bou1++)
           {if(mag[bou1]==1)
           if(posfire[bou].y>=posmage[bou1].y && posfire[bou].y<=posmage[bou1].y+130)
           if(posfire[bou].x>=posmage[bou1].x && posfire[bou].x<=posmage[bou1].x+100)
           {
             md[bou]=2;
            viemage[bou1]-=firedamage;
           }
           }


       }
       if(md[bou]==2)
       {
           if(tempsinitial-timefire_up[bou]>=delaifire_up)
           {
            md[bou]=0;
            firegauchemenu++;
           }
       }
        }
         if(firegauchemenu>5)
        firegauchemenu=5;
        if(firegauchemenu<1)
        firegauchemenu=1;

        //fire mage  speed
        for(bou=1;bou<nombremage;bou++)
        {
           if(magef[bou]==3)
           {

               tfiremage[bou]=SDL_GetTicks();
       if(tfiremage[bou]-tfire1mage[bou]>firetimemage)
       {
       	ffmage[bou]++;
       	tfire1mage[bou]=SDL_GetTicks();
       }




   if(vufiremage[bou]==0)
    {
           if(tfiremage[bou]-tempfiremovegmage[bou]>firemovetime)
       {
       	tempfiremovegmage[bou]=SDL_GetTicks();
       	posfiremage[bou].x+=firevitesse;
       }
         if(posfiremage[bou].x>=largeur-100)
           magef[bou]=0;
           else
           if(posplayer.y<posfiremage[bou].y+10 && posplayer.y>posfiremage[bou].y-42)
            if(posplayer.x+20>posfiremage[bou].x && posplayer.x<posfiremage[bou].x+30 )
           {
                if(dashh==0)
                {
               vieplayer-=firedamage;
               magef[bou]=0;
                }
           }
    }
       else
   if(vufiremage[bou]==1)
    {
        vufiremage[bou]=1;
           if(tfiremage[bou]-tempfiremovegmage[bou]>firemovetime)
       {
       	tempfiremovegmage[bou]=SDL_GetTicks();
       	posfiremage[bou].x-=firevitesse;
       }

        if(posfiremage[bou].x<=50)
           magef[bou]=0;
           else
             if(posplayer.y<posfiremage[bou].y+10 && posplayer.y>posfiremage[bou].y-42)
            if(posplayer.x+20>posfiremage[bou].x && posplayer.x<posfiremage[bou].x+30 )
           {
               if(dashh==0)
               {
                 magef[bou]=0;
               vieplayer-=firedamage;
               }
           }
    }


       }

       if(ffmage[bou]>=8)
        ffmage[bou]=1;
        if(magef[bou]==1)
        {
        if(vumage[bou]==1)
        vufiremage[bou]=1;
       else if(vumage[bou]==0)
        vufiremage[bou]=0;
        magef[bou]=3;
        }
        }

     //velkoz animation standard
     tempsactuel=SDL_GetTicks();
     if(vel==1 )
       {

        if(tempsactuel-tempsvel1>stdvel)
       {
       	ve++;
       	tempsvel1=SDL_GetTicks();
       }

      // gauche


           posvelkoz1=posvelkoz;
           if (vuvel==1)
           {
           if(tempsactuel-tempvelmoveg>stdvelmove)
       {
          posvelkoz.x-=speedvel;
       	tempvelmoveg=SDL_GetTicks();
       }
           }

           //droit
           else if(vuvel==0)
           {

              if(tempsactuel-tempvelmove>stdvelmove)
       {
          posvelkoz.x+=speedvel;
       	tempvelmove=SDL_GetTicks();
       }
           }
           // IA velkoze  Right side in the map

           	if(posplayer.x+60<=posvelkoz.x )
       	{

       	 if(posvelkoz.x-posplayer.x<300 && posvelkoz.y-posplayer.y<100 && posvelkoz.x<=largeur-270 )
       	   vuvel=0;
       	   if(posvelkoz.x-posplayer.x<60 && vuvel==1)
            vuvel=1;
       	}

       	// IA velkoze  gauche side in the map
           else	if(posplayer.x>posvelkoz.x)
       	{

       	 if(posplayer.x-posvelkoz.x<460 && posvelkoz.y-posplayer.y<100 && posvelkoz.x>400 )
       	   vuvel=1;

       	}

           if(posvelkoz.x>=largeur-170)
               vuvel=1;

           if(posvelkoz.x<=55)
            vuvel=0;

           //vie

            posvie=posvelkoz1;
            posvie.y-=8;
             if(vuvel==0)
                posvie.x=posvelkoz1.x+30;



        if(ve==16)
            ve=1;
            if(vievel<=1)
            {
                vel=0;
                vievel=1;
                score+=scorevel;
            }
             //ghost spawn
             bou=1;
    do
    {
                 if(ghost[bou]==0)
        {
            tghostspawn[bou]=SDL_GetTicks();
       if(tghostspawn[bou]-tghostspawn1>ghosttimespawn)
       {
       	ghost[bou]=2;
       	exitspawnghost=1;
       	vughost[bou]=vuvel;
       	tghostspawn1=SDL_GetTicks();
       	posghost[bou].x=posvelkoz.x;
       	posghost[bou].y=sol+3+bou*2;
        // vie spawn
        vieghost[bou]=constvieghost;
         posghostvie[bou]=posghost[bou];
       	posghostvie[bou].y-=8;


       }
        }
       bou++;
    }while(bou!=9 && exitspawnghost!=1);

     //mage spawn
             bou=1;
    do
    {
                 if(mag[bou]==0)
        {
            tmagespawn[bou]=SDL_GetTicks();
       if(tmagespawn[bou]-tmagespawn1[bou]>magetimespawn)
       {
       	mag[bou]=1;
       	exitspawnmage=1;
       	vumage[bou]=vuvel;
       	tmagespawn1[bou]=SDL_GetTicks();
       	posmage[bou].x=posvelkoz.x;
       	posmage[bou].y=sol-58+bou*2;
        // vie spawn
        viemage[bou]=constviemage;
         posmagevie[bou]=posmage[bou];
       	posmagevie[bou].y-=8;


       }
        }
        else
        {
            tmagespawn1[bou]=SDL_GetTicks();
        }
       bou++;
    }while(bou!=nombremage && exitspawnmage!=1);
       }

      //Velkoz take damage
      if(vel==1 && attackk==1)
      {
       if(posattack.y>=posvelkoz1.y && posattack.y<=posvelkoz1.y+111)
                {
                    if(vu==0)
                    {
                if(posattack.x+75>=posvelkoz1.x && posattack.x+75<=posvelkoz1.x+125)
                if(a==1 || a==5)
                {
                    vievel-=attackdamage;
                    a++;
                }
                    }
                    else
                 if(vu==1)
                 {
                if(posattack.x>=posvelkoz1.x && posattack.x<=posvelkoz1.x+125)
                if(a==1 || a==5)
                {
                    vievel-=attackdamage;
                    a++;
                }
                 }
                }
                if(a>=9)
                    a=1;
      }
      //ghost take damage
      for(bou=1;bou<9;bou++)
      {
          if(ghost[bou]==1 )
          {
              if(posplayer.y>=posghost[bou].y-30)
                {
                    if(vu==0 && dashh==0)
                    {
                if(posplayer.x<=posghost[bou].x-10 && posplayer.x+80>=posghost[bou].x)
                {
                if(a==1 || a==7 || a==5)
                {    if(attackk==1)
                    {
                    vieghost[bou]-=attackdamage;
                    vieplayer+=ghostdamage;
                    a++;
                    }
                }
                //ghost damage player
                if(gg[bou]==1)
                {
                 vieplayer-=ghostdamage;
                 gg[bou]++;
                }
                }
                    }
                    else
                 if(vu==1 && dashh==0)
                 {
                if(posplayer.x+60>=posghost[bou].x+44 && posplayer.x-20<=posghost[bou].x+44)
                {
                if(a==1 || a==7 || a==5)
                {
                    if(attackk==1)
                    {
                    vieghost[bou]-=attackdamage;
                    vieplayer+=ghostdamage;
                    a++;
                    }

                }
                //ghost damage player
                if(gg[bou]==1)
                {
                 vieplayer-=ghostdamage;
                 gg[bou]++;
                }
                }
                 }
                 if(a>=9)
                    a=1;
                }


          }
          if(vieghost[bou]<=1)
            {
                ghost[bou]=3;
                vieghost[bou]=constvieghost;
                posghostdead[bou]=posghost[bou];
                score+=scoreghost;
            }

      }
   if(vieplayer>=constvieplayer)
    vieplayer=constvieplayer;

    // mage take damage
     for(bou=1;bou<nombremage;bou++)
      {
          if(mag[bou]==1 )
          {
              if(posplayer.y>=posmage[bou].y && posplayer.y<posmage[bou].y+130 )
                {
                    if(vu==0 && dashh==0 && attackk==1)
                    {
                if(posplayer.x>=posmage[bou].x-40 && posplayer.x<=posmage[bou].x+40)
                {
                if(a==1 || a==7 || a==5)
                {    if(attackk==1)
                    {
                    viemage[bou]-=attackdamage+1;
                    a++;
                    }
                }

                }
                    }
                    else
                 if(vu==1 && dashh==0 && attackk==1)
                 {
                if(posplayer.x<=posmage[bou].x+140 && posplayer.x>=posmage[bou].x+30)
                {
                if(a==1 || a==7 || a==5)
                {
                    if(attackk==1)
                    {
                    viemage[bou]-=attackdamage+1;
                    a++;
                    }

                }
                }
                 }
                 if(a>=9)
                    a=1;
                }
          }
          if(viemage[bou]<=1)
            {
                mag[bou]=0;
                viemage[bou]=constviemage;
                score+=scoremage;
            }

      }
    //mage speed
    for(bou=1;bou<nombremage;bou++)
    {
        if(mag[bou]==1)
        {
        tmage[bou]=SDL_GetTicks();
        if(tmage[bou]-tmage1[bou]>magetime)
       {
       	ggmage[bou]++;
       	if(mageattack[bou]==1)
       	ma[bou]++;
       	tmage1[bou]=SDL_GetTicks();
       }
       if(ggmage[bou]>=27)
       {
               ggmage[bou]=1;

       }
        if(ma[bou]>=20)
        {
            ma[bou]=1;
            mageattack[bou]=0;
        }
         if(ma[bou]==10)
         magef[bou]=1;



        //IA mage
      if(bou==1)
      {
          if(posmage[bou].x<largeur-160 &&mageattack[bou]<1)
          {
        posmage[bou].x+=2;
        vumage[bou]=0;
          }
        else
        if(posmage[bou].x>=largeur-160 && mageattack[bou]<1)
        {
            vumage[bou]=1;
        }

      }
      else
        if(bou==2)
      {
         if(vel==1)
         {
          if(posmage[bou].x<posvelkoz.x && mageattack[bou]<1)
          {
            posmage[bou].x+=2;
            vumage[bou]=0;
          }
          else
            if(posmage[bou].x>posvelkoz.x && mageattack[bou]<1)
          {
            posmage[bou].x-=2;
            vumage[bou]=1;
          }
      }
      else
        if(vel==0)
      {

          if(posmage[bou].x>20 && vumage[bou]==1 && mageattack[bou]<1)
          {
        posmage[bou].x-=2;
        vumage[bou]=1;
          }
        else
        if(posmage[bou].x<largeur-160 && mageattack[bou]<1)
        {
            posmage[bou].x+=2;
            vumage[bou]=0;

        }

      }
      }
       if(bou==3)
      {
          if(posmage[bou].x>20 && mageattack[bou]<1)
          {
        posmage[bou].x-=2;
        vumage[bou]=1;
          }
        else
        if(posmage[bou].x<=20 && mageattack[bou]<1)
        {
            vumage[bou]=0;
        }

      }
      //delai attack
      if(mageattack[bou]==-1)
      {
      tattackmag[bou]=SDL_GetTicks();
       if(tattackmag[bou]-tattackmag1[bou]>amagetime)
       {
       	mageattack[bou]=2;
       	tattackmag1[bou]=SDL_GetTicks();
       }
      }
      else
      {
        tattackmag[bou]=SDL_GetTicks();
        tattackmag1[bou]=SDL_GetTicks();
      }


      //attack

      if(mageattack[bou]==2)
      {
          posfiremage[bou]=posmage[bou];
           posfiremage[bou].y+=50;
           if(vumage[bou]==0)
            posfiremage[bou].x+=100;

      if(posplayer.y<280)
      {
        posmage[bou].y-=2;
        if(posplayer.x>posmage[bou].x)
        {
            vumage[bou]=0;
        }
        else
            vumage[bou]=1;
      }
        if(posplayer.y-30>=posmage[bou].y)
        {
            mageattack[bou]=1;
            ma[bou]=1;
        }
      }
        if(mageattack[bou]==0)
        {
            posmage[bou].y+=2;

        if(posmage[bou].y>=sol-58)
        {
         posmage[bou].y=sol-58+bou*2;
         mageattack[bou]=-1;
        }
        }

        }
    }
            //ghost speed
      for(bou=1;bou<9;bou++)
      {
           if(ghost[bou]==1)
           {
               posghostvie[bou]=posghost[bou];
       	posghostvie[bou].y-=8;
            tghost[bou]=SDL_GetTicks();
       if(tghost[bou]-tghost1[bou]>ghosttime)
       {
       	gg[bou]++;
       	tghost1[bou]=SDL_GetTicks();
       }
       //IA ghost
       if(tghost[bou]-tempghostmove[bou]>ghostmovetime)
       {
       	tempghostmove[bou]=SDL_GetTicks();
       	//loin droit
       	if(posplayer.x-40>posghost[bou].x)
       	{
            if(posplayer.x-posghost[bou].x<350 && posghost[bou].y-posplayer.y<160 )
       	   vughost[bou]=0;
           else
            if(iaghost[bou]<ghostial)
            {
            vughost[bou]=1;
            }
            else
            if(iaghost[bou]>=ghostial && iaghost[bou]<ghostialmax )
           {
            vughost[bou]=0;
           }

       	}
       	//loin gauche
       	if(posplayer.x+40<=posghost[bou].x)
       	{

       	 if(posghost[bou].x-posplayer.x<350 && posghost[bou].y-posplayer.y<160 )
       	   vughost[bou]=1;
           else
            if(iaghost[bou]<ghostial)
            {
            vughost[bou]=1;
            }
            else
            if(iaghost[bou]>=ghostial && iaghost[bou]<ghostialmax )
           {
            vughost[bou]=0;
           }
       	}




       	iaghost[bou]++;
       	if(iaghost[bou]==ghostialmax-1)
            iaghost[bou]=0;




       }
       if(posghost[bou].x<=55)
        vughost[bou]=0;
        else
        if(posghost[bou].x>=largeur-55)
        vughost[bou]=1;

           if(vughost[bou]==1)
            posghost[bou].x-=ghostvitesse;
        else if(vughost[bou]==0)
        posghost[bou].x+=ghostvitesse;

                if(gg[bou]>=3)
               gg[bou]=1;

      }
      //spawn ghost animation
      else if(ghost[bou]==2)
      {
          tghost[bou]=SDL_GetTicks();
       if(tghost[bou]-tghostspawns1[bou]>ghosttimespawns)
       {
       	ggs[bou]++;
       	tghostspawns1[bou]=SDL_GetTicks();
       }
       if(ggs[bou]>=12)
       {
           ggs[bou]=1;
           ghost[bou]=1;
       }


      }
      //ghost animation dead

      else if(ghost[bou]==3)
      {
          tghost[bou]=SDL_GetTicks();
       if(tghost[bou]-tghostdeads1[bou]>ghosttimespawns)
       {
       	ggd[bou]--;
       	tghostdeads1[bou]=SDL_GetTicks();
       }
       posghostdead[bou].y-=3;
       if(ggd[bou]<=1)
       {
           ggd[bou]=15;
           ghost[bou]=0;
       }


      }

      }
      //coin
        if(Co[Coi]==0)
        {
            tempscoin=SDL_GetTicks();
        if(tempscoin-tempscoin1>=delaicoin)
   {
       Co[Coi]=1;
        Coi++;
       tempscoin1=SDL_GetTicks();
   }
        }
        else
            if(Co[Coi]==1)
        {
            tempscoin=SDL_GetTicks();
            tempscoin1=SDL_GetTicks();

            tempscoin2=SDL_GetTicks();
        if(tempscoin2-tempscoin3>=delaicoinanim-accel)
   {
       W++;

       CC++;
       tempscoin3=SDL_GetTicks();
   }
   if(W>=2)
   {
    accel++;
    W=0;
   }

     if(accel>=100)
     {
         Co[Coi]=0;
         accel=0;
     }
     if(posplayer.y<poscoin[Coi].y+10 && posplayer.y>poscoin[Coi].y-42)
        if(posplayer.x+20>poscoin[Coi].x && posplayer.x<poscoin[Coi].x+30)
     {
         Co[Coi]=0;
         accel=0;
         W=0;
         score+=scorecoin;
     }
           if(CC>=8)
            CC=1;
        }
        if(Coi>=nombrecoin)
            Coi=1;



   //animation standard droit
    tempsactuel=SDL_GetTicks();
       if(rom==0 && vu==0 )
       {

        if(tempsactuel-tempsprerun>standa)
       {
       	j++;
       	tempsprerun=SDL_GetTicks();
       }
           posshadow.x=posplayer.x-10;
           posshadow.y=sol+55;
         k=1;
         d=1;

        if(j==13)
            j=1;
      }
      //animation standard gauche
       else
       if(rom==0 && vu==1)
       {

        if(tempsactuel-tempsprerun>standa)
       {
       	j++;
       	tempsprerun=SDL_GetTicks();
       }
        posshadow.x=posplayer.x-14;
           posshadow.y=sol+55;
       d=1;
       k=1;
        if(j==13)
            j=1;
       }
       //player en vie
       if(vieplayer<=0)
       {
           vieplayer=0;
           exite=5;
       }


   SDL_Delay(optifin);

   if(tempsinitial-tempsback>=delaiback)
   {
       i++;
       if(i>3)
        i=1;
       tempsback=SDL_GetTicks();
   }

   if(posplayer.x<=46)
   {
       posplayer.x=46;
   }
   if(posplayer.x>=largeur-100)
   {
       posplayer.x=largeur-100;
   }
    }





//affichage

    SDL_BlitSurface(backe[i],NULL,screen,&posback);
     //manaplayer
   SDL_BlitSurface(manaplayer_img[mana],NULL,screen,&posmanaplayer);
    //vieplayer
   SDL_BlitSurface(vieplayer_img[vieplayer],NULL,screen,&posvieplayer);
   //fire info

   SDL_BlitSurface(fireg_up[firegauchemenu],NULL,screen,&posfireg_up);
   SDL_BlitSurface(fire_up[firedroitmenu],NULL,screen,&posfire_up);


      //affiche velkoz
      if(vel==1)
      {
          if(vuvel==1)
     SDL_BlitSurface(velkozg[ve],NULL,screen,&posvelkoz);
     else if(vuvel==0)
        SDL_BlitSurface(velkoz[ve],NULL,screen,&posvelkoz);
     //vie velkoz
     if(vievel<1)
        vievel=1;
    SDL_BlitSurface(vie[vievel],NULL,screen,&posvie);
      }

    if(rom==0 && vu==1 && plat>=0)
    SDL_BlitSurface(playerg[j],NULL,screen,&posplayer);
    if(rom==0 && vu==0 && plat>=0 )
    SDL_BlitSurface(player[j],NULL,screen,&posplayer);
    if(runn==1 &&vu==0 && plat>=0)
    SDL_BlitSurface(playerrun[k],NULL,screen,&posplayerrun);
    if(runn==1 && vu==1 && plat>=0)
    SDL_BlitSurface(playerrung[k],NULL,screen,&posplayerrun);
    if(dashh==1 && vu==0)
    SDL_BlitSurface(playerdash[d],NULL,screen,&posplayerrun);
    if(dashh==1 && vu==1)
    SDL_BlitSurface(playerdashg[d],NULL,screen,&posplayerrun);
    // jump
    if(aimm==0 && attackk==0 && dashh==0)
    if(sup>0 || up>0 || plat==-1)
    {
    if(vu==0)
         {
             posplayerjump.x=posplayer.x;
       SDL_BlitSurface(playerjump[e],NULL,screen,&posplayerjump);

         }
       else if(vu==1)
       {
          posplayerjump.x=posplayer.x-12;
         SDL_BlitSurface(playerjumpg[e],NULL,screen,&posplayerjump);

       }
    }
    // affiche ghost
      for(bou=1;bou<9;bou++)
           {
           if(ghost[bou]==1)
           {
               if(vughost[bou]==1)
              SDL_BlitSurface(ghostg[gg[bou]],NULL,screen,&posghost[bou]);
              else if(vughost[bou]==0)
                SDL_BlitSurface(ghostd[gg[bou]],NULL,screen,&posghost[bou]);
                // vie ghost

               SDL_BlitSurface(viemob[vieghost[bou]*7],NULL,screen,&posghostvie[bou]);
           }
           //spawn ghost
           else if (ghost[bou]==2)
           {     if(vughost[bou]==1)
               SDL_BlitSurface(ghostspawng[ggs[bou]],NULL,screen,&posghost[bou]);
               else if(vughost[bou]==0)
                 SDL_BlitSurface(ghostspawn[ggs[bou]],NULL,screen,&posghost[bou]);
           } //dead ghost
            else if (ghost[bou]==3)
           {     if(vughost[bou]==1)
              {

               SDL_BlitSurface(ghostdeadg[ggd[bou]],NULL,screen,&posghostdead[bou]);
              }
               else if(vughost[bou]==0)
               {

                 SDL_BlitSurface(ghostdead[ggd[bou]],NULL,screen,&posghostdead[bou]);
               }
           }
       }
    //attack droit
    if(attackk==1 && vu==0)
    {
        posattack.x=posplayer.x-10;
        if(a==1)
        {
            posattack.y=posplayer.y+2;
        }
       else
        posattack.y=posplayer.y+10;
    SDL_BlitSurface(attack[a],NULL,screen,&posattack);
    }
    //attack gauche
    if(attackk==1 && vu==1)
    {
        posattack.x=posplayer.x-48;
        if(a==1)
        {
            posattack.y=posplayer.y+2;
        }
       else
        posattack.y=posplayer.y+10;
    SDL_BlitSurface(attackg[a],NULL,screen,&posattack);
    }
    //aim

    if( aimm==1 && vu==0 && runn==0 && dashh==0)
    {
        posplayerrun.y=posplayer.y+7;
        posplayerrun.x=posplayer.x-5;
    SDL_BlitSurface(aim[k],NULL,screen,&posplayerrun);
    }
    //aim
     if(aimm==2 && vu==1 && runn==0 && dashh==0)
     {
         posplayerrun.y=posplayer.y+7;
         posplayerrun.x=posplayer.x-5;
    SDL_BlitSurface(aimg[k],NULL,screen,&posplayerrun);
     }

  //affichage droit fire
           for(bou=1;bou<5;bou++)
           {
           if(md[bou]==1)
           {
    SDL_BlitSurface(fire[ff[bou]],NULL,screen,&posfire[bou]);
    SDL_BlitSurface(shadow[i],NULL,screen,&posshadowfire[bou]);
           }
       }

       //affichage gauche fire
      for(bou=5;bou<9;bou++)
      {
       if(md[bou]==1)
           {
    SDL_BlitSurface(fireg[ff[bou]],NULL,screen,&posfire[bou]);
    SDL_BlitSurface(shadow[i],NULL,screen,&posshadowfire[bou]);

           }
      }

    //affiche mage
      for(bou=1;bou<nombremage;bou++)
           {
           if(mag[bou]==1 && mageattack[bou]!=1)
           {
               if(vumage[bou]==1)
              SDL_BlitSurface(magieg[ggmage[bou]],NULL,screen,&posmage[bou]);
              else if(vumage[bou]==0)
                SDL_BlitSurface(magie[ggmage[bou]],NULL,screen,&posmage[bou]);

           }
           if(mageattack[bou]==1 && mag[bou]==1)
           {
               if(vumage[bou]==1)
              SDL_BlitSurface(magieattackg[ma[bou]],NULL,screen,&posmage[bou]);
              else if(vumage[bou]==0)
                SDL_BlitSurface(magieattack[ma[bou]],NULL,screen,&posmage[bou]);

           }
           //affiche vie mage
           if(mag[bou]==1)
          {
                posmagevie[bou]=posmage[bou];
                posmagevie[bou].x+=50;
                posmagevie[bou].y+=20;
            SDL_BlitSurface(viemob[viemage[bou]],NULL,screen,&posmagevie[bou]);
           }

           }

           //affichage mage fire
      for(bou=1;bou<nombremage;bou++)
      {
       if(magef[bou]==3)
           {if(vufiremage[bou]==0)
    SDL_BlitSurface(firemage[ffmage[bou]],NULL,screen,&posfiremage[bou]);
    else
    if(vufiremage[bou]==1)
    SDL_BlitSurface(firemageg[ffmage[bou]],NULL,screen,&posfiremage[bou]);

           }
      }

      if(plat<=0)
      {
      //shadow standard
    if( rom==0)
    SDL_BlitSurface(shadow[i],NULL,screen,&posshadow);
    if(aimm==1 || aimm==2 )
    {
    SDL_BlitSurface(shadowaim[i],NULL,screen,&posshadowaim);
    }
    if(runn==1)
    SDL_BlitSurface(shadowrun,NULL,screen,&posshadowrun);
    //shadoww attack droit
    if(attackk==1 && vu==0)
    {
         posshadowrun.x=posplayer.x+10;
            posshadowrun.y=sol+20;
    SDL_BlitSurface(shadowrun,NULL,screen,&posshadowrun);
    }
    //shadow attack gauche
    if(attackk==1 && vu==1)
    {
         posshadowrun.x=posplayer.x-10;
            posshadowrun.y=sol+20;
    SDL_BlitSurface(shadowrun,NULL,screen,&posshadowrun);
    }
    //shadow jump
    if(sup>0 || up>0)
    {
         posshadow.x=posplayer.x;
             posshadow.y=sol+20;
     SDL_BlitSurface(shadowrun,NULL,screen,&posshadow);
    }
      }
    // affiche pause
    if(exite==4)
         SDL_BlitSurface(pause[pausee],NULL,screen,&posback);
    //affiche score
         sprintf(ok," Score : %d",score);
   sscore=TTF_RenderText_Shaded(police,ok,blanc,noir);
   SDL_BlitSurface(sscore,NULL,screen,&posscore);
   //affiche coin
   if(Co[Coi]==1)
    SDL_BlitSurface(coin[CC],NULL,screen,&poscoin[Coi]);

    SDL_Flip(screen);



   }
   }

    SDL_Quit();
    TTF_Quit();
   return EXIT_SUCCESS;

}

