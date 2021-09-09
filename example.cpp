#include "libasciigfx.h"
/* Settigs for libasciigfx can be found in the libasciigfx.h header file */

int main(){
    asciigfx graphics;

    // Initializes layers
    graphics.initLayer(0);
    graphics.initLayer(1);

    // Draws squares onto Layers
    graphics.drawSquare(0, 0, 0, 20, 80, "#");
    graphics.drawSquare(1, 1, 1, 19, 79, "@");

    // Renders frame
    graphics.renderFrame(0);
}