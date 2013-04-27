#include <QtGui/QApplication>
#include "guMainWindow.h"
#include "guSettDialog.h"
#include <QSettings>
#include <QCoreApplication>
#include <QFile>
#include <QMessageBox>
//#define TEST  //������������ ��� ����� ������������
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSettings settings(QSettings::IniFormat, QSettings::UserScope, "Irbis.Soft", "Library Genesis uploader (beta)");
#ifdef TEST //���� ���������

    //������� ���� ���� ������
    if (QFile::exists(qApp->applicationDirPath() + "/gu.sqlite"))
        QFile::remove(qApp->applicationDirPath() + "/gu.sqlite");
#endif
    if (!settings.contains("version"))//������� �������� �� ��, ���������� �� ��������� � �������
    {

        settings.clear(); //������� ���������
        settings.setValue("version","0.4");
        settings.sync();
        guSettDialog settDlg;           //������ ��������
        settDlg.setModal(true);         //������ ���������
        settDlg.setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | Qt::WindowTitleHint| Qt::CustomizeWindowHint);
        int retCode = settDlg.exec();   //�������� ��� ��������
        if (retCode == 0)               //���� ������ "������"
        {
            return 0;                   //������� �� ���������
        }
    }
    //���� �� ��������� ���� ��� �� �� �������
    guMainWindow w;                     //������� ������� ����
    w.show();                           //����������
    return a.exec();                    //������ ����� ��������� ���������
}
