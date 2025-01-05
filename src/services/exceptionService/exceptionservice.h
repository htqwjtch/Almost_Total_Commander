#ifndef EXCEPTIONSERVICE_H
#define EXCEPTIONSERVICE_H

#include <QString>

class ExceptionService
{
public:
    ExceptionService(QString exceptionInfo);
    const QString getInfo() const noexcept;

private:
    QString exceptionInfo = "Something went wrong";
};

#endif // EXCEPTIONSERVICE_H
