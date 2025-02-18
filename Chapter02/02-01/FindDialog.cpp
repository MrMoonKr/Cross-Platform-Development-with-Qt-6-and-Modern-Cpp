#include "FindDialog.h"



FindDialog::FindDialog( QWidget* parent )
    : QDialog( parent )
{
    m_label = new QLabel( tr( "Find &what:" ), this );
    m_lineEdit = new QLineEdit( this );
    m_label->setBuddy( m_lineEdit );

    m_caseCheckBox = new QCheckBox( tr( "Match &case" ), this );
    m_backwardCheckBox = new QCheckBox( tr( "Search &backward" ), this );

    m_findButton = new QPushButton( tr( "&Find" ), this );
    m_findButton->setDefault( true );
    m_findButton->setEnabled( false );

    m_closeButton = new QPushButton( tr( "Close" ), this );

    QObject::connect( m_lineEdit, &QLineEdit::textChanged, this, &FindDialog::enableFindButton );
    QObject::connect( m_findButton, &QPushButton::clicked, this, &FindDialog::findClicked );
    QObject::connect( m_closeButton, &QPushButton::clicked, this, &FindDialog::close );

    QHBoxLayout* topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget( m_label );
    topLeftLayout->addWidget( m_lineEdit );

    QVBoxLayout* leftLayout = new QVBoxLayout;
    leftLayout->addLayout( topLeftLayout );
    leftLayout->addWidget( m_caseCheckBox );
    leftLayout->addWidget( m_backwardCheckBox );

    QVBoxLayout* rightLayout = new QVBoxLayout;
    rightLayout->addWidget( m_findButton );
    rightLayout->addWidget( m_closeButton );
    rightLayout->addStretch();

    QHBoxLayout* mainLayout = new QHBoxLayout( this );
    mainLayout->addLayout( leftLayout );
    mainLayout->addLayout( rightLayout );

    setLayout( mainLayout );

    setWindowTitle( tr( "Find" ) );
    setFixedHeight( sizeHint().height() );
}


void FindDialog::findClicked()
{
    QString text = m_lineEdit->text();
    Qt::CaseSensitivity cs = m_caseCheckBox->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;
    if ( m_backwardCheckBox->isChecked() )
    {
        emit findPrevious( text, cs );
    }
    else
    {
        emit findNext( text, cs );
    }
}

void FindDialog::enableFindButton( const QString& text )
{
    m_findButton->setEnabled( !text.isEmpty() );
}

