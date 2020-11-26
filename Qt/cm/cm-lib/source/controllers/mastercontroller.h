#ifndef MASTERCONTROLLER_H
#define MASTERCONTROLLER_H

#include <QObject>
#include <QString>

#include <cm-lib_global.h>

namespace cm {
namespace controller {

class CMLIBSHARED_EXPORT MasterController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString ui_welcomeMessage MEMBER welcomeMessage CONSTANT)
public:
    explicit MasterController(QObject *parent = nullptr);
    QString welcomeMessage;

signals:

public slots:
};
}}
#endif // MASTERCONTROLLER_H
