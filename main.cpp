#include <QApplication>
#include <QDir>
#include <fstream>
#include <iostream>
#include "LoginScreenUI.h"
#include "Temp/orderDataBase.hpp"
#include "MenuScreenUI.h"
#include "main.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);



    LoginScreenUI loginScreen;
    if (loginScreen.exec() == QDialog::Accepted) {

    }

    cout << "return in main hit" << endl;
    return app.exec();
}
Main::Main(QWidget *parent) : QWidget(parent) {
    // Constructor implementation
}

Main::~Main() {
    // Destructor implementation
}



bool Main::copyFileContents(const std::string& sourcePath, const std::string& destinationPath) {
    std::ifstream sourceFile(sourcePath, std::ios::binary);  // Open source file in binary mode
    if (!sourceFile.is_open()) {
        std::cerr << "Error: Could not open source file: " << sourcePath << std::endl;
        return false;
    }

    std::ofstream destinationFile(destinationPath, std::ios::binary);  // Open destination file in binary mode
    if (!destinationFile.is_open()) {
        std::cerr << "Error: Could not open destination file: " << destinationPath << std::endl;
        return false;
    }

    destinationFile << sourceFile.rdbuf();  // Copy contents
    std::cout << "Successfully copied contents from " << sourcePath << " to " << destinationPath << std::endl;

    return true;
}

