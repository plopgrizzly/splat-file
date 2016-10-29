#include "main.h"
#include "la_effect.h"
#include "la_text.h"
#include "la_memory.h"
#include "la_buffer.h"
#include "la_window.h"

void* splatfile_data(void);
uint64_t splatfile_size(void);

void sf_loop(ctx_t* ctx) {
	if(la_fileviewer_loop(&ctx->fileviewer)) exit(0);
}

void ex_wdns(ctx_t* ctx, la_window_t* window) {
	la_fileviewer_draw(&ctx->fileviewer);
}

// Called when window is made/resized.
static void ex_edit_resz(ctx_t* ctx, la_window_t* window) {
/*	float ar = la_ro_ar(window);
	float colors[] = { 1.f, 1.f, 1.f, 1.f };

	la_print("EXXXXXXXXXXXXXXXXXXXXAMPLE Resizing Window....");
	la_ro_image_rect(window, &ctx->vo1, window->textures.game, 1.f, ar);
	la_ro_plain_rect(window, &ctx->vo2, colors, 2.f, 1.f);
	la_print("EXXXXXXXXXXXXXXXXXXXXAMPLE Resize'd Window....");*/
}

static void sf_init(ctx_t* ctx, la_window_t* window) {
	la_buffer_t packagedata;

	la_buffer_fromdata(&packagedata, splatfile_data(), splatfile_size());
	la_window_icon(window, &packagedata, "/icon.png");
	la_fileviewer_init(window, &ctx->fileviewer, NULL, NULL, 0);
	la_draw_fnchange(window, (la_draw_fn_t) ex_wdns, la_draw_dont,
		(la_draw_fn_t) ex_edit_resz);
}

int main(int argc, char* argv[]) {
	return la_start(sf_init, (la_fn_t) sf_loop, la_dont,
		"Splat File", sizeof(ctx_t));
}
