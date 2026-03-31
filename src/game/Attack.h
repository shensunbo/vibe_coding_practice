#ifndef SRC_GAME_ATTACK_H_
#define SRC_GAME_ATTACK_H_

namespace game {

enum class AttackType {
  kLight,
  kHeavy,
  kSpecial,
};

struct Attack {
  AttackType type;
  int damage;
  float range;
};

Attack MakeAttack(AttackType type);

}  // namespace game

#endif  // SRC_GAME_ATTACK_H_
