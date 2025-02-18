#include "SortDialog.h"
#include "ui_SortDialog.h"

#include <QtGui>
#include <QtWidgets>


SortDialog::SortDialog( QWidget* parent )
    : QDialog( parent )
    , m_ui( new Ui::SortDialog )
{
    m_ui->setupUi( this );

    m_ui->secondaryGroupBox->hide();
    m_ui->tertiaryGroupBox->hide();
    layout()->setSizeConstraint( QLayout::SetFixedSize );

    setColumnRange( 'A', 'Z' );
}

SortDialog::~SortDialog()
{
    delete m_ui;
}

void SortDialog::setColumnRange( QChar first, QChar last )
{
    m_ui->primaryColumnCombo->clear();
    m_ui->secondaryColumnCombo->clear();
    m_ui->tertiaryColumnCombo->clear();

    m_ui->secondaryColumnCombo->addItem( tr( "None" ) );
    m_ui->tertiaryColumnCombo->addItem( tr( "None" ) );

    m_ui->primaryColumnCombo->setMinimumSize( m_ui->secondaryColumnCombo->sizeHint() );

    QChar ch = first;
    while ( ch <= last )
    {
        m_ui->primaryColumnCombo->addItem( QString( ch ) );
        m_ui->secondaryColumnCombo->addItem( QString( ch ) );
        m_ui->tertiaryColumnCombo->addItem( QString( ch ) );
        ch = QChar( ch.unicode() + 1 );
    }
}

