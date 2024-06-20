/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/startupscreen_screen/StartupScreenViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>

StartupScreenViewBase::StartupScreenViewBase() :
    fadeLogoInEndedCallback(this, &StartupScreenViewBase::fadeLogoInEndedCallbackHandler)
{
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    background.setPosition(0, 0, 800, 480);
    background.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    add(background);

    image_GLYN.setBitmap(touchgfx::Bitmap(BITMAP_GLYNLOGO_ID));
    image_GLYN.setPosition(100, 149, 600, 182);
    image_GLYN.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);
    image_GLYN.setAlpha(0);
    add(image_GLYN);
}

StartupScreenViewBase::~StartupScreenViewBase()
{

}

void StartupScreenViewBase::setupScreen()
{

}

void StartupScreenViewBase::afterTransition()
{
    //FadeLogoIn
    //When screen transition ends fade image_GLYN
    //Fade image_GLYN to alpha:255 with LinearIn easing in 3000 ms (180 Ticks)
    image_GLYN.clearFadeAnimationEndedAction();
    image_GLYN.startFadeAnimation(255, 180, touchgfx::EasingEquations::linearEaseIn);
    image_GLYN.setFadeAnimationEndedAction(fadeLogoInEndedCallback);
}

void StartupScreenViewBase::fadeLogoInEndedCallbackHandler(const touchgfx::FadeAnimator<touchgfx::ScalableImage>& comp)
{
    //GoToMainScreen
    //When FadeLogoIn completed change screen to MainScreen
    //Go to MainScreen with screen transition towards East
    application().gotoMainScreenScreenSlideTransitionEast();

}
