#ifndef AUDIO_HPP
#define AUDIO_HPP


#include <SDL2/SDL.h>

char sound_name[3][35] = {"../../ChessAudio/move.wav","../../ChessAudio/capture.wav","../../ChessAudio/illegal.wav"};

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