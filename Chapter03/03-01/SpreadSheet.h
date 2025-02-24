#pragma once


#include <QTableWidget>

class Cell;
class SpreadSheetCompare;

class SpreadSheet : public QTableWidget
{
    Q_OBJECT

public:
    SpreadSheet( QWidget* parent = nullptr );
    ~SpreadSheet();

    bool autoRecalculate() const { return m_autoRecalc; }
    QString currentLocation() const;
    QString currentFormula() const;
    QTableWidgetSelectionRange selectedRange() const;
    void clear();
    bool readFile( const QString& fileName );
    bool writeFile( const QString& fileName );
    void sort( const SpreadSheetCompare& compare );
    
signals:
    void modified();

public slots:
    void cut();
    void copy();
    void paste();
    void del();
    void selectCurrentRow();
    void selectCurrentColumn();
    void recalculate();
    void setAutoRecalculate( bool recalc );
    void findNext( const QString& str, Qt::CaseSensitivity cs );
    void findPrevious( const QString& str, Qt::CaseSensitivity cs );


private slots:
    void somethingChanged();

private:
    enum
    {
        MagicNumber = 0x7F51C883,
        RowCount = 999,
        ColumnCount = 26
    };

    Cell* cell( int row, int column ) const;
    QString text( int row, int column ) const;
    QString formula( int row, int column ) const;
    void setFormula( int row, int column, const QString& formula );

    bool m_autoRecalc;


};


class SpreadSheetCompare
{
public:
    bool operator()( const QStringList& lhs, const QStringList& rhs ) const ;

    enum 
    {
        KeyCount = 3
    };

    int keys[ KeyCount ];
    bool ascending[ KeyCount ];

};

