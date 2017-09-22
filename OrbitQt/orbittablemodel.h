//-----------------------------------
// Copyright Pierric Gimmig 2013-2017
//-----------------------------------
#pragma once

#include <QAbstractTableModel>
#include <memory>
#include "../OrbitGl/DataViewModel.h"

//-----------------------------------------------------------------------------
class OrbitTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit OrbitTableModel(DataViewType a_Type, QObject* parent = 0);
    explicit OrbitTableModel(QObject* parent = 0);
    virtual ~OrbitTableModel();

    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    virtual void sort(int column, Qt::SortOrder order = Qt::AscendingOrder);

    int GetUpdatePeriodMs() { return m_DataViewModel->GetUpdatePeriodMs(); }
    int GetSelectedIndex() { return m_DataViewModel->GetSelectedIndex(); }
    QModelIndex CreateIndex( int a_Row, int a_Column ){ return createIndex(a_Row, a_Column); }
    std::shared_ptr<DataViewModel> GetDataViewModel() { return m_DataViewModel; }
    void SetDataViewModel( std::shared_ptr<DataViewModel> a_Model ){ m_DataViewModel = a_Model; }

    void OnTimer();
    void OnFilter( const QString & a_Filter );
    void OnClicked( const QModelIndex & index );

protected:
    std::shared_ptr<DataViewModel> m_DataViewModel;
    bool m_AlternateRowColor;
};

