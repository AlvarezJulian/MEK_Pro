/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/gpio_screen/GPIOViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

GPIOViewBase::GPIOViewBase() :
    buttonCallback(this, &GPIOViewBase::buttonCallbackHandler)
{
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    box1.setPosition(0, 0, 800, 480);
    box1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(box1);

    box2.setPosition(0, 166, 800, 50);
    box2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    box2.setAlpha(75);
    add(box2);

    BackButton.setXY(700, 14);
    BackButton.setBitmaps(touchgfx::Bitmap(BITMAP_BLUISH3_ID), touchgfx::Bitmap(BITMAP_BLUISH3_ID));
    BackButton.setLabelText(touchgfx::TypedText(T___SINGLEUSE_B1M8));
    BackButton.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    BackButton.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    BackButton.setAction(buttonCallback);
    add(BackButton);

    textArea2.setXY(57, 179);
    textArea2.setColor(touchgfx::Color::getColorFromRGB(255, 188, 20));
    textArea2.setLinespacing(0);
    textArea2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_LXSS));
    add(textArea2);

    textArea2_1.setXY(9, 0);
    textArea2_1.setColor(touchgfx::Color::getColorFromRGB(255, 188, 20));
    textArea2_1.setLinespacing(0);
    textArea2_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_0K4H));
    add(textArea2_1);

    BulbWhite.setXY(66, 240);
    BulbWhite.setBitmap(touchgfx::Bitmap(BITMAP_BULBWHITE_ID));
    add(BulbWhite);

    BulbYellow.setXY(65, 240);
    BulbYellow.setBitmap(touchgfx::Bitmap(BITMAP_BULBYELLOW_ID));
    BulbYellow.setVisible(false);
    add(BulbYellow);

    GPIO4Button.setXY(375, 239);
    GPIO4Button.setBitmaps(touchgfx::Bitmap(BITMAP_ORANGE1_ID), touchgfx::Bitmap(BITMAP_GRAY1_ID));
    GPIO4Button.setLabelText(touchgfx::TypedText(T___SINGLEUSE_E6A2));
    GPIO4Button.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    GPIO4Button.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    GPIO4Button.setAction(buttonCallback);
    add(GPIO4Button);

    GPIO5ToggleButton.setXY(577, 251);
    GPIO5ToggleButton.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_TOGGLEBARS_TOGGLE_ROUND_LARGE_BUTTON_OFF_ID), touchgfx::Bitmap(BITMAP_BLUE_TOGGLEBARS_TOGGLE_ROUND_LARGE_BUTTON_ON_ID));
    GPIO5ToggleButton.setAction(buttonCallback);
    add(GPIO5ToggleButton);

    ModalWindow.setBackground(touchgfx::BitmapId(BITMAP_MY_MODAL_BACKGROUND_ID), 230, 120);
    ModalWindow.setShadeColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    ModalWindow.setShadeAlpha(150);
    ModalWindow.hide();
    ModalWindowText.setPosition(51, 106, 238, 25);
    ModalWindowText.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    ModalWindowText.setLinespacing(0);
    ModalWindowText.setTypedText(touchgfx::TypedText(T___SINGLEUSE_MKQJ));
    ModalWindow.add(ModalWindowText);

    CloseModalButton.setXY(241, 11);
    CloseModalButton.setBitmaps(touchgfx::Bitmap(BITMAP_BLUISH3_ID), touchgfx::Bitmap(BITMAP_BLUISH3_ID));
    CloseModalButton.setLabelText(touchgfx::TypedText(T___SINGLEUSE_H2IS));
    CloseModalButton.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    CloseModalButton.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    CloseModalButton.setAction(buttonCallback);
    ModalWindow.add(CloseModalButton);

    add(ModalWindow);
}

GPIOViewBase::~GPIOViewBase()
{

}

void GPIOViewBase::setupScreen()
{

}

void GPIOViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &BackButton)
    {
        //GoToSelect
        //When BackButton clicked change screen to Select
        //Go to Select with no screen transition
        application().gotoSelectScreenNoTransition();
    }
    if (&src == &CloseModalButton)
    {
        //CloseModalWindow
        //When CloseModalButton clicked hide ModalWindow
        //Hide ModalWindow
        ModalWindow.setVisible(false);
        ModalWindow.invalidate();
    }
    if (&src == &GPIO4Button)
    {
        //GPIO4Active
        //When GPIO4Button clicked call virtual function
        //Call GPIO4Active
        GPIO4Active();
    }
    if (&src == &GPIO5ToggleButton)
    {
        //ToggleGPIO5
        //When GPIO5ToggleButton clicked call virtual function
        //Call ToggleGPIO5
        ToggleGPIO5();
    }
}

void GPIOViewBase::handleKeyEvent(uint8_t key)
{
    if(48 == key)
    {
        //Gpio0Low
        //When hardware button 48 clicked show BulbYellow
        //Show BulbYellow
        BulbYellow.setVisible(true);
        BulbYellow.invalidate();
    
    }

    if(49 == key)
    {
        //Gpio1Low
        //When hardware button 49 clicked show ModalWindow
        //Show ModalWindow
        ModalWindow.setVisible(true);
        ModalWindow.invalidate();
    
    }
}
