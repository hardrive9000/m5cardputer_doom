#ifndef DOOMTYPES_H
#define DOOMTYPES_H

#include <stdint.h>
#include <stddef.h>
#include <limits.h>

typedef int32_t fixed_t;
typedef uint32_t angle_t;


#define FRACBITS 16
#define FRACUNIT (1<<FRACBITS)

inline static int D_abs(fixed_t x)
{
  fixed_t _t = (x),_s;
  _s = _t >> (8*sizeof(_t)-1);
  return (_t^_s)-_s;
}

inline static fixed_t FixedDiv(fixed_t a, fixed_t b)
{
  return ((unsigned)D_abs(a)>>14) >= (unsigned)D_abs(b) ? ((a^b)>>31) ^ INT_MAX :
    (fixed_t)(((int64_t) a << FRACBITS) / b);
}

//*************************************************************************************
//WAD file structs from Doom sources.
//*************************************************************************************

typedef struct
{
    char identification[4];                  // Should be "IWAD" or "PWAD".
    int32_t  numlumps;
    int32_t  infotableofs;
} wadinfo_t;

typedef struct
{
    int32_t  filepos;
    int32_t  size;
    char name[8];
} filelump_t;



//
// Map level types.
// The following data structures define the persistent format
// used in the lumps of the WAD files.
//

// Lump order in a map WAD: each map needs a couple of lumps
// to provide a complete scene geometry description.
enum {
  ML_LABEL,             // A separator, name, ExMx or MAPxx
  ML_THINGS,            // Monsters, items..
  ML_LINEDEFS,          // LineDefs, from editing
  ML_SIDEDEFS,          // SideDefs, from editing
  ML_VERTEXES,          // Vertices, edited and BSP splits generated
  ML_SEGS,              // LineSegs, from LineDefs split by BSP
  ML_SSECTORS,          // SubSectors, list of LineSegs
  ML_NODES,             // BSP nodes
  ML_SECTORS,           // Sectors, from editing
  ML_REJECT,            // LUT, sector-sector visibility
  ML_BLOCKMAP           // LUT, motion clipping, walls/grid element
};



//*************************************************************************************
//r_defs structs from Doom sources.
//*************************************************************************************

typedef struct
{
    fixed_t x, y;
} vertex_t;

// A single Vertex.
typedef struct
{
    short x,y;
} mapvertex_t;


#define NO_INDEX ((unsigned short)-1)

#define ML_TWOSIDED             4


typedef enum
{
  ST_HORIZONTAL,
  ST_VERTICAL,
  ST_POSITIVE,
  ST_NEGATIVE
} slopetype_t;

typedef enum
{                 // cph:
    RF_TOP_TILE  = 1,     // Upper texture needs tiling
    RF_MID_TILE = 2,     // Mid texture needs tiling
    RF_BOT_TILE = 4,     // Lower texture needs tiling
    RF_IGNORE   = 8,     // Renderer can skip this line
    RF_CLOSED   =16,     // Line blocks view
} r_flags;


/* Bounding box coordinate storage. */
enum
{
  BOXTOP,
  BOXBOTTOM,
  BOXLEFT,
  BOXRIGHT
};  /* bbox coordinates */


typedef struct line_s
{
    vertex_t v1;
    vertex_t v2;            // Vertices, from v1 to v2.
    uint32_t lineno;         //line number.
    fixed_t dx, dy;        // Precalculated v2 - v1 for side checking.

    uint16_t sidenum[2];        // Visual appearance: SideDefs.

    fixed_t bbox[4];        //Line bounding box.

    uint16_t flags;           // Animation related.
    int16_t special;
    int16_t tag;
    uint16_t slopetype; // To aid move clipping.

} line_t;

typedef struct {
  unsigned short v1;
  unsigned short v2;
  unsigned short flags;
  short special;
  short tag;
  // proff 07/23/2006 - support more than 32768 sidedefs
  // use the unsigned value and special case the -1
  // sidenum[1] will be -1 (NO_INDEX) if one sided
  unsigned short sidenum[2];
} maplinedef_t;


// LineSeg, generated by splitting LineDefs
// using partition lines selected by BSP builder.
typedef struct {
  unsigned short v1;
  unsigned short v2;
  short angle;
  unsigned short linedef;
  short side;
  short offset;
} mapseg_t;


//
// The LineSeg.
//
typedef struct
{
    vertex_t v1;
    vertex_t v2;            // Vertices, from v1 to v2.

    fixed_t offset;
    angle_t angle;

    uint16_t sidenum;
    uint16_t linenum;

    uint16_t frontsectornum;
    uint16_t backsectornum;
} seg_t;



// A SideDef, defining the visual appearance of a wall,
// by setting textures and offsets.
typedef struct
{
  short textureoffset;
  short rowoffset;
  char  toptexture[8];
  char  bottomtexture[8];
  char  midtexture[8];
  short sector;  // Front sector, towards viewer.
} mapsidedef_t;

// A SideDef, defining the visual appearance of a wall,
// by setting textures and offsets.
typedef struct
{
  short textureoffset;
  short rowoffset;
  short toptexture;
  short bottomtexture;
  short midtexture;
  short sector;  // Front sector, towards viewer.
} sidedef_t;

typedef struct
{
  short originx;
  short originy;
  short patch;
  short stepdir;         // unused in Doom but might be used in Phase 2 Boom
  short colormap;        // unused in Doom but might be used in Phase 2 Boom
} mappatch_t;

typedef struct
{
  char       name[8];
  char       pad2[4];      // unused
  short      width;
  short      height;
  char       pad[4];       // unused in Doom but might be used in Boom Phase 2
  short      patchcount;
  mappatch_t patches[1];
} maptexture_t;

#endif // DOOMTYPES_H
