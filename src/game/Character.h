#ifndef SRC_GAME_CHARACTER_H_
#define SRC_GAME_CHARACTER_H_

#include "game/Attack.h"

namespace game {

class Character {
 public:
  Character(int max_health, float position_x);

  int health() const { return health_; }
  int max_health() const { return max_health_; }
  float position_x() const { return position_x_; }
  bool is_ko() const { return health_ <= 0; }

  void Move(float delta_x);
  bool InRange(const Character& target, const Attack& attack) const;
  bool TryAttack(Character* target, AttackType type);
  void TakeDamage(int damage);

 private:
  int health_;
  int max_health_;
  float position_x_;
};

}  // namespace game

#endif  // SRC_GAME_CHARACTER_H_
