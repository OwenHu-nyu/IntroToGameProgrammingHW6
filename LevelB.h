#include "Scene.h"

class LevelB : public Scene {
public:
    // ————— STATIC ATTRIBUTES ————— //
    int ENEMY_COUNT = 30;

    // ————— CONSTRUCTOR ————— //
    ~LevelB();

    // ————— METHODS ————— //
    void initialise() override;
    void update(float delta_time) override;
    void render(ShaderProgram* program) override;
    int  const getNoteCount() { return ENEMY_COUNT; }
};