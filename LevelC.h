#include "Scene.h"

class LevelC : public Scene {
public:
    // ————— STATIC ATTRIBUTES ————— //
    int ENEMY_COUNT = 60;

    // ————— CONSTRUCTOR ————— //
    ~LevelC();

    // ————— METHODS ————— //
    void initialise() override;
    void update(float delta_time) override;
    void render(ShaderProgram* program) override;
    int  const getNoteCount() { return ENEMY_COUNT; }
};