#include "Scene.h"

class LevelD : public Scene {
public:
    // ����� STATIC ATTRIBUTES ����� //
    int ENEMY_COUNT = 180;

    // ����� CONSTRUCTOR ����� //
    ~LevelD();

    // ����� METHODS ����� //
    void initialise() override;
    void update(float delta_time) override;
    void render(ShaderProgram* program) override;
    int  const getNoteCount() { return ENEMY_COUNT; }
};