#include <stdint.h>
#include <stddef.h>
#include <limine.h>
#include <vendor/flanterm/flanterm.h>
#include <vendor/flanterm/backends/fb.h>
#include <vendor/printf.h>

// The Limine requests can be placed anywhere, but it is important that
// the compiler does not optimise them away, so, usually, they should
// be made volatile or equivalent.

static volatile struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0
};
struct flanterm_context* ft_ctx;

// Halt and catch fire function.
static void hcf(void) {
    asm ("cli");
    for (;;) {
        asm ("hlt");
    }
}

// The following will be our kernel's entry point.
// If renaming _start() to something else, make sure to change the
// linker script accordingly.
void _start(void) {
    // Ensure we got a framebuffer.
    if (framebuffer_request.response == NULL
     || framebuffer_request.response->framebuffer_count < 1) {
        hcf();
    }

    // Fetch the first framebuffer.
    struct limine_framebuffer *framebuffer = framebuffer_request.response->framebuffers[0];

    ft_ctx = flanterm_fb_simple_init(
        framebuffer->address, framebuffer->width,
        framebuffer->height, framebuffer->pitch);

    char* version = "0.0.12923";

    printf("Blint version %s\n\n",version);


    printf("\x1b[38;5;126m  ####   ### \n");
    printf("\x1b[38;5;126m    ##   ### \n");
    printf("\x1b[38;5;126m    #######  \n");
    printf("\x1b[38;5;126m    ##   ### \n");
    printf("\x1b[38;5;126m    ##   ### \n");
    printf("\x1b[38;5;126m    #######  \n");

    hcf();
}
