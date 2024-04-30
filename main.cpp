#define GL_SILENCE_DEPRECATION
#define GL_GLEXT_PROTOTYPES 1
#define FIXED_TIMESTEP 0.0166666f
#define LEVEL1_WIDTH 14
#define LEVEL1_HEIGHT 8
#define LEVEL1_LEFT_EDGE 5.0f
#define LEVEL_RIGHT_EDGE 28.0f
#define LOG(argument) std::cout << argument << '\n'

#ifdef _WINDOWS
#include <GL/glew.h>
#endif

#include <SDL_mixer.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "ShaderProgram.h"
#include "cmath"
#include <ctime>
#include <vector>
#include "Utility.h"
#include "Scene.h"
#include "MainMenu.h"
#include "LevelA.h"
#include "LevelB.h"
#include "stb_image.h"

// ————— CONSTANTS ————— //
const int WINDOW_WIDTH = 640,
WINDOW_HEIGHT = 480;

const float BG_RED = 0.1922f,
BG_BLUE = 0.549f,
BG_GREEN = 0.9059f,
BG_OPACITY = 1.0f;

const int VIEWPORT_X = 0,
VIEWPORT_Y = 0,
VIEWPORT_WIDTH = WINDOW_WIDTH,
VIEWPORT_HEIGHT = WINDOW_HEIGHT;

const char V_SHADER_PATH[] = "shaders/vertex_textured.glsl",
F_SHADER_PATH[] = "shaders/fragment_textured.glsl",
FONT_FILEPATH[] = "assets/font1.png";

const float MILLISECONDS_IN_SECOND = 1000.0;

// ————— GLOBAL VARIABLES ————— //
Scene* g_current_scene;
MainMenu* g_main_menu;
LevelA* g_level_a;
LevelB* g_level_1;

SDL_Window* g_display_window;
bool g_game_is_running = true;

ShaderProgram g_shader_program;
glm::mat4 g_view_matrix, g_projection_matrix;

float g_previous_ticks = 0.0f;
float g_accumulator = 0.0f;


int lives = 3;
int curr_note = 0;
int num_points = 0;
int notes_missed = 0;
float max_ticks = 269.0f;
const int NUMBER_OF_TEXTURES = 1;
const GLint LEVEL_OF_DETAIL = 0;
const GLint TEXTURE_BORDER = 0;
const int FONTBANK_SIZE = 16;
GLuint font_texture_id;
std::string MenuMsg = "Press Enter to Start";
std::string WinMsg = "You Win!";
std::string LoseMsg = "You Lose!";
std::string Level1 = "Level 1";
std::string Level2 = "Level 2";
std::string Level3 = "Level 3";
int difficulty;
float spacing = 0.1f;
bool GameOver = false;
bool PlayerWin = false;
bool was_note_clicked = false;

GLuint load_texture(const char* filepath)
{
    int width, height, number_of_components;
    unsigned char* image = stbi_load(filepath, &width, &height, &number_of_components, STBI_rgb_alpha);

    if (image == NULL)
    {
        LOG("Unable to load image. Make sure the path is correct.");
        assert(false);
    }

    GLuint textureID;
    glGenTextures(NUMBER_OF_TEXTURES, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, LEVEL_OF_DETAIL, GL_RGBA, width, height, TEXTURE_BORDER, GL_RGBA, GL_UNSIGNED_BYTE, image);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    stbi_image_free(image);

    return textureID;
}

void DrawText(ShaderProgram* program, GLuint font_texture_id, std::string text, float screen_size, float spacing, glm::vec3 position)
{
    // Scale the size of the fontbank in the UV-plane
    // We will use this for spacing and positioning
    float width = 1.0f / FONTBANK_SIZE;
    float height = 1.0f / FONTBANK_SIZE;

    // Instead of having a single pair of arrays, we'll have a series of pairs—one for each character
    // Don't forget to include <vector>!
    std::vector<float> vertices;
    std::vector<float> texture_coordinates;

    // For every character...
    for (int i = 0; i < text.size(); i++) {
        // 1. Get their index in the spritesheet, as well as their offset (i.e. their position
        //    relative to the whole sentence)
        int spritesheet_index = (int)text[i];  // ascii value of character
        float offset = (screen_size + spacing) * i;

        // 2. Using the spritesheet index, we can calculate our U- and V-coordinates
        float u_coordinate = (float)(spritesheet_index % FONTBANK_SIZE) / FONTBANK_SIZE;
        float v_coordinate = (float)(spritesheet_index / FONTBANK_SIZE) / FONTBANK_SIZE;

        // 3. Inset the current pair in both vectors
        vertices.insert(vertices.end(), {
            offset + (-0.5f * screen_size), 0.5f * screen_size,
            offset + (-0.5f * screen_size), -0.5f * screen_size,
            offset + (0.5f * screen_size), 0.5f * screen_size,
            offset + (0.5f * screen_size), -0.5f * screen_size,
            offset + (0.5f * screen_size), 0.5f * screen_size,
            offset + (-0.5f * screen_size), -0.5f * screen_size,
            });

        texture_coordinates.insert(texture_coordinates.end(), {
            u_coordinate, v_coordinate,
            u_coordinate, v_coordinate + height,
            u_coordinate + width, v_coordinate,
            u_coordinate + width, v_coordinate + height,
            u_coordinate + width, v_coordinate,
            u_coordinate, v_coordinate + height,
            });
    }

    // 4. And render all of them using the pairs
    glm::mat4 model_matrix = glm::mat4(1.0f);
    model_matrix = glm::translate(model_matrix, position);

    program->set_model_matrix(model_matrix);
    glUseProgram(program->get_program_id());

    glVertexAttribPointer(program->get_position_attribute(), 2, GL_FLOAT, false, 0, vertices.data());
    glEnableVertexAttribArray(program->get_position_attribute());
    glVertexAttribPointer(program->get_tex_coordinate_attribute(), 2, GL_FLOAT, false, 0, texture_coordinates.data());
    glEnableVertexAttribArray(program->get_tex_coordinate_attribute());

    glBindTexture(GL_TEXTURE_2D, font_texture_id);
    glDrawArrays(GL_TRIANGLES, 0, (int)(text.size() * 6));

    glDisableVertexAttribArray(program->get_position_attribute());
    glDisableVertexAttribArray(program->get_tex_coordinate_attribute());
}

void switch_to_scene(Scene* scene)
{
    g_current_scene = scene;
    g_current_scene->initialise();
}

void initialise()
{
    // ————— VIDEO ————— //
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    g_display_window = SDL_CreateWindow("Hello, Scenes!",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        SDL_WINDOW_OPENGL);

    SDL_GLContext context = SDL_GL_CreateContext(g_display_window);
    SDL_GL_MakeCurrent(g_display_window, context);

#ifdef _WINDOWS
    glewInit();
#endif

    // ————— GENERAL ————— //
    glViewport(VIEWPORT_X, VIEWPORT_Y, VIEWPORT_WIDTH, VIEWPORT_HEIGHT);
    g_shader_program.load(V_SHADER_PATH, F_SHADER_PATH);

    g_view_matrix = glm::mat4(1.0f);
    g_projection_matrix = glm::ortho(-5.0f, 5.0f, -3.75f, 3.75f, -1.0f, 1.0f);

    g_shader_program.set_projection_matrix(g_projection_matrix);
    g_shader_program.set_view_matrix(g_view_matrix);

    glUseProgram(g_shader_program.get_program_id());

    glClearColor(BG_RED, BG_BLUE, BG_GREEN, BG_OPACITY);

    // ————— LEVEL A SETUP ————— //
    g_main_menu = new MainMenu();
    switch_to_scene(g_main_menu);

    g_level_a = new LevelA();
    g_level_1 = new LevelB();
    //switch_to_scene(g_level_a);
    GLuint font_texture_id = load_texture(FONT_FILEPATH);
    // ————— BLENDING ————— //
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void process_input()
{
    if (g_current_scene != g_main_menu) {
        g_current_scene->m_state.player->set_movement(glm::vec3(0.0f));
    }

    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type) {
        case SDL_QUIT:
        case SDL_WINDOWEVENT_CLOSE:
            g_game_is_running = false;
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
            case SDLK_q:
                // Quit the game with a keystroke
                g_game_is_running = false;
                break;

            case SDLK_SPACE:
                // Jump
                if (g_current_scene->m_state.player->m_collided_bottom)
                {
                    g_current_scene->m_state.player->m_is_jumping = true;
                    //Mix_VolumeChunk(g_current_scene->m_state.jump_sfx, MIX_MAX_VOLUME / 2);
                    Mix_PlayChannel(-1, g_current_scene->m_state.jump_sfx, 0);
                }
                break;

            case SDLK_RETURN:
                // Switch to level A
                if (g_current_scene == g_main_menu) {
                    switch_to_scene(g_level_1);
                }
                break;

            /*case SDLK_1:
                if (g_current_scene == g_main_menu) {
                    difficulty = 0;
                    switch_to_scene(g_level_1);
                }
                break;

            case SDLK_2:
                if (g_current_scene == g_main_menu) {
                    difficulty = 1;
                    switch_to_scene(g_level_2);
                }
                break;

            case SDLK_3:
                if (g_current_scene == g_main_menu) {
                    difficulty = 2;
                    switch_to_scene(g_level_3);
                }
                break;*/

            /*case SDLK_LEFT:
                if (g_current_scene != g_main_menu) {
                    if (g_current_scene->m_state.enemies[curr_note].check_isClickable()) {
                        if (g_current_scene->m_state.enemies[curr_note].get_direction() == "Left") {
                            float y_distance = fabs(g_current_scene->m_state.player->get_position().y - g_current_scene->m_state.enemies[curr_note].get_position().y);
                            if (y_distance <= 0.25f) {
                                num_points += 10;
                            }
                            else if (y_distance <= 0.5f) {
                                num_points += 5;
                            }
                            else if (y_distance <= 0.75) {
                                num_points += 1;
                            }
                            else {
                                notes_missed++;
                            }
                        }
                        else {
                            notes_missed++;
                        }
                        g_current_scene->m_state.enemies[curr_note].set_notClickable();
                        g_current_scene->m_state.enemies[curr_note].deactivate();
                        was_note_clicked = true;
                    }
                }*/
            default:
                break;
            }

        default:
            break;
        }
    }

    const Uint8* key_state = SDL_GetKeyboardState(NULL);
    if (g_current_scene != g_main_menu) {
        if (key_state[SDL_SCANCODE_LEFT])
        {
            g_current_scene->m_state.player->move_left();
            g_current_scene->m_state.player->m_animation_indices = g_current_scene->m_state.player->m_walking[g_current_scene->m_state.player->LEFT];
        }
        else if (key_state[SDL_SCANCODE_RIGHT])
        {
            g_current_scene->m_state.player->move_right();
            g_current_scene->m_state.player->m_animation_indices = g_current_scene->m_state.player->m_walking[g_current_scene->m_state.player->RIGHT];
        }

        // This makes sure that the player can't move faster diagonally
        if (glm::length(g_current_scene->m_state.player->get_movement()) > 1.0f)
        {
            g_current_scene->m_state.player->set_movement(glm::normalize(g_current_scene->m_state.player->get_movement()));
        }
    }
}

void update()
{
    // ————— DELTA TIME / FIXED TIME STEP CALCULATION ————— //
    GLuint font_texture_id = load_texture(FONT_FILEPATH);
    float ticks = (float)SDL_GetTicks() / MILLISECONDS_IN_SECOND;
    float delta_time = ticks - g_previous_ticks;
    g_previous_ticks = ticks;
    // below for full length of song
    /*if (ticks > max_ticks) { 
        GameOver = true;
    }*/
    delta_time += g_accumulator;

    if (delta_time < FIXED_TIMESTEP)
    {
        g_accumulator = delta_time;
        return;
    }

    while (delta_time >= FIXED_TIMESTEP) {
        // ————— UPDATING THE SCENE (i.e. map, character, enemies...) ————— //
        //float y_distance = (float)(g_current_scene->m_state.enemies[curr_note].get_position().y - g_current_scene->m_state.player->get_position().y);
        //switch (difficulty)
        //{
        //case 0:
        //    if (curr_note % 10 == 5) {
        //        g_current_scene->m_state.enemies[curr_note].set_isRotating();
        //    }
        //}
        //if (!g_current_scene->m_state.enemies[curr_note].check_isClickable()) {
        //    if (y_distance <= 1.0) {
        //        g_current_scene->m_state.enemies[curr_note].set_isClickable();
        //    }
        //}
        //else {
        //    if (y_distance < -1.0) {
        //        g_current_scene->m_state.enemies[curr_note].set_notClickable();
        //        if (!was_note_clicked) {
        //            notes_missed++;
        //            g_current_scene->m_state.enemies[curr_note].deactivate(); // remove if deactivate doesn't work properly
        //            curr_note++;
        //        }
        //    }
        //}
        //if (notes_missed == 10) {
        //    GameOver = true;
        //}
        /*for (int i = 0; i < 3; i++) {
            if (g_current_scene->m_state.player->check_collision(&g_current_scene->m_state.enemies[i]) == true) {
                lives -= 1;
            }
        }*/
        if (lives == 0) {
            GameOver = true;
        }
        if (!GameOver) {
            g_current_scene->update(FIXED_TIMESTEP);
        }
        delta_time -= FIXED_TIMESTEP;
    }

    g_accumulator = delta_time;


    // ————— PLAYER CAMERA ————— //
    g_view_matrix = glm::mat4(1.0f);

    if (g_current_scene->m_state.player->get_position().x > LEVEL1_LEFT_EDGE) {
        if (g_current_scene == g_main_menu) {
            g_view_matrix = glm::translate(g_view_matrix, glm::vec3(-g_current_scene->m_state.player->get_position().x, 3.75, 0));
        }
        else {
            g_view_matrix = glm::translate(g_view_matrix, glm::vec3(-g_current_scene->m_state.player->get_position().x, g_current_scene->m_state.player->get_position().y, 0));
        }
    }
    else {
        if (g_current_scene == g_main_menu) {
            g_view_matrix = glm::translate(g_view_matrix, glm::vec3(5, 3.75, 0));
        }
        else {
            g_view_matrix = glm::translate(g_view_matrix, glm::vec3(-g_current_scene->m_state.player->get_position().x, -g_current_scene->m_state.player->get_position().y, 0));
        }
    }

    if (g_current_scene->m_state.player->get_position().x >= LEVEL_RIGHT_EDGE) {
        GameOver = true;
        PlayerWin = true;
    }
}

void render()
{
    font_texture_id = load_texture(FONT_FILEPATH);
    g_shader_program.set_view_matrix(g_view_matrix);
    glClear(GL_COLOR_BUFFER_BIT);
    if (g_current_scene == g_main_menu) {
        DrawText(&g_shader_program, font_texture_id, MenuMsg, 0.5f, 0.05f, glm::vec3(3.0f, -1.0f, 0.0f));
    }
    if (!GameOver && g_current_scene != g_main_menu) {
        DrawText(&g_shader_program, font_texture_id, Level1, 0.5f, 0.05f, glm::vec3(3.0f, -1.0f, 0.0f));
        //DrawText(&g_shader_program, font_texture_id, Level2, 0.5f, 0.1f, glm::vec3(13.0f, -1.0f, 0.0f));
        //DrawText(&g_shader_program, font_texture_id, Level3, 0.5f, 0.1f, glm::vec3(23.0f, -1.0f, 0.0f));
    }
    /*if (g_current_scene == g_main_menu) {
        DrawText(&g_shader_program, font_texture_id, MenuMsg, 0.5f, 0.1f, glm::vec3(3.0f, -5.0f, 0.0f));
    }*/
    // ————— RENDERING THE SCENE (i.e. map, character, enemies...) ————— //
    g_current_scene->render(&g_shader_program);
    float msg_spot = g_current_scene->m_state.player->get_position().x - 3;
    if (GameOver && g_current_scene != g_main_menu) {
        if (PlayerWin) {
            DrawText(&g_shader_program, font_texture_id, WinMsg, 0.5f, 0.05f, glm::vec3(msg_spot, -1.0f, 0.0f));
        }
        else {
            DrawText(&g_shader_program, font_texture_id, LoseMsg, 0.5f, 0.05f, glm::vec3(msg_spot, -1.0f, 0.0f));
        }
    }
    SDL_GL_SwapWindow(g_display_window);
}

void shutdown()
{
    SDL_Quit();

    // ————— DELETING LEVEL A DATA (i.e. map, character, enemies...) ————— //
    delete g_level_a;
    // delete g_level_2;
    // delete g_level_3;
    delete g_main_menu;
}

// ————— GAME LOOP ————— //
int main(int argc, char* argv[])
{
    initialise();

    while (g_game_is_running)
    {
        process_input();
        update();
        render();
    }

    shutdown();
    return 0;
}