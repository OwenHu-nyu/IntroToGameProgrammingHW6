#define GL_SILENCE_DEPRECATION
#define STB_IMAGE_IMPLEMENTATION

#ifdef _WINDOWS
#include <GL/glew.h>
#endif

#define GL_GLEXT_PROTOTYPES 1
#include <SDL.h>
#include <SDL_opengl.h>
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "ShaderProgram.h"
#include "Entity.h"
#include "Map.h"

Entity::Entity()
{
    // ––––– PHYSICS ––––– //
    m_position = glm::vec3(0.0f);
    m_velocity = glm::vec3(0.0f);
    m_acceleration = glm::vec3(0.0f);

    // ––––– TRANSLATION ––––– //
    m_movement = glm::vec3(0.0f);
    m_speed = 0;
    m_model_matrix = glm::mat4(1.0f);
}

Entity::~Entity()
{
    delete[] m_animation_up;
    delete[] m_animation_down;
    delete[] m_animation_left;
    delete[] m_animation_right;
    delete[] m_walking;
}

void Entity::draw_sprite_from_texture_atlas(ShaderProgram* program, GLuint texture_id, int index)
{
    // Step 1: Calculate the UV location of the indexed frame
    float u_coord = (float)(index % m_animation_cols) / (float)m_animation_cols;
    float v_coord = (float)(index / m_animation_cols) / (float)m_animation_rows;

    // Step 2: Calculate its UV size
    float width = 1.0f / (float)m_animation_cols;
    float height = 1.0f / (float)m_animation_rows;

// Step 3: Just as we have done before, match the texture coordinates to the vertices
float tex_coords[] =
{
    u_coord, v_coord + height, u_coord + width, v_coord + height, u_coord + width, v_coord,
    u_coord, v_coord + height, u_coord + width, v_coord, u_coord, v_coord
};

float vertices[] =
{
    -0.5, -0.5, 0.5, -0.5,  0.5, 0.5,
    -0.5, -0.5, 0.5,  0.5, -0.5, 0.5
};

// Step 4: And render
glBindTexture(GL_TEXTURE_2D, texture_id);

glVertexAttribPointer(program->get_position_attribute(), 2, GL_FLOAT, false, 0, vertices);
glEnableVertexAttribArray(program->get_position_attribute());

glVertexAttribPointer(program->get_tex_coordinate_attribute(), 2, GL_FLOAT, false, 0, tex_coords);
glEnableVertexAttribArray(program->get_tex_coordinate_attribute());

glDrawArrays(GL_TRIANGLES, 0, 6);

glDisableVertexAttribArray(program->get_position_attribute());
glDisableVertexAttribArray(program->get_tex_coordinate_attribute());
}

void Entity::ai_activate(Entity* player)
{
    switch (m_ai_type)
    {
    case WALKER:
        ai_walk();
        break;

    case GUARD:
        ai_guard(player);
        break;

    default:
        break;
    }
}

void Entity::ai_activate_jumper(float delta_time, Map* gameMap)
{
    switch (m_ai_type)
    {
    case JUMPER:
        ai_jumper(delta_time, gameMap);
    default:
        break;
    }
}


void Entity::ai_deactivate(Entity* player) {
    m_is_active = false;
}

void Entity::ai_walk()
{
    m_movement = glm::vec3(-1.0f, 0.0f, 0.0f);

}

void Entity::ai_guard(Entity* player)
{
    switch (m_ai_state) {
    case IDLE:
        if (glm::distance(m_position, player->get_position()) < 3.0f) m_ai_state = WALKING;
        break;

    case WALKING:
        if (m_position.x > player->get_position().x) {
            m_movement = glm::vec3(-1.0f, 0.0f, 0.0f);
        }
        else {
            m_movement = glm::vec3(1.0f, 0.0f, 0.0f);
        }
        break;

    case ATTACKING:
        break;

    default:
        break;
    }
}
bool const Entity::isGrounded(Map* gameMap) {
    float checkBelowY = m_position.y - (m_height / 2.0f) - 0.1f;
    glm::vec3 checkPosition = glm::vec3(m_position.x, checkBelowY, 0.0f);
    return gameMap->is_solid(checkPosition, nullptr, nullptr);
}
void Entity::ai_jumper(float delta_time, Map* gameMap)
{
    float checkBelowY = m_position.y - 0.1f;
    if (gameMap->is_solid(glm::vec3(m_position.x, checkBelowY, 0.0f), nullptr, nullptr)) {
        m_velocity.y = m_jumping_power;
    }
    m_velocity.x = m_movement.x * m_speed;
    m_velocity += m_acceleration * delta_time;

    m_position.y += m_velocity.y * delta_time;

    m_position.x += m_velocity.x * delta_time;

    if (m_collided_bottom) {
        m_is_jumping = true;
    }
    // ––––– JUMPING ––––– //
    if (m_is_jumping)
    {
        // STEP 1: Immediately return the flag to its original false state
        m_is_jumping = false;

        // STEP 2: The player now acquires an upward velocity
        m_velocity.y += m_jumping_power;
    }

    // ––––– TRANSFORMATIONS ––––– //
    m_model_matrix = glm::mat4(1.0f);
    m_model_matrix = glm::translate(m_model_matrix, m_position);
}

void Entity::update(float delta_time, Entity* player, Map* gameMap)
{
    if (!m_is_active) {
        glDeleteTextures(1, &m_texture_id);
        return;
    }
    m_collided_top = false;
    m_collided_bottom = false;
    m_collided_left = false;
    m_collided_right = false;

    if (m_entity_type == ENEMY) {
        if (m_ai_type == GUARD or m_ai_type == WALKER) {
            ai_activate(player);
        }
        else if (m_ai_type == JUMPER) {
            ai_activate_jumper(delta_time, gameMap);
        }
    }
    m_velocity += m_acceleration * delta_time;
    glm::vec3 potentialPosition = m_position + m_velocity + delta_time;

    float penetrationX = 0, penetrationY = 0;
    bool collidedX = gameMap->is_solid(glm::vec3(potentialPosition.x, m_position.y, 0.0), &penetrationX, nullptr);
    bool collidedY = gameMap->is_solid(glm::vec3(m_position.x, potentialPosition.y, 0.0), nullptr, &penetrationY);
    if (!collidedX) {
        m_position.x = potentialPosition.x;
    }
    else {
        m_velocity.x = 0;
        m_position.x += penetrationX;
    }
    if (!collidedY) {
        m_position.y = potentialPosition.y;
    }
    else {
        m_velocity.y = 0;
        if (get_ai_type() == JUMPER && !m_collided_bottom) {

        }
    }
    // ––––– ANIMATION ––––– //
    if (m_animation_indices != NULL)
    {
        if (glm::length(m_movement) != 0)
        {
            m_animation_time += delta_time;
            float frames_per_second = (float)1 / SECONDS_PER_FRAME;

            if (m_animation_time >= frames_per_second)
            {
                m_animation_time = 0.0f;
                m_animation_index++;

                if (m_animation_index >= m_animation_frames)
                {
                    m_animation_index = 0;
                }
            }
        }
    }

    // ––––– GRAVITY ––––– //
   /* m_velocity.x = m_movement.x * m_speed;
    m_velocity += m_acceleration * delta_time;

    m_position.y += m_velocity.y * delta_time;
    check_collision_y(collidable_entities, collidable_entity_count);

    m_position.x += m_velocity.x * delta_time;
    check_collision_x(collidable_entities, collidable_entity_count);*/

    // ––––– JUMPING ––––– //
    if (m_is_jumping)
    {
        // STEP 1: Immediately return the flag to its original false state
        m_is_jumping = false;

        // STEP 2: The player now acquires an upward velocity
        m_velocity.y += m_jumping_power;
    }

    // ––––– TRANSFORMATIONS ––––– //
    m_model_matrix = glm::mat4(1.0f);
    m_model_matrix = glm::translate(m_model_matrix, m_position);
}

void const Entity::check_collision_y(Map* gameMap)
{
    float penetrationX = 0;
    if (gameMap->is_solid(glm::vec3(m_position.x + m_velocity.x, m_position.y, 0.0f), &penetrationX, nullptr)) {
        m_position.x += penetrationX;
        m_velocity.x = 0;
    }
    /*for (int i = 0; i < collidable_entity_count; i++)
    {
        Entity* collidable_entity = &collidable_entities[i];

        if (check_collision(collidable_entity))
        {
            float y_distance = fabs(m_position.y - collidable_entity->get_position().y);
            float y_overlap = fabs(y_distance - (m_height / 2.0f) - (collidable_entity->get_height() / 2.0f));
            if (m_velocity.y > 0) {
                m_position.y -= y_overlap;
                m_velocity.y = 0;
                m_collided_top = true;
            }
            else if (m_velocity.y < 0) {
                m_position.y += y_overlap;
                m_velocity.y = 0;
                m_collided_bottom = true;
            }
        }
    }*/
}

void const Entity::check_collision_x(Map* gameMap)
{
    float penetrationY = 0;
    if (gameMap->is_solid(glm::vec3(m_position.x + m_velocity.x, m_position.y, 0.0f), &penetrationY, nullptr)) {
        m_position.y += penetrationY;
        m_velocity.y = 0;
    }/*
    for (int i = 0; i < collidable_entity_count; i++)
    {
        Entity* collidable_entity = &collidable_entities[i];

        if (check_collision(collidable_entity))
        {
            float x_distance = fabs(m_position.x - collidable_entity->get_position().x);
            float x_overlap = fabs(x_distance - (m_width / 2.0f) - (collidable_entity->get_width() / 2.0f));
            if (m_velocity.x > 0) {
                m_position.x -= x_overlap;
                m_velocity.x = 0;
                m_collided_right = true;
            }
            else if (m_velocity.x < 0) {
                m_position.x += x_overlap;
                m_velocity.x = 0;
                m_collided_left = true;
            }
        }
    }*/
}

bool const Entity::check_collision_x_player(Entity* other)
{
    if (check_collision(other))
    {
        float x_distance = fabs(m_position.x - other->get_position().x);
        float x_overlap = fabs(x_distance - (m_width / 2.0f) - (other->get_width() / 2.0f));
        if (m_velocity.x > 0) {
            std::cout << "Collided!\n";
            return true;
        }
        else if (m_velocity.x < 0) {
            std::cout << "Collided!\n";
            return true;
        }
    }
    return false;
}

bool const Entity::check_collision_y_player(Entity* other)
{
    if (check_collision(other))
    {
        float y_distance = fabs(m_position.y - other->get_position().y);
        float y_overlap = fabs(y_distance - (m_height / 2.0f) - (other->get_height() / 2.0f));
        if (m_velocity.y > 0) {
            m_position.y -= y_overlap;
            m_velocity.y = 0;
            return true;
        }
        else if (m_velocity.y < 0) {
            m_position.y += y_overlap;
            m_velocity.y = 0;
            return true;
        }
    }
    return false;
}
void Entity::render(ShaderProgram* program)
{
    /*if (get_ai_type() == ENEMY) {
        scale(glm::vec3(2.0f, 2.0f, 0.0f));
    }*/
    program->set_model_matrix(m_model_matrix);

    if (m_animation_indices != NULL)
    {
        draw_sprite_from_texture_atlas(program, m_texture_id, m_animation_indices[m_animation_index]);
        return;
    }
    /*if (get_entity_type() == ENEMY) {
        scale(glm::vec3(2.0f, 2.0f, 0.0f));
    }*/
    float vertices[] = { -0.5, -0.5, 0.5, -0.5, 0.5, 0.5, -0.5, -0.5, 0.5, 0.5, -0.5, 0.5 };
    float tex_coords[] = { 0.0,  1.0, 1.0,  1.0, 1.0, 0.0,  0.0,  1.0, 1.0, 0.0,  0.0, 0.0 };

    glBindTexture(GL_TEXTURE_2D, m_texture_id);

    glVertexAttribPointer(program->get_position_attribute(), 2, GL_FLOAT, false, 0, vertices);
    glEnableVertexAttribArray(program->get_position_attribute());
    glVertexAttribPointer(program->get_tex_coordinate_attribute(), 2, GL_FLOAT, false, 0, tex_coords);
    glEnableVertexAttribArray(program->get_tex_coordinate_attribute());

    glDrawArrays(GL_TRIANGLES, 0, 6);

    glDisableVertexAttribArray(program->get_position_attribute());
    glDisableVertexAttribArray(program->get_tex_coordinate_attribute());
}

bool const Entity::check_collision(Entity* other) const
{
    if (other == this) return false;
    // If either entity is inactive, there shouldn't be any collision
    if (!m_is_active || !other->m_is_active) return false;

    float x_distance = fabs(m_position.x - other->m_position.x) - ((m_width + other->m_width) / 2.0f);
    float y_distance = fabs(m_position.y - other->m_position.y) - ((m_height + other->m_height) / 2.0f);

    return x_distance < 0.0f && y_distance < 0.0f;
}
