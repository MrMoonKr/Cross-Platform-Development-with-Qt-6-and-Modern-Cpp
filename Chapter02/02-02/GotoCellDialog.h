#pragma once

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class GotoCellDialog; }
QT_END_NAMESPACE

class GotoCellDialog : public QDialog
{
    Q_OBJECT

public:
    GotoCellDialog( QWidget* parent = nullptr );
    ~GotoCellDialog();

private slots:
    void on_lineEdit_textChanged();
    //void on_lineEdit_textEdited();

private:
    Ui::GotoCellDialog* m_ui;
};


