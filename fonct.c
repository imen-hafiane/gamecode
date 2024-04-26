#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_ttf.h>
#include<math.h>
#include "fonction.h"



void setMusicVolume(int volume)
{
    Mix_VolumeMusic(volume);
}

void initialiser_audio(Mix_Music *music)
{
if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
   printf("%s",SDL_GetError());
}
music=Mix_LoadMUS("music.mp3");
Mix_PlayMusic(music,-1);
Mix_VolumeMusic(30);
}



void SaveScreenMode(SDL_Surface *ecran, int *Mode)
{
    if (*Mode == 0)
    {
        SDL_Flip(ecran);
        ecran = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    }
    else
    {
        SDL_Flip(ecran);
        ecran = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_FULLSCREEN);
    }
    
}

void SetFull(SDL_Surface *ecran, int *Mode)
{
    *Mode = 1;
    ecran = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_FULLSCREEN);
}

void SetNorm(SDL_Surface *ecran, int *Mode)
{
    *Mode = 0;
    ecran = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
}




void initialiser_imageBACK(image *imge)
{
imge->ur1="masque.png";
imge->img=IMG_Load(imge->ur1);
if(imge->img==NULL)
{
  printf("unable to load background image %s \n",SDL_GetError());
  return ;
}
imge->pos_img_ecran.x=-55;
imge->pos_img_ecran.y=80;
imge->pos_img_affiche.x=0;
imge->pos_img_affiche.y=0;
imge->pos_img_affiche.h=SCREEN_H;
imge->pos_img_affiche.w=SCREEN_W;
}

void afficher_imageBMP(SDL_Surface *screen,image imge)
{
SDL_BlitSurface(imge.img,&imge.pos_img_affiche,screen,&imge.pos_img_ecran);
}

void liberer_image(image imge)
{
SDL_FreeSurface(imge.img);
}


void initEntity(Entity *e)
{
	e->Entity=IMG_Load("robot3.png");
	e->rect.x=600;
	e->rect.y=350;
	e->rect.w=1000;
	e->rect.h=500;
	e->posSprite.x=0;
	e->posSprite.y=0;
	e->posSprite.w=93.4;
	e->posSprite.h=210;
	e->direction_x=0;
	e->direction_y=0;

}

void afficherEnnemi(Entity *e, SDL_Surface *screen)
{
     SDL_BlitSurface(e->Entity,&e->posSprite,screen,&e->rect);
}

void animerEntity(Entity *e)
{

	e->posSprite.x +=93.4;
	if( e->posSprite.x > 560)
	{
	
		e->posSprite.x =0; 
		e->posSprite.y =(e->direction_y)*210;
	}	
	else    
		e->posSprite.x = e->posSprite.x + e->posSprite.w;
}

void move(Entity *e) 
{

if(e->direction_y==0)
    if (e->rect.y >=350)
       e->direction_y =1;
     else 
       e->rect.y +=1;

if (e->direction_y ==1)
    if (e->rect.y <=150)
       e->direction_y =0;
     else 
       e->rect.y -=1;


if (e->direction_x ==2)
    if (e->rect.x <=600)
       e->direction_x =0;
     else 
       e->rect.x -=1;
}


void initEntity2(Entity *e)
{
	e->Entity=IMG_Load("robot3.png");
	e->rect.x=200;
	e->rect.y=350;
	e->rect.w=1000;
	e->rect.h=500;
	e->posSprite.x=0;
	e->posSprite.y=0;
	e->posSprite.w=93.4;
	e->posSprite.h=210;
	e->direction_x=0;
	e->direction_y=0;
}


void move2(Entity *e2) 
{
if(e2->direction_y==0)
    if (e2->rect.y >=350)
       e2->direction_y =1;
     else 
       e2->rect.y +=2;

if (e2->direction_y ==1)
    if (e2->rect.y <=150)
       e2->direction_y =0;
     else 
       e2->rect.y -=2;
}




void initPerso(perso *p)
{
	p->spritesheet=IMG_Load("perso.png");
	p->poshero.x=35;
	p->poshero.y=350;
	p->poshero.h=180;
	p->poshero.w=98.67;
	p->posSprite.x=0;
	p->posSprite.y=440;
	p->posSprite.w=98.67;
	p->posSprite.h=180;
	p->position_tri.centre.x=p->poshero.x+p->poshero.w/2;
	p->position_tri.centre.y=p->poshero.y+p->poshero.h/2;
	p->position_tri.rayon=sqrt((p->poshero.w/2)*(p->poshero.w/2)+(p->poshero.h/2)*(p->poshero.h/2));
}

void afficherPerso(perso p, SDL_Surface * screen)
{
	SDL_BlitSurface(p.spritesheet,&p.posSprite,screen,&p.poshero);
}


void moveIA(Entity *e, perso pos_hero)
{
	if(e->rect.x>pos_hero.poshero.x)
	{
		e->rect.x-=2;
	}
	else
	{
		e->rect.x+=2;
	}
	if(e->rect.y>pos_hero.poshero.y)
	{
		e->rect.y-=2;
	}
	else
	{
		e->rect.y+=2;
	}
}
/*void moveIA(Entity *e)
{
    // Suppose que la position du héros est accessible depuis e->pos_hero
    if (e->rect.x > e->pos_hero.poshero.x)
    {
        e->rect.x -= 2;
    }
    else
    {
        e->rect.x += 2;
    }
    if (e->rect.y > e->pos_hero.poshero.y)
    {
        e->rect.y -= 2;
    }
    else
    {
        e->rect.y += 2;
    }
}*/



		



int collisionBB(SDL_Rect posp, SDL_Rect pose)
{
   int collision=0;
 
  if ((posp.x>=pose.x)&&(posp.y>=pose.y)&&(posp.x<=pose.x+pose.w)&&(posp.y<=pose.y+pose.h)) 
  {
    collision = 1;
  } 
  return collision;
}


void initialiseBonus(Bonus *b)
{

	b->collected=1;
	b->img=IMG_Load("coin.png");
	b->rect.x=300;
	b->rect.y=330;
	b->rect_aff.w=204;
	b->rect_aff.h=204;
	b->position_tri.centre.x=b->rect.x+b->rect_aff.w/2;
	b->position_tri.centre.y=b->rect.y+b->rect_aff.h/2;
	b->position_tri.rayon=102;

}

void affichBonus(Bonus *b, SDL_Surface *screen)
{

     SDL_BlitSurface(b->img,&b->rect_aff,screen,&b->rect);
}


int collisionTri(perso *p,Bonus *b)
{
	p->position_tri.centre.x=p->poshero.x+p->poshero.w/2;
	p->position_tri.centre.y=p->poshero.y+p->poshero.h/2;

	int r=b->position_tri.rayon+p->position_tri.rayon;
	int d=sqrt(((p->position_tri.centre.x-b->position_tri.centre.x)*(p->position_tri.centre.x-b->position_tri.centre.x))+((p->position_tri.centre.y-b->position_tri.centre.y)*(p->position_tri.centre.y-b->position_tri.centre.y)));
	if(r>d)
	{
		return 1;
	}
	return 0;
}





