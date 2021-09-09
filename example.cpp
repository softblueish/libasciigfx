#include "libasciigfx.h"

int main(){
    Asciigfx graphics(false, 20, 80, 2);

    // Initializes layers
    graphics.initLayer(0);
    graphics.initLayer(1);

    // Draws shapes onto Layers
    graphics.drawSquare(0, 0, 0, 19, 79, '#');
    graphics.drawPoint(1, 2, 2, 'L');

    // Renders frame
    graphics.renderFrame();

}
