#include "libasciigfx.h"

int main(){
    Asciigfx graphics(false, 80, 20, 2);

    // Initializes layers
    graphics.initLayer(0);
    graphics.initLayer(1);

    // Draws shapes onto Layers
    graphics.drawSquare(0, 0, 0, 79, 19, '#');
    graphics.drawLine(1, 10, 10, 15, 15, '.');


    // Renders frame
    graphics.renderFrame();

}
