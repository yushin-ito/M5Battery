#include <M5Unified.h>

class M5Battery {
private:
  const uint8_t MAX_SIZE = 7;
  const uint8_t MIN_SIZE = 1;

  M5Canvas* canvas;
  bool _flag = true;
  int32_t _x;
  int32_t _y;
  size_t _size;
  int32_t _width;
  int32_t _height;
  int32_t _top_width;
  uint32_t _bg_color;
  uint32_t _border_color;

  void drawBatteryShape();
  uint32_t getBatteryColor();

public:
  M5Battery();
  void setCusor(int32_t x, int32_t y);
  void setSize(size_t size);
  void setBgColor(uint32_t color);
  void setBorderColor(uint32_t color);
  void showBattery();
  void deleteBattery();
  void updateBattery();
  bool isLowBattery();
};