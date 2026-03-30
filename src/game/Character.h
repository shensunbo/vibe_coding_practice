// Character.h - Character class for 2D fighting game

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

enum CharacterState {
    CHARACTER_STATE_IDLE,
    CHARACTER_STATE_MOVING,
    CHARACTER_STATE_ATTACKING,
    CHARACTER_STATE_DEFENDING,
    CHARACTER_STATE_HIT,
    CHARACTER_STATE_DEAD
};

enum CharacterDirection {
    DIRECTION_LEFT,
    DIRECTION_RIGHT
};

class Character {
public:
    Character(const std::string& name, float x, float y);
    ~Character();

    void update(float deltaTime);
    void render();

    // Movement
    void moveLeft(float speed);
    void moveRight(float speed);
    void jump();

    // Actions
    void attack();
    void defend();
    void useSkill(int skillIndex);

    // Getters and setters
    const std::string& getName() const;
    float getX() const;
    float getY() const;
    float getHealth() const;
    float getEnergy() const;
    CharacterState getState() const;
    CharacterDirection getDirection() const;

    void setX(float x);
    void setY(float y);
    void setHealth(float health);
    void setEnergy(float energy);
    void setState(CharacterState state);
    void setDirection(CharacterDirection direction);

    // Collision detection
    bool checkCollision(const Character& other) const;

    // Damage handling
    void takeDamage(float damage);

private:
    std::string name;
    float x, y;
    float width, height;
    float health;
    float maxHealth;
    float energy;
    float maxEnergy;
    CharacterState state;
    CharacterDirection direction;
    float velocityX, velocityY;
    bool isJumping;
};

#endif // CHARACTER_H
