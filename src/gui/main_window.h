#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QComboBox>

namespace my_streaming_software {
namespace gui {

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void applySelectedEffect();

private:
    void setupUI();
    QComboBox *effectsComboBox;
};

} // namespace gui
} // namespace my_streaming_software

#endif // MAIN_WINDOW_H
