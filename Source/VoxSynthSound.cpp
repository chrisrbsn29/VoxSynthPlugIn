/*
  ==============================================================================

    VoxSynthSound.cpp
    Created: 15 Feb 2021 9:41:23pm
    Author:  Chris Robinson

  ==============================================================================
*/

#include "VoxSynthSound.h"


//==============================================================================
VoxSynthSound::VoxSynthSound(){}

bool VoxSynthSound::appliesToNote( int )    { return true; }
bool VoxSynthSound::appliesToChannel( int ) { return true; }

