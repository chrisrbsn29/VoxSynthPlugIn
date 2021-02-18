/*
  ==============================================================================

    VoxSynthVoice.cpp
    Created: 15 Feb 2021 9:40:56pm
    Author:  Chris Robinson

  ==============================================================================
*/

#include "VoxSynthVoice.h"
//==============================================================================
VoxSynthVoice::VoxSynthVoice()
{
    
}

bool VoxSynthVoice::canPlaySound (juce::SynthesiserSound* sound)
{
        return dynamic_cast<VoxSynthSound*> (sound) != nullptr;
}

void VoxSynthVoice::startNote (int midiNoteNumber, float velocity,
                            juce::SynthesiserSound*, int currentPitchWheelPosition)
{
    isOn = 1;
    currentSampleRate = getSampleRate();
    frequency = juce::MidiMessage::getMidiNoteInHertz (midiNoteNumber);
    updateAngleDelta();
}

void VoxSynthVoice::stopNote (float /*velocity*/, bool allowTailOff)
{
    clearCurrentNote();
    isOn = 0;
}

void VoxSynthVoice::pitchWheelMoved (int /*newPitchWheelValue*/)
{
//    setPitchBend(newPitchWheelValue);
//    frequency = noteHz(noteNumber, pitchBendCents());
}

void VoxSynthVoice::controllerMoved (int, int){}

void VoxSynthVoice::renderNextBlock (juce::AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
    if( isOn )
    {
        for (auto sample = 0; sample < numSamples; ++sample)
        {
            auto currentSample = (float) std::sin (currentAngle);
            
            for(auto channel = 0; channel < outputBuffer.getNumChannels(); channel++)
            {
                outputBuffer.addSample(channel, sample, currentSample);
            }
            currentAngle += angleDelta;
        }
    }
}

void VoxSynthVoice::updateAngleDelta()
{
    auto cyclesPerSample = frequency / currentSampleRate;
    angleDelta = cyclesPerSample * 2.0 * juce::MathConstants<double>::pi;
}
