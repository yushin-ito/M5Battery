#ifndef M5Battery_H
#define M5Battery_H
#include <M5Unified.h>

class M5Battery {
private:
  const uint8_t MAX_SIZE = 7;
  const uint8_t MIN_SIZE = 1;

  M5Canvas* canvas;
  bool _drawing;
  bool _changed;
  int32_t _x;
  int32_t _y;
  uint8_t _rotation;
  size_t _size;
  int32_t _width;
  int32_t _height;
  int32_t _border_width;
  int32_t _top_width;
  uint32_t _bg_color;
  uint32_t _border_color;

public:
  M5Battery();
  void setPosition(int32_t x, int32_t y);
  void setRotation(uint8_t rotation);
  void setSize(size_t size);
  void setBgColor(uint32_t color);
  void setBorderColor(uint32_t color);
  void init(int32_t x, int32_t y);
  void show();
  void hide();
  bool isDrawing();
  bool isChanged();
  void setChanged(bool changed);
  void drawBattery();
  uint32_t getBatteryColor();
  bool isWarning();
  bool isCharging();
};

#endif // M5Battery_H

#ifndef CONTEXT_H
#define CONTEXT_H

class Context {
private:
  M5Battery* _bat;

public:
  Context(M5Battery* bat);
  M5Battery* getBattery();
};
#endif // CONTEXT_H