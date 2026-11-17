/**********************************************************************************************
*
*   raylib SDL event callback extension (SDL2 and SDL3 backends only)
*
*   Copyright (c) 2013-2026 Ramon Santamaria (@raysan5) and contributors
*   Licensed under the zlib/libpng license; see LICENSE.
*
**********************************************************************************************/

#ifndef RAYLIB_SDL_H
#define RAYLIB_SDL_H

#include "raylib.h"              // RLAPI

// SDL2 and SDL3 both define SDL_Event as a union. Include the matching SDL
// headers separately to inspect the event. Do not mix SDL major versions.
union SDL_Event;
typedef void (*RaylibSDLEventCallback)(const union SDL_Event *event, void *userData);

#if defined(__cplusplus)
extern "C" {
#endif

// Available only when raylib is built with its SDL backend. Replaces the single
// callback; pass NULL to unregister. Register and unregister on the thread that
// calls PollInputEvents (normally the SDL video/main thread); no synchronization
// is provided. CloseWindow also clears the callback.
//
// Called synchronously, once per event dequeued by raylib, before raylib processes
// it. The event and any data it references are borrowed for the call only; do not
// retain or modify them. The callback must not poll or modify the SDL event queue,
// recursively poll raylib input, or change the callback or window lifecycle.
// Register after the consumer is initialized and unregister before it shuts down
// or the window is destroyed. Events consumed elsewhere are not forwarded.
RLAPI void SetSDLEventCallback(RaylibSDLEventCallback callback, void *userData);

#if defined(__cplusplus)
}
#endif

#endif // RAYLIB_SDL_H
