#include "board.hpp"

Board::Board()
{
    int side = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i == 0 || i == 1)
                side = BLACK;
            else if (i == 6 || i == 7)
                side = WHITE;

            if (i == 0 || i == 7)
            {
                if (j == 0)
                    tiles[i][j].piece = new Rook(side);
                else if (j == 1)
                    tiles[i][j].piece = new Knight(side);
                else if (j == 2)
                    tiles[i][j].piece = new Bishop(side);
                else if (j == 3)
                    tiles[i][j].piece = new Queen(side);
                else if (j == 4)
                    tiles[i][j].piece = new King(side);
                else if (j == 5)
                    tiles[i][j].piece = new Bishop(side);
                else if (j == 6)
                    tiles[i][j].piece = new Knight(side);
                else
                    tiles[i][j].piece = new Rook(side);
            }
            else if (i == 1 || i == 6)
            {
                tiles[i][j].piece = new Pawn(side);
            }
            else
            {
                tiles[i][j].piece = nullptr;
            }

            tiles[i][j].square.w = 60;
            tiles[i][j].square.h = 60;
           /*
            tiles[i][j].picture_square.w = 60 * 0.8;
            tiles[i][j].picture_square.h = 60 * 0.8;
           */
        }
    }

    int x_pos = (800 / 2) - (4 * 60);
    int y_pos = (600 / 2) - (4 * 60);
  
    
/*
    int x_p_pos = x_pos * 1.05;
    int y_p_pos = y_pos * 1.1;
*/

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            tiles[i][j].square.x = x_pos;
            tiles[i][j].square.y = y_pos;
            /*
            tiles[i][j].picture_square.x =
            tiles[i][j].square.x + (tiles[i][j].square.w - tiles[i][j].picture_square.w) / 2;

            tiles[i][j].picture_square.y =
            tiles[i][j].square.y + (tiles[i][j].square.h - tiles[i][j].picture_square.h) / 2;
            */
            x_pos += 60;
        }
        y_pos += 60;
        x_pos = (800 / 2) - (4 * 60);
    }
}

void Board::drawBoard(SDL_Renderer* renderer)
{
    SDL_Rect border;
    border.x = (800 / 2) - (4 * 60) - 15;
    border.y = (600 / 2) - (4 * 60) - 15;
    border.w = 60 * 8 + 30;
    border.h = 60 * 8 + 30;

    SDL_SetRenderDrawColor(renderer,149,83,59, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer,60,60,60, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer,&border);

    SDL_Rect inner_board;
    inner_board.x = (800 / 2) - (4 * 60);
    inner_board.y = (600 / 2) - (4 * 60);
    inner_board.w = 60 * 8;
    inner_board.h = 60 * 8;

    SDL_SetRenderDrawColor(renderer,149,83,59, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer,&inner_board);

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((i + j) % 2 == 0)
            {
                if (tiles[i][j].colour == SELECT)
                    SDL_SetRenderDrawColor(renderer, 130, 255, 130, SDL_ALPHA_TRANSPARENT);
                else if (tiles[i][j].colour == DANGER)
                    SDL_SetRenderDrawColor(renderer, 255, 130, 130, SDL_ALPHA_TRANSPARENT);
                else if (tiles[i][j].colour == CHECK)
                    SDL_SetRenderDrawColor(renderer, 140, 10, 10, SDL_ALPHA_OPAQUE);
                else
                    SDL_SetRenderDrawColor(renderer,251,194,115, SDL_ALPHA_OPAQUE);

                SDL_RenderFillRect(renderer, &(tiles[i][j].square));
            }
            else
            {
                if (tiles[i][j].colour == SELECT)
                {
                    SDL_SetRenderDrawColor(renderer, 130, 255, 130, SDL_ALPHA_TRANSPARENT);
                    SDL_RenderFillRect(renderer, &(tiles[i][j].square));
                }
                else if (tiles[i][j].colour == DANGER)
                {
                    SDL_SetRenderDrawColor(renderer, 255, 130, 130, SDL_ALPHA_TRANSPARENT);
                    SDL_RenderFillRect(renderer, &(tiles[i][j].square));
                }
                else if (tiles[i][j].colour == CHECK)
                {
                    SDL_SetRenderDrawColor(renderer, 140, 10, 10, SDL_ALPHA_OPAQUE);
                    SDL_RenderFillRect(renderer, &(tiles[i][j].square));
                }
                else
                {
                    SDL_SetRenderDrawColor(renderer,251,194,115, SDL_ALPHA_OPAQUE);
                    SDL_RenderDrawRect(renderer, &(tiles[i][j].square));
                }
            }

            if (tiles[i][j].piece != nullptr && tiles[i][j].piece->image != nullptr)
            {
                if (tiles[i][j].piece->texture == nullptr)
                {
                    tiles[i][j].piece->texture = SDL_CreateTextureFromSurface(renderer, tiles[i][j].piece->image);
                    SDL_SetTextureScaleMode(tiles[i][j].piece->texture, SDL_ScaleModeLinear);
                }
                SDL_RenderCopy(renderer, tiles[i][j].piece->texture, NULL, &(tiles[i][j].square));
            }
        }
    }

    SDL_RenderPresent(renderer);
}

void Board::resetTileColours()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            tiles[i][j].colour = NORMAL;
}