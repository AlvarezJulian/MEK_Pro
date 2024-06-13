/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <new>
#include <gui_generated/common/FrontendApplicationBase.hpp>
#include <gui/common/FrontendHeap.hpp>
#include <touchgfx/transitions/NoTransition.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Texts.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <platform/driver/lcd/LCD16bpp.hpp>
#include <gui/start_screen/StartView.hpp>
#include <gui/start_screen/StartPresenter.hpp>
#include <gui/select_screen/SelectView.hpp>
#include <gui/select_screen/SelectPresenter.hpp>
#include <gui/rs232_screen/RS232View.hpp>
#include <gui/rs232_screen/RS232Presenter.hpp>
#include <gui/rs485_screen/RS485View.hpp>
#include <gui/rs485_screen/RS485Presenter.hpp>
#include <gui/can_screen/CANView.hpp>
#include <gui/can_screen/CANPresenter.hpp>
#include <gui/spi_screen/SPIView.hpp>
#include <gui/spi_screen/SPIPresenter.hpp>
#include <gui/i2c_screen/I2CView.hpp>
#include <gui/i2c_screen/I2CPresenter.hpp>
#include <gui/cdc_screen/CDCView.hpp>
#include <gui/cdc_screen/CDCPresenter.hpp>
#include <gui/gpio_screen/GPIOView.hpp>
#include <gui/gpio_screen/GPIOPresenter.hpp>
#include <gui/hid_screen/HIDView.hpp>
#include <gui/hid_screen/HIDPresenter.hpp>
#include <gui/info_screen/INFOView.hpp>
#include <gui/info_screen/INFOPresenter.hpp>

using namespace touchgfx;

FrontendApplicationBase::FrontendApplicationBase(Model& m, FrontendHeap& heap)
    : touchgfx::MVPApplication(),
      transitionCallback(),
      frontendHeap(heap),
      model(m)
{
    touchgfx::HAL::getInstance()->setDisplayOrientation(touchgfx::ORIENTATION_LANDSCAPE);
    touchgfx::Texts::setLanguage(GB);
    reinterpret_cast<touchgfx::LCD16bpp&>(touchgfx::HAL::lcd()).enableTextureMapperAll();
    reinterpret_cast<touchgfx::LCD16bpp&>(touchgfx::HAL::lcd()).enableDecompressorL8_All();
}

/*
 * Screen Transition Declarations
 */

// Start

void FrontendApplicationBase::gotoStartScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoStartScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoStartScreenNoTransitionImpl()
{
    touchgfx::makeTransition<StartView, StartPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Select

void FrontendApplicationBase::gotoSelectScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoSelectScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoSelectScreenNoTransitionImpl()
{
    touchgfx::makeTransition<SelectView, SelectPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// RS232

void FrontendApplicationBase::gotoRS232ScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoRS232ScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoRS232ScreenNoTransitionImpl()
{
    touchgfx::makeTransition<RS232View, RS232Presenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// RS485

void FrontendApplicationBase::gotoRS485ScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoRS485ScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoRS485ScreenNoTransitionImpl()
{
    touchgfx::makeTransition<RS485View, RS485Presenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// CAN

void FrontendApplicationBase::gotoCANScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoCANScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoCANScreenNoTransitionImpl()
{
    touchgfx::makeTransition<CANView, CANPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// I2C

void FrontendApplicationBase::gotoI2CScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoI2CScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoI2CScreenNoTransitionImpl()
{
    touchgfx::makeTransition<I2CView, I2CPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// CDC

void FrontendApplicationBase::gotoCDCScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoCDCScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoCDCScreenNoTransitionImpl()
{
    touchgfx::makeTransition<CDCView, CDCPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// GPIO

void FrontendApplicationBase::gotoGPIOScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoGPIOScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoGPIOScreenNoTransitionImpl()
{
    touchgfx::makeTransition<GPIOView, GPIOPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// INFO

void FrontendApplicationBase::gotoINFOScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoINFOScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoINFOScreenNoTransitionImpl()
{
    touchgfx::makeTransition<INFOView, INFOPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}
