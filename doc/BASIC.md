# Basics

- [Basics](#basics)
  - [Instance Basics](#instance-basics)
    - [Create a instance](#create-a-instance)
  - [Functions Basic](#functions-basic)
    - [bat.setCusor(x, y) => void](#batsetcusorx-y--void)
    - [bat.setSize(size) => void](#batsetsizesize--void)
    - [bat.setBgColor(color) => void](#batsetbgcolorcolor--void)
    - [bat.setBorderColor(color) => void](#batsetbordercolorcolor--void)
    - [bat.flip() => void](#batflip--void)
    - [bat.showBattery() => void](#batshowbattery--void)
    - [bat.deleteBattery() => void](#batdeletebattery--void)
    - [bat.updateBattery() => void](#batupdatebattery--void)
    - [bat.isLowBattery() => bool](#batislowbattery--bool)

## Instance Basics

### Create a instance

Include the `M5Battery.h` and `M5Unified`

```c
#include <M5Unified.h>
#include <M5Battery.h>
```

Then Instanciate

```c
M5Battery bat;
```

Your instance is now ready.

## Functions Basic

Call the fuctions using the created instance.

### bat.setCusor(x, y) => void

Set position of battery box.

Kind: instance method of `M5Battery`

| Param |  Type   |
| :---: | :-----: |
|   x   | int32_t |
|   y   | int32_t |

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

### bat.flip() => void

Flip battery box.

Kind: instance method of `M5Battery`

### bat.showBattery() => void

Show battery.

Kind: instance method of `M5Battery`

### bat.deleteBattery() => void

Delete battery.

Kind: instance method of `M5Battery`

### bat.updateBattery() => void

Update battery.

Kind: instance method of `M5Battery`

### bat.isLowBattery() => bool

Get if the battery is low.

Kind: instance method of `M5Battery`
