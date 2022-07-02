#include "raylib.h"
#include <stdio.h>

const int WIDTH = 800;
const int HEIGHT = 700;
/* const float G = 6.67 / 1e11; */
const float G = 0.001f;

typedef struct Planet {
    int radius;
    int mass;
    Vector2 pos;
    Vector2 vel;
    Vector2 acc;

}Planet;

/* void PlacePlanet(int MouseX, int MouseY){ */
/*     Planet Planet3; */
/*     Planet3.radius = 10; */
/*     Planet3.mass = 10; */
/*     Planet3.pos.x = MouseX; */
/*     Planet3.pos.y = MouseY; */
/*     Planet3.vel.x = 1; */
/*     Planet3.vel.y = 0.1f; */

/*     DrawCircle((float)Planet3.pos.x, (float)Planet3.pos.y,Planet3.radius, BLACK); */
/* } */


int main(void)
{
    InitWindow(WIDTH, HEIGHT, "GRAVITY");
    SetTargetFPS(60);

    float dtime = 0.16f;

    Planet Planet1;
    Planet1.radius = 10;
    Planet1.mass = 100;
    Planet1.pos.x = WIDTH/4;
    Planet1.pos.y = HEIGHT/2;
    Planet1.vel.x = 0.5f;
    Planet1.vel.y = 0.5f;

    Planet Planet2;
    Planet2.radius = 10;
    Planet2.mass = 100;
    Planet2.pos.x = WIDTH/2;
    Planet2.pos.y = HEIGHT/2;
    Planet1.vel.x = 0.1f;
    Planet1.vel.y = 0.3f;

    Vector2 r1;

    RenderTexture2D target = LoadRenderTexture(WIDTH,HEIGHT);


    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);
        DrawTextureRec(target.texture, (Rectangle) { 0, 0, (float)target.texture.width, (float)-target.texture.height },(Vector2) { 0, 0 }, WHITE );
        DrawCircle((float)Planet1.pos.x, (float)Planet1.pos.y,Planet1.radius, LIGHTGRAY);
        DrawCircle((float)Planet2.pos.x, (float)Planet2.pos.y,Planet2.radius, LIGHTGRAY);

        EndDrawing();

        r1.x = Planet2.pos.x - Planet1.pos.x;
        r1.y = Planet2.pos.y - Planet1.pos.y;
        int modr1 = r1.x*r1.x + r1.y*r1.y;

        Planet1.acc.x = (G*Planet2.mass/modr1)*r1.x;
        Planet1.acc.y = (G*Planet2.mass/modr1)*r1.y;

        Planet1.vel.x = Planet1.vel.x + Planet1.acc.x;
        Planet1.vel.y = Planet1.vel.y + Planet1.acc.y;

        Planet1.pos.x = Planet1.pos.x + Planet1.vel.x;
        Planet1.pos.y = Planet1.pos.y + Planet1.vel.y;

        Planet2.acc.x = -(G*Planet1.mass/modr1)*r1.x;
        Planet2.acc.y = -(G*Planet1.mass/modr1)*r1.y;

        Planet2.vel.x = Planet2.vel.x + Planet2.acc.x;
        Planet2.vel.y = Planet2.vel.y + Planet2.acc.y;

        Planet2.pos.x = Planet2.pos.x + Planet2.vel.x;
        Planet2.pos.y = Planet2.pos.y + Planet2.vel.y;

        if(Planet1.pos.x + Planet1.radius > WIDTH) Planet1.vel.x = -Planet1.vel.x;
        if(Planet1.pos.x - Planet1.radius < 0) Planet1.vel.x = -Planet1.vel.x;
        if(Planet1.pos.y + Planet1.radius > HEIGHT) Planet1.vel.y = -Planet1.vel.y;
        if(Planet1.pos.y + Planet1.radius < 0) Planet1.vel.y = -Planet1.vel.y;
        if(Planet2.pos.x + Planet2.radius > WIDTH) Planet2.vel.x = -Planet2.vel.x;
        if(Planet2.pos.x - Planet2.radius < 0) Planet2.vel.x = -Planet2.vel.x;
        if(Planet2.pos.y + Planet2.radius > HEIGHT) Planet2.vel.y = -Planet2.vel.y;
        if(Planet2.pos.y + Planet2.radius < 0) Planet2.vel.y = -Planet2.vel.y;

        // Draws on frame buffer
        BeginTextureMode(target);
        DrawPixel(Planet1.pos.x, Planet1.pos.y, DARKGRAY);
        DrawPixel(Planet2.pos.x, Planet2.pos.y, DARKGRAY);
        EndTextureMode();
    }

    CloseWindow();

    return 0;
}
