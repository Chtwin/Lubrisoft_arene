#ifndef DEF_CONSTANTES
#define DEF_CONSTANTES

#define COULEUR 32
#define CASE   10
#define TAILLE_BLOC         10
#define LARGEUR_FENETRE     1280
#define HAUTEUR_FENETRE     900
#define NB_BLOCS_LARGEUR    LARGEUR_FENETRE / TAILLE_BLOC
#define NB_BLOCS_HAUTEUR    HAUTEUR_FENETRE/ TAILLE_BLOC
#define MINY    TAILLE_BLOC*2 + 5
#define MINX    TAILLE_BLOC + 5
#define MAXY    NB_BLOCS_HAUTEUR - TAILLE_BLOC - 4
#define MAXX    NB_BLOCS_LARGEUR - TAILLE_BLOC - 8
#define VOLUME  0 //15
#define BLUE_BONUS  5
#define RED_BONUS   20
#define ECART 33
#define DEGAT_EPEE 5
#define RECUP_RUBIS 3
#define CENTRE_CERCLE_X  (LARGEUR_FENETRE/2 -50) / TAILLE_BLOC
#define CENTRE_CERCLE_Y  (HAUTEUR_FENETRE/2) / TAILLE_BLOC
#define DEGAT_BOMBE 75
#define RECUP_DEGAT_BOMBE 25
#define RAYON_BOMBE 10
#ifndef TOURNOIS
#define NB_PLAYER 2 // modifiez la quantité de joueur à votre guise
#define IAS {ia_1, ia_2}
#endif

typedef int (*ia_ptr)(int maps_ia[][NB_BLOCS_HAUTEUR], int, int, int, int, int);

/*
    Ajout de la structure propre à chaque IA
*/
typedef struct Player Player;
struct Player
{
    int x;
    int y;
    int points;
    int item;
    bool bouclier;       // Est ce que l'IA pare les coups.
    int orientation;    // Direction dans laquelle regarde l'IA.
    int anim;           // Boucle qui servira pour les animations.
    int classement;
};

/*
    Ajout de la structure propre à chaque bombe
*/
typedef struct Item Item;
struct Item
{
    int x;
    int y;
    int tours;
    int joueur;
    int anim;
    bool active;
};

enum {UP, DOWN, LEFT, RIGHT,ANIM_UP1,ANIM_UP2,ANIM_UP3,ANIM_DOWN1,ANIM_DOWN2,ANIM_DOWN3,ANIM_LEFT1,ANIM_LEFT2,ANIM_LEFT3,ANIM_RIGHT1,ANIM_RIGHT2,ANIM_RIGHT3, HIT_UP, HIT_DOWN, HIT_LEFT, HIT_RIGHT, SHIELD};
enum {HAUT, BAS, GAUCHE, DROITE, EPEE_HAUT,EPEE_BAS,EPEE_DROITE,EPEE_GAUCHE, PARER,BOMBE};  /// Différentes actions que peuvent faire les IA's
enum{GREEN_RUPEE,BLUE_RUPEE,RED_RUPEE,VIDE,MUR,IA,GANON,POT,BOMBE_MAP,BOMBE_DEFLAG};    /// Différents éléments trouvables dans le tableau en argument.

int play (SDL_Surface* screen);
void init_map(int maps[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR]);
void setup_ia(int maps[][NB_BLOCS_HAUTEUR], Player **links);
void setup_map (int maps[][NB_BLOCS_HAUTEUR], Item *p_box);
void setup_medias (SDL_Surface *link[21],SDL_Surface *rupees[3],SDL_Surface *ganon[5], SDL_Surface *zelda[6], SDL_Surface *guard[16], SDL_Surface *skull[4],SDL_Surface *daruina[4],SDL_Surface *granma[4],SDL_Surface *koume[4],SDL_Surface *maple [4],SDL_Surface *oldman[4],SDL_Surface *nayru[4],SDL_Surface *saria[4],SDL_Surface *sheik[4], SDL_Surface *ruto[4], SDL_Surface *rauru[4],SDL_Surface *bombes[10],SDL_Surface **box, SDL_Surface **background, SDL_Surface **scoreboard, TTF_Font **police, TTF_Font **police2,Mix_Chunk **s_ruppes, Mix_Chunk **s_sword, Mix_Chunk **s_degat,Mix_Music **gerudo);
void timer (char temps[],char score[],int points,int tours, SDL_Surface *screen, TTF_Font *police, SDL_Color couleurNoire);
int movePlayer (int maps[][NB_BLOCS_HAUTEUR], SDL_Rect *position, int direction, Mix_Chunk *s_ruppes, Item *p_box);
void ganon_move(int maps[][NB_BLOCS_HAUTEUR], Mix_Chunk *s_degat, Player links[], SDL_Rect *position, int tours);
void animation(SDL_Surface* screen, SDL_Surface *zelda[6], SDL_Surface *skull[4],SDL_Surface *daruina[4],SDL_Surface *granma[4],SDL_Surface *koume[4],SDL_Surface *maple [4],SDL_Surface *oldman[4],SDL_Surface *nayru[4],SDL_Surface *saria[4],SDL_Surface *sheik[4], SDL_Surface *ruto[4], SDL_Surface *rauru[4], int tours);
void garde(SDL_Surface* screen, SDL_Surface *guard[16], int tours);
void damage(int maps[][NB_BLOCS_HAUTEUR], Player links[], int playernow);
int test_ia(int maps[][NB_BLOCS_HAUTEUR], int x, int y, int points, int item);
void item(int maps[][NB_BLOCS_HAUTEUR], Player links[], int tours, Item bombes [100]);
void blit_items(int maps[][NB_BLOCS_HAUTEUR], SDL_Surface* screen, SDL_Surface* rupees[3], SDL_Surface *bombes[10],SDL_Surface *box, Item *p_box);
bool test_class(int maps[][NB_BLOCS_HAUTEUR], Player links[]);
int win (bool survivant, SDL_Surface* screen, Mix_Music *gerudo, Player links[], int continuer, int tours);

void SDL_Delay(Uint32 ms);
Uint32 SDL_GetTicks(void);
int Mix_OpenAudio(int frequency, Uint16 format, int channels, int chunksize);
int Mix_PlayMusic(Mix_Music *music, int loops);

#ifndef TOURNOIS
/*
Fonction qui renvoie un entier pour faire bouger l'IA
 */

int ia_1(int maps_ia[][NB_BLOCS_HAUTEUR], int x, int y, int points, int item, int tours)
{
    if (rand()%25 == 0)
    {
        return  4 + rand()%4;
    }
    return  0 + rand()%4;
}

int ia_2(int maps_ia[][NB_BLOCS_HAUTEUR], int x, int y, int points, int item, int tours)
{
    if (rand()%25 == 0)
    {
        return  4 + rand()%4;
    }
    return  0 + rand()%4;
}
#endif

#endif
