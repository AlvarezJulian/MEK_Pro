#ifndef RS232_PRESENTER_HPP
#define RS232_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class RS232View;

class RS232Presenter : public Presenter, public ModelListener
{
public:
    RS232Presenter(RS232View& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~RS232Presenter() {};
       
    virtual void RS232CharReceived(uint8_t *data , uint16_t len);
    
    void RS232SliderValueChanged(uint8_t value);    

private:
    RS232Presenter();

    RS232View& view;
};


#endif // RS232_PRESENTER_HPP
