/*
  ==============================================================================

    VoxSynthSound.h
    Created: 15 Feb 2021 9:41:23pm
    Author:  Chris Robinson

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>


//==============================================================================
struct VoxSynthSound   : public juce::SynthesiserSound
{
public:
    VoxSynthSound();
    
    bool appliesToNote    (int) override;
    bool appliesToChannel (int) override;
};
