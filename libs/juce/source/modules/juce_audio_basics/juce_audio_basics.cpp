/*
  ==============================================================================

   This file is part of the JUCE library.
   Copyright (c) 2016 - ROLI Ltd.

   Permission is granted to use this software under the terms of the ISC license
   http://www.isc.org/downloads/software-support-policy/isc-license/

   Permission to use, copy, modify, and/or distribute this software for any
   purpose with or without fee is hereby granted, provided that the above
   copyright notice and this permission notice appear in all copies.

   THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH REGARD
   TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
   FITNESS. IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT,
   OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF
   USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
   TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
   OF THIS SOFTWARE.

   -----------------------------------------------------------------------------

   To release a closed-source product which uses other parts of JUCE not
   licensed under the ISC terms, commercial licenses are available: visit
   www.juce.com for more information.

  ==============================================================================
*/

#ifdef JUCE_AUDIO_BASICS_H_INCLUDED
 /* When you add this cpp file to your project, you mustn't include it in a file where you've
    already included any other headers - just put it inside a file on its own, possibly with your config
    flags preceding it, but don't include anything else. That also includes avoiding any automatic prefix
    header files that the compiler may be using.
 */
 #error "Incorrect use of JUCE cpp file"
#endif

#include "AppConfig.h"

#include "juce_audio_basics.h"

#if JUCE_MINGW && ! defined (__SSE2__)
 #define JUCE_USE_SSE_INTRINSICS 0
#endif

#if JUCE_MINGW && ! defined (alloca)
 #define alloca __builtin_alloca
#endif

#ifndef JUCE_USE_SSE_INTRINSICS
 #define JUCE_USE_SSE_INTRINSICS 1
#endif

#if ! JUCE_INTEL
 #undef JUCE_USE_SSE_INTRINSICS
#endif

#if JUCE_USE_SSE_INTRINSICS
 #include <emmintrin.h>
#endif

#ifndef JUCE_USE_VDSP_FRAMEWORK
 #define JUCE_USE_VDSP_FRAMEWORK 1
#endif

#if (JUCE_MAC || JUCE_IOS) && JUCE_USE_VDSP_FRAMEWORK
 #include <Accelerate/Accelerate.h>
#else
 #undef JUCE_USE_VDSP_FRAMEWORK
#endif

#if __ARM_NEON__ && ! (JUCE_USE_VDSP_FRAMEWORK || defined (JUCE_USE_ARM_NEON))
 #define JUCE_USE_ARM_NEON 1
#endif

#if TARGET_IPHONE_SIMULATOR
 #ifdef JUCE_USE_ARM_NEON
  #undef JUCE_USE_ARM_NEON
 #endif
 #define JUCE_USE_ARM_NEON 0
#endif

#if JUCE_USE_ARM_NEON
 #include <arm_neon.h>
#endif

namespace juce
{

#include "buffers/juce_AudioDataConverters.cpp"
#include "buffers/juce_FloatVectorOperations.cpp"
#include "buffers/juce_AudioChannelSet.cpp"
#include "effects/juce_IIRFilter.cpp"
#include "effects/juce_IIRFilterOld.cpp"
#include "effects/juce_LagrangeInterpolator.cpp"
#include "effects/juce_CatmullRomInterpolator.cpp"
#include "effects/juce_FFT.cpp"
#include "midi/juce_MidiBuffer.cpp"
#include "midi/juce_MidiFile.cpp"
#include "midi/juce_MidiKeyboardState.cpp"
#include "midi/juce_MidiMessage.cpp"
#include "midi/juce_MidiMessageSequence.cpp"
#include "midi/juce_MidiRPN.cpp"
#include "mpe/juce_MPEValue.cpp"
#include "mpe/juce_MPENote.cpp"
#include "mpe/juce_MPEZone.cpp"
#include "mpe/juce_MPEZoneLayout.cpp"
#include "mpe/juce_MPEInstrument.cpp"
#include "mpe/juce_MPEMessages.cpp"
#include "mpe/juce_MPESynthesiserBase.cpp"
#include "mpe/juce_MPESynthesiserVoice.cpp"
#include "mpe/juce_MPESynthesiser.cpp"
#include "sources/juce_BufferingAudioSource.cpp"
#include "sources/juce_ChannelRemappingAudioSource.cpp"
#include "sources/juce_IIRFilterAudioSource.cpp"
#include "sources/juce_MixerAudioSource.cpp"
#include "sources/juce_ResamplingAudioSource.cpp"
#include "sources/juce_ReverbAudioSource.cpp"
#include "sources/juce_ToneGeneratorAudioSource.cpp"
#include "synthesisers/juce_Synthesiser.cpp"

}
