#include "Texture.h"
#include "Vector2D.h"

const Vector2D		ARROW_DIR				= { 1.0, 0.0 };
const Uint32		ARROW_WIDTH				= 130;
const Uint32		ARROW_HEIGHT			= 20;
const double		ARROW_SPEED				= 20.0;

const Vector2D		BALLOON_DIR				= { 0.0, -1.0 };
const Uint32		BALLOON_WIDTH			= 128;
const Uint32		BALLOON_HEIGHT			= 128;
const double		BALLOON_MAX_SPEED		= 10.0;
const double		BALLOON_MIN_SPEED		= 3.0;
const Uint32		BURST_ANIMATION_TIME	= 300;
const Uint32		BURST_ANIMATION_FRAMES	= 6;
const Uint32		BURST_FRAME_TIME		= BURST_ANIMATION_TIME / BURST_ANIMATION_FRAMES;

const Vector2D		BOW_DIR					= { 0.0, 0.0 };
const Uint32		BOW_WIDTH				= 100;
const Uint32		BOW_HEIGHT				= 150;
const Uint32		ARMED_BOW_WIDTH			= 100;
const Uint32		ARMED_BOW_HEIGHT		= 150;
const double		BOW_SPEED				= 10.0;
const int			BOW_ANGLE_LIMIT			= 45;
const int			BOW_ANGLE_INCREMENT		= 3;

const Uint32		FRAME_RATE				= 16;
const Uint32		WIN_WIDTH				= 1280;
const Uint32		WIN_HEIGHT				= 720;
const Uint32		NUM_TEXTURES			= 8;
const Uint32		NUM_ARROWS				= 10;
const Uint32		SPAWN_TIME				= 200;
const Uint32		SPAWN_LOWER_BOUND		= WIN_WIDTH / 3;
const Uint32		SPAWN_UPPER_BOUND		= WIN_WIDTH - BALLOON_WIDTH;
const Uint32		SPAWN_SPACE				= SPAWN_UPPER_BOUND - SPAWN_LOWER_BOUND;
const std::string	STATE_FILE				= "state.txt";
const std::string	IMAGE_PATH				= "..\\res\\images\\";