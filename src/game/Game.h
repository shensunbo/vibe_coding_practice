#ifndef SRC_GAME_GAME_H_
#define SRC_GAME_GAME_H_

#include "game/Character.h"

struct GLFWwindow;

namespace game {

enum class RoundResult {
  kInProgress,
  kPlayerWins,
  kAiWins,
  kDraw,
};

class Game {
 public:
  explicit Game(bool headless = false);
  ~Game();

  bool initialize();
  void run();

  Character& player() { return player_; }
  Character& ai() { return ai_; }
  int remaining_time_seconds() const { return remaining_time_seconds_; }

  void TickSecond();
  RoundResult GetRoundResult() const;

 private:
  void ProcessInput(float dt);
  void Update(float dt);
  void UpdateAI(float dt);
  void Render();
  void Shutdown();

  bool headless_;
  bool initialized_;
  GLFWwindow* window_;
  Character player_;
  Character ai_;
  int remaining_time_seconds_;
  double last_frame_time_;
  double time_accumulator_;
  float attack_cooldown_;
  float ai_attack_cooldown_;
  float ai_move_direction_;
};

}  // namespace game

#endif  // SRC_GAME_GAME_H_
