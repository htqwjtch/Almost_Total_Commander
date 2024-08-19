#ifndef EXCEPTIONSERVICE_H
#define EXCEPTIONSERVICE_H

#include <QString>

class ExceptionService
{
    QString exceptionInfo = "Something went wrong";

public:
    ExceptionService() = default;
    ExceptionService(QString exceptionInfo);
    const QString getInfo() const noexcept;
};

#endif // EXCEPTIONSERVICE_H
