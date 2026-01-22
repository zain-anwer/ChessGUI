#ifndef AUDIO_HPP
#define AUDIO_HPP


#include <SDL2/SDL.h>

extern const char* sound_name[5];

class Audio
{
	private:
		SDL_AudioSpec wavSpec;
		Uint8* wavStart;
		Uint32 wavLength;

    public:
	    void playSound (int type);
	
};

#endif