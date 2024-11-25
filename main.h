#ifndef MAIN_H
#define MAIN_H

#include <QWidget>

class Main : public QWidget {
    Q_OBJECT

public:
    explicit Main(QWidget *parent = nullptr);
    ~Main();

    bool copyFileContents(const std::string& sourcePath, const std::string& destinationPath);
};

#endif // MAIN_H
