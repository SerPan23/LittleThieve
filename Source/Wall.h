#ifndef WALL_H_INCLUDED
#define WALL_H_INCLUDED
#include "LittleThieve.h"
#include "TextureFuncs.h"
#include "ObjectData.h"

class Wall
{
    public:
        //short id;
        //int x, y;
        //int w, h;
        int depth;
        //vector <vector<SDL_Color> > texture;

        ObjectData objData;

        /*Wall(short id, int x, int y, int w, int h, int depth, int r, int g, int b, bool type)
        {
            this->id = id;
            this->x = x;
            this->y = y;
            this->w = w;
            this->h = h;
            this->depth = depth;
            this->r = r;
            this->g = g;
            this->b = b;
            this->type = type;
        }*/
        Wall(short id, int x, int y, int w, int h, int depth)
        {
            this->objData.id = id;
            this->objData.x = x;
            this->objData.y = y;
            this->objData.width = w;
            this->objData.height = h;
            this->depth = depth;
        }
        void    drawWall(SDL_Renderer *renderer)
        {
            /*if(type)
            {
                for(int i = 0; i < w / depth; i++){
                    //filled_rect(renderer, i*depth + x, y, depth, depth, r, g, b);
                    //filled_rect(renderer, i*depth + x, h, depth, depth, r, g, b);
                    drawTexture(this->texture, renderer, i*depth + x, y);
                    drawTexture(this->texture, renderer, i*depth + x, h);
                }
                for(int i = 0; i < h / depth; i++)
                {
                    //filled_rect(renderer, x, i*depth + y, depth, depth, r, g, b);
                    //filled_rect(renderer, w, i*depth + y, depth, depth, r, g, b);
                    drawTexture(this->texture, renderer, x, i*depth + y);
                    drawTexture(this->texture, renderer, w, i*depth + y);
                }
            }*/
                if(depth == objData.width)
                    for(int i = 0; i < objData.height / depth; i++)
                        //filled_rect(renderer, x, i*depth + y, depth, depth, r, g, b);
                        drawTexture(this->objData.texture, renderer, objData.x, i*depth + objData.y);
                else
                    for(int i = 0; i < objData.width / depth; i++)
                        //filled_rect(renderer, i*depth + x, y, depth, depth, r, g, b);
                        drawTexture(this->objData.texture, renderer, i*depth + objData.x, objData.y);
        }
};

#endif // WALL_H_INCLUDED
