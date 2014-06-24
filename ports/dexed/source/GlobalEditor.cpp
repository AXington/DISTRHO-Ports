/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "GlobalEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
GlobalEditor::GlobalEditor ()
{
    addAndMakeVisible (lfoType = new ComboBox ("lfoType"));
    lfoType->setEditableText (false);
    lfoType->setJustificationType (Justification::centredLeft);
    lfoType->setTextWhenNothingSelected (String::empty);
    lfoType->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    lfoType->addItem (TRANS("TRIANGLE"), 1);
    lfoType->addItem (TRANS("SAW DOWN"), 2);
    lfoType->addItem (TRANS("SAW UP"), 3);
    lfoType->addItem (TRANS("SQUARE"), 4);
    lfoType->addItem (TRANS("SINE"), 5);
    lfoType->addItem (TRANS("S&HOLD"), 6);
    lfoType->addListener (this);

    addAndMakeVisible (lfoSpeed = new Slider ("lfoSpeed"));
    lfoSpeed->setRange (0, 99, 1);
    lfoSpeed->setSliderStyle (Slider::LinearHorizontal);
    lfoSpeed->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    lfoSpeed->addListener (this);

    addAndMakeVisible (lfoAmDepth = new Slider ("lfoAmDepth"));
    lfoAmDepth->setRange (0, 99, 1);
    lfoAmDepth->setSliderStyle (Slider::Rotary);
    lfoAmDepth->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    lfoAmDepth->addListener (this);

    addAndMakeVisible (lfoPitchDepth = new Slider ("lfoPitchDepth"));
    lfoPitchDepth->setRange (0, 99, 1);
    lfoPitchDepth->setSliderStyle (Slider::Rotary);
    lfoPitchDepth->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    lfoPitchDepth->addListener (this);

    addAndMakeVisible (lfoDelay = new Slider ("lfoDelay"));
    lfoDelay->setRange (0, 99, 1);
    lfoDelay->setSliderStyle (Slider::Rotary);
    lfoDelay->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    lfoDelay->addListener (this);

    addAndMakeVisible (cutoff = new Slider ("cutoff"));
    cutoff->setRange (0, 1, 0);
    cutoff->setSliderStyle (Slider::Rotary);
    cutoff->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    cutoff->addListener (this);

    addAndMakeVisible (reso = new Slider ("reso"));
    reso->setRange (0, 1, 0);
    reso->setSliderStyle (Slider::Rotary);
    reso->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    reso->addListener (this);

    addAndMakeVisible (pitchRate2 = new Slider ("pitchRate2"));
    pitchRate2->setRange (0, 99, 1);
    pitchRate2->setSliderStyle (Slider::Rotary);
    pitchRate2->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    pitchRate2->addListener (this);

    addAndMakeVisible (pitchRate3 = new Slider ("pitchRate3"));
    pitchRate3->setRange (0, 99, 1);
    pitchRate3->setSliderStyle (Slider::Rotary);
    pitchRate3->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    pitchRate3->addListener (this);

    addAndMakeVisible (pitchRate4 = new Slider ("pitchRate4"));
    pitchRate4->setRange (0, 99, 1);
    pitchRate4->setSliderStyle (Slider::Rotary);
    pitchRate4->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    pitchRate4->addListener (this);

    addAndMakeVisible (pitchRate1 = new Slider ("pitchRate1"));
    pitchRate1->setRange (0, 99, 1);
    pitchRate1->setSliderStyle (Slider::Rotary);
    pitchRate1->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    pitchRate1->addListener (this);

    addAndMakeVisible (pitchLevel2 = new Slider ("pitchLevel2"));
    pitchLevel2->setRange (0, 99, 1);
    pitchLevel2->setSliderStyle (Slider::Rotary);
    pitchLevel2->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    pitchLevel2->addListener (this);

    addAndMakeVisible (pitchLevel3 = new Slider ("pitchLevel3"));
    pitchLevel3->setRange (0, 99, 1);
    pitchLevel3->setSliderStyle (Slider::Rotary);
    pitchLevel3->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    pitchLevel3->addListener (this);

    addAndMakeVisible (pitchLevel4 = new Slider ("pitchLevel4"));
    pitchLevel4->setRange (0, 99, 1);
    pitchLevel4->setSliderStyle (Slider::Rotary);
    pitchLevel4->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    pitchLevel4->addListener (this);

    addAndMakeVisible (pitchLevel1 = new Slider ("pitchLevel1"));
    pitchLevel1->setRange (0, 99, 1);
    pitchLevel1->setSliderStyle (Slider::Rotary);
    pitchLevel1->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    pitchLevel1->addListener (this);

    addAndMakeVisible (transpose = new Slider ("transpose"));
    transpose->setRange (0, 48, 0);
    transpose->setSliderStyle (Slider::LinearVertical);
    transpose->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    transpose->addListener (this);

    addAndMakeVisible (oscSync = new ToggleButton ("oscSync"));
    oscSync->setButtonText (String::empty);

    addAndMakeVisible (pitchModSens = new Slider ("pitchModSens"));
    pitchModSens->setRange (0, 7, 0);
    pitchModSens->setSliderStyle (Slider::Rotary);
    pitchModSens->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    pitchModSens->addListener (this);

    addAndMakeVisible (lfoSync = new ToggleButton ("lfoSync"));
    lfoSync->setButtonText (String::empty);

    addAndMakeVisible (pitchEnvDisplay = new PitchEnvDisplay());
    pitchEnvDisplay->setName ("pitchEnvDisplay");

    addAndMakeVisible (algoDisplay = new AlgoDisplay());
    algoDisplay->setName ("algoDisplay");

    addAndMakeVisible (feedback = new Slider ("feedback"));
    feedback->setRange (0, 7, 1);
    feedback->setSliderStyle (Slider::Rotary);
    feedback->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    feedback->addListener (this);

    addAndMakeVisible (algo = new Slider ("algo"));
    algo->setRange (1, 32, 1);
    algo->setSliderStyle (Slider::Rotary);
    algo->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    algo->addListener (this);

    addAndMakeVisible (lcdDisplay = new LcdDisplay());
    lcdDisplay->setName ("lcdDisplay");

    addAndMakeVisible (output = new Slider ("cutoff"));
    output->setRange (0, 1, 0);
    output->setSliderStyle (Slider::Rotary);
    output->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    output->addListener (this);

    addAndMakeVisible (vuOutput = new VuMeter());
    vuOutput->setName ("vuOutput");


    //[UserPreSize]
    //[/UserPreSize]

    setSize (855, 90);


    //[Constructor] You can add your own custom stuff here..
    vuOutput->totalBlocks = 6;

    //[/Constructor]
}

GlobalEditor::~GlobalEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    lfoType = nullptr;
    lfoSpeed = nullptr;
    lfoAmDepth = nullptr;
    lfoPitchDepth = nullptr;
    lfoDelay = nullptr;
    cutoff = nullptr;
    reso = nullptr;
    pitchRate2 = nullptr;
    pitchRate3 = nullptr;
    pitchRate4 = nullptr;
    pitchRate1 = nullptr;
    pitchLevel2 = nullptr;
    pitchLevel3 = nullptr;
    pitchLevel4 = nullptr;
    pitchLevel1 = nullptr;
    transpose = nullptr;
    oscSync = nullptr;
    pitchModSens = nullptr;
    lfoSync = nullptr;
    pitchEnvDisplay = nullptr;
    algoDisplay = nullptr;
    feedback = nullptr;
    algo = nullptr;
    lcdDisplay = nullptr;
    output = nullptr;
    vuOutput = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void GlobalEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.setColour (Colours::black);
    g.setFont (Font (10.00f, Font::plain));
    g.drawText (TRANS("Volume"),
                27, 73, 45, 15,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (10.00f, Font::plain));
    g.drawText (TRANS("Cutoff"),
                75, 73, 45, 15,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (10.00f, Font::plain));
    g.drawText (TRANS("Resonance"),
                123, 73, 45, 15,
                Justification::centred, true);

    //[UserPaint] Add your own custom painting code here..

    //[/UserPaint]
}

void GlobalEditor::resized()
{
    lfoType->setBounds (624, 40, 96, 16);
    lfoSpeed->setBounds (624, 16, 96, 16);
    lfoAmDepth->setBounds (672, 64, 24, 24);
    lfoPitchDepth->setBounds (648, 64, 24, 24);
    lfoDelay->setBounds (624, 64, 24, 24);
    cutoff->setBounds (80, 40, 40, 40);
    reso->setBounds (128, 40, 40, 40);
    pitchRate2->setBounds (752, 64, 32, 24);
    pitchRate3->setBounds (776, 64, 32, 24);
    pitchRate4->setBounds (800, 64, 32, 24);
    pitchRate1->setBounds (728, 64, 32, 24);
    pitchLevel2->setBounds (752, 40, 32, 24);
    pitchLevel3->setBounds (776, 40, 32, 24);
    pitchLevel4->setBounds (800, 40, 32, 24);
    pitchLevel1->setBounds (728, 40, 32, 24);
    transpose->setBounds (832, 0, 24, 88);
    oscSync->setBounds (600, 64, 24, 24);
    pitchModSens->setBounds (696, 64, 24, 24);
    lfoSync->setBounds (600, 40, 24, 24);
    pitchEnvDisplay->setBounds (728, 8, 96, 32);
    algoDisplay->setBounds (442, 8, 152, 74);
    feedback->setBounds (568, 32, 24, 24);
    algo->setBounds (568, 8, 24, 24);
    lcdDisplay->setBounds (8, 0, 232, 32);
    output->setBounds (32, 40, 40, 40);
    vuOutput->setBounds (8, 44, 16, 38);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void GlobalEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == lfoType)
    {
        //[UserComboBoxCode_lfoType] -- add your combo box handling code here..
        //[/UserComboBoxCode_lfoType]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void GlobalEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == lfoSpeed)
    {
        //[UserSliderCode_lfoSpeed] -- add your slider handling code here..
        //[/UserSliderCode_lfoSpeed]
    }
    else if (sliderThatWasMoved == lfoAmDepth)
    {
        //[UserSliderCode_lfoAmDepth] -- add your slider handling code here..
        //[/UserSliderCode_lfoAmDepth]
    }
    else if (sliderThatWasMoved == lfoPitchDepth)
    {
        //[UserSliderCode_lfoPitchDepth] -- add your slider handling code here..
        //[/UserSliderCode_lfoPitchDepth]
    }
    else if (sliderThatWasMoved == lfoDelay)
    {
        //[UserSliderCode_lfoDelay] -- add your slider handling code here..
        //[/UserSliderCode_lfoDelay]
    }
    else if (sliderThatWasMoved == cutoff)
    {
        //[UserSliderCode_cutoff] -- add your slider handling code here..
        //[/UserSliderCode_cutoff]
    }
    else if (sliderThatWasMoved == reso)
    {
        //[UserSliderCode_reso] -- add your slider handling code here..
        //[/UserSliderCode_reso]
    }
    else if (sliderThatWasMoved == pitchRate2)
    {
        //[UserSliderCode_pitchRate2] -- add your slider handling code here..
        pitchEnvDisplay->repaint();
        //[/UserSliderCode_pitchRate2]
    }
    else if (sliderThatWasMoved == pitchRate3)
    {
        //[UserSliderCode_pitchRate3] -- add your slider handling code here..
        pitchEnvDisplay->repaint();
        //[/UserSliderCode_pitchRate3]
    }
    else if (sliderThatWasMoved == pitchRate4)
    {
        //[UserSliderCode_pitchRate4] -- add your slider handling code here..
        pitchEnvDisplay->repaint();
        //[/UserSliderCode_pitchRate4]
    }
    else if (sliderThatWasMoved == pitchRate1)
    {
        //[UserSliderCode_pitchRate1] -- add your slider handling code here..
        pitchEnvDisplay->repaint();
        //[/UserSliderCode_pitchRate1]
    }
    else if (sliderThatWasMoved == pitchLevel2)
    {
        //[UserSliderCode_pitchLevel2] -- add your slider handling code here..
        pitchEnvDisplay->repaint();
        //[/UserSliderCode_pitchLevel2]
    }
    else if (sliderThatWasMoved == pitchLevel3)
    {
        //[UserSliderCode_pitchLevel3] -- add your slider handling code here..
        pitchEnvDisplay->repaint();
        //[/UserSliderCode_pitchLevel3]
    }
    else if (sliderThatWasMoved == pitchLevel4)
    {
        //[UserSliderCode_pitchLevel4] -- add your slider handling code here..
        pitchEnvDisplay->repaint();
        //[/UserSliderCode_pitchLevel4]
    }
    else if (sliderThatWasMoved == pitchLevel1)
    {
        //[UserSliderCode_pitchLevel1] -- add your slider handling code here..
        pitchEnvDisplay->repaint();
        //[/UserSliderCode_pitchLevel1]
    }
    else if (sliderThatWasMoved == transpose)
    {
        //[UserSliderCode_transpose] -- add your slider handling code here..
        //[/UserSliderCode_transpose]
    }
    else if (sliderThatWasMoved == pitchModSens)
    {
        //[UserSliderCode_pitchModSens] -- add your slider handling code here..
        //[/UserSliderCode_pitchModSens]
    }
    else if (sliderThatWasMoved == feedback)
    {
        //[UserSliderCode_feedback] -- add your slider handling code here..
        //[/UserSliderCode_feedback]
    }
    else if (sliderThatWasMoved == algo)
    {
        //[UserSliderCode_algo] -- add your slider handling code here..
        //[/UserSliderCode_algo]
    }
    else if (sliderThatWasMoved == output)
    {
        //[UserSliderCode_output] -- add your slider handling code here..
        //[/UserSliderCode_output]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void GlobalEditor::bind(DexedAudioProcessor *parent) {
	parent->algo->bind(algo);
	parent->lfoRate->bind(lfoSpeed);
	parent->lfoDelay->bind(lfoDelay);
	parent->lfoWaveform->bind(lfoType);
	parent->lfoAmpDepth->bind(lfoAmDepth);
	parent->lfoPitchDepth->bind(lfoPitchDepth);
    parent->lfoSync->bind(lfoSync);
    parent->oscSync->bind(oscSync);
    parent->transpose->bind(transpose);
    parent->feedback->bind(feedback);
    parent->pitchModSens->bind(pitchModSens);
    parent->pitchEgLevel[0]->bind(pitchLevel1);
    parent->pitchEgLevel[1]->bind(pitchLevel2);
    parent->pitchEgLevel[2]->bind(pitchLevel3);
    parent->pitchEgLevel[3]->bind(pitchLevel4);
    parent->pitchEgRate[0]->bind(pitchRate1);
    parent->pitchEgRate[1]->bind(pitchRate2);
    parent->pitchEgRate[2]->bind(pitchRate3);
    parent->pitchEgRate[3]->bind(pitchRate4);
    parent->fxCutoff->bind(cutoff);
    parent->fxReso->bind(reso);
    parent->output->bind(output);
    algoDisplay->algo = &(parent->data[134]);
    pitchEnvDisplay->pvalues = &(parent->data[126]);
    processor = parent;
    repaint();
}

void GlobalEditor::setSystemMessage(String msg) {
    lcdDisplay->setSystemMsg(msg);
}

void GlobalEditor::setParamMessage(String msg) {
    lcdDisplay->paramMsg = msg;
    repaint();
}

void GlobalEditor::updateDisplay() {
    algoDisplay->repaint();
    pitchEnvDisplay->repaint();
    repaint();
}

void GlobalEditor::updatePitchPos(int pos) {
    pitchEnvDisplay->vPos = pos;
    pitchEnvDisplay->repaint();
}

void GlobalEditor::updateVu(float f) {
    vuOutput->v = f;
    vuOutput->repaint();
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="GlobalEditor" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="855" initialHeight="90">
  <BACKGROUND backgroundColour="ffffff">
    <TEXT pos="27 73 45 15" fill="solid: ff000000" hasStroke="0" text="Volume"
          fontname="Default font" fontsize="10" bold="0" italic="0" justification="36"/>
    <TEXT pos="75 73 45 15" fill="solid: ff000000" hasStroke="0" text="Cutoff"
          fontname="Default font" fontsize="10" bold="0" italic="0" justification="36"/>
    <TEXT pos="123 73 45 15" fill="solid: ff000000" hasStroke="0" text="Resonance"
          fontname="Default font" fontsize="10" bold="0" italic="0" justification="36"/>
  </BACKGROUND>
  <COMBOBOX name="lfoType" id="31018596af3b34e9" memberName="lfoType" virtualName=""
            explicitFocusOrder="0" pos="624 40 96 16" editable="0" layout="33"
            items="TRIANGLE&#10;SAW DOWN&#10;SAW UP&#10;SQUARE&#10;SINE&#10;S&amp;HOLD"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="lfoSpeed" id="b10eaf327ab3bff5" memberName="lfoSpeed" virtualName=""
          explicitFocusOrder="0" pos="624 16 96 16" min="0" max="99" int="1"
          style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="lfoAmDepth" id="3e95a6206fa4a891" memberName="lfoAmDepth"
          virtualName="" explicitFocusOrder="0" pos="672 64 24 24" min="0"
          max="99" int="1" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="lfoPitchDepth" id="6ead769ca786c813" memberName="lfoPitchDepth"
          virtualName="" explicitFocusOrder="0" pos="648 64 24 24" min="0"
          max="99" int="1" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="lfoDelay" id="1fce68dc81619ef5" memberName="lfoDelay" virtualName=""
          explicitFocusOrder="0" pos="624 64 24 24" min="0" max="99" int="1"
          style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="cutoff" id="40531f16bb0bd225" memberName="cutoff" virtualName=""
          explicitFocusOrder="0" pos="80 40 40 40" min="0" max="1" int="0"
          style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="reso" id="c8c13464e81a8d83" memberName="reso" virtualName=""
          explicitFocusOrder="0" pos="128 40 40 40" min="0" max="1" int="0"
          style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="pitchRate2" id="73f386b3c91d3de4" memberName="pitchRate2"
          virtualName="" explicitFocusOrder="0" pos="752 64 32 24" min="0"
          max="99" int="1" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="pitchRate3" id="187c25b24413fccf" memberName="pitchRate3"
          virtualName="" explicitFocusOrder="0" pos="776 64 32 24" min="0"
          max="99" int="1" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="pitchRate4" id="1aeb2a8fbbcbeaab" memberName="pitchRate4"
          virtualName="" explicitFocusOrder="0" pos="800 64 32 24" min="0"
          max="99" int="1" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="pitchRate1" id="419d613b3fb9604e" memberName="pitchRate1"
          virtualName="" explicitFocusOrder="0" pos="728 64 32 24" min="0"
          max="99" int="1" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="pitchLevel2" id="3a355ad2221887d9" memberName="pitchLevel2"
          virtualName="" explicitFocusOrder="0" pos="752 40 32 24" min="0"
          max="99" int="1" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="pitchLevel3" id="5c5d782e8a7f3ad7" memberName="pitchLevel3"
          virtualName="" explicitFocusOrder="0" pos="776 40 32 24" min="0"
          max="99" int="1" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="pitchLevel4" id="eb900b141fbad8ff" memberName="pitchLevel4"
          virtualName="" explicitFocusOrder="0" pos="800 40 32 24" min="0"
          max="99" int="1" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="pitchLevel1" id="344cbe26ec9fa128" memberName="pitchLevel1"
          virtualName="" explicitFocusOrder="0" pos="728 40 32 24" min="0"
          max="99" int="1" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="transpose" id="7d1266b1c1534947" memberName="transpose"
          virtualName="" explicitFocusOrder="0" pos="832 0 24 88" min="0"
          max="48" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <TOGGLEBUTTON name="oscSync" id="8f3fe641537cd00" memberName="oscSync" virtualName=""
                explicitFocusOrder="0" pos="600 64 24 24" buttonText="" connectedEdges="0"
                needsCallback="0" radioGroupId="0" state="0"/>
  <SLIDER name="pitchModSens" id="904f73df85a9f886" memberName="pitchModSens"
          virtualName="" explicitFocusOrder="0" pos="696 64 24 24" min="0"
          max="7" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <TOGGLEBUTTON name="lfoSync" id="ff92bb0a5a4f7187" memberName="lfoSync" virtualName=""
                explicitFocusOrder="0" pos="600 40 24 24" buttonText="" connectedEdges="0"
                needsCallback="0" radioGroupId="0" state="0"/>
  <GENERICCOMPONENT name="pitchEnvDisplay" id="9ddaae8ef924a038" memberName="pitchEnvDisplay"
                    virtualName="" explicitFocusOrder="0" pos="728 8 96 32" class="PitchEnvDisplay"
                    params=""/>
  <GENERICCOMPONENT name="algoDisplay" id="b26fb9e3b5f0bc37" memberName="algoDisplay"
                    virtualName="" explicitFocusOrder="0" pos="442 8 152 74" class="AlgoDisplay"
                    params=""/>
  <SLIDER name="feedback" id="4fac1940c29ab8c" memberName="feedback" virtualName=""
          explicitFocusOrder="0" pos="568 32 24 24" min="0" max="7" int="1"
          style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="algo" id="8a226ddf9bbff752" memberName="algo" virtualName=""
          explicitFocusOrder="0" pos="568 8 24 24" min="1" max="32" int="1"
          style="Rotary" textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <GENERICCOMPONENT name="lcdDisplay" id="30c7bb8f114cbbe3" memberName="lcdDisplay"
                    virtualName="" explicitFocusOrder="0" pos="8 0 232 32" class="LcdDisplay"
                    params=""/>
  <SLIDER name="cutoff" id="7697fdd54fd1593e" memberName="output" virtualName=""
          explicitFocusOrder="0" pos="32 40 40 40" min="0" max="1" int="0"
          style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <GENERICCOMPONENT name="vuOutput" id="dac75af912267f51" memberName="vuOutput" virtualName=""
                    explicitFocusOrder="0" pos="8 44 16 38" class="VuMeter" params=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
