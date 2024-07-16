/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef TOPMENUBASE_HPP
#define TOPMENUBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/ScalableImage.hpp>
#include <touchgfx/containers/clock/DigitalClock.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/Image.hpp>

class TopMenuBase : public touchgfx::Container
{
public:
    TopMenuBase();
    virtual ~TopMenuBase();
    virtual void initialize();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::ScalableImage TopImage;
    touchgfx::ScalableImage wifi_sig_0;
    touchgfx::ScalableImage wifi_sig_1;
    touchgfx::ScalableImage wifi_sig_2;
    touchgfx::ScalableImage wifi_sig_3;
    touchgfx::ScalableImage bluetooth_0;
    touchgfx::ScalableImage bluetooth_Active;
    touchgfx::DigitalClock currentClock;
    touchgfx::DigitalClock LoginClock;
    touchgfx::TextArea Tetxt_LogInTime;
    touchgfx::Image logOut_Led;
    touchgfx::Image logIn_Led;
    touchgfx::ScalableImage scalableImage1;

private:

};

#endif // TOPMENUBASE_HPP
