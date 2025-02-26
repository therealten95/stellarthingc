#pragma once
#include "core/vectors.h"

/// makes a window
void StWindow_new(const char* title, stvec2i size);

/// toggles fullscreen
void StWindow_toggle_fullscreen();

/// if true, the window is closing
bool StWindow_closing();

/// requests the window to be closed. this doesn't free the window stuff.
void StWindow_close();

/// updates the window. put this at the end of your main loop
void StWindow_update();

/// sets the target frames per second
void StWindow_set_target_fps(uint32 fps);

/// frees the window
void StWindow_free();

/// if true, there is, in fact, a window
bool StWindow_is_ready();

/// returns seconds since the window was opened
float64 StWindow_get_time();

/// returns time between frames in seconds. look up delta time
float64 StWindow_get_delta_time();

/// returns the frame rate the game is running at
int64 StWindow_get_fps();