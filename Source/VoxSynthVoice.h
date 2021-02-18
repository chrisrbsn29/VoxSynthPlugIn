/*
  ==============================================================================

    VoxSynthVoice.h
    Created: 15 Feb 2021 9:40:56pm
    Author:  Chris Robinson

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

#include "VoxSynthSound.h"

//==============================================================================
class VoxSynthVoice   : public juce::SynthesiserVoice

{
public:

    VoxSynthVoice();
    
    bool canPlaySound (juce::SynthesiserSound* sound) override;
    void startNote (int midiNoteNumber, float velocity,
                    juce::SynthesiserSound*, int currentPitchWheelPosition) override;
    void stopNote (float /*velocity*/, bool allowTailOff) override;
    void pitchWheelMoved (int) override;
    void controllerMoved (int, int) override;
    void renderNextBlock (juce::AudioSampleBuffer& outputBuffer, int startSample, int numSamples) override;

    void updateAngleDelta(); //delete
    
    bool isOn = false;
    double frequency = 0.0;
    
    double currentSampleRate = 0.0, currentAngle = 0.0, angleDelta = 0.0; //delete
    double currentFrequency = 500.0, targetFrequency = 500.0; //delete
    float currentLevel = 0.1f, targetLevel = 0.1f; //delete
    
};
