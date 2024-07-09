/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/statusscreen_screen/StatusScreenViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

StatusScreenViewBase::StatusScreenViewBase()
{
    __background.setPosition(0, 0, 480, 800);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    ELS_Status.setBackground(touchgfx::BitmapId(BITMAP_HINTERGRUND_TEXT_ID), 40, 171);
    ELS_Status.setShadeColor(touchgfx::Color::getColorFromRGB(252, 197, 93));
    ELS_Status.setShadeAlpha(150);
    ELS_Status.hide();
    textArea9.setXY(70, 356);
    textArea9.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea9.setLinespacing(0);
    textArea9.setTypedText(touchgfx::TypedText(T___SINGLEUSE_9FL6));
    ELS_Status.add(textArea9);

    textArea8.setXY(116, 294);
    textArea8.setColor(touchgfx::Color::getColorFromRGB(0, 48, 99));
    textArea8.setLinespacing(0);
    textArea8.setTypedText(touchgfx::TypedText(T___SINGLEUSE_H3TU));
    ELS_Status.add(textArea8);

    textArea7.setXY(70, 153);
    textArea7.setColor(touchgfx::Color::getColorFromRGB(0, 48, 99));
    textArea7.setLinespacing(0);
    textArea7.setTypedText(touchgfx::TypedText(T___SINGLEUSE_VCEW));
    ELS_Status.add(textArea7);

    ELS_Icon.setXY(178, 57);
    ELS_Icon.setBitmap(touchgfx::Bitmap(BITMAP_ICON_ELS_2_ID));
    ELS_Status.add(ELS_Icon);

    add(ELS_Status);

    Workshop.setBackground(touchgfx::BitmapId(BITMAP_HINTERGRUND_TEXT_ID), 40, 171);
    Workshop.setShadeColor(touchgfx::Color::getColorFromRGB(252, 197, 93));
    Workshop.setShadeAlpha(150);
    Workshop.hide();
    textArea6.setXY(81, 366);
    textArea6.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea6.setLinespacing(0);
    textArea6.setTypedText(touchgfx::TypedText(T___SINGLEUSE_YGB5));
    textArea6.setAlpha(190);
    Workshop.add(textArea6);

    textArea5.setXY(50, 319);
    textArea5.setColor(touchgfx::Color::getColorFromRGB(252, 197, 93));
    textArea5.setLinespacing(0);
    textArea5.setTypedText(touchgfx::TypedText(T___SINGLEUSE_BQYK));
    Workshop.add(textArea5);

    textArea4.setXY(89, 173);
    textArea4.setColor(touchgfx::Color::getColorFromRGB(252, 197, 93));
    textArea4.setLinespacing(0);
    textArea4.setTypedText(touchgfx::TypedText(T___SINGLEUSE_L4TK));
    Workshop.add(textArea4);

    Workshop_Icon.setXY(178, 68);
    Workshop_Icon.setBitmap(touchgfx::Bitmap(BITMAP_ICON_WERKSTATTMODUS_ID));
    Workshop.add(Workshop_Icon);

    add(Workshop);

    Crash.setBackground(touchgfx::BitmapId(BITMAP_HINTERGRUND_TEXT_ID), 40, 171);
    Crash.setShadeColor(touchgfx::Color::getColorFromRGB(235, 92, 71));
    Crash.setShadeAlpha(150);
    textArea3.setXY(73, 351);
    textArea3.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea3.setLinespacing(0);
    textArea3.setTypedText(touchgfx::TypedText(T___SINGLEUSE_KBYA));
    Crash.add(textArea3);

    textArea2.setXY(87, 294);
    textArea2.setColor(touchgfx::Color::getColorFromRGB(235, 92, 71));
    textArea2.setLinespacing(0);
    textArea2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_JK69));
    Crash.add(textArea2);

    textArea1.setXY(138, 201);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(235, 92, 71));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_SW5X));
    Crash.add(textArea1);

    add(Crash);

    topMenu1.setXY(0, 0);
    add(topMenu1);
}

StatusScreenViewBase::~StatusScreenViewBase()
{

}

void StatusScreenViewBase::setupScreen()
{
    topMenu1.initialize();
}