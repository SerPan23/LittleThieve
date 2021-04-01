#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED


class Player{
    public:
        int x;
        int y;
        int width = 48;
        int height = 48;
        int y;
        int speed = 3;

        void movePlayer(SDL_Event event)
        {
            if (event.key.keysym.scancode == SDL_SCANCODE_UP || event.key.keysym.scancode == SDL_SCANCODE_W)
            {
                y -= speed;
            }

            if (event.key.keysym.scancode == SDL_SCANCODE_DOWN || event.key.keysym.scancode == SDL_SCANCODE_S)
            {
                y += speed;
            }

            if (event.key.keysym.scancode == SDL_SCANCODE_LEFT || event.key.keysym.scancode == SDL_SCANCODE_A)
            {
                x -= speed;
            }

            if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT || event.key.keysym.scancode == SDL_SCANCODE_D)
            {
                x += speed;
            }
        }
};


#endif // PLAYER_H_INCLUDED
