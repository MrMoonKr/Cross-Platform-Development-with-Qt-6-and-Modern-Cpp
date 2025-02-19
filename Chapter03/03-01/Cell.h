#pragma once


#include <QTableWidgetItem>


class Cell : public QTableWidgetItem
{
    // Q_OBJECT

public:
    Cell();
    ~Cell();

    QTableWidgetItem* clone() const;
    void setData( int role, const QVariant& value );
    QVariant data( int role ) const;
    void setFormula( const QString& formula );
    QString formula() const;
    void setDirty();

private:
    QVariant value() const;
    QVariant evalExpression( const QString& str, int& pos ) const;
    QVariant evalTerm( const QString& str, int& pos ) const;
    QVariant evalFactor( const QString& str, int& pos ) const;

    mutable QVariant m_CachedValue;
    mutable bool m_CacheIsDirty;

};

