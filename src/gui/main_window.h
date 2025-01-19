#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include "ui_main_window.h"

namespace my_streaming_software {
namespace gui {

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void applySelectedEffect();
    void onStartButtonClicked();
    void onStopButtonClicked();

private:
    void setupUI();
    QComboBox *effectsComboBox;
    Ui::MainWindow ui;
    bool isStreaming = false;
};

} // namespace gui
} // namespace my_streaming_software

#endif // MAIN_WINDOW_H
