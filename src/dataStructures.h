#ifndef dataStructures_h
#define dataStructures_h
#include <QString>
#include <QTreeWidgetItem>
struct ebook
{
    QString MD5;
    bool    inLib;              //�������, ������������ �� ��� � ��
    bool    inLibCheckSended;   //��������, ��������� �� ������ �� �������� �� �����
    bool    inLibChecked;       //�������, ��������� �� �� ������������
    bool    biblioSetted;       //�������, ��������� �� ������������
    bool    uploaded;           //�������, ��������� �� ����� �� ������
    bool    toUpload;           //�������, ��������� �� ����� �� ������

    //��������� (Topics)
    QString category;                  //��������� (�����)
    //1. ���������, ������� ������� �� ������ categoryTreeSetted
    bool categoryTreeSetted;           //�������, ������� �� ��������� �� ������ ���������
    QTreeWidgetItem *categoryItem;     //��������� �� ���� � ������ ���������, ��������� �������������
    //2. ���������, ������� ������� �� ������ ���������
    bool catogorySubjectSetted;        //�������, ������ �� ������������ ��������� �� ������ subjects
    QStringList subjects;              //������ ���������, ���������� �� ������ ���������� subjectSetted
    int  subjectIndex;                 //����� ��������� � ������, ��������� �������������
    //3. ���������, ������� ������������ ����� ������ ���
    bool categoryManualSetted;         //�������, ���� ������������ ��� ������� ���� ���������

    //���������� � �����
    QString fileName;                  //��� �����
    QString filePath;                  //������ ���� � �����
    QString fileExtension;             //���������� �����
    int     fileSize;                  //������ ����� � ������
    //��������������
    QList<QString> ISBNs;              //����� (���� ������ ������� - ���� �� ������)

    //������������
    ///! - ����, ������������ � ����������(���� ��� �� �������� �� ������ ����������)
    QString authors;            //������            !
    QString title;              //���������         !
    QString series;             //�����
    QString publisher;          //������������      !
    QString sity;               //�����
    QString periodical;         //���������
    QString BBC;                //���
    QString UDC;                //���
    int pubYear;                //��� ������� (0 - �� �������) !
    int pageNum;                //���-�� ������� (0 - �� �������)  !
    QString issue;              //�������
    QString volume;             //���
    QString  language;          //���� TODO: ������� ����� ����� �� ������
    QString collection;         //������������� ���������-��������
    QString collectionIssue;    //����� ������� ������������� ���������-���������

    int orientation;            //���������� ����� (0 - �� �������, 1 - portrait, 2 - landscape)

    int scanDpi;                //���������� ����� (0 - �� �������)
    int scanColor;              //������� ���� (0 - �� �������, 1 - yes, 2 - no)
    int scanCleaned;            //��������� ���� (0 - �� �������, 1 - yes, 2 - no)
    QString description;        //�������� (���������)
    QString commentary;
    //�������
    QString coverUrl;
    QString ASIN;
    QPixmap cover;

    QTreeWidgetItem *item; //��������� �� GUI � ������ ������
};

#endif // dataStructures_h
