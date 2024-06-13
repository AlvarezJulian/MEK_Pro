#ifndef SHOW_CANVIEW_HPP
#define SHOW_CANVIEW_HPP

#include <gui_generated/show_can_screen/Show_CANViewBase.hpp>
#include <gui/show_can_screen/Show_CANPresenter.hpp>

class Show_CANView : public Show_CANViewBase
{
public:
    Show_CANView();
    virtual ~Show_CANView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SHOW_CANVIEW_HPP
