#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "config.h"
#include "game.h"
#include "utils.h"

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) == false) {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        return 1;
    }

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    if (SDL_CreateWindowAndRenderer("PixelSim", SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer) == false) {
        SDL_Log("Window/Renderer creation failed: %s", SDL_GetError());
        return 1;
    }

    struct game_s* game = game_new();

    bool running = true;
    while (running) {
        Uint64 time_ms = SDL_GetTicks();

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT:
                    running = false;
                    break;

                case SDL_EVENT_KEY_DOWN:
                    game_keydown(game, event.key.key);
                    break;

                case SDL_EVENT_KEY_UP:
                    game_keyup(game, event.key.key);
                    break;
            }
        }

        game_update(game);
        game_render(game, renderer);

        Uint32 sleeping_time_ms = 16 - (SDL_GetTicks() - time_ms);
        sleeping_time_ms = MAX(0, sleeping_time_ms);
        SDL_Delay(sleeping_time_ms);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
