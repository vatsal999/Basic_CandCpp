#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const long int NUMPARTICLES = 200000;
const int WIDTH = 800;
const int HEIGHT = 700;
const float friction = 0.1;

typedef struct Particle {
    Vector2 pos;
    Vector2 vel;
    Vector2 acc;
    Vector2 r1;

}Particle;

int main(void)
{
    Particle particles[NUMPARTICLES];

    for( long int i = 0; i < NUMPARTICLES; i++){
        particles[i].pos.x = GetRandomValue(0, WIDTH-1);
        particles[i].pos.y = GetRandomValue(0, HEIGHT-1);
        particles[i].vel.x = 0;
        particles[i].vel.y = 0;

    }

    InitWindow(WIDTH, HEIGHT, "1MPARTICLE");
    /* SetTargetFPS(60); */
    /* Particle *particles = (Particle*)malloc(NUMPARTICLES * sizeof(Particle)); */


    while (!WindowShouldClose())
    {

        /* Vector2 GetMousePosition; */
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            for( long int z = 0; z < NUMPARTICLES; z++){
                particles[z].r1.x = GetMouseX() - particles[z].pos.x;
                particles[z].r1.y = GetMouseY() - particles[z].pos.y;
                float modr1 = sqrt(particles[z].r1.x*particles[z].r1.x + particles[z].r1.y*particles[z].r1.y);
                particles[z].vel.x = (2/modr1)*particles[z].r1.x;
                particles[z].vel.y = (2/modr1)*particles[z].r1.y;
            }
        }

        for(long  int j = 0; j < NUMPARTICLES; j++ ){

            /* particles[j].vel.x = particles[j].vel.x + particles[j].acc.x; */
            /* particles[j].vel.y = particles[j].vel.y + particles[j].acc.y; */

            particles[j].pos.x = particles[j].pos.x + particles[j].vel.x*friction;
            particles[j].pos.y = particles[j].pos.y + particles[j].vel.y*friction;
        }

        BeginDrawing();
        ClearBackground(BLACK);

        for(long int k = 0; k < NUMPARTICLES; k++){
            DrawPixel((float)particles[k].pos.x,(float)particles[k].pos.y,WHITE);
        }

        DrawFPS(10, 10);
        EndDrawing();

    }

    CloseWindow();
    /* MemFree(particles); */

    return 0;
}
