#include "Cell.h"

#include <QtGui>

Cell::Cell()
{
    setDirty();
}

Cell::~Cell()
{
}

QTableWidgetItem* Cell::clone() const
{
    return new Cell( *this );
}


void Cell::setData( int role, const QVariant& value )
{
    QTableWidgetItem::setData( role, value );

    if( role == Qt::EditRole )
    {
        setDirty();
    }
}

QVariant Cell::data( int role ) const
{
    if( role == Qt::DisplayRole )
    {
        if( value().isValid() )
        {
            return value().toString();
        }
        else
        {
            return "####";
        }
    }
    else if ( role == Qt::TextAlignmentRole )
    {
        if( value().metaType().id() == QMetaType::Double )
        {
            return int( Qt::AlignLeft | Qt::AlignVCenter );
        }
        else
        {
            return int( Qt::AlignRight | Qt::AlignVCenter );
        }
    }
    else
    {
        return QTableWidgetItem::data( role );
    }

    return 0;
}

void Cell::setFormula( const QString& formula )
{
    setData( Qt::EditRole, formula );
}

QString Cell::formula() const
{
    return data( Qt::EditRole ).toString();
}

void Cell::setDirty()
{
    m_CacheIsDirty = true;
}

const QVariant Invalid;

QVariant Cell::value() const
{
    if( m_CacheIsDirty )
    {
        m_CacheIsDirty = false;

        QString formulaStr = formula();
        if( formulaStr.startsWith( "\'" ) )
        {
            m_CachedValue = formulaStr.mid( 1 );
        }
        else if( formulaStr.startsWith( "=" ) )
        {
            m_CachedValue = Invalid;
            QString expr = formulaStr.mid( 1 );
            expr.replace( " ", "" );
            expr.append( QChar::Null );

            int pos = 0;
            m_CachedValue = evalExpression( expr, pos );
            if( expr[ pos ] != QChar::Null )
            {
                m_CachedValue = Invalid;
            }
        }
        else
        {
            bool ok;
            double d = formulaStr.toDouble( &ok );
            if( ok )
            {
                m_CachedValue = d;
            }
            else
            {
                m_CachedValue = formulaStr;
            }
        }
    }

    return m_CachedValue;
}

QVariant Cell::evalExpression( const QString& str, int& pos ) const
{
    QVariant result = evalTerm( str, pos );

    while( str[ pos ] != QChar::Null )
    {
        QChar op = str[ pos ];
        if( op != '+' && op != '-' )
        {
            return result;
        }

        ++pos;

        QVariant term = evalTerm( str, pos );
        if( result.metaType().id() == QMetaType::Double && term.metaType().id() == QMetaType::Double )
        {
            if( op == '+' )
            {
                result = result.toDouble() + term.toDouble();
            }
            else
            {
                result = result.toDouble() - term.toDouble();
            }
        }
        else
        {
            result = Invalid;
        }
    }

    return result;
}

QVariant Cell::evalTerm( const QString& str, int& pos ) const
{
    QVariant result = evalFactor( str, pos );

    while( str[ pos ] != QChar::Null )
    {
        QChar op = str[ pos ];
        if( op != '*' && op != '/' )
        {
            return result;
        }

        ++pos;

        QVariant factor = evalFactor( str, pos );
        if( result.metaType().id() == QMetaType::Double && factor.metaType().id() == QMetaType::Double )
        {
            if( op == '*' )
            {
                result = result.toDouble() * factor.toDouble();
            }
            else
            {
                if( factor.toDouble() == 0.0 )
                {
                    result = Invalid;
                }
                else
                {
                    result = result.toDouble() / factor.toDouble();
                }
            }
        }
        else
        {
            result = Invalid;
        }
    }

    return result;
}

QVariant Cell::evalFactor( const QString& str, int& pos ) const
{
    QVariant result;

    bool negative = false;
    if( str[ pos ] == '-' )
    {
        negative = true;
        ++pos;
    }

    if( str[ pos ] == '(' )
    {
        ++pos;
        result = evalExpression( str, pos );
        if( str[ pos ] == ')' )
        {
            ++pos;
        }
    }
    else
    {
        QRegularExpression regExp( "([A-Za-z][1-9][0-9]{0,2})" );
        QString token;

        while( str[ pos ].isLetterOrNumber() || str[ pos ] == '.' )
        {
            token += str[ pos ];
            ++pos;
        }

        if( regExp.match( token ).matchType() == QRegularExpression::MatchType::NormalMatch )
        {
            int column = token[ 0 ].toUpper().unicode() - 'A';
            int row = token.mid( 1 ).toInt() - 1;

            Cell* c = static_cast<Cell*>( tableWidget()->item( row, column ) );
            if( c )
            {
                result = c->value();
            }
            else
            {
                result = 0.0;
            }
        }
        else
        {
            bool ok;
            result = token.toDouble( &ok );
            if( !ok )
            {
                result = Invalid;
            }
        }
    }

    if( negative && result.metaType().id() == QMetaType::Double )
    {
        result = -result.toDouble();
    }

    return result;
}