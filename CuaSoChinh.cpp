#include "CuaSoChinh.h"

CuaSoChinh::CuaSoChinh(QWidget *parent)
    : QWidget(parent)
{
    txtSo1 = new QLineEdit(this);
    txtSo2 = new QLineEdit(this);
    lblKetQua = new QLabel("Kết quả: ", this);
    lstLichSu = new QListWidget(this);

    btnCong = new QPushButton("Cộng", this);
    btnTru = new QPushButton("Trừ", this);
    btnNhan = new QPushButton("Nhân", this);
    btnChia = new QPushButton("Chia", this);
    btnClearLichSu = new QPushButton("Xoá lịch sử", this);
    btnExit = new QPushButton("Thoát", this);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(new QLabel("Số thứ nhất:", this));
    mainLayout->addWidget(txtSo1);
    mainLayout->addWidget(new QLabel("Số thứ hai:", this));
    mainLayout->addWidget(txtSo2);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(btnCong);
    buttonLayout->addWidget(btnTru);
    buttonLayout->addWidget(btnNhan);
    buttonLayout->addWidget(btnChia);
    buttonLayout->addWidget(btnClearLichSu);

    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(lblKetQua);
    mainLayout->addWidget(new QLabel("Lịch sử phép tính:", this));
    mainLayout->addWidget(lstLichSu);
    mainLayout->addWidget(btnExit);

    connect(btnCong, &QPushButton::clicked, this, &CuaSoChinh::cong);
    connect(btnTru, &QPushButton::clicked, this, &CuaSoChinh::tru);
    connect(btnNhan, &QPushButton::clicked, this, &CuaSoChinh::nhan);
    connect(btnChia, &QPushButton::clicked, this, &CuaSoChinh::chia);
    connect(btnClearLichSu, &QPushButton::clicked, this, &CuaSoChinh::xoaLichSu);
    connect(btnExit, &QPushButton::clicked, this, &CuaSoChinh::thoat);
}

void CuaSoChinh::ghiLichSu(const QString &phepTinh)
{
    lstLichSu->insertItem(0, phepTinh); // Kết quả mới nhất ở trên cùng
}

void CuaSoChinh::cong()
{
    double a = txtSo1->text().toDouble();
    double b = txtSo2->text().toDouble();
    double kq = a + b;
    lblKetQua->setText("Kết quả: " + QString::number(kq));
    ghiLichSu(QString("%1 + %2 = %3").arg(a).arg(b).arg(kq));
}

void CuaSoChinh::tru()
{
    double a = txtSo1->text().toDouble();
    double b = txtSo2->text().toDouble();
    double kq = a - b;
    lblKetQua->setText("Kết quả: " + QString::number(kq));
    ghiLichSu(QString("%1 - %2 = %3").arg(a).arg(b).arg(kq));
}

void CuaSoChinh::nhan()
{
    double a = txtSo1->text().toDouble();
    double b = txtSo2->text().toDouble();
    double kq = a * b;
    lblKetQua->setText("Kết quả: " + QString::number(kq));
    ghiLichSu(QString("%1 * %2 = %3").arg(a).arg(b).arg(kq));
}

void CuaSoChinh::chia()
{
    double a = txtSo1->text().toDouble();
    double b = txtSo2->text().toDouble();
    QString kq;
    if (b == 0)
        kq = "Không thể chia cho 0";
    else
        kq = QString::number(a / b);

    lblKetQua->setText("Kết quả: " + kq);
    ghiLichSu(QString("%1 / %2 = %3").arg(a).arg(b).arg(kq));
}

void CuaSoChinh::xoaLichSu()
{
    txtSo1->clear();
    txtSo2->clear();
    lblKetQua->setText("Kết quả: ");
    lstLichSu->clear();
}

void CuaSoChinh::thoat()
{
    close();
}
