/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef STARTVIEWBASE_HPP
#define STARTVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/start_screen/StartPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/ScalableImage.hpp>
#include <touchgfx/containers/clock/DigitalClock.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <gui/containers/TopMenu.hpp>
#include <touchgfx/widgets/Image.hpp>

class StartViewBase : public touchgfx::View<StartPresenter>
{
public:
    StartViewBase();
    virtual ~StartViewBase();
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::ScalableImage background_BlueLogo;
    touchgfx::DigitalClock EbzTimeClock;
    touchgfx::ScalableImage line5;
    touchgfx::TextArea text_EZB;
    touchgfx::DigitalClock LogTimeClock;
    touchgfx::TextArea textLogtime;
    touchgfx::ScalableImage line4;
    touchgfx::TextArea tex_ELS;
    touchgfx::ScalableImage line3;
    touchgfx::TextArea Tetxt_Bluetooth;
    touchgfx::ScalableImage Line2;
    touchgfx::TextArea text_Wifi;
    touchgfx::ScalableImage line1;
    touchgfx::TextAreaWithOneWildcard User_ID_Start;
    TopMenu topMenu1;
    touchgfx::TextArea textArea1;
    touchgfx::Image Wifi_Icon;
    touchgfx::Image Bluetooth_Icon;
    touchgfx::Image ELS_Icon;
    touchgfx::Image image1;
    touchgfx::Image image2;
    touchgfx::Image image3;
    touchgfx::Image ID_Icon;

    /*
     * Wildcard Buffers
     */
    static const uint16_t USER_ID_START_SIZE = 32;
    touchgfx::Unicode::UnicodeChar User_ID_StartBuffer[USER_ID_START_SIZE];

private:

};

#endif // STARTVIEWBASE_HPP
