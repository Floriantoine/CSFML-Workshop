![SFML](https://www.sfml-dev.org/images/logo.png)

# Sprite & Texture 

[![Sprite & Texture Link]](https://www.sfml-dev.org/tutorials/2.5/graphics-sprite-fr.php)
[![Sprite github Link]](https://github.com/SFML/CSFML/blob/master/include/SFML/Graphics/Sprite.h)
[!(Texture github Link)](https://github.com/SFML/CSFML/blob/master/include/SFML/Graphics/Texture.h)

## sfTexture_createFromFile("char *", NULL)

    - Brief:
        Create a new texture from a file
    - Param:
        1)filename Path of the image file to load
        2)Area of the source image to load (NULL to load the entire image)
    - Return:
        A new sfTexture object, or NULL if it failed

---

## sfSprite_create()

    - Brief:
        Create a new sprite
    - Return:
        A new sfSprite object, or NULL if it failed

---

## sfSprite_setTexture(sprite, texture, sfFalse)
    - Brief:
        Set the sub-rectangle of the texture that a sprite will display
    - Param:
        1) sprite Sprite object
        2) rectangle Rectangle defining the region of the texture to display

---

## sfRenderWindow_drawSprite(window, sprite, NULL)
    - Brief:
    - Param:
    - Return:
---

## sfSprite_setPosition(sprite, newPos)
    - Brief:
    - Param:
    - Return:
---

**other sprite function**:
https://www.sfml-dev.org/documentation/2.5.1-fr/classsf_1_1Sprite.php


