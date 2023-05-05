#include "mbed.h"

// Initialize DigitalIn pins for p13 and p16 as input buttons
DigitalIn button1(p13);
DigitalIn button2(p16);

// Initialize DigitalOut pins for p23 and p25 as output LEDs
DigitalOut led1(p23);
DigitalOut led2(p25);

int main() {
    while (1) {
        // If p13 (button1) is pressed
        if (button1) {
            // Turn on p23 (led1) and turn off p25 (led2)
            led1 = 1;
            led2 = 0;
        }
        // If p16 (button2) is pressed
        else if (button2) {
            // Turn on p25 (led2) and turn off p23 (led1)
            led1 = 0;
            led2 = 1;
        }
        // If no button is pressed
        else {
            // Turn off p23 (led1) and p25 (led2)
            led1 = 0;
            led2 = 0;
        }
        
        // Wait for 50 milliseconds to debounce the button inputs
        wait_ms(50);
    }
}
