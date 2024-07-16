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
        gotoLoginScreenNoTransition();
    }

    // Login
    void gotoLoginScreenNoTransition();

    void gotoLoginScreenSlideTransitionWest();

    // Wellcome
    void gotoWellcomeScreenSlideTransitionEast();

    // VehicleCheck
    void gotoVehicleCheckScreenSlideTransitionEast();

    // Start
    void gotoStartScreenSlideTransitionEast();

protected:
    touchgfx::Callback<FrontendApplicationBase> transitionCallback;
    FrontendHeap& frontendHeap;
    Model& model;

    // Login
    void gotoLoginScreenNoTransitionImpl();

    void gotoLoginScreenSlideTransitionWestImpl();

    // Wellcome
    void gotoWellcomeScreenSlideTransitionEastImpl();

    // VehicleCheck
    void gotoVehicleCheckScreenSlideTransitionEastImpl();

    // Start
    void gotoStartScreenSlideTransitionEastImpl();
};

#endif // FRONTENDAPPLICATIONBASE_HPP
