#include "LevelA.h"
#include "Utility.h"

#define LEVEL_WIDTH 30
#define LEVEL_HEIGHT 8

unsigned int LEVEL_A_DATA[] =
{
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3,
    3, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 8, 8, 0, 0, 0, 0, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
    3, 2, 2, 2, 2, 2, 2, 2, 2, 6, 6, 6, 6, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
    3, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13
};

LevelA::~LevelA()
{
    delete [] m_state.enemies;
    delete    m_state.player;
    delete    m_state.map;
    Mix_FreeChunk(m_state.jump_sfx);
    Mix_FreeMusic(m_state.bgm);
}

void LevelA::initialise()
{
    GLuint map_texture_id = Utility::load_texture("assets/mini-spritesheet-thumbnail.png");
    m_state.map = new Map(LEVEL_WIDTH, LEVEL_HEIGHT, LEVEL_A_DATA, map_texture_id, 1.0f, 4, 4);
    
    // Code from main.cpp's initialise()
    /**
     George's Stuff
     */
    // Existing
    m_state.player = new Entity();
    m_state.player->set_entity_type(PLAYER);
    m_state.player->set_position(glm::vec3(5.0f, 0.0f, 0.0f));
    m_state.player->set_movement(glm::vec3(0.0f));
    m_state.player->set_speed(2.5f);
    m_state.player->set_acceleration(glm::vec3(0.0f, -9.81f, 0.0f));
    m_state.player->m_texture_id = Utility::load_texture("assets/player.png");
    
    // Walking
    m_state.player->m_walking[m_state.player->LEFT]  = new int[6] { 0, 1, 2, 3, 4, 5 };
    m_state.player->m_walking[m_state.player->RIGHT] = new int[6] { 6, 7, 8, 9, 10, 11};
    m_state.player->m_walking[m_state.player->UP]    = new int[6] { 12, 13, 14, 15, 16, 17 };
    m_state.player->m_walking[m_state.player->DOWN]  = new int[6] { 18, 19, 20, 21, 22, 23 };

    m_state.player->m_animation_indices = m_state.player->m_walking[m_state.player->RIGHT];  // start George looking left
    m_state.player->m_animation_frames = 6;
    m_state.player->m_animation_index  = 0;
    m_state.player->m_animation_time   = 0.0f;
    m_state.player->m_animation_cols   = 6;
    m_state.player->m_animation_rows   = 10;
    m_state.player->set_height(0.9f);
    m_state.player->set_width(0.4f);
    
    // Jumping
    m_state.player->m_jumping_power = 5.0f;
    
    /**
     Enemies' stuff */
    GLuint enemy_texture_id = Utility::load_texture("assets/slime.png");
    
    m_state.enemies = new Entity[ENEMY_COUNT];
    for (int i = 0; i < ENEMY_COUNT; i++) {
        m_state.enemies[i].set_entity_type(ENEMY); 
        m_state.enemies[i].set_ai_type(GUARD); // set to Note
        m_state.enemies[i].set_ai_state(IDLE);
        m_state.enemies[i].m_texture_id = enemy_texture_id;
        m_state.enemies[i].set_movement(glm::vec3(0.0f)); // delete line
        m_state.enemies[i].set_speed(1.0f); // delete line
        m_state.enemies[i].set_acceleration(glm::vec3(0.0f, -9.81f, 0.0f)); // delete line
        m_state.enemies[i].set_height(0.6f);
        m_state.enemies[i].set_width(0.6f);
        m_state.enemies[i].m_walking[m_state.enemies[i].LEFT] = new int[1] {0}; // delete line
        m_state.enemies[i].m_animation_indices = m_state.enemies[i].m_walking[m_state.enemies[i].LEFT];  // start George looking left
        m_state.enemies[i].m_animation_frames = 4;
        m_state.enemies[i].m_animation_index = 0;
        m_state.enemies[i].m_animation_time = 0.0f;
        m_state.enemies[i].m_animation_cols = 7;
        m_state.enemies[i].m_animation_rows = 5;
        //m_state.enemies[i].set_height(0.5f);
        //m_state.enemies[i].set_width(0.4f);
        m_state.enemies[i].set_jumping_power(0.4f);
    }
    m_state.enemies[0].set_position(glm::vec3(8.0f, 0.0f, 0.0f));
    m_state.enemies[1].set_position(glm::vec3(18.0f, 0.0f, 0.0f));
    m_state.enemies[2].set_position(glm::vec3(28.0f, 0.0f, 0.0f));
    /**
     BGM and SFX
     */
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
    
    m_state.bgm = Mix_LoadMUS("assets/musicstuff.mp3");
    Mix_PlayMusic(m_state.bgm, -1);
    
    m_state.jump_sfx = Mix_LoadWAV("assets/bounce.wav");
    Mix_VolumeMusic(20);
    //Mix_VolumeChunk(m_state.jump_sfx, MIX_MAX_VOLUME / 2);
}

void LevelA::update(float delta_time)
{
    m_state.player->update(delta_time, m_state.player, m_state.enemies, ENEMY_COUNT, m_state.map);
    
    for (int i = 0; i < ENEMY_COUNT; i++)
    {
        m_state.enemies[i].update(delta_time, m_state.player, NULL, NULL, m_state.map);
    }
}


void LevelA::render(ShaderProgram *program)
{
    m_state.map->render(program);
    m_state.player->render(program);
    for (int i = 0; i < ENEMY_COUNT; i++) {
        m_state.enemies[i].render(program);
    }
}
