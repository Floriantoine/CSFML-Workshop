![SFML](https://www.sfml-dev.org/images/logo.png)

# RenderWindow

[![RenderWindow Link]](https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RenderWindow.php)

## sfVideoMode mode:

```c
typedef struct
{
  unsigned int width;        ///< Video mode width, in pixels
  unsigned int height;       ///< Video mode height, in pixels
  unsigned int bitsPerPixel; ///< Video mode pixel depth, in bits per pixels
} sfVideoMode;
```
---

## sfRenderWindow_create:

```c
sfRenderWindow *window = sfRenderWindow_create(mode, "HUNTER", sfResize | sfClose, NULL);
```
    - Arg1: Video mode to use 
    - Arg2: Window Title
    - Arg3: Window style
    - Arg4: settings Additional settings for the underlying OpenGL context

---

## sfRenderWindow_clear(sfRenderWindow *, sfColor)

>apply a color to the whole screen

---


## sfRenderWindow_isOpen(sfRenderWindow *)

>return True if the window is Open else False

---

## sfRenderWindow_close(sfRenderWindow *);

> Close a window and destroy all the attached resources

