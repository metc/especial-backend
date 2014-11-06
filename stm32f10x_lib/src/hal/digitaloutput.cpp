/*
 * DigitalOutput.cpp
 */
#include "digitaloutput.h"

DigitalOutput::DigitalOutput(uint8_t port, uint8_t pin) :
		DigitalIO(port, pin) {
}

DigitalOutput::~DigitalOutput() {
	// Not used
}

/**
 * Configure the pin as output.
 */
bool DigitalOutput::initialize() {
	assert(_pin.port >= 'A' && _pin.port <= 'G');

	// Enable needed clocks
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO | gpio_port_rcc, ENABLE);

	/* Configure the pin as push-pull output. */
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = _pin.pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	return true;
}

void DigitalOutput::setState(State state) {
	_state = state;

	if (_state == State(On))
		GPIO_ResetBits(gpio_port_base, _pin.pin); // clear
	else
		GPIO_SetBits(gpio_port_base, _pin.pin); // set
}

DigitalIO::State DigitalOutput::state() const {
	return _state;
}
