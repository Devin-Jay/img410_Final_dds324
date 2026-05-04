# img410_Final_dds324

# Authors
Devin Jay San Nicolas
dds324@nau.edu

# Usage
Download/clone repo.

ffmpeg is needed

Make

main.c contains programs top level flow. Read input -> raycast -> output to ppm

raycast.c contains functions to read input scene and raycast.

raycast.c also utilizes past projects to do vector3 math.

raycast.c now implements lighting and shadows when calculating a pixel's color.

structures.h contains various datatypes created.

Run with ./build/raycast.exe 500 500 input.scene output && ffmpeg -framerate 30 -i images/output_%04d.ppm -pix_fmt yuv420p output.mp4

output images are put into the images folder and a output.mp4 is made
Make clean to delete object files and .exe files.

# Known Issues
None
