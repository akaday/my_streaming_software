#include "main_window.h"
#include "real_time_effects.h"
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

namespace my_streaming_software {
namespace gui {

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setupUI();
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

} // namespace gui
} // namespace my_streaming_software
