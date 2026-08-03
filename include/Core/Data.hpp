#include <raylib.h>

#include <cstdint>

enum class JOINTS {
  HEAD,
  TOP,
  MID_LEFT,
  MID_RIGHT,
  BOT_LEFT,
  BOT_RIGHT,
};

enum DATA : uint8_t {
  HEAD      = 1 << 0,
  TOP       = 1 << 1,
  MID_LEFT  = 1 << 2,
  MID_RIGHT = 1 << 3,
  BOT_LEFT  = 1 << 4,
  BOT_RIGHT = 1 << 5,
};
