#ifndef TOPMENU_HPP
#define TOPMENU_HPP

#include <gui_generated/containers/TopMenuBase.hpp>

class TopMenu : public TopMenuBase
{
public:
    TopMenu();
    virtual ~TopMenu() {}

    virtual void initialize();
protected:
};

#endif // TOPMENU_HPP
