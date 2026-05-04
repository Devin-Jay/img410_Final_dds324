#include "raycast.h"

// argv[1] -> width
// argv[2] -> height
// argv[3] -> input file
// argv[4] -> output file
// argc -> 5

int main(int argc, char* argv[])
{
    // Handle improper arguments
    if (argc < 5)
    {
        fprintf(stderr, "Error: Missing input/output filenames\n");
        return 1;
    }

    // parse input scene file and create scene struct
    Scene *scene = readInputScene(argv[3]);

    // if scene input fails, exit with error
    if (!scene)
    {
        return 1;
    }

    int totalFrames = 300;

    for (int frame = 0; frame < totalFrames; frame++) {
        float t = frame * 0.05f;

        //  move sphere in a circle
        scene->objects[0].pos.y = cosf(t) * 2.0f;
        scene->objects[0].pos.x = sinf(t) * 2.0f;

        // Render
        PPMImage* img = raycast(scene, atoi(argv[1]), atoi(argv[2]));

        // Save frame
        char filename[25];
        sprintf(filename, "images/%s_%04d.ppm", argv[4], frame);
        writeOutputPPMFile(filename, img);

        free(img->pixels);
        free(img);
    }


    // free allocated memory
    free(scene->objects);
    free(scene->lights);
    free(scene);

	return 0;

    //make && ./build/raycast.exe 500 500 input.scene output && ffmpeg -framerate 30 -i images/output_%04d.ppm -pix_fmt yuv420p output.mp4
}