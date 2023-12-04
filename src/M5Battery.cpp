#include "M5Battery.h"

static TaskHandle_t drawTaskHandle;

Context::Context(M5Battery* bat) {
    _bat = bat;
}

M5Battery* Context::getBattery() {
    return _bat;
}

static void drawLoop(void* args) {
    Context* ctx = reinterpret_cast<Context*>(args);
    M5Battery* bat = ctx->getBattery();

    while (bat->isDrawing() || bat->isChanged()) {
        if (bat->isDrawing()) {
            bat->drawBattery();
        }
        if (bat->isChanged()) {
            M5.Display.clear();
            bat->setChanged(false);
        }
        vTaskDelay(1);
    }
    vTaskDelete(NULL);
}


M5Battery::M5Battery() {
    canvas = new M5Canvas(&M5.Lcd);
    _drawing = false;
    _changed = false;
    _x = 0;
    _y = 0;
    _rotation = 0;
    _size = 3;
    _border_width = 2;
    _bg_color = canvas->color888(0, 0, 0);
    _border_color = canvas->color888(255, 255, 255);
}

void M5Battery::setPosition(int32_t x, int32_t y) {
    _x = x;
    _y = y;
    _changed = true;
}

void M5Battery::setRotation(uint8_t rotation) {
    _rotation = rotation;
    _changed = true;
}

void M5Battery::setSize(size_t size) {
    if (MAX_SIZE < size) {
        _size = MAX_SIZE;
    }
    else if (size < MIN_SIZE) {
        _size = MIN_SIZE;
    }
    else {
        _size = size;
    }
    _changed = true;
}

void M5Battery::setBgColor(uint32_t color) {
    _bg_color = color;
    _changed = true;
}

void M5Battery::setBorderColor(uint32_t color) {
    _border_color = color;
    _changed = true;
}

void M5Battery::init(int32_t x, int32_t y) {
    _x = x;
    _y = y;

    show();
}

void M5Battery::show() {
    Context* ctx = new Context(this);

    if (_drawing) return;
    _drawing = true;

    xTaskCreateUniversal(drawLoop,
        "drawLoop",
        2048,
        ctx,
        3,
        &drawTaskHandle,
        APP_CPU_NUM);
}

void M5Battery::hide() {
    _drawing = false;
    _changed = true;
}

bool M5Battery::isDrawing() {
    return _drawing;
}

bool M5Battery::isChanged() {
    return _changed;
}

void M5Battery::setChanged(bool changed) {
    _changed = changed;
}

void M5Battery::drawBattery() {
    _width = 12 * _size;
    _height = 5 * _size;
    _top_width = 1 * _size;

    int32_t _sprite_width = _width + _top_width;
    int32_t _sprite_height = _height;

    canvas->createSprite(_sprite_width, _sprite_height);

    canvas->fillRect(_top_width, 0, _width, _height, _border_color);
    canvas->fillRect(_top_width + _border_width, _border_width, _width - _border_width * 2, _height - _border_width * 2, 0);
    canvas->fillRect(0, _top_width, _top_width, _height - (_top_width * 2), _border_color);

    int32_t _percent = M5.Power.getBatteryLevel();
    int32_t _fill_width = int32_t((_width - _border_width * 2) * (_percent / 100.0f));
    canvas->fillRect(_sprite_width - _fill_width - _border_width, _border_width, _fill_width, _height - _border_width * 2, getBatteryColor());

    canvas->pushRotateZoom(&M5.Display, _x + _sprite_width / 2, _y + _sprite_height / 2, _rotation * 90, 1.0, 1.0);

    canvas->deleteSprite();
}

uint32_t M5Battery::getBatteryColor() {
    uint32_t _color = canvas->color888(255, 255, 255);
    if (isWarning()) {
        _color = canvas->color888(255, 0, 0);
    }
    else if (isCharging()) {
        _color = canvas->color888(0, 255, 0);
    }
    return _color;
}

bool M5Battery::isWarning() {
    int32_t percent = M5.Power.getBatteryLevel();
    if (percent > 20) {
        return false;
    }
    else {
        return true;
    }
}

bool M5Battery::isCharging() {
    return M5.Power.isCharging() == 1;
}