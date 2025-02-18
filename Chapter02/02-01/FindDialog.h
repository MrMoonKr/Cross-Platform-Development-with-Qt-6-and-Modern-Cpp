#pragma once

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QHBoxLayout>


class FindDialog : public QDialog
{
    Q_OBJECT

public:
    FindDialog( QWidget* parent = nullptr );

signals:
    void findNext( const QString& str, Qt::CaseSensitivity cs );
    void findPrevious( const QString& str, Qt::CaseSensitivity cs );

private slots:
    void findClicked();
    void enableFindButton( const QString& text );

private:
    QLabel*         m_label;
    QLineEdit*      m_lineEdit;
    QCheckBox*      m_caseCheckBox;
    QCheckBox*      m_backwardCheckBox;
    QPushButton*    m_findButton;
    QPushButton*    m_closeButton;

};

