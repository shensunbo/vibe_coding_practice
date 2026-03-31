#include "game/Attack.h"

namespace game {

Attack MakeAttack(AttackType type) {
  switch (type) {
    case AttackType::kLight:
      return Attack{type, 8, 1.2f};
    case AttackType::kHeavy:
      return Attack{type, 14, 1.6f};
    case AttackType::kSpecial:
      return Attack{type, 20, 2.0f};
  }

  return Attack{AttackType::kLight, 8, 1.2f};
}

}  // namespace game
