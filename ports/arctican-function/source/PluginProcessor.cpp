/*
  ==============================================================================

    This file was auto-generated by the Jucer!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

#include <cmath>

//==============================================================================
TheFunctionAudioProcessor::TheFunctionAudioProcessor()
{
    gain = 1.0f;
    gainL = 1.0f;
    gainR = 1.0f;
    panL = 0.0f;
    panR = 1.0f;
    phaseL = 0.0f;
    phaseR = 0.0f;
    currentPreset = 0;
}

TheFunctionAudioProcessor::~TheFunctionAudioProcessor()
{
}

//==============================================================================
const String TheFunctionAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int TheFunctionAudioProcessor::getNumParameters()
{
    return totalNumParams;
}

float TheFunctionAudioProcessor::getParameter (int index)
{
    switch (index)
    {
        case gainParam:     return gain;
        case gainLParam:    return gainL;
        case gainRParam:    return gainR;
        case panLParam:     return panL;
        case panRParam:     return panR;
        case phaseLParam:   return phaseL;
        case phaseRParam:   return phaseR;
        default:            return 0.0f;
    }
}

void TheFunctionAudioProcessor::setParameter (int index, float newValue)
{
	switch (index)
    {
        case gainParam:     gain = newValue;   break;
        case gainLParam:    gainL = newValue;  break;
        case gainRParam:    gainR = newValue;  break;
        case panLParam:     panL = newValue;   break;
        case panRParam:     panR = newValue;   break;
        case phaseLParam:   phaseL = newValue; break;
        case phaseRParam:   phaseR = newValue; break;
        default:            break;
    }
}

const String TheFunctionAudioProcessor::getParameterName (int index)
{
    switch (index)
    {
        case gainParam:   return "Gain";
        case gainLParam:  return "Gain L";
        case gainRParam:  return "Gain R";
        case panLParam:   return "Pan L";
        case panRParam:   return "Pan R";
        case phaseLParam: return "Phase L";
        case phaseRParam: return "Phase R";
        default:          return String::empty;
    }
}

const String TheFunctionAudioProcessor::getParameterText (int index)
{
    return String (getParameter (index), 2);
}

const String TheFunctionAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String TheFunctionAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool TheFunctionAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool TheFunctionAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool TheFunctionAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool TheFunctionAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

int TheFunctionAudioProcessor::getNumPrograms()
{
    return 5;
}

int TheFunctionAudioProcessor::getCurrentProgram()
{
    return currentPreset;
}

void TheFunctionAudioProcessor::setCurrentProgram (int index)
{
	if((Time::getMillisecondCounter()-timeSinceChunkCalled)<200) // Thanks to "valhallasound" from the JUCE forum for this tip! :)
      return;

	switch(index)
	{
	case 0:
	  gain = 1.0f;
	  gainL = 1.0f;
	  gainR = 1.0f;
	  panL = 0.0f;
	  panR = 1.0f;
	  phaseL = 0.0f;
	  phaseR = 0.0f;
	  currentPreset = 0;
	break;
	case 1:
	  gain = 1.0f;
	  gainL = 1.0f;
	  gainR = 1.0f;
	  panL = 0.0f;
	  panR = 1.0f;
	  phaseL = 1.0f;
	  phaseR = 0.0f;
	  currentPreset = 1;
	break;
	case 2:
	  gain = 0.5f;
	  gainL = 1.0f;
	  gainR = 1.0f;
	  panL = 0.5f;
	  panR = 0.5f;
	  phaseL = 0.0f;
	  phaseR = 0.0f;
	  currentPreset = 2;
	break;
	case 3:
	  gain = 1.0f;
	  gainL = 1.0f;
	  gainR = 1.0f;
	  panL = 0.5f;
	  panR = 0.5f;
	  phaseL = 0.0f;
	  phaseR = 1.0f;
	  currentPreset = 3;
	break;
	case 4:
	  gain = 0.3f;
	  gainL = 1.0f;
	  gainR = 1.0f;
	  panL = 0.0f;
	  panR = 1.0f;
	  phaseL = 0.0f;
	  phaseR = 0.0f;
	  currentPreset = 4;
	break;

	}
}

const String TheFunctionAudioProcessor::getProgramName (int index)
{
	switch(index)
	{
		case 0:
			return "Blank Canvas";
			break;
		case 1:
			return "Phased";
			break;
		case 2:
			return "Stereo->Mono";
			break;
		case 3:
			return "Mono Blocker";
			break;
		case 4:
			return "Gain Reduction";
			break;
		default:
			return "This isn't a preset";
			break;
	}
}

void TheFunctionAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void TheFunctionAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    tmpBuffer.setSize(2, samplesPerBlock);
    tmpBuffer.clear();
}

void TheFunctionAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.

}

void TheFunctionAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
// This is the place where you'd normally do the guts of your plugin's
    // audio processing...

        int numberOfSamples = buffer.getNumSamples();

        float* channelDataL = buffer.getWritePointer (0);
        float* channelDataR = buffer.getWritePointer (1);

        tmpBuffer.copyFrom(0, 0, channelDataL, numberOfSamples);
        tmpBuffer.copyFrom(1, 0, channelDataR, numberOfSamples);

        float* inputDataL = tmpBuffer.getWritePointer (0);
        float* inputDataR = tmpBuffer.getWritePointer (1);

		float LinLout; // Left IN Left OUT - Gain
		float LinRout; // Left IN Right OUT - Gain

		float RinLout; // Right IN Left OUT - Gain
		float RinRout; // Right IN Right OUT - Gain


	// Work out L+R channel pan positions
		if (panL < 0.5)
		{
			LinLout = 1;
			LinRout = panL * 2;
		}
		else
		{
			LinLout = ((panL *2) -2) *-1;
		    LinRout = 1;
		}

		if (panR < 0.5)
		{
			RinLout = 1;
			RinRout = panR * 2;
		}
		else
		{
			RinLout = ((panR *2) -2) *-1;
		    RinRout = 1;
		}
	//******************

	// Apply individual channel phase, pan and gain
		float peakLevelL = 0;
		float peakLevelR = 0;
		float RMSLevelL = 0;
		float RMSLevelR = 0;
		for (int i = 0; i < numberOfSamples; ++i)
		{
		// Phase
			if (phaseL >= 0.5)
				inputDataL[i] *= -1;

			if (phaseR >= 0.5)
				inputDataR[i] *= -1;

		// Pan
			channelDataR[i] = (inputDataR[i] * RinRout) + (inputDataL[i] * LinRout);
			channelDataL[i] = (inputDataL[i] * LinLout) + (inputDataR[i] * RinLout);

		// Gain
			channelDataL[i] *= gainL;
			channelDataR[i] *= gainR;

			if (channelDataL[i] > peakLevelL)
				peakLevelL = channelDataL[i];
			if (channelDataR[i] > peakLevelR)
				peakLevelR = channelDataR[i];

			RMSLevelL += std::abs(channelDataL[i]);
			RMSLevelR += std::abs(channelDataR[i]);

		}
	//******************


	// Master Gain
		buffer.applyGain (0, numberOfSamples, gain);


    // In case we have more outputs than inputs, we'll clear any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
    {
        buffer.clear (i, 0, buffer.getNumSamples());
    }
}


//==============================================================================
bool TheFunctionAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* TheFunctionAudioProcessor::createEditor()
{
    return new TheFunctionAudioProcessorEditor (this);
}

//==============================================================================
void TheFunctionAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.

	// Create an outer XML element..
    XmlElement xml ("MYPLUGINSETTINGS");

    // add some attributes to it..
   // xml.setAttribute ("uiWidth", lastUIWidth);
   // xml.setAttribute ("uiHeight", lastUIHeight);
    //xml.setAttribute ("gain", gain);
   // xml.setAttribute ("delay", delay);
	xml.setAttribute ("gain", gain);
	xml.setAttribute ("gainL", gainL);
	xml.setAttribute ("gainR", gainR);

	xml.setAttribute ("panL", panL);
	xml.setAttribute ("panR", panR);

	xml.setAttribute ("phaseL", phaseL);
	xml.setAttribute ("phaseR", phaseR);

    // then use this helper function to stuff it into the binary blob and return it..
    copyXmlToBinary (xml, destData);
}

void TheFunctionAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.

	timeSinceChunkCalled = Time::getMillisecondCounter();
	 ScopedPointer<XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));

    if (xmlState != 0)
    {
        // make sure that it's actually our type of XML object..
        if (xmlState->hasTagName ("MYPLUGINSETTINGS"))
        {
            // ok, now pull out our parameters..
           // gain  = xmlState->getIntAttribute ("gain", gain);
            //lastUIHeight = xmlState->getIntAttribute ("uiHeight", lastUIHeight);

            gain  = (float) xmlState->getDoubleAttribute ("gain", gain);

			gainL  = (float) xmlState->getDoubleAttribute ("gainL", gainL);
			gainR  = (float) xmlState->getDoubleAttribute ("gainR", gainR);

			panL  = (float) xmlState->getDoubleAttribute ("panL", panL);
			panR  = (float) xmlState->getDoubleAttribute ("panR", panR);

			phaseL  = (float) xmlState->getDoubleAttribute ("phaseL", phaseL);
			phaseR  = (float) xmlState->getDoubleAttribute ("phaseR", phaseR);

           // delay = (float) xmlState->getDoubleAttribute ("delay", delay);
        }
    }
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TheFunctionAudioProcessor();
}
