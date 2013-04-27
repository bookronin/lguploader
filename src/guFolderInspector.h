#ifndef guFolderInspector_h
#define guFolderInspector_h

#include <QThread>
#include <QObject>
#include <QStringList>
#include <QString>
#include <QtSql>
#include "dataStructures.h"
#include <QRegExp>
#include <QSqlDatabase>

#include "libdjvu/miniexp.h"
#include "libdjvu/ddjvuapi.h"
#include "poppler/qt4/poppler-qt4.h"
//#include "poppler/Page.h"
#include "poppler/PDFDoc.h"

//#include "chmlib/chm_lib.h"
//#include "chmlib/lzx.h"
#include "libchmfile/libchmfile.h"
#include "libchmfile/libchmfileimpl.h"

class guFolderInspector : public QThread
{
    Q_OBJECT
public:
    guFolderInspector();
    ~guFolderInspector();
    void run();
private:
    //chmFile* chm;
    bool checkFromLibGen; //����, ��������� �� �� �� �������
    bool terminate;
    QSqlDatabase libGenDb;
    LCHMFileImpl *chmFileImpl;
    ddjvu_context_t *ctx;
    ddjvu_document_t *doc;

    //for pdf
    //Poppler::Document* document;
    QStringList nameFilters;
    bool toSearchInSubFolders;

    bool toExtractIdentifiersFromFiles;
    bool toExtractIdentifiersFromFileNames;

    QString searchPath;
    QString dbFilePath;
    QSqlDatabase db; //���� ������

    bool open(QString dbFilePath);//�������� ��
    bool initDb();//�������������� �������������
    bool inLib(QString MD5); //��������, � ���������� �� (���������� �� ��������, ��������� ��
    //���� ���������, �� �����������, ���� �� ����, ������������ � �������� ������ �� ���. ���
    //������������ ������
    bool inLibGen(QString MD5);//���������, ���� �� � �� �������

public slots:
    void onAbortInspect();
    void inspectFolder(QString path, QStringList searchFileExtensions,
                       bool searchInSubFolders,
                       bool extractIdentifiersFromFiles,
                       bool extractIdentifiersFromFileNames);
    void extractIsbnsFromFile(QString fileName, QList<QString> &ISBNList, QString type);
    void extractIsbnsFromDjvu(QString fileName, QList<QString> &ISBNList);
    void extractIsbnsFromChm(QString fileName, QList<QString> &ISBNList);
    void extractIsbnsFromPdf(QString fileName, QList<QString> &ISBNList);

    void onSetNameFilters(QStringList fileNameFilters);
    void onSetSearchDirectory(QString searchPathStr);
    void onSetSearchInSubdirs(bool toSearch);
    void onSetDbFilePath( QString databaseFilePath);
signals:
    void addNewEbook(QString MD5, ebook newEbook);
    void dublicateFinded();
    void inspectFinished();
};

#endif // guFolderInspector_h
