/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef WELLCOMEVIEWBASE_HPP
#define WELLCOMEVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/wellcome_screen/WellcomePresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/ScalableImage.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>

class WellcomeViewBase : public touchgfx::View<WellcomePresenter>
{
public:
    WellcomeViewBase();
    virtual ~WellcomeViewBase();
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::ScalableImage Background_BluePicLogo;
    touchgfx::TextArea text_hinweis;
    touchgfx::TextArea text_hinweis_1;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  btnToStart;
    touchgfx::TextArea textProductName;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<WellcomeViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

    /*
     * Callback Handler Declarations
     */
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

};

#endif // WELLCOMEVIEWBASE_HPP
