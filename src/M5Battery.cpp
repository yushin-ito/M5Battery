#include "M5Battery.h"

M5Battery::M5Battery() {
    canvas = new M5Canvas(&M5.Display);
    _x = 0;
    _y = 0;
    _size = 3;
    _flip = false;
    _width = 12 * _size;
    _height = 5 * _size;
    _border_width = 2;
    _top_width = 1 * _size;
    _bg_color = canvas->color888(0, 0, 0);
    _border_color = canvas->color888(255, 255, 255);
}

void M5Battery::setCusor(int32_t x, int32_t y) {
    _x = x;
    _y = y;
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

    _width = 12 * _size;
    _height = 5 * _size;
    _top_width = 1 * _size;
}

void M5Battery::setBgColor(uint32_t color) { _bg_color = color; }

void M5Battery::setBorderColor(uint32_t color) { _border_color = color; }

void M5Battery::flip() { _flip = true; }

void M5Battery::showBattery() {
    _flag = true;
    drawBatteryShape();
    canvas->setColorDepth(16);
    canvas->createSprite(_width - _border_width * 2, _height - _border_width * 2);
}

void M5Battery::deleteBattery() {
    canvas->deleteSprite();
    canvas->createSprite(_width + _top_width, _height);
    canvas->fillSprite(_bg_color);
    canvas->pushSprite(_x, _y);
    canvas->deleteSprite();
    _flag = false;
}

void M5Battery::updateBattery() {
    if (!_flag) {
        return;
    }

    int32_t percent = M5.Power.getBatteryLevel();

    canvas->fillRect(0, 0, _width - _border_width * 2, _height - _border_width * 2, _bg_color);

    int32_t fill_width = int32_t((_width - _border_width * 2) * (percent / 100.0f));

    canvas->fillRect(0, 0, fill_width, _height - _border_width * 2, getBatteryColor());

    if (!_flip) {
        canvas->pushSprite(_x + _border_width + _top_width, _y + _border_width);
    }
    else {
        canvas->pushSprite(_x + _border_width, _y + _border_width);
    }   
}

void M5Battery::drawBatteryShape() {
    canvas->setColorDepth(1);
    canvas->createSprite(_width + _top_width, _height);
    canvas->fillSprite(0);

    if (!_flip) {
        canvas->fillRect(_top_width, 0, _width, _height, _border_color);
        canvas->fillRect(_top_width + _border_width, _border_width, _width - _border_width * 2, _height - _border_width * 2, 0);
        canvas->fillRect(0, _top_width, _top_width, _height - (_top_width * 2),
            _border_color);
    }
    else {
        canvas->fillRect(0, 0, _width, _height, _border_color);
        canvas->fillRect(_border_width, _border_width, _width - _border_width * 2, _height - _border_width * 2, 0);
        canvas->fillRect(_width, _top_width, _top_width, _height - (_top_width * 2),
            _border_color);
    }

    canvas->setBitmapColor(_border_color, 0);
    canvas->pushSprite(_x, _y, 0);
}

uint32_t M5Battery::getBatteryColor() {
    uint32_t color = canvas->color888(255, 255, 255);
    if (isLowBattery()) {
        color = canvas->color888(255, 0, 0);
    }
    else if (M5.Power.isCharging()) {
        color = canvas->color888(0, 255, 0);
    }
    return color;
}

bool M5Battery::isLowBattery() {
    int32_t percent = M5.Power.getBatteryLevel();
    if (percent > 20) {
        return false;
    }
    else {
        return true;
    }
}