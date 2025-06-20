#ifndef GLOBAL_INIT_H
#define GLOBAL_INIT_H

//******************************************************************************
//am_map.c
//******************************************************************************

_g->scale_mtof = (fixed_t)INITSCALEMTOF;
_g->stopped = true;

_g->lastlevel = -1;
_g->lastepisode = -1;

_g->mtof_zoommul = FRACUNIT; // how far the window zooms each tic (map coords)
_g->ftom_zoommul  = FRACUNIT; // how far the window zooms each tic (fb coords)



//******************************************************************************
//d_main.c
//******************************************************************************

_g->wipegamestate = GS_DEMOSCREEN;
_g->oldgamestate = -1;


//******************************************************************************
//doomstat.c
//******************************************************************************

// Game Mode - identify IWAD as shareware, retail etc.
_g->gamemode = indetermined;
_g->gamemission = doom;

_g->cheat_buffer[0] = 0;

//******************************************************************************
//m_menu.c
//******************************************************************************

_g->showMessages = 1;    // Show messages has default, 0 = off, 1 = on


//******************************************************************************
//p_setup.c
//******************************************************************************


_g->rejectlump = -1;// cph - store reject lump num if cached


//******************************************************************************
//r_main.c
//******************************************************************************

_g->validcount = 1;         // increment every time a check is made


_g->freehead = &_g->freetail;     // killough


//******************************************************************************
//s_sounds.c
//******************************************************************************

_g->snd_SfxVolume = 15;

// Maximum volume of music. Useless so far.
_g->snd_MusicVolume = 8;


//******************************************************************************
//st_stuff.c
//******************************************************************************

_g->st_oldhealth = -1;

_g->alwaysRun = 1;



#endif // GLOBAL_INIT_H
