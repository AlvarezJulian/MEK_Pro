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
        gotoStartScreenNoTransition();
    }

    // Start
    void gotoStartScreenNoTransition();

    // Select
    void gotoSelectScreenNoTransition();

    // RS232
    void gotoRS232ScreenNoTransition();

    // RS485
    void gotoRS485ScreenNoTransition();

    // CAN
    void gotoCANScreenNoTransition();

    // I2C
    void gotoI2CScreenNoTransition();

    // CDC
    void gotoCDCScreenNoTransition();

    // GPIO
    void gotoGPIOScreenNoTransition();

    // INFO
    void gotoINFOScreenNoTransition();

protected:
    touchgfx::Callback<FrontendApplicationBase> transitionCallback;
    FrontendHeap& frontendHeap;
    Model& model;

    // Start
    void gotoStartScreenNoTransitionImpl();

    // Select
    void gotoSelectScreenNoTransitionImpl();

    // RS232
    void gotoRS232ScreenNoTransitionImpl();

    // RS485
    void gotoRS485ScreenNoTransitionImpl();

    // CAN
    void gotoCANScreenNoTransitionImpl();

    // I2C
    void gotoI2CScreenNoTransitionImpl();

    // CDC
    void gotoCDCScreenNoTransitionImpl();

    // GPIO
    void gotoGPIOScreenNoTransitionImpl();

    // INFO
    void gotoINFOScreenNoTransitionImpl();
};

#endif // FRONTENDAPPLICATIONBASE_HPP