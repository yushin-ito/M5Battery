# Basics

- [Basics](#basics)
  - [Instance Basics](#instance-basics)
    - [Create a instance](#create-a-instance)
  - [Functions Basic](#functions-basic)
    - [bat.setPosition(x, y) => void](#batsetpositionx-y--void)
    - [bat.setRotation(rotation) => void](#batsetrotationrotation--void)
    - [bat.setSize(size) => void](#batsetsizesize--void)
    - [bat.setBgColor(color) => void](#batsetbgcolorcolor--void)
    - [bat.setBorderColor(color) => void](#batsetbordercolorcolor--void)
    - [bat.init(x, y) => void](#batinitx-y--void)
    - [bat.show() => void](#batshow--void)
    - [bat.hide() => void](#bathide--void)
    - [bat.isDrawing() => bool](#batisdrawing--bool)
    - [bat.isChanged() => bool](#batischanged--bool)
    - [bat.drawBattery() => void](#batdrawbattery--void)
    - [bat.getBatteryColor() => uint32_t](#batgetbatterycolor--uint32_t)
    - [bat.isWarning() => bool](#batiswarning--bool)
    - [bat.isCharging() => bool](#batischarging--bool)

## Instance Basics

### Create a instance

Include the `M5Battery.h` and `M5Unified`

```c++
#include <M5Unified.h>
#include <M5Battery.h>
```

Then Instanciate

```c++
M5Battery bat;
```

Your instance is now ready.

## Functions Basic

Call the fuctions using the created instance.

### bat.setPosition(x, y) => void

Set position of battery box.

Kind: instance method of `M5Battery`

| Param |  Type   |
| :---: | :-----: |
|   x   | int32_t |
|   y   | int32_t |

### bat.setRotation(rotation) => void

Set rotation of battery box.

Kind: instance method of `M5Battery`

|  Param   |  Type   |
| :------: | :-----: |
| rotation | uint8_t |

### bat.setSize(size) => void

Set size(1~7) of battery box.

Kind: instance method of `M5Battery`

| Param |  Type  |
| :---: | :----: |
| size  | size_t |

### bat.setBgColor(color) => void

Set bg color of battery box.

Kind: instance method of `M5Battery`

| Param |   Type   |
| :---: | :------: |
| color | uint32_t |

### bat.setBorderColor(color) => void

Set border color of battery box.

Kind: instance method of `M5Battery`

| Param |   Type   |
| :---: | :------: |
| color | uint32_t |

### bat.init(x, y) => void

Initialize battery with position.

Kind: instance method of `M5Battery`

| Param |  Type   |
| :---: | :-----: |
|   x   | int32_t |
|   y   | int32_t |

### bat.show() => void

Show battery.

Kind: instance method of `M5Battery`

### bat.hide() => void

Hide battery.

Kind: instance method of `M5Battery`

### bat.isDrawing() => bool

Get if the battery is drawing.

Kind: instance method of `M5Battery`

### bat.isChanged() => bool

Get if the battery style is changed.

Kind: instance method of `M5Battery`

### bat.drawBattery() => void

Display battery.

Kind: instance method of `M5Battery`

### bat.getBatteryColor() => uint32_t

Get battery color.

Kind: instance method of `M5Battery`

### bat.isWarning() => bool

Get if the battery is low.

Kind: instance method of `M5Battery`

### bat.isCharging() => bool

Get if the battery is charging.

Kind: instance method of `M5Battery`
