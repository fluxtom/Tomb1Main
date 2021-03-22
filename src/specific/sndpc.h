#ifndef T1M_SPECIFIC_SNDPC_H
#define T1M_SPECIFIC_SNDPC_H

#include <stdint.h>

#include "global/types.h"

#define SOUND_INVALID_HANDLE ((void *)-1)

// clang-format off
#define SoundMakeSample     ((int (*)(SAMPLE_DATA *sample_data))0x00419F50)
// clang-format on

int32_t SoundInit();
void SoundLoadSamples(char **sample_pointers, int32_t num_samples);
SAMPLE_DATA *SoundLoadSample(char *content);

int32_t CDPlay(int16_t track_id);
int32_t CDPlayLooped();
int32_t S_CDPlay(int16_t track);
int32_t S_CDStop();
int32_t S_StartSyncedAudio(int16_t track);
void S_CDLoop();
void S_CDVolume(int16_t volume);
void *S_SoundPlaySample(
    int32_t sample_id, uint16_t volume, uint16_t pitch, int16_t pan);
void *S_SoundPlaySampleLooped(
    int32_t sample_id, uint16_t volume, uint16_t pitch, int16_t pan);
int32_t S_SoundSampleIsPlaying(void *handle);
void S_SoundStopAllSamples();
void S_SoundStopSample(void *handle);
void S_SoundSetPanAndVolume(void *handle, int16_t pan, int16_t volume);

void T1MInjectSpecificSndPC();

#endif
