/*
** sprites for cpp_arcade
**
** Made by pirou_g in /home/pirou_g/ClionProjects/cpp_arcade
** Login   <pirou_g@epitech.net>
**
** Started on     29/03/16 11:57
** Last update on 29/03/16 11:57
*/

#ifndef CPP_ARCADE_SPRITES_H
#define CPP_ARCADE_SPRITES_H

typedef struct CSprite {
    unsigned int 	 width;
    unsigned int 	 height;
    unsigned int 	 bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */
    unsigned char	 pixel_data[64 * 64 * 3 + 1];
} CSprite;

extern const CSprite pacmanDot;
extern const CSprite pacmanPowerUp;
extern const CSprite pacmanGround;
extern const CSprite pacmanWall;
extern const CSprite apple;
extern const CSprite snakeGround;
extern const CSprite snakeWall;
extern const CSprite snakeHead;
extern const CSprite snakeBody;
extern const CSprite pacman;
extern const CSprite ghost;

#endif //CPP_ARCADE_SPRITES_H
