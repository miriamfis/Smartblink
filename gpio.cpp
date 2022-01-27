#include "gpio.h"
#include <lgpio.h>
#include <QDebug>

Gpio::Gpio(QObject *parent) : QObject(parent)
{
    m_handle = lgGpiochipOpen(0); /* get a handle to the GPIO */
    int init_level = 0;     /* initial level 1 */
    for (auto pin: LEDS)
        lgGpioClaimOutput(m_handle, LFLAGS, pin, init_level);
}

Gpio::~Gpio()
{
    int init_level = 0;     /* initial level 1 */
    for (auto pin: LEDS)
        lgGpioWrite(m_handle, pin, init_level);
    lgGpiochipClose(m_handle);
    qDebug() << "bye";
}

void Gpio::set(int pin, bool value)
{
    lgGpioWrite(m_handle, pin, value);
}

void Gpio::set(unsigned int pattern)
{
    int n = 0;
    int value = 0;
    for (auto pin: LEDS)
    {
        // n-te Stelle vom Pattern ausmaskieren
        lgGpioWrite(m_handle, pin, value);
        // Maske um 1 Stelle nach vorne verschieben
    }
}
