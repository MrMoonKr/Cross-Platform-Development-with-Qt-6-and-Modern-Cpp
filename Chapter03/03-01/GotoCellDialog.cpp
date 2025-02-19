#include "GotoCellDialog.h"
#include "ui_GotoCellDialog.h"

#include <QtGui>
#include <QtWidgets>


GotoCellDialog::GotoCellDialog( QWidget* parent )
    : QDialog( parent )
    , m_ui( new Ui::GotoCellDialog )
{
    m_ui->setupUi( this );
    m_ui->buttonBox->button( QDialogButtonBox::Ok )->setEnabled( false );

    QRegularExpression regExp( "[A-Za-z][1-9][0-9]{0,2}" );
    m_ui->lineEdit->setValidator( new QRegularExpressionValidator( regExp, m_ui->lineEdit ) );

    QObject::connect( m_ui->lineEdit, &QLineEdit::textChanged, this, &GotoCellDialog::on_lineEdit_textChanged );
    //connect( m_ui->lineEdit, &QLineEdit::textEdited, this, &GotoCellDialog::on_lineEdit_textEdited );

    //m_ui->buttonBox->button( QDialogButtonBox::Ok )->setEnabled( false );
}

GotoCellDialog::~GotoCellDialog()
{
    delete m_ui;
}

void GotoCellDialog::on_lineEdit_textChanged()
{
    m_ui->buttonBox->button( QDialogButtonBox::Ok )->setEnabled( m_ui->lineEdit->hasAcceptableInput() );
}