#ifndef guMainWindow_h
#define guMainWindow_h
//������������ ����� Qt
#include <QtCore>                   //������ ���� ����������
#include <QtGui>                    //������ GUI - ���������
#include <QtNetwork>                //������ �������� ��������������
#include <QtSql>                    //������ ������ � ������ ������

//#include "qtsoap/qtsoap.h"
//������������ ����� ���������
#include "guFolderInspector.h" //��� ������ ����, ���������� ��������������� ���������� � �����
#include "dataStructures.h"    //��������� ������ ��� �������� ���������� � ������
#include "guBookUploader.h"    //�������� �����, �������� � ��������� �����
#include "guLogger.h"          //������ � ���

namespace Ui {
    class guMainWindow;
}

//�����, ���������������� resizeEvent ������ QGraphicsView ��� ����������� �������
//�� ��� ��������� �������
class GraphicsViewEx : public QGraphicsView
{
public:
    GraphicsViewEx(QGraphicsScene *scene)
        : QGraphicsView(scene)
    {}
protected:
    //�������, ����������� ������ ��� ��� ��������� �������� �������
    void resizeEvent(QResizeEvent *event)
    {
            if (this->scene()->items().count() == 0)//���� �� ����� ��� ��� ���������
                return;//�������
            //����� �������� ������ ������� (��� ��� �� ����� ���� - ������� �����)
            QGraphicsItem *item = this->scene()->items().at(0);
            //� ������������ View ��� ������� � ����������� ���������
            this->fitInView(item,Qt::KeepAspectRatio);
    }
};
//����� �������� ����
class guMainWindow : public QMainWindow {
    Q_OBJECT
public:
    guMainWindow(QWidget *parent = 0);
    ~guMainWindow();
protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *event);

private:
    Ui::guMainWindow *ui;               //GUI ���������
    GraphicsViewEx *graphicsView;       //����������� ������ ��� ����������� �������
    QGraphicsScene *coverScene;         //����������� ����� �� ������� ����� ���������� �������

    QMap<QString, ebook> MD52EbookMap;  //����� MD5 - ������ "�����" �� dataStructures.h

    //����� ������
    guFolderInspector *inspector;       //�����, � ������� �������������� ����������
    bool toSearchInSubFolders;          //�������, ������������ �� ����� � ��������������
    QString searchFilePath;             //�����, � ������� �������������� ����� ����
    QStringList searchExtensions;       //���������� ������ ��� ������
    bool extractIsbnFromFiles;          //�������, ��������� �� ISBN �� ������
    bool extractIsbnFromFileNames;      //�������, ��������� �� ISBN �� ���� ������

    //���� (���� �� ������������)
    bool useApplicationProxy;          //���������� �� ������
    QNetworkProxy applicationProxy;    //������ ��� ����� ����������

    //SOAP (����� �� ������ ������������� soap)
    //QtSoapHttpTransport soap;
    //�������� �� ���������
    //2. �������� ����������� HTTP ��������
    QNetworkAccessManager *httpCheckDublicatesManager;      //�������� �� ��������� ����� HTTP
    int numOfCheckDublicateConnections;           //���������� HTTP ������������ �������� ��� �������� �� �����

    //�������� (UPLOADING)
    //
    QString serviceUrl;
    guBookUploader *uploader;           //��������� �� ������

    //�����������
    guLogger      *logger;              //������

    //����� ����������������� ����������
    int numOfFillBibliographyConnections;                   //���-�� ��������, ������������ �� ����� ����
    QNetworkAccessManager *httpFillBibliographyManager;     //����� � ������ ���������� ���. ������
    QNetworkAccessManager *coverLoaderManager;

    //����������
    int numOfInspected;  //���������� �����������
    int numOfDublicates; //���������� ����������
    int numOfNew;        //���������� �����
    int numOfWithIsbn;   //���������� � ISBN
    int numOfWithBiblio;
    int numOfUploaded;   //���������� ����������� �� ������

    //���������
    //����������� �������� ���������� ������
    QTimer *processTimer;           //������
    //����� ��������� �������
    QColor dublicateColor;          //���� ���������
    QColor withIsbnColor;           //���� ����� � ���� �� ����� ISBN
    QColor withBibliographyColor;   //���� ����� � ����������� �������������
    QColor uploadedColor;           //���� �����, ����������� �� ������
    //�������������� �������� �����
    QColor categorySelectedColor;   //��������� ��������� ��������� � ������ ���������


    void checkEbookDublicate(QString MD5);      //��������� ����� �� �����
    void fillBibliography(QString MD5, QString dataSource);//�������� ������������ ��� ����� � ���������� ���������

    QString getMd5ofCurrentItem();  //��������� MD5 �������� item � ������ ����
    //���������� ������ "� �������������" ��� "���" ��� ����� �� ��� MD5
    void setBiblioStateForItem(QString MD5, bool setted);
    //��������, ��� �� ���� ���������� ���������
    bool isBiblioFull(QString MD5);
    void updateStatusLabels();
public slots:
    void show();
private slots:
    //TEST
    void onGetSoapResponse();
    void testWebService();

    void loadCover(QString MD5, QString coverUrl);
    void onCopyMD5ToClipboard();
    void onOpenCurrentEbook();                          //������� �����
    //��������� �������� ��� ���� ��������� ����
    //TODO: �������� - ���������� � ������ � �� id ������������� ��������
    void onSetLibraryForAllBooks();
    void onSetLibraryIssueForAllBooks();
    void onSetPeriodicalForAllBooks();
    void onSetTitleForAllBooks();
    void onSetAuthorsForAllBooks();
    void onSetSeriesForAllBooks();
    void onSetPublisherForAllBooks();
    void onSetSityForAllBooks();
    void onSetUdcForAllBooks();
    void onSetPubYearForAllBooks();
    void onSetBbcForAllBooks();
    void onSetLanguageForAllBooks();
    void onSetOrientationForAllBooks();
    void onSetScanDpiForAllBooks();
    void onSetColorScanForAllBooks();
    void onSetCleanScanForAllBooks();

    //��� ������ � DOM
    QString getParamValue(QDomDocument *document, QString param);
    void onSetCategoryForAllBooks();
    void onSetCommentaryForAllBooks();
    void onAbortInspectProcess();
    void onAllEbooksUploaded();     //��������� ������� �� �������� � ���, ��� ��� ������� �������� �����
    void onShowAbout();
    void onHelp();

    void initBaseSettings();           //�������� ���������� �� ����������� �������� ���������
    void initSearchFilesSettings();

    void processCheckDublicateReply(QNetworkReply* reply); //���������� ������� �� �������� �� ��������
    void processFillBibliographyReply(QNetworkReply* reply);//���������� ������� �� ���������� ���. ������
    void processLoadCoverReply(QNetworkReply *reply);
    //��������� �������� �� ������ ������
    void onCurrentFileChanged(QTreeWidgetItem * current, QTreeWidgetItem * previous); //��������� ������ ���� � �����
    void onFilesTreeDoubleClicked(QTreeWidgetItem* item,int column);

    //��������� �������� �� ����������
    void onAddNewEbook(QString MD5, ebook newEbook); //���������� ����� �����
    void onDublicateFinded();                        //������ �����
    void onInspectFinished();                        //��������������� ���������

    void onStartProcess(); //
    void onEndProcess();   //
    void onTimerTimeout(); //

    //��������� �������� �� ������ ���������
    void onCurrentCategoryChanged(QTreeWidgetItem * current, QTreeWidgetItem * previous);//��������� ��������� ���������(��������) �����
    void onCurrentCategoryChangedFillStr(QTreeWidgetItem * current, QTreeWidgetItem * previous);

    //������� ����� �����
    void clearEditFields();

    //gui actions
    //1. ��� ����� ������ ����
    void onInspectFolder(); //������� - �������������� �����
    void onGetBiblioInfo(); //������� - �������� ���. ���-� ��� ���� ����, � ������� ���� ISBN
    void onUploadToServer();//������� - ��������� �� ������ ��� ���������� ����� � ���-�
    void onFileListRight();
    void onFileListLeft();


    //2. ��� ���������� �����
    void onGetBiblioForCurrentEbook(); //������� - �������� ���. ���������� ��� ������� �����
    void setGuiEditForCurrentItem();                             //������� �������� ����� ����� ��� ������� �����
    void onSaveChangesForBook();                                 //��������� ���������� ���. ����

    //�������� (UPLOADING)
    void onUploadEbookProgress(QString MD5OfUpload,int persent); //��������� ���� � �������� �������� �����
    void onUploadEbookFinished(QString MD5);                     //��������� ���������� �������� �����

    void onShowSettingsDialog();  //������� - ����� ������� ��������

    //��������� �������� � ������ �����-�������� ����
    void onIsbnFieldChanged(QString isbn); //��������� ����� ISBN
    void onIsbnsListItemActivated();       //����� ISBN� �� ������
    void onAddIsbn();                      //����� ���������� ISBN� �� lineEdit �
    void onRemoveIsbn();                   //����� �������� ISBN� �� ������

    void onAddIsbnToEbook(QString MD5, QString ISBN);      //��������� ���������� ISBN� ��� �����
    void onRemoveIsbnFromEbook(QString MD5, QString ISBN); //��������� �������� ISBN� ��� �����

    //��������� �������� � ����� � ���� ����������������� ����������
    void onCommentaryTextChanged(QString);
    void onTitleTextChanged(const QString newText);
    void onAuthorsTextChanged(QString);
    void onSeriesTextChanged(QString);
    void onPublisherTextChanged(QString);
    void onUdcTextChanged(QString);
    void onBbcTextChanged(QString);
    void onPubYearTextChanged(QString);
    void onPageNumTextChanged(QString);
    void onIssueTextChanged(QString);
    void onVolumeTextChanged(QString);
    void onLanguageTextChanged(QString);
    void onDescriptionTextChanged();
    void onSityTextChanged(QString sity);
    void onPeriodicalTextChanged(QString periodical);
    void onCategoryTextChanged(QString);
    void onOrientationIndexChanged(int index);
    void onBiblioTextChanged(QString biblio);
    void onDpiTextChanged(QString dpi);
    void onDvdNumTextChanged(QString dvdNum);
    void onColorScanStateChanged(int scanState);
    void onClearScanStateChanged(int clearState);
    void onSelectAllToUploadToogled(bool select);
    void onSubjectIndexChanged(int index);

    //��������� ������ ������������ item'��
    void onToogleShowDublicates(bool show);       //��������/������ ������ - �����
    void onToogleShowUploaded(bool show);         //��������/������ ����������� �����
    void onToogleShowWithISBN(bool show);         //��������/������ ������ � ISBN
    void onToogleShowWithBibliography(bool show); //��������/������ ������ � ���. �����������
signals:
    void abortInspectProcess();
};
#endif // guMainWindow_h
