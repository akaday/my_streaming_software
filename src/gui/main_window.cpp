#include "main_window.h"
#include <QApplication>
#include <QMessageBox>

namespace my_streaming_software {
namespace gui {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // Connect signals and slots
    connect(ui.startButton, &QPushButton::clicked, this, &MainWindow::onStartButtonClicked);
    connect(ui.stopButton, &QPushButton::clicked, this, &MainWindow::onStopButtonClicked);
}

void MainWindow::onStartButtonClicked()
{
    // Start recording or streaming
    if (!isStreaming) {
        // Start streaming logic
        isStreaming = true;
        ui.statusLabel->setText("Streaming started.");
    } else {
        QMessageBox::warning(this, "Warning", "Streaming is already in progress.");
    }
}

void MainWindow::onStopButtonClicked()
{
    // Stop recording or streaming
    if (isStreaming) {
        // Stop streaming logic
        isStreaming = false;
        ui.statusLabel->setText("Streaming stopped.");
    } else {
        QMessageBox::warning(this, "Warning", "No streaming is in progress.");
    }
}

} // namespace gui
} // namespace my_streaming_software
