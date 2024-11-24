#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PARTICLES 1
#define WIDTH 800
#define HEIGHT 600
#define DT 0.1


typedef struct
{
    float x, y;
    float vx, vy;
} Particle;


void initializeParticles(Particle particles[], int n) {
    for (int i = 0; i < n; i++) {
        particles[i].x = rand() % WIDTH;
        particles[i].y = rand() % HEIGHT;
        particles[i].vx = (rand() % 200 - 100) / 10.0;
        particles[i].vy = (rand() % 200 - 100) / 10.0;
    }
}

void updateParticles(Particle particles[], int n) 
{
    for (int i = 0; i < n; i++) {
        particles[i].x += particles[i].vx * DT;
        particles[i].y += particles[i].vy * DT;

        if (particles[i].x < 0 || particles[i].x > WIDTH) particles[i].vx *= -1;
        if (particles[i].y < 0 || particles[i].y > HEIGHT) particles[i].vy *= -1;
    }
}

void renderParticles(Particle particles[], int n) {
    printf("\033[H\033[J"); // Clear screen
    for (int i = 0; i < n; i++) {
        printf("Particle %d: (%.1f, %.1f)\n", i, particles[i].x, particles[i].y);
    }
}

int main() {
    srand(time(NULL));
    Particle particles[NUM_PARTICLES];
    initializeParticles(particles, NUM_PARTICLES);

    while (1)
    {
        updateParticles(particles, NUM_PARTICLES);
        renderParticles(particles, NUM_PARTICLES);
        usleep(50000);
    }

    return 0;
}
