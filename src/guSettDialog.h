#ifndef GUSETTDIALOG_H
#define GUSETTDIALOG_H

#include <QDialog>
#include <QListWidgetItem>
#include <QString>
#include <QColor>
#include <QButtonGroup>

namespace Ui {
    class guSettDialog;
}

class guSettDialog : public QDialog {
    Q_OBJECT
public:
    guSettDialog(QWidget *parent = 0);
    ~guSettDialog();

protected:
    void changeEvent(QEvent *e);
    void initColors();     //������� ������ �� ���������
    void loadSettings(); //�������� ������������ ��������

private:
    Ui::guSettDialog *ui;

    QButtonGroup  *inLibFileActions;
    //colors
    QColor dublicateColor; //���� ����������
    QColor isbnColor;      //���� ���� � ��������� ����
    QColor biblioColor;    //���� ���� � ����������� �������������
    QColor uploadedColor;  //���� ����, ����������� �� ������
    QColor categoryColor;  //���� ��������� ��������� ��� �����

    QString colorToStyle(QColor color); //������� ������������ ����� ��� ������


private slots:

    void currentSettGroupChanged(int currentIndex); //����� ������ �������� � ������ �����
    void onSaveSettings();             //���������� ��������
    //��������� �����
    void onChangeDublicateColor();
    void onChangeIsbnColor();
    void onChangeBiblioColor();
    void onChangeUploadColor();
    void onChangeCategoryColor();
};

#endif // GUSETTDIALOG_H
