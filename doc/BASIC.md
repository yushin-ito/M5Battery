# Basics

- [Basics](#basics)
  - [Instance Basics](#instance-basics)
    - [Create a instance](#create-a-instance)
  - [Functions Basic](#functions-basic)
    - [ts.Cusor(x, y, scroll_pixel) => void](#tssetcusorx-y-scroll_pixel--void)
    - [ts.setTextFont(font) => void](#tssettextfontfont--void)
    - [ts.setBgColor(color) => void](#tssetbgcolorcolor--void)
    - [ts.setTextColor(color) => void](#tssettextcolorcolor--void)
    - [ts.setText(text) => void](#tssettexttext--void)
    - [ts.showTextScroll() => void](#tsshowtextscroll--void)
    - [ts.getScrollCount() => void](#tsgetscrollcount--uint8_t)

## Instance Basics

### Create a instance

Include the `M5TextScroll.h` and `M5Unified`

```c
#include <M5Unified.h>
#include <M5TextScroll.h>
```

Then Instanciate

```c
M5TextScroll ts;
```

Your instance is now ready.

## Functions Basic

Call the fuctions using the created instance.

### ts.setCusor(x, y, scroll_pixel) => void

Set position and speed of text scroll box.
Kind: instance method of `M5TextScroll`

|    Param     |  Type   |
| :----------: | :-----: |
|      x       | int32_t |
|      y       | int32_t |
| scroll_pixel | uint8_t |

### ts.setTextFont(font) => void

Set font of text.
Kind: instance method of `M5TextScroll`

| Param |     Type      |
| :---: | :-----------: |
| font  | lgfx::IFont\* |

### ts.setBgColor(color) => void

Set bg color of text scroll box.
Kind: instance method of `M5TextScroll`

| Param |   Type   |
| :---: | :------: |
| color | uint32_t |

### ts.setTextColor(color) => void

Set bg color of text.
Kind: instance method of `M5TextScroll`

| Param |   Type   |
| :---: | :------: |
| color | uint32_t |

### ts.setText(text) => void

Set scrolling text.
Kind: instance method of `M5TextScroll`

| Param |     Type     |
| :---: | :----------: |
| text  | const chat\* |

### ts.showTextScroll() => void

Show text scroll.
Kind: instance method of `M5TextScroll`

### ts.getScrollCount() => uint8_t

Get scrolling count.
Kind: instance method of `M5TextScroll`
