/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/spi_screen/SPIViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

SPIViewBase::SPIViewBase()
{
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    box1.setPosition(0, 0, 800, 480);
    box1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(box1);

    BackButton.setXY(700, 14);
    BackButton.setBitmaps(touchgfx::Bitmap(BITMAP_BLUISH3_ID), touchgfx::Bitmap(BITMAP_BLUISH3_ID));
    BackButton.setLabelText(touchgfx::TypedText(T___SINGLEUSE_Z3DR));
    BackButton.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    BackButton.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(BackButton);
}

SPIViewBase::~SPIViewBase()
{

}

void SPIViewBase::setupScreen()
{

}
