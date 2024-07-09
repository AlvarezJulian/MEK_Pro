#ifndef BUTTONSTOCHANGESCREEN_HPP
#define BUTTONSTOCHANGESCREEN_HPP

#include <gui_generated/containers/ButtonsToChangeScreenBase.hpp>

class ButtonsToChangeScreen : public ButtonsToChangeScreenBase
{
public:
    ButtonsToChangeScreen();
    virtual ~ButtonsToChangeScreen() {}

    virtual void initialize();
protected:
};

#endif // BUTTONSTOCHANGESCREEN_HPP
