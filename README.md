<h1>M5Battery</h1>

<div align="left">
  <img src="https://img.shields.io/badge/version-0.0.1-red.svg">
  <img src="https://img.shields.io/github/actions/workflow/status/yushin-ito/M5Battery/build.yml">
  <img src="https://img.shields.io/github/stars/yushin-ito/M5Battery?color=yellow">
  <img src="https://img.shields.io/github/commit-activity/t/yushin-ito/M5Battery">
  <img src="https://img.shields.io/badge/license-MIT-green">
</div>

<br>

<h2>📝 Overview</h2>
An M5Stack library for displaying battery charge.

<br>
<br>

<h2>🚀 Features</h2>
<ul>
  <li>Display battery charge</li>
  <li>Customize size and rotation</li>
</ul>
<br>
<div align="center">
  <img src="https://github.com/yushin-ito/M5Battery/assets/75526539/b1e6bdbb-6da7-4f03-a09a-3ff254dc0549" width="80%"/>
</div>

<br>

<h2>📦 Installation</h2>
<a href="https://open.vscode.dev/yushin-ito/M5Battery">
  <img src="https://img.shields.io/static/v1?logo=visualstudiocode&label=&message=Open%20in%20Visual%20Studio%20Code&labelColor=2c2c32&color=007acc&logoColor=007acc">
</a>
<br>
<br>
<ol>
  <li>Initialize your Platform IO project</li>

```powershell
platformio init -d . -b m5stack-core-esp32
```

  <li>Install the library and its dependency</li>

```powershell
platformio lib install M5Battery
platformio lib install M5Unified
```

</ol>

<h2>🔧 Usage</h2>

> **Warning**
> This library has been tested only with M5Stack and M5StickC-PLUS.

<br>

```cpp
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
```

<p>You can also read the <a href="https://github.com/yushin-ito/M5Battery/blob/main/doc/BASIC.md">module doc</a> for a list of supported calls.</p>

<br>

<h2>👀 Author</h2>
<a href="https://github.com/yushin-ito">Yushin Ito</a>

<br>
<br>

<h2>📜 License</h2>
<a href="https://github.com/yushin-ito/M5Battery/blob/main/LICENSE">MIT License</a>
