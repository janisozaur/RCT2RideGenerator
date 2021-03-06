#ifndef BACKEND_H_INCLUDED
#define BACKEND_H_INCLUDED
#include "image.h"
#include "math_defines.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_STRING_TABLES 3
#define NUM_LANGUAGES 11
#define NUM_CARS 4

#define TILE_SLOPE (1 / sqrt(6))

#define FLAT 0

#define GENTLE (atan(TILE_SLOPE))
#define STEEP (atan(4 * TILE_SLOPE))
#define VERTICAL M_PI_2
#define FG_TRANSITION ((FLAT + GENTLE) / 2)
#define GS_TRANSITION ((GENTLE + STEEP) / 2)
#define SV_TRANSITION ((STEEP + VERTICAL) / 2)

#define GENTLE_DIAGONAL (atan(TILE_SLOPE * M_SQRT1_2))
#define STEEP_DIAGONAL (atan(4 * TILE_SLOPE * M_SQRT1_2))
#define FG_TRANSITION_DIAGONAL ((FLAT + GENTLE_DIAGONAL) / 2)

#define BANK M_PI_4
#define BANK_TRANSITION (M_PI_4 / 2)

#define CORKSCREW_RIGHT_YAW(angle) \
    (atan2(0.5 * (1 - cos(angle)), 1 - 0.5 * (1 - cos(angle))))
#define CORKSCREW_RIGHT_PITCH(angle) (-asin(-sin(angle) / sqrt(2.0)))
#define CORKSCREW_RIGHT_ROLL(angle) (-atan2(sin(angle) / sqrt(2.0), cos(angle)))

#define CORKSCREW_LEFT_YAW(angle) (-CORKSCREW_RIGHT_YAW(angle))
#define CORKSCREW_LEFT_PITCH(angle) (-CORKSCREW_RIGHT_PITCH(-angle))
#define CORKSCREW_LEFT_ROLL(angle) (-CORKSCREW_RIGHT_ROLL(angle))

typedef enum {
    STRING_TABLE_NAME = 0,
    STRING_TABLE_DESCRIPTION = 1,
    STRING_TABLE_CAPACITY = 2
} string_table_index_t;

typedef enum { LANGUAGE_ENGLISH_UK = 0,
    LANGUAGE_ENGLISH_US = 1 } language_t;

enum {
    RIDE_VEHICLE_TAB_SCALE_HALF = 0x00000001u,
    RIDE_NO_INVERSIONS = 0x00000002u,
    RIDE_NO_BANKED_TRACK = 0x00000004u,
    RIDE_CHUFFING_ON_DEPART = 0x00000008u,
    RIDE_SWING_MODE_1 = 0x00000010u,
    RIDE_ROTATION_MODE_1 = 0x00000020u, //twist
    RIDE_ROTATION_MODE_2 = 0x00000040u, //enterprise
    RIDE_FLAG_7 = 0x0000080u,
    RIDE_PLAY_SPLASH_SOUND = 0x00000100u,
    RIDE_PLAY_SPLASH_SOUND_SLIDE = 0x00000200u,
    RIDE_COVERED = 0x00000400u,
    RIDE_LIMIT_AIRTIME_BONUS = 0x00000800u,
    RIDE_SEPARATE_RIDE_DEPRECATED = 0x00001000u,
    RIDE_SEPARATE_RIDE = 0x00002000u, //this enables track designs
    RIDE_CANNOT_BREAK_DOWN = 0x00004000u,
    RIDE_DISABLE_LAST_OPERATING_MODE = 0x00008000u,
    RIDE_FLAG_16 = 0x00010000u,
    RIDE_DISABLE_FIRST_TWO_OPERATING_MODES = 0x00020000u,
    RIDE_FLAG_18 = 0x00040000u,
    RIDE_DISABLE_COLOR_TAB = 0x00080000u,
    RIDE_ALTERNATIVE_SWING_MODE_2 = 0x00100000u,
    RIDE_WET = 0x00000100u,
    RIDE_SLOW_IN_WATER = 0x00000200u,
    RIDE_SEPERATE = 0x00001000u
    // from showing in the window
};

enum {
    CAR_ANIMATION_NONE = 0x00u, //1 vehicle sprite, 1 peep sprite
    CAR_ANIMATION_STEAM = 0x01u, //4 vehicle sprites, uknown peep sprites, slow animation
    CAR_ANIMATION_2 = 0x02u, //unknown, possibly 3
    CAR_ANIMATION_ROWING = 0x03u, // 1 vehicle sprite, 6 peep sprites
    CAR_ANIMATION_4 = 0x04u, //unknown
    CAR_ANIMATION_5 = 0x05u, //unknown, possibly 2 frames?
    CAR_ANIMATION_OBSERVATION = 0x06u, //8 vehicle sprites, unknown peep sprites, we don't really know how to get this to work
    CAR_ANIMATION_GENERIC = 0x07u, //4 vehicle sprites, 4 peep sprites, fast animation speed
    CAR_ANIMATION_BICYCLE = 0x08u, //4 vehicle sprites, 4 peep sprites, medium animation speed, only animates with riders present
    CAR_ANIMATION_4D = 0x09u, // unknown

};

// clang-format off
enum {
    CAR_FLAG_1 =                      0x1u << 8,//these are all bit-shifted 8 because the flags field is offset one byte
    CAR_NO_UPSTOPS_TIGHT_TOLERANCE =  0x2u << 8,
    CAR_NO_UPSTOPS =                  0x4u << 8,//bobsled-style with 0.05 extra G's
    CAR_IS_MINIGOLFER =               0x8u << 8,
    CAR_FLAG_4 =                     0x01u << 8,
    CAR_FLAG_5 =                     0x02u << 8,
    CAR_CAN_INVERT =                 0x04u << 8,//I assume this is set on the flying and lay-down so they can spawn properly on inverted station track
    CAR_FLAG_7 =                     0x80u << 8,
    CAR_OPENS_DOORS =               0x100u << 8,//only relevant for making things backwards-compatible with RCT2 and doors
    CAR_ENABLE_REMAP3 =             0x200u << 8,
    CAR_FLAG_10 =                   0x400u << 8,
    CAR_FLAG_11 =                   0x800u << 8,
    CAR_OVERRIDE_VERTICAL_FRAMES = 0x1000u << 8,//this is set on all 3 swinging rides (dingys, bobsled, suspended), with an override value of 0
    CAR_FLAG_13 =                  0x2000u << 8,
    CAR_FLAG_14 =                  0x4000u << 8,
    CAR_FLAG_15 =                  0x8000u << 8,
    CAR_ENABLE_REMAP2 =           0x10000u << 8,
    CAR_IS_SWINGING =             0x20000u << 8,
    CAR_IS_SPINNING =             0x40000u << 8,
    CAR_IS_POWERED =              0x80000u << 8,
    CAR_ENABLE_ROLLING_SOUND =   0x100000u << 8,//riders can scream?
    CAR_FLAG_21 =                0x200000u << 8,//related to swinging sprites - I believe this is set automatically
    CAR_FLAG_22 =                0x400000u << 8,
    CAR_IS_ANIMATED =            0x800000u << 8,
    /*
    CAR_FLAG_24 = 1 << 24,
    CAR_FLAG_25 = 1 << 25,// related to swinging sprites?
    CAR_FLAG_26 = 1 << 26,
    CAR_FLAG_27 = 1 << 27,// related to swinging sprites
    CAR_REVERSE_THRUST_DISABLED = 1 << 28,//allows cars to accelerate down slopes like water rides and ghost train
    CAR_FLAG_29 = 1 << 20,
    CAR_FLAG_30 = 1 << 30,
    CAR_FLAG_31 = 1u << 31
    */
    CAR_STEAM_EFFECT =                0x1u//this should be an animation type
};
// clang-format on

enum {
    SPRITE_FLAT_SLOPE = 0x0001,
    SPRITE_GENTLE_SLOPE = 0x0002,
    SPRITE_STEEP_SLOPE = 0x0004,
    SPRITE_VERTICAL_SLOPE = 0x0008,
    SPRITE_DIAGONAL_SLOPE = 0x0010,
    SPRITE_BANKING = 0x0020,
    SPRITE_INLINE_TWIST = 0x0040,
    SPRITE_SLOPE_BANK_TRANSITION = 0x0080,
    SPRITE_DIAGONAL_BANK_TRANSITION = 0x0100,
    SPRITE_SLOPED_BANK_TRANSITION = 0x0200,
    SPRITE_SLOPED_BANKED_TURN = 0x0400,
    SPRITE_BANKED_SLOPE_TRANSITION = 0x0800,
    SPRITE_CORKSCREW = 0x1000,
    SPRITE_RESTRAINT_ANIMATION = 0x2000,
    SPRITE_SPIRAL_LIFT = 0x4000
};

enum {
    RUNNING_SOUND_WOODEN_OLD = 1,
    RUNNING_SOUND_WOODEN_MODERN = 54,
    RUNNING_SOUND_STEEL = 2,
    RUNNING_SOUND_STEEL_SMOOTH = 57,
    RUNNING_SOUND_WATERSLIDE = 32,
    RUNNING_SOUND_TRAIN = 31,
    RUNNING_SOUND_ENGINE = 21,
    RUNNING_SOUND_NONE = 255
};

enum {
    SECONDARY_SOUND_SCREAMS_1 = 0,
    SECONDARY_SOUND_SCREAMS_2 = 1,
    SECONDARY_SOUND_SCREAMS_3 = 2,
    SECONDARY_SOUND_WHISTLE = 3,
    SECONDARY_SOUND_BELL = 4,
    SECONDARY_SOUND_NONE = 255,
};

enum {
    CAR_INDEX_DEFAULT = 0,
    CAR_INDEX_FRONT = 1,
    CAR_INDEX_SECOND = 2,
    CAR_INDEX_THIRD = 4,
    CAR_INDEX_REAR = 3
};

enum {
    CATEGORY_TRANSPORT_RIDE = 0,
    CATEGORY_GENTLE_RIDE = 1,
    CATEGORY_ROLLERCOASTER = 2,
    CATEGORY_THRILL_RIDE = 3,
    CATEGORY_WATER_RIDE = 4
};

#define TRACK_STATION 0x0000000000000004l
#define TRACK_STRAIGHT 0x0000000000000002l
#define TRACK_CHAIN_LIFT 0x0000000000000008l
#define TRACK_STEEP_CHAIN_LIFT 0x0000000000000010l
#define TRACK_TIRE_DRIVE_LIFT 0x0000000000000020l // Junior only
#define TRACK_BANKING 0x0000000000000040l
#define TRACK_VERTICAL_LOOP 0x0000000000000080l
#define TRACK_GENTLE_SLOPE 0x0000000000000100l
#define TRACK_STEEP_SLOPE 0x0000000000000200l
#define TRACK_FLAT_TO_STEEP_SLOPE_SMALL 0x0000000000000400l
#define TRACK_SLOPED_TURNS 0x0000000000000800l //(Enables available turns)
#define TRACK_STEEP_SLOPED_TURNS 0x0000000000001000l
#define TRACK_S_BEND 0x0000000000002000l
#define TRACK_TINY_TURNS 0x0000000000004000l
#define TRACK_SMALL_TURN 0x0000000000008000l //(Flat enabled)
#define TRACK_LARGE_TURN 0x0000000000010000l
#define TRACK_INLINE_TWIST 0x0000000000020000l
#define TRACK_HALF_LOOP 0x0000000000040000l
#define TRACK_HALF_CORKSCREW 0x0000000000080000l
#define TRACK_VERTICAL_TOWER \
    0x0000000000100000l // Launched Freefall + Roto-Drop?)
#define TRACK_HELIX 0x0000000000200000l //(For upright track only)
#define TRACK_QUARTER_HELIX 0x0000000000400000l //(For inverted track only)
#define TRACK_UNBANKED_QUARTER_HELIX \
    0x0000000000800000l // Suspended Swinging only
#define TRACK_BRAKES 0x0000000001000000l
#define TRACK_ON_RIDE_PHOTO_SECTION 0x0000000004000000l
#define TRACK_WATER_SPLASH 0x0000000008000000l // Wooden only
#define TRACK_VERTICAL_SLOPE 0x0000000010000000l
#define TRACK_BARREL_ROLL 0x0000000020000000l
#define TRACK_LAUNCHED_LIFT 0x0000000040000000l
#define TRACK_LARGE_HALF_LOOP 0x0000000080000000l
#define TRACK_BANKED_FLAT_TO_UNBANKED_GENTLE_SLOPE_TURN 0x0000000100000000l
#define TRACK_HEARTLINE_ROLL 0x0000000400000000l // Heartline only
#define TRACK_REVERSER_TURNTABLE 0x0000000200000000l // Log Flume only
#define TRACK_REVERSER 0x0000000800000000l // Reverser only
#define TRACK_FLAT_TO_VERTICAL_SLOPE \
    0x0000001000000000l // Enables vertical track
#define TRACK_VERTICAL_TO_FLAT 0x0000002000000000l // Enables top section
#define TRACK_BLOCK_BRAKES 0x0000004000000000l
#define TRACK_GENTLE_SLOPE_BANKING \
    0x0000008000000000l //(Enables available turns)
#define TRACK_FLAT_TO_STEEP_SLOPE 0x0000010000000000l
#define TRACK_VERTICAL_SLOPED_TURNS 0x0000020000000000l
#define TRACK_CABLE_LIFT 0x0000080000000000 // Giga only
#define TRACK_SPIRAL_LIFT 0x0000100000000000l // Spiral Coaster only
#define TRACK_QUARTER_LOOP 0x0000200000000000l
#define TRACK_SPINNING_TUNNEL 0x0000400000000000l //(Ghost Train and Car Rides)
#define TRACK_SPINNING_TOGGLE 0x0000800000000000l // Spinning Wild Mouse only)
#define TRACK_INLINE_TWIST_UNINVERT 0x0001000000000000l
#define TRACK_INLINE_TWIST_INVERT 0x0002000000000000l
#define TRACK_QUARTER_LOOP_INVERT 0x0004000000000000l
#define TRACK_QUARTER_LOOP_UNINVERT 0x0008000000000000l
#define TRACK_RAPIDS \
    0x0010000000000000l // Rapids / Log Bumps, River Rapids / Monster Trucks only
#define TRACK_HALF_LOOP_UNINVERT 0x0020000000000000l
#define TRACK_HALF_LOOP_INVERT 0x0040000000000000l

typedef struct {
    uint8_t* data;
    uint32_t size;
    uint32_t allocated;
} buffer_t;

typedef uint64_t track_section_t;

typedef struct {
    uint32_t start_address;
    uint16_t width;
    uint16_t height;
    int16_t x_offset;
    int16_t y_offset;
    uint16_t flags;
} graphic_record_t;

typedef struct {
    image_t** images;
    uint32_t num_images;
    uint32_t allocated;
} image_list_t;

typedef struct {
    language_t language;
    char* str;
} string_table_entry_t;

typedef struct {
    string_table_entry_t* strings;
    uint8_t num_strings;
} string_table_t;

typedef struct {
    uint32_t flags;
    uint32_t spacing;
    uint16_t unknown[9];
    uint16_t sprites;
    uint16_t friction;
    uint8_t running_sound;
    uint8_t secondary_sound;
    uint8_t extra_swing_frames;
    uint8_t highest_rotation_index;
    uint8_t rider_pairs;
    uint8_t riders;
    uint8_t rider_sprites;
    uint8_t spin_inertia;
    uint8_t spin_friction;
    uint8_t powered_acceleration;
    uint8_t powered_velocity;
    uint8_t z_value;
} car_t;

typedef struct {
    uint64_t track_sections;
    uint32_t flags;
    uint8_t car_icon_index;
    uint8_t zero_cars;
    uint8_t preview_index;
    uint8_t track_style;
    uint8_t excitement;
    uint8_t intensity;
    uint8_t nausea;
    uint8_t max_height;
    uint8_t categories[2];
    uint8_t car_types[5];
    uint8_t minimum_cars;
    uint8_t maximum_cars;
    car_t cars[NUM_CARS];
} ride_header_t;

typedef struct {
    uint8_t colors[3];
} color_scheme_t;

typedef struct {
    uint8_t* positions;
    uint16_t num;
} peep_position_data_t;

typedef struct {
    color_scheme_t* default_colors;
    uint8_t num_default_colors;
    peep_position_data_t peep_positions[4];
} ride_structures_t;

typedef struct {
    ride_header_t* ride_header;
    string_table_t* string_tables[3];
    ride_structures_t* optional;
    image_list_t* images;
    uint32_t num_images;
} object_t;

string_table_t* string_table_new();
char* string_table_get_string_by_language(string_table_t* table,
    language_t language);
void string_table_set_string_by_language(string_table_t* table,
    language_t language,
    char* str);

image_list_t* image_list_new();
image_list_t* image_list_load(uint8_t* bytes, uint32_t* pos_ptr);
void image_list_write(image_list_t* list, buffer_t* buffer);
void image_list_set_image(image_list_t* list, int index, image_t* image);
void image_list_set_num_images(image_list_t* list, uint32_t num_images);
void image_list_free(image_list_t* list);

ride_header_t* ride_header_new();

ride_structures_t* ride_structures_new();
void ride_structures_set_num_peep_positions(ride_structures_t* structures,
    int car,
    int num);
void ride_structures_set_num_default_colors(ride_structures_t* structures,
    int num);

object_t* object_new_ride();
object_t* object_load_dat(const char* filename);
void object_save_dat(object_t* object, const char* filename, uint32_t checksum);
char* object_get_string(object_t* object,
    string_table_index_t table_num,
    language_t language);
void object_set_string(object_t* object,
    string_table_index_t table_num,
    language_t language,
    char* new_string);
/*void RenderSprites(object_t* file,Animation* animations[5]);*/
void object_free(object_t* object);
void track_encode(buffer_t* data, char* filename);
buffer_t* load_file(char* filename);
buffer_t* track_decode(char* file);
#endif /*BACKEND_H_INCLUDED*/
