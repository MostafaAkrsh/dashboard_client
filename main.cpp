#include "MainWindow.h"
#include <QtWidgets/QApplication>
#include "cudacode.cuh"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{

    qDebug() << "This will output to the spawned console!";
	QApplication a(argc, argv);
    MainWindow w;
    w.show();

   wrapper();

    return a.exec();
}
