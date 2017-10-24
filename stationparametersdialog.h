#ifndef STATIONPARAMETERSDIALOG_H
#define STATIONPARAMETERSDIALOG_H

#include <QDialog>
#include <QStringListModel>
#include <QSortFilterProxyModel>
#include <QMessageBox>
#include <ParameterSettings.h>

namespace Ui {
class stationParametersDialog;
}

class stationParametersDialog : public QDialog
{
    Q_OBJECT

public:
    explicit stationParametersDialog(QWidget *parent = 0);
    ~stationParametersDialog();

    void addBandNames(QStringList bands);

    void addSourceNames(QStringList sources);

    std::pair<std::string, VieVS::ParameterSettings::ParametersStations> getParameters();

private slots:
    void on_listView_ignoreSources_clicked(const QModelIndex &index);

    void on_lineEdit_filter_textChanged(const QString &arg1);

    void on_listWidget_selectedIgnoreSources_clicked(const QModelIndex &index);

    void on_buttonBox_accepted();


private:
    Ui::stationParametersDialog *ui;

    QStringListModel *sources;
    QSortFilterProxyModel *sources_proxy;
};

#endif // STATIONPARAMETERSDIALOG_H
