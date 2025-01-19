#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include "ui_main_window.h"

namespace my_streaming_software {
namespace gui {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void onStartButtonClicked();
    void onStopButtonClicked();

private:
    Ui::MainWindow ui;
    bool isStreaming = false;
};

} // namespace gui
} // namespace my_streaming_software

#endif // MAIN_WINDOW_H
