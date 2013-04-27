#ifndef GUFINDBOOKFILESDIALOG_H
#define GUFINDBOOKFILESDIALOG_H

#include <QDialog>
#include <QSettings>
#include <QButtonGroup>

namespace Ui {
    class guFindBookFilesDialog;
}

class guFindBookFilesDialog : public QDialog {
    Q_OBJECT
public:
    guFindBookFilesDialog(QWidget *parent = 0);
    ~guFindBookFilesDialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::guFindBookFilesDialog *ui;

    QString searchPath;    //���� � �����, ��� ����� �������������� �����
    QStringList searchExtensions;
    QButtonGroup *extGroup;

public slots:
    //����������� ������� ����������
    void onSelectFolderClicked();      //����� ����� ��� ������������
    void onSaveSettings();
    void loadSettings();
signals:
};

#endif // GUFINDBOOKFILESDIALOG_H
