#ifndef GUI_H
#define GUI_H

#include "ui_gui.h"
#include "gpio.h"
#include <QTimer>

const int TIMEOUT = 1000; // ms

class Gui : public QWidget, private Ui::Gui
{
    Q_OBJECT

public:
    explicit Gui(QWidget *parent = nullptr);
    ~Gui();

private slots:
    void on_speedSlider_valueChanged(int value);
    void on_blinkButton_clicked();
    void on_lauflichtButton_clicked();

private:
    QTimer* m_timer;
    bool m_state;
    Gpio* m_leds;
};

#endif // GUI_H
