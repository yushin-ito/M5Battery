#include <M5Unified.h>
#include <M5Battery.h>

M5Battery bat;

void setup() {
    auto cfg = M5.config();
    M5.begin(cfg);

    bat.init(0, 0);
}

void loop() {
    M5.update();
    
    if (M5.BtnA.wasPressed()) {
        if (bat.isDrawing()) {
            bat.hide();
        }
        else {
            bat.show();
        }
    }

    if (M5.BtnB.wasPressed()) {
        bat.setPosition(random(0, M5.Display.width()), random(0, M5.Display.height()));
        bat.setRotation(random(0, 3));
        bat.setSize(random(1, 7));
    }

    delay(100);
}