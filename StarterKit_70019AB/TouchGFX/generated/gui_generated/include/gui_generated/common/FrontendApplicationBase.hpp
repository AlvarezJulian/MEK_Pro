/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef FRONTENDAPPLICATIONBASE_HPP
#define FRONTENDAPPLICATIONBASE_HPP

#include <mvp/MVPApplication.hpp>
#include <gui/model/Model.hpp>

class FrontendHeap;

class FrontendApplicationBase : public touchgfx::MVPApplication
{
public:
    FrontendApplicationBase(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplicationBase() { }

    virtual void changeToStartScreen()
    {
        gotoStartupScreenScreenNoTransition();
    }

    // StartupScreen
    void gotoStartupScreenScreenNoTransition();

    // MainScreen
    void gotoMainScreenScreenSlideTransitionEast();

    void gotoMainScreenScreenSlideTransitionWest();

    // GraphScreen
    void gotoGraphScreenScreenSlideTransitionEast();

protected:
    touchgfx::Callback<FrontendApplicationBase> transitionCallback;
    FrontendHeap& frontendHeap;
    Model& model;

    // StartupScreen
    void gotoStartupScreenScreenNoTransitionImpl();

    // MainScreen
    void gotoMainScreenScreenSlideTransitionEastImpl();

    void gotoMainScreenScreenSlideTransitionWestImpl();

    // GraphScreen
    void gotoGraphScreenScreenSlideTransitionEastImpl();
};

#endif // FRONTENDAPPLICATIONBASE_HPP
