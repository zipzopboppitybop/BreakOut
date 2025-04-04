#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "MyRectangle.h"

// Global Variables
int screenWidth = 1280;
int screenHeight = 1040;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
int isRunning = 1;
// example
struct My_rectangle rectangle = { 100, 100, 200, 150 };
int rectSpeed = 5;

// Initialize SDL
int initSDL() {
    // Error Message if fail to initialize
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    // Create Window
    window = SDL_CreateWindow("SDL3 Template", screenWidth, screenHeight, 0);
    if (!window) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    // Create Renderer
    renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    return 1;
}

// Handle Events
void handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type)
        {
        case SDL_EVENT_QUIT:
            {
                isRunning = 0;
                break;
            }
        }
    }
}

// Update Game Logic
void update() {
    // Example
    rectangle.x += rectSpeed;

    if (rectangle.x + rectangle.w > screenWidth)
    {
        rectSpeed *= -1;
    }

    if (rectangle.x < 0)
    {
        rectSpeed *= -1;
    }
}

// Render Graphics
void render() {
    // Clear screen with black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  
    SDL_RenderClear(renderer);

    // Draw a white rectangle
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // Create rectangle with my_rectangle struct
    SDL_FRect rect = { rectangle.x, rectangle.y, rectangle.w, rectangle.h };
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer);
}

// Clean Up SDL
void cleanup() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

// Main Function
int main(int argc, char* argv[]) {
    if (!initSDL()) {
        return -1;
    }

    while (isRunning) {
        handleEvents();
        update();
        render();
        // Limit to 60 FPS
        SDL_Delay(16); 
    }

    // Example
    print_rectangle(&rectangle);

    cleanup();
    return 0;
}