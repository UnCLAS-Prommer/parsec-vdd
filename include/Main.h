#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include "MainUI.h"
#include <QtWidgets/QWidget>
#include <QtWidgets/QApplication>
#include <QCloseEvent>
#include <QMessageBox>
#include "parsec-vdd.h"
#include <chrono>
#include <thread>
using namespace parsec_vdd;
using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    QMainWindow *mainwindow;
    void closeEvent(QCloseEvent *event){
        Exit();
    }
    void StatusCheck(){
        DeviceStatus status = QueryDeviceStatus(&VDD_CLASS_GUID, VDD_HARDWARE_ID);
        if (status != DEVICE_OK)
        {
            auto message = QMessageBox::information(this, "tooltip", QString::fromUtf8("Parsec VDD device is not OK, got status " + status));
            emit StatusError();
            return;
        }
        if (vdd == NULL || vdd == INVALID_HANDLE_VALUE) {
            auto message = QMessageBox::information(this, "tooltip", QString::fromUtf8("Failed to obtain the device handle."));
            emit StatusError();
            return;
        }
    }
    HANDLE vdd = OpenDeviceHandle(&VDD_ADAPTER_GUID);
    vector<int> displays;
    bool running = true;
    void UpdateVdd(){
        while(running){
            VddUpdate(vdd);
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }
    void KeepUpdate(){
        std::thread updater(&MainWindow::UpdateVdd, this);
        updater.detach();
    }
    void RemoveAll(){
        for(int index : displays) {
            VddRemoveDisplay(vdd, index);
        }
    }
    void PopupMessage(int type,int index){
        switch (type)
        {
        case 0:{
            string mes = "Added a new virtual display, index: ";
            string pop = mes + to_string(index);
            auto message = QMessageBox::information(this, "tooltip", QString::fromStdString(pop));
            break;
        }
        case 1:{
            string mes = "Removed the last virtual display, index: ";
            string pop = mes + to_string(index);
            auto message = QMessageBox::information(this, "tooltip", QString::fromStdString(pop));
            break;
        }
        }
    }
signals:
    void StatusError();
    void QuitApp();
public slots:
    void Exit(){
        running = false;
        RemoveAll();
        CloseDeviceHandle(vdd);
        emit QuitApp();
    }
    void AddScreen(){
        if(displays.size() < VDD_MAX_DISPLAYS){
            int index = VddAddDisplay(vdd);
            std::cout << index << endl;
            displays.push_back(index);
            PopupMessage(0, index);
        }
        else{
            auto message = QMessageBox::information(this, "tooltip", QString::fromUtf8("Limit exceeded, could not add more virtual displays."));
        }
    }
    void RemoveScreen(){
        if(displays.size() > 0){
            int index = displays.back();
            VddRemoveDisplay(vdd, index);
            displays.pop_back();
            PopupMessage(1, index);
        }
        else{
            auto message = QMessageBox::information(this, "tooltip", QString::fromUtf8("No added virtual displays."));
        }
    }
};

void Connects(MainWindow *Window, QApplication *Application);
#endif