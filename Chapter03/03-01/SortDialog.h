#pragma once

#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class SortDialog; }
QT_END_NAMESPACE

class SpreadSheet;
class SpreadSheetCompare;

class SortDialog : public QDialog
{
    Q_OBJECT

public:
    SortDialog( QWidget* parent = nullptr );
    ~SortDialog();

    void setColumnRange( QChar first, QChar last );
    void setCompare( SpreadSheetCompare& compare );

    Ui::SortDialog* getUI() { return this->m_ui; }

public:
    Ui::SortDialog* m_ui;

};

