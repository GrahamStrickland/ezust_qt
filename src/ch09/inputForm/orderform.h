#ifndef ORDERFORM_H
#define ORDERFORM_H

#include "order.h"
#include <QDateEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QWidget>

class OrderForm : public QWidget {
  Q_OBJECT
public:
  OrderForm(QWidget *parent = 0);
  void setOrder(Order *prod);

public slots:
  void cancel();
  void submit();
  void updateTotalPrice();

private:
  QLineEdit *m_nameEdit;
  QDateEdit *m_dateEdit;
  QSpinBox *m_quantitySpin;
  QDoubleSpinBox *m_unitPriceSpin;
  QDoubleSpinBox *m_totalPriceSpin;
  QPushButton *m_submitButton;
  QPushButton *m_cancelButton;

  Order *m_order;
};

#endif // ORDERFORM_H
