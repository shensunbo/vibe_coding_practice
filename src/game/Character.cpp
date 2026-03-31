#include "game/Character.h"

#include <cmath>

namespace game {

Character::Character(int max_health, float position_x)
    : health_(max_health), max_health_(max_health), position_x_(position_x) {}

void Character::Move(float delta_x) { position_x_ += delta_x; }

bool Character::InRange(const Character& target, const Attack& attack) const {
  return std::fabs(target.position_x() - position_x_) <= attack.range;
}

bool Character::TryAttack(Character* target, AttackType type) {
  if (target == nullptr || is_ko()) {
    return false;
  }

  const Attack attack = MakeAttack(type);
  if (!InRange(*target, attack)) {
    return false;
  }

  target->TakeDamage(attack.damage);
  return true;
}

void Character::TakeDamage(int damage) {
  if (damage < 0) {
    return;
  }
  health_ -= damage;
  if (health_ < 0) {
    health_ = 0;
  }
}

}  // namespace game
