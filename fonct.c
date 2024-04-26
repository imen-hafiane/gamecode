#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_ttf.h>
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
        ecran = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);//mode normal
    }
    else
    {
        SDL_Flip(ecran);
        ecran = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_FULLSCREEN);//mode fullscren
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
imge->ur1="level1.png";
imge->img=IMG_Load(imge->ur1);
if(imge->img==NULL)
{
  printf("unable to load background image %s \n",SDL_GetError());
  return ;
}
imge->posecran.x=-30;
imge->posecran.y=80;
imge->pos_img_affiche.x=0;
imge->pos_img_affiche.y=0;
imge->pos_img_affiche.h=SCREEN_H;
imge->pos_img_affiche.w=SCREEN_W;
}

void initialiser_life3(life *imge)
{
imge->image=IMG_Load("life.png");
imge->posecran.x=1000;
imge->posecran.y=50;
imge->posecran.w=imge->image->w;
imge->posecran.h=imge->image->h;
}

void initialiser_life2(life *imge)
{
imge->image=IMG_Load("life.png");
imge->posecran.x=900;
imge->posecran.y=50;
imge->posecran.w=imge->image->w;
imge->posecran.h=imge->image->h;

}
void initialiser_life1(life *imge)
{
imge->image=IMG_Load("life.png");
imge->posecran.x=800;
imge->posecran.y=50;
imge->posecran.w=imge->image->w;
imge->posecran.h=imge->image->h;

}

void afficher_life(SDL_Surface *ecran,life imge)
{
SDL_BlitSurface(imge.image, NULL, ecran, &imge.posecran);
}

void afficher_image(SDL_Surface *ecran,image imge)
{
SDL_BlitSurface(imge.img,&imge.pos_img_affiche,ecran,&imge.posecran);
}


void liberer_image(image imge)
{
SDL_FreeSurface(imge.img);
}


void liberer_life(life imge)
{
SDL_FreeSurface(imge.image);
}

void initialiseEntity(perso *p)
{
	p->sprite=IMG_Load("sheet.png");

	p->direction=3; 

	p->possprite.x=0;
	p->possprite.y=426;
	p->possprite.w=100 ; 
	p->possprite.h=213; 

	p->posecran.x=70;
	p->posecran.y=350;
	p->posecran.w=1200;
	p->posecran.h=730;

	p->acceleration=0;
	p->vitesse=0,5;
	p->vitesseV=0;
	p->vie=3;
	p->score=0;
	p->up=0;

}

void initialiseEntity2(perso *p)
{
	p->sprite=IMG_Load("sheet2.png");

	p->posecran.x=40;
	p->posecran.y=350;
	p->posecran.w=1200;
	p->posecran.h=730;

	p->direction=3;
	p->acceleration=0;
	p->vitesse=0.5;
        p->vitesseV=0;
	p->vie=5;
	p->score=0;
	p->up=0;

	

	p->possprite.x=0;
	p->possprite.y=434;
	p->possprite.w=98,66;
	p->possprite.h=217; 
}

void animateEntity2(perso *p)
{
if (p->possprite.x>=480) 
{
	p->possprite.x =0; 
	p->possprite.y =(p->direction-1) * 217; 
}
else 
{
	p->possprite.x +=98,67;  
}

}

void animateEntity(perso *p)
{
if (p->possprite.x>=500)
{
	p->possprite.x  =0; 
	p->possprite.y =(p->direction-1) * 213; 
}
else 
{
	p->possprite.x +=100;  
}

}

void blitEntity(perso *p, SDL_Surface *ecran)
{
SDL_BlitSurface(p->sprite,&p->possprite,ecran,&p->posecran);
}


void movePerso (perso *p,Uint32 dt)
{
double dx;
if(p->acceleration!=0)
{
	dx = 0.5 * p->acceleration * dt *dt + p->vitesse * dt ;  

	if (p->posecran.x> 1040) 
		p->direction=2;
	if (p->posecran.x<70)
		p->direction=1;
	if (p->direction==1 || p->direction==3 )
                p->posecran.x+=dx;
	if (p->direction==2 || p->direction==4 )
                p->posecran.x-=dx;
     
}
}


void saut_Personnage(perso *p, Uint32 dt, int posx_absolu, int posy_absolu)
{

if(p->up==1|| p->up==2)
{
   p->vitesse=1;	
   if(p->up==1)
	{
	if(posy_absolu-190 <= p->posecran.y-((p->vitesse)*dt))
     		p->posecran.y-= (p->vitesse)*dt;
	else
		p->posecran.y=posy_absolu-190;
	}
   else if(p->up==2)
	{
	if(posy_absolu >= p->posecran.y+((p->vitesse)*dt))
    		 p->posecran.y+= (p->vitesse)*dt;
	else
		 p->posecran.y=posy_absolu;       
	}

   if(p->posecran.y<=(posy_absolu-190) && p->up==1)
        p->up=2;
   if(p->posecran.y>=posy_absolu && p->up==2)
        p->up=0;
}

		if(p->up==3)
		{
			p->posRelative.x+=10;
			p->posRelative.y= (-0.04) * p->posRelative.x * p->posRelative.x+100;
		       	p->posecran.x=p->px + p->posRelative.x+50;
	       		p->posecran.y=p->py - p->posRelative.y;
		}
		if(p->up==4)
		{
			p->posRelative.x+=10;
			p->posRelative.y= (-0.04) * p->posRelative.x * p->posRelative.x+100;
		       	p->posecran.x=p->px - p->posRelative.x-50;
	       		p->posecran.y=p->py - p->posRelative.y;
		}
}   



void liberer(perso p, SDL_Surface * ecran)
{
SDL_FreeSurface(p.sprite);
}




