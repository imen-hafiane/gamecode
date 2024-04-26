#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_H 730
#define SCREEN_W 1200


void SetFull(SDL_Surface *ecran, int *Mode);
void SetNorm(SDL_Surface *ecran, int *Mode);
void SaveScreenMode(SDL_Surface *ecran, int *Mode);

void setMusicVolume(int volume);
void initialiser_audio(Mix_Music *music);



typedef struct
{
  char *ur1;
  SDL_Rect pos_img_affiche;
  SDL_Rect posecran;
  SDL_Surface *img;
}image;

typedef struct
{
SDL_Surface *image;
SDL_Rect posecran;

}life;

typedef struct 
{
SDL_Surface *sprite;
SDL_Rect posecran;  
SDL_Rect possprite;
SDL_Rect posRelative;
int direction; 
int vie,score;
double vitesse,acceleration,vitesseV;  
int pas,px,py,up;
Uint32 dt; 
}perso;



void initialiseEntity(perso *p);
void initialiseEntity2(perso *p);	
void blitEntity(perso *p, SDL_Surface *ecran);
void animateEntity(perso *p);
void animateEntity2(perso *p);
void movePerso (perso *p,Uint32 dt);	
void saut_Personnage(perso *p,Uint32 dt,int posx_absolu, int posy_absolu);	
void liberer(perso p, SDL_Surface * ecran);


void initialiser_imageBACK(image *imge);
void afficher_image(SDL_Surface *ecran,image imge);
void liberer_image(image imge);

void initialiser_life3(life *imge);
void initialiser_life2(life *imge);
void initialiser_life1(life *imge);
void afficher_life(SDL_Surface *ecran,life imge);
void liberer_life(life imge);


#endif
