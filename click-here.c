/**
 * click-here
 * Description: This program performs a mouse click at a given screen location.
 *
 * Usage: ./click-here x y
 *
 * This content is released under the MIT license (see LICENSE file.)
 */

#include <ApplicationServices/ApplicationServices.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if (argc > 2) {

        int x = atoi(argv[1]);
        int y = atoi(argv[2]);

        // click settings
        CGEventRef click = CGEventCreateMouseEvent(
            NULL,
            kCGEventLeftMouseDown,
            CGPointMake(x,y),
            kCGMouseButtonLeft
        );

        // perform click
        CGEventPost(kCGHIDEventTap, click);

        CFRelease(click);
    }

    return 0;
}
