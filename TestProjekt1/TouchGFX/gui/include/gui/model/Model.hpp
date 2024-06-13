#ifndef MODEL_HPP
#define MODEL_HPP

#include <touchgfx/Utils.hpp>

class ModelListener;

/**
 * The Model class defines the data model in the model-view-presenter paradigm.
 * The Model is a singular object used across all presenters. The currently active
 * presenter will have a pointer to the Model through deriving from ModelListener.
 *
 * The Model will typically contain UI state information that must be kept alive
 * through screen transitions. It also usually provides the interface to the rest
 * of the system (the backend). As such, the Model can receive events and data from
 * the backend and inform the current presenter of such events through the modelListener
 * pointer, which is automatically configured to point to the current presenter.
 * Conversely, the current presenter can trigger events in the backend through the Model.
 */
class Model
{
public:
    Model();

    /**
     * Sets the modelListener to point to the currently active presenter. Called automatically
     * when switching screen.
     */
    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    /**
     * This function will be called automatically every frame. Can be used to e.g. sample hardware
     * peripherals or read events from the surrounding system and inject events to the GUI through
     * the ModelListener interface.
     */
    void tick();
        
    float getTemperature() const { return Temperature; }
    void USBCDCSend(int value);    
    void SendRS232(uint8_t value);
    void SendRS485(uint8_t value);
    float ReadTemperatureSensor();
    void SetGPIO4Active(); 
    void SetGPIO5(char value);
    
    void SendCAN(uint8_t value);
    
    bool GetGPIO_0_State() const {return ! (GPIO_0_State & 0x01); }
    bool GetGPIO_1_State() const {return ! (GPIO_1_State & 0x02); }

protected:
    /**
     * Pointer to the currently active presenter.
     */
    ModelListener* modelListener;
    
private:
  uint8_t n;
  double Temperature;
  uint8_t Tx_Buffer[50];
  uint8_t USB_CDC_Tx_Buffer[64];
  uint8_t Rx_Buffer[50];
  uint8_t i;
  bool x;
  int pulsecount, tickcount;  
  char GPIO_0_State, GPIO_1_State, GPIO_5_State, GPIO5_Level;
  char old_GPIO_0_State, old_GPIO_1_State, old_GPIO_5_State;
  int16_t raw;
  int16_t intTemperature;
    
};

#endif /* MODEL_HPP */
