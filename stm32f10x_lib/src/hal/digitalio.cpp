/*
 * digitalio.cpp
 */
#include "digitalio.h"

DigitalIO::DigitalIO(uint8_t port, uint8_t pin) :
		_pin(port, pin), _state(Invalid) {
}

DigitalIO::~DigitalIO() {
	// Not used
}

const map<uint8_t, uint32_t> DigitalIO::_ports_rcc = {
	{ 'A', RCC_APB2Periph_GPIOA },
	{ 'B', RCC_APB2Periph_GPIOB },
	{ 'C', RCC_APB2Periph_GPIOC },
	{ 'D', RCC_APB2Periph_GPIOD },
	{ 'E', RCC_APB2Periph_GPIOE },
	{ 'F', RCC_APB2Periph_GPIOF },
	{ 'G', RCC_APB2Periph_GPIOG }
};

const map<uint8_t, GPIO_TypeDef*> DigitalIO::_ports_base = {
		{ 'A', GPIOA },
		{ 'B', GPIOB },
		{ 'C', GPIOC },
		{ 'D', GPIOD },
		{ 'E', GPIOE },
		{ 'F', GPIOF },
		{ 'G', GPIOG }
};

