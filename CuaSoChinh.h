#ifndef CUASOCHINH_H
#define CUASOCHINH_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>

class CuaSoChinh : public QWidget
{
    Q_OBJECT

public:
    CuaSoChinh(QWidget *parent = nullptr);

private slots:
    void cong();
    void tru();
    void nhan();
    void chia();
    void xoaLichSu();
    void thoat();

private:
    QLineEdit *txtSo1;
    QLineEdit *txtSo2;
    QLabel *lblKetQua;
    QListWidget *lstLichSu;
    QPushButton *btnCong;
    QPushButton *btnTru;
    QPushButton *btnNhan;
    QPushButton *btnChia;
    QPushButton *btnClearLichSu;
    QPushButton *btnExit;

    void ghiLichSu(const QString &phepTinh);
};

#endif // CUASOCHINH_H
