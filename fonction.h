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


  SDL_Rect centre; 
  int rayon;

}tri;

 typedef struct
{
  char *ur1;
  SDL_Rect pos_img_affiche;
  SDL_Rect pos_img_ecran;
  SDL_Surface *img;
}image;


void initialiser_imageBACK(image *imge);
void afficher_imageBMP(SDL_Surface *screen,image imge);
void liberer_image(image imge);

typedef struct 
{

  SDL_Surface *Entity;
  SDL_Rect rect; 
  SDL_Rect posSprite;
  int direction_x,direction_y;

}Entity;


typedef struct perso
{
  SDL_Surface *spritesheet;
  SDL_Rect poshero;
  SDL_Rect posSprite;
  int direction;
  int nbVie ;

tri position_tri;
}perso;



typedef struct 
{
  SDL_Surface *img;
 SDL_Rect rect;
SDL_Rect rect_aff;
tri position_tri;
int collected;
}Bonus;


void initEntity(Entity *e);
void afficherEnnemi(Entity *e, SDL_Surface *screen);
void initialiseBonus(Bonus *b);
void animerEntity(Entity *e);
void move(Entity *e);


void initEntity2(Entity *e);
void move2(Entity *e2);


void initPerso(perso *p);
void afficherPerso(perso p, SDL_Surface * screen);
void moveIA(Entity *e , perso pos_hero);

int collisionBB(SDL_Rect posp, SDL_Rect pose);
int collisionTri(perso *p,Bonus *b);


void affichBonus(Bonus *e, SDL_Surface *screen);








#endif
