#include <QApplication>
#include <QDir>
#include <fstream>
#include <iostream>
#include "LoginScreenUI.h"
#include "Temp/orderDataBase.hpp"
#include "MenuScreenUI.h"
#include "main.h"
#include <memory>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    while (true) {
        LoginScreenUI loginScreen;
        if (loginScreen.exec() != QDialog::Accepted) {
            break;  // Exit the loop if login fails or is canceled
        }

        std::string ordersFile = "orders.csv";
        auto orderDB = std::make_shared<OrderDatabase>(ordersFile);

        MenuScreenUI menuScreen(nullptr, orderDB.get());
        if (menuScreen.exec() != QDialog::Accepted) {
            continue;  // Loop back to login screen on logout
        }
    }

    return 0;


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

