/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/info_screen/INFOViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

INFOViewBase::INFOViewBase() :
    buttonCallback(this, &INFOViewBase::buttonCallbackHandler)
{
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    box1.setPosition(1, 0, 800, 480);
    box1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(box1);

    BackButton.setXY(699, 17);
    BackButton.setBitmaps(touchgfx::Bitmap(BITMAP_BLUISH3_ID), touchgfx::Bitmap(BITMAP_BLUISH3_ID));
    BackButton.setLabelText(touchgfx::TypedText(T___SINGLEUSE_RCK0));
    BackButton.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    BackButton.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    BackButton.setAction(buttonCallback);
    add(BackButton);

    textArea1.setXY(100, 150);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_YIP1));
    add(textArea1);

    ProjectName.setXY(300, 150);
    ProjectName.setColor(touchgfx::Color::getColorFromRGB(100, 165, 255));
    ProjectName.setLinespacing(0);
    ProjectName.setTypedText(touchgfx::TypedText(T___SINGLEUSE_3C89));
    add(ProjectName);

    textArea1_2.setXY(99, 200);
    textArea1_2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1_2.setLinespacing(0);
    textArea1_2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ODGV));
    add(textArea1_2);

    textArea1_1_1.setXY(300, 200);
    textArea1_1_1.setColor(touchgfx::Color::getColorFromRGB(100, 165, 255));
    textArea1_1_1.setLinespacing(0);
    textArea1_1_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ELE2));
    add(textArea1_1_1);

    textArea1_3.setXY(100, 250);
    textArea1_3.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1_3.setLinespacing(0);
    textArea1_3.setTypedText(touchgfx::TypedText(T___SINGLEUSE_FY9E));
    add(textArea1_3);

    Date.setXY(300, 250);
    Date.setColor(touchgfx::Color::getColorFromRGB(100, 165, 255));
    Date.setLinespacing(0);
    Date.setTypedText(touchgfx::TypedText(T___SINGLEUSE_HZDI));
    add(Date);

    textArea1_3_1.setXY(100, 300);
    textArea1_3_1.setColor(touchgfx::Color::getColorFromRGB(100, 165, 255));
    textArea1_3_1.setLinespacing(0);
    textArea1_3_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_1KBC));
    add(textArea1_3_1);

    Version.setXY(306, 300);
    Version.setColor(touchgfx::Color::getColorFromRGB(100, 165, 255));
    Version.setLinespacing(0);
    Version.setTypedText(touchgfx::TypedText(T___SINGLEUSE_Y90Y));
    add(Version);

    textArea1_3_1_1.setXY(100, 350);
    textArea1_3_1_1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1_3_1_1.setLinespacing(0);
    textArea1_3_1_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_NIQS));
    add(textArea1_3_1_1);

    textArea1_3_1_2.setXY(100, 300);
    textArea1_3_1_2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1_3_1_2.setLinespacing(0);
    textArea1_3_1_2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_1NQ7));
    add(textArea1_3_1_2);

    Version_1.setXY(306, 350);
    Version_1.setColor(touchgfx::Color::getColorFromRGB(100, 165, 255));
    Version_1.setLinespacing(0);
    Version_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_490X));
    add(Version_1);
}

INFOViewBase::~INFOViewBase()
{

}

void INFOViewBase::setupScreen()
{

}

void INFOViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &BackButton)
    {
        //GoToSelect
        //When BackButton clicked change screen to Select
        //Go to Select with no screen transition
        application().gotoSelectScreenNoTransition();
    }
}
