/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/login_screen/LoginViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

LoginViewBase::LoginViewBase()
{
    __background.setPosition(0, 0, 480, 800);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    Background_BluePicLogo.setBitmap(touchgfx::Bitmap(BITMAP_HINTERGRUND_MIT_ICON_UND_LOGO_ID));
    Background_BluePicLogo.setPosition(0, 0, 480, 800);
    Background_BluePicLogo.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);
    add(Background_BluePicLogo);

    text_hinweis.setXY(91, 217);
    text_hinweis.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    text_hinweis.setLinespacing(0);
    text_hinweis.setTypedText(touchgfx::TypedText(T___SINGLEUSE_TMQ7));
    add(text_hinweis);

    text_hinweis_1.setXY(100, 252);
    text_hinweis_1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    text_hinweis_1.setLinespacing(0);
    text_hinweis_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_4DD2));
    add(text_hinweis_1);

    textProductName.setXY(124, 108);
    textProductName.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textProductName.setLinespacing(0);
    textProductName.setTypedText(touchgfx::TypedText(T___SINGLEUSE_A2NM));
    add(textProductName);

    topMenu1.setXY(0, 0);
    add(topMenu1);
}

LoginViewBase::~LoginViewBase()
{

}

void LoginViewBase::setupScreen()
{
    topMenu1.initialize();
}
