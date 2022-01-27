#include "gui.h"

Gui::Gui(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    m_leds = new Gpio(this);    // LEDs

    m_state = 0;
    // timing
    m_timer = new QTimer();
    connect(m_timer, &QTimer::timeout, this, &Gui::on_blinkButton_clicked); // Verbindung Timer Timeout (Signal) -> Gui Label Toggle (Slot)
    m_timer->start(TIMEOUT);    // periodischer Timer, sendet alle 20000ms Signal "Timeout"
}

void Gui::on_speedSlider_valueChanged(int value)
{
    m_timer->start(1000/value);
}

void Gui::on_blinkButton_clicked()
{
    m_state = !m_state; // invert
    label->setNum(m_state);
    m_leds ->set(LEDS[3], m_state);     // LEDS = {18, 23, 24, 25};
}

void Gui::on_lauflichtButton_clicked()
{
    m_state = !m_state; // invert
    label->setNum(m_state);
    m_leds ->set(LEDS[0], m_state);     // LEDS = 18
    m_leds ->set(LEDS[1], m_state);     // LEDS = 23
    m_leds ->set(LEDS[2], m_state);     // LEDS = 24
    m_leds ->set(LEDS[3], m_state);     // LEDS = 25
}

Gui::~Gui()
{
    delete m_leds;
}
