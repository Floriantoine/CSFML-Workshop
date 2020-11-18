# RenderWindow


https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RenderWindow.php


sfVideoMode mode:

typedef struct
{
  unsigned int width;        ///< Video mode width, in pixels
  unsigned int height;       ///< Video mode height, in pixels
  unsigned int bitsPerPixel; ///< Video mode pixel depth, in bits per pixels
} sfVideoMode;

---

sfRenderWindow *window = sfRenderWindow_create(mode, "HUNTER", sfResize | sfClose, NULL); // create window
