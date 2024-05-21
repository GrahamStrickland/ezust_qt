#include "orderform.h"
#include <QAbstractSpinBox>
#include <QHBoxLayout>
#include <QFormLayout>

OrderForm::OrderForm(QWidget *parent) :
    QWidget(parent)
{
    // Create line/date edits.
    m_nameEdit = new QLineEdit;

    m_dateEdit = new QDateEdit;
    m_dateEdit->setMinimumDate(QDate::currentDate().addDays(-365));
    m_dateEdit->setMaximumDate(QDate::currentDate().addDays(365));
    m_dateEdit->setDisplayFormat("yyyy/MM/dd");

    // Create spin boxes.
    m_quantitySpin = new QSpinBox;
    m_quantitySpin->setMinimum(0);
    m_quantitySpin->setMaximum(100);

    m_unitPriceSpin = new QDoubleSpinBox;
    m_totalPriceSpin = new QDoubleSpinBox;

    m_unitPriceSpin->setMinimum(0.0);
    m_unitPriceSpin->setMaximum(1000.00);
    m_unitPriceSpin->setDecimals(2);
    m_totalPriceSpin->setMinimum(0.0);
    m_totalPriceSpin->setDecimals(2);
    m_totalPriceSpin->setMaximum(100000.00);
    m_totalPriceSpin->setReadOnly(true);
    m_totalPriceSpin->setButtonSymbols(QAbstractSpinBox::NoButtons);

    // Create buttons.
    m_submitButton = new QPushButton(tr("OK"));
    m_cancelButton = new QPushButton(tr("Cancel"));

    // Connect signals to slots.
    connect(m_cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
    connect(m_submitButton, SIGNAL(clicked()), this, SLOT(submit()));
    connect(m_quantitySpin, SIGNAL(valueChanged(int)), this, SLOT(updateTotalPrice()));
    connect(m_unitPriceSpin, SIGNAL(valueChanged(double)), this, SLOT(updateTotalPrice()));

    // Create layout.
    QHBoxLayout *buttons = new QHBoxLayout;
    buttons->addWidget(m_submitButton, Qt::AlignRight);
    buttons->addWidget(m_cancelButton, Qt::AlignRight);

    QFormLayout *layout = new QFormLayout;
    layout->addRow(tr("Name"), m_nameEdit);
    layout->addRow(tr("Date Added"), m_dateEdit);
    layout->addRow(tr("Quantity"), m_quantitySpin);
    layout->addRow(tr("Unit Price"), m_unitPriceSpin);
    layout->addRow(tr("Total Price"), m_totalPriceSpin);
    layout->addRow(buttons);

    setLayout(layout);
}

void OrderForm::setOrder(Order *prod)
{
    m_order = prod;

    m_nameEdit->setPlaceholderText(prod->name());
    m_dateEdit->setDate(prod->dateAdded());
    m_quantitySpin->setValue(prod->quantity());
    m_unitPriceSpin->setValue(prod->price());
    m_totalPriceSpin->setValue(prod->quantity() * prod->price());
}

void OrderForm::cancel()
{
    this->close();
}

void OrderForm::submit()
{
    m_order->setName(m_nameEdit->text());
    m_order->setDateAdded(m_dateEdit->date());
    m_order->setQuantity(m_quantitySpin->value());
    m_order->setPrice(m_unitPriceSpin->value());

    this->close();
}

void OrderForm::updateTotalPrice()
{
    m_totalPriceSpin->setValue(m_quantitySpin->value() * m_unitPriceSpin->value());
}
