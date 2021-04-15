#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include <QMainWindow>
#include <QKeySequence>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QPlainTextEdit>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include <QSharedPointer>
#include "FindDialog.h"
#include "ReplaceDialog.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    QPlainTextEdit mainEditor;
    QLabel statusLbl;
    QString m_filePath;
    bool m_isTextChanged;
    QSharedPointer<FindDialog> m_pFindDlg;
    QSharedPointer<ReplaceDialog> m_pReplaceDlg;

    MainWindow();
    MainWindow(const MainWindow&);
    MainWindow& operator= (const MainWindow&);

    bool construct();
    bool initMenuBar();
    bool initToolBar();
    bool initStatusBar();
    bool initMainEditor();
    bool initFileMenu(QMenuBar* mb);
    bool initEditMenu(QMenuBar* mb);
    bool initFormatMenu(QMenuBar* mb);
    bool initViewMenu(QMenuBar* mb);
    bool initHelpMenu(QMenuBar* mb);
    bool initFileToolItem(QToolBar* tb);
    bool initEditToolItem(QToolBar* tb);
    bool initFormatToolItem(QToolBar* tb);
    bool initViewToolItem(QToolBar* tb);
    bool makeAction(QAction*& action, QWidget* parent, QString text, int key);
    bool makeAction(QAction*& action, QWidget* parent, QString tip, QString icon);

    QString showFileDialog(QFileDialog::AcceptMode mode, QString title);
    int showQueryMessage(QString message);
    void showErrorMessage(QString message);
    QString saveCurrentData(QString path = "");
    int preEditorChange();
    void openFileToEditor(QString path);
    QAction* findMenuBarAction(QString text);
    QAction* findToolBarAction(QString text);

protected:
    QToolBar* toolBar();
    void closeEvent(QCloseEvent* e);
    void dragEnterEvent(QDragEnterEvent* e);
    void dropEvent(QDropEvent* e);

private slots:
    void onFileNew();
    void onFileOpen();
    void onFileSave();
    void onFileSaveAs();
    void onFilePrint();
    void onFileExit();
    void onTextChanged();
    void onCopyAvailable(bool available);
    void onRedoAvailable(bool available);
    void onUndoAvailable(bool available);
    void onCursorPositionChanged();
    void onEditFind();
    void onEditReplace();
    void onEditDelete();
    void onEditGoto();
    void onFormatWrap();
    void onFormatFont();
    void onViewToolBar();
    void onViewStatusBar();
    void onHelpManual();
    void onHelpAbout();

public:
    static MainWindow* NewInstance();
    ~MainWindow();

    void show();
    void openFile(QString path);
};

#endif // _MAINWINDOW_H_
