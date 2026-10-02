#include <cmath>
#include "tgaimage.h"

constexpr TGAColor white   = {255, 255, 255, 255}; // attention, BGRA order
constexpr TGAColor green   = {  0, 255,   0, 255};
constexpr TGAColor red     = {  0,   0, 255, 255};
constexpr TGAColor blue    = {255, 128,  64, 255};
constexpr TGAColor yellow  = {  0, 200, 255, 255};

// Drawing a line utilizing the simplest approach explained in the tutorial
void drawLine(int ax, int ay, int bx, int by, TGAImage& framebuffer, const TGAColor& color)
{
    // Increment across the parametric value t
    for (float t { 0 }; t <= 1; t += 0.01)
    {
        // Determining x and y values
        float xValue = ax + t * (bx - ax);
        float yValue = ay + t * (by - ay);

        framebuffer.set(xValue, yValue, color);   
    }
}

int main(int argc, char** argv) {
    constexpr int width  = 64;
    constexpr int height = 64;
    TGAImage framebuffer(width, height, TGAImage::RGB);

    int ax =  7, ay =  3;
    int bx = 12, by = 37;
    int cx = 62, cy = 53;

    framebuffer.set(ax, ay, white);
    framebuffer.set(bx, by, white);
    framebuffer.set(cx, cy, white);

    // Drawing a triangle using simplest approach!
    drawLine(ax, ay, bx, by, framebuffer, blue);
    drawLine(bx, by, cx, cy, framebuffer, green);
    drawLine(cx, cy, ax, ay, framebuffer, red);

    framebuffer.write_tga_file("framebuffer.tga");
    return 0;
}
