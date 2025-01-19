#include "main_window.h"
#include "real_time_effects.h"
#include <QApplication>
#include <QComboBox>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

namespace my_streaming_software {
namespace gui {

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setupUI();

    // Connect signals and slots
    connect(ui.startButton, &QPushButton::clicked, this, &MainWindow::onStartButtonClicked);
    connect(ui.stopButton, &QPushButton::clicked, this, &MainWindow::onStopButtonClicked);
}

void MainWindow::setupUI() {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    QLabel *effectsLabel = new QLabel("Select Real-Time Effect:", this);
    mainLayout->addWidget(effectsLabel);

    effectsComboBox = new QComboBox(this);
    effectsComboBox->addItem("None");
    effectsComboBox->addItem("Grayscale");
    effectsComboBox->addItem("Sepia");
    effectsComboBox->addItem("Invert");
    mainLayout->addWidget(effectsComboBox);

    QPushButton *applyEffectButton = new QPushButton("Apply Effect", this);
    mainLayout->addWidget(applyEffectButton);

    connect(applyEffectButton, &QPushButton::clicked, this, &MainWindow::applySelectedEffect);
}

void MainWindow::applySelectedEffect() {
    QString selectedEffect = effectsComboBox->currentText();
    if (selectedEffect == "None") {
        return;
    }

    my_streaming_software::effects::RealTimeEffects realTimeEffects;
    realTimeEffects.applyEffect(selectedEffect.toStdString(), "input.mp4", "output.mp4");
}

void MainWindow::onStartButtonClicked() {
    // Start recording or streaming
    if (!isStreaming) {
        // Start streaming logic
        isStreaming = true;
        ui.statusLabel->setText("Streaming started.");
    } else {
        QMessageBox::warning(this, "Warning", "Streaming is already in progress.");
    }
}

void MainWindow::onStopButtonClicked() {
    // Stop recording or streaming
    if (isStreaming) {
        // Stop streaming logic
        isStreaming = false;
        ui.statusLabel->setText("Streaming stopped.");
    } else {
        QMessage