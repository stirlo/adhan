#include <furi.h>
#include <gui/gui.h>

// Entry point for the application
int32_t application_start(FuriMessageQueue* app_message_queue) {
    // Initialize the LED
    Led* led = furi_record_open("led");
    bool led_state = false;

    // Main loop
    while(1) {
        // Toggle LED state
        led_state = !led_state;
        if(led_state) {
            led_on(led, LedIdGreen);
        } else {
            led_off(led, LedIdGreen);
        }

        // Wait for 500 milliseconds
        osDelay(500);
    }

    // Cleanup (though we never get here in this example)
    furi_record_close("led");
    return 0;
}
