/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/start_screen/StartViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

StartViewBase::StartViewBase() :
    buttonCallback(this, &StartViewBase::buttonCallbackHandler)
{
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    box1.setPosition(0, 0, 800, 480);
    box1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(box1);

    StartButton.setXY(316, 389);
    StartButton.setBitmaps(touchgfx::Bitmap(BITMAP_LIGHTBLUE1_ID), touchgfx::Bitmap(BITMAP_LIGHTGGRAY1_ID));
    StartButton.setLabelText(touchgfx::TypedText(T___SINGLEUSE_I4PH));
    StartButton.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    StartButton.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    StartButton.setAlpha(0);
    StartButton.setAction(buttonCallback);
    add(StartButton);
}

StartViewBase::~StartViewBase()
{

}

void StartViewBase::setupScreen()
{

}

void StartViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &StartButton)
    {
        //GoToSelect
        //When StartButton clicked change screen to Select
        //Go to Select with no screen transition
        application().gotoSelectScreenNoTransition();
    }
}

void StartViewBase::afterTransition()
{
    //ShowStartButton
    //When screen transition ends fade StartButton
    //Fade StartButton to alpha:255 with LinearIn easing in 3000 ms (180 Ticks)
    StartButton.clearFadeAnimationEndedAction();
    StartButton.startFadeAnimation(255, 180, touchgfx::EasingEquations::linearEaseIn);
}
